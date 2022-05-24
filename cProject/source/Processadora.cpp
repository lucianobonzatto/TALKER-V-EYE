#include "Processadora.h"

Processadora::Processadora() {
    m1.setPin(14);
    m2.setPin(15);
    m3.setPin(23);
    m4.setPin(24);
    mp.setPin(17);

    m4.setIntensity(0);
    m3.setIntensity(0);
    m2.setIntensity(0);
    m1.setIntensity(0);
    mp.setIntensity(0);

    int teste = 0;
    int count = 0;
    while(teste < 100){
        teste++;
        std::cout << endl << "============================= " << teste << " ===============================" << endl;
//        testeMotor();

        rs_sensor.read_img();
        cv::Mat* img =  rs_sensor.get_img();
//        imshow("Display window", *img);
//        int k = waitKey(0);
        if(count ==0){
           sockClient.sendImageForApi(img);
	   cout << "send image finished "<< endl;
           count++;
	}
        
//        detectaObstaculo();
//        detectaLidar();

//        std::cout << "\tlidar\t\t->\t" << ll_sensor.getDistance() << std::endl;
//        rs_sensor.print_points();
//        printRSDepth();
//        rs_sensor.print_img();
//        usleep(1000000);
    }
    m4.setIntensity(0);
    m3.setIntensity(0);
    m2.setIntensity(0);
    m1.setIntensity(0);
    mp.setIntensity(0);

}

Processadora::~Processadora() {

}

void Processadora::printRSDepth() {
    int width, height, i_aux = -1, j_aux = -1;
    float men_dist, at_dist;

//    rs_sensor.read_img();
    width = rs_sensor.get_depth_width();
    height = rs_sensor.get_depth_height();
    men_dist = 10000;

    for(int i=0; i<width; i+=10){
        for(int j=0; j<height; j+=10){
            at_dist = rs_sensor.get_depth(i, j);
            if(at_dist > 0 && men_dist > at_dist){
                men_dist = at_dist;
                i_aux = i;
                j_aux = j;
            }
        }
    }
    std::cout << "\tdepth(" << i_aux << ")(" << j_aux << ")\t->\t" << men_dist << std::endl;
//    std::cout << "\tdepth(" << width/2 << ")(" << height/2 << ")\t->\t" << rs_sensor.get_depth(width/2, height/2) << std::endl;
}

void Processadora::printLLDepth() {
    std::cout << "\t\t" << "lidar\t->\t" << ll_sensor.getDistance() << std::endl;
}

void Processadora::testeMotor() {
    static int intensidade = 50;
    static int msel = 0;

    intensidade+=3;
    if(intensidade > 255){
        intensidade = 0;
        msel = (msel+1)%5;
    }

    switch(msel){
    case 0:
        m4.setIntensity(intensidade);
        m3.setIntensity(0);
        m2.setIntensity(0);
        m1.setIntensity(0);
        mp.setIntensity(0);
        break;
    case 1:
        m4.setIntensity(0);
        m3.setIntensity(intensidade);
        m2.setIntensity(0);
        m1.setIntensity(0);
        mp.setIntensity(0);
        break;
    case 2:
        m4.setIntensity(0);
        m3.setIntensity(0);
        m2.setIntensity(intensidade);
        m1.setIntensity(0);
        mp.setIntensity(0);
        break;
    case 3:
        m4.setIntensity(0);
        m3.setIntensity(0);
        m2.setIntensity(0);
        m1.setIntensity(intensidade);
        mp.setIntensity(0);
        break;
    case 4:
        m4.setIntensity(0);
        m3.setIntensity(0);
        m2.setIntensity(0);
        m1.setIntensity(0);
        mp.setIntensity(intensidade);
        break;

    }
    std::cout << "\tintensidade\t->\t" << intensidade << "\tmotor\t->\t" << msel << std::endl;
}

void Processadora::detectaLidar(){
    float dist = ll_sensor.getDistance();

    std::cout << "\tlidar\t\t->\t" << dist << std::endl;

    if(dist < DIST_MIN_LL || dist > DIST_MAX_LL)
        mp.setIntensity(0);
    else
        mp.setIntensity(converteDistanciaIntensidade_ll(dist));
}

void Processadora::detectaObstaculo(){
    rs2::points* pontos = rs_sensor.getPoints();
    auto vertices = pontos->get_vertices();
    float distanciaMinima = 99999999;
    int indiceMenorPonto = 0;

    /*Primeira varredura na nuvem de pontos*/
    for (int i = 0; i < pontos->size(); i++)
    {
        float xi = vertices[i].x;
        float yi = vertices[i].y;
        float zi = vertices[i].z;
        float distanciaAtual = calculaDistancia(xi, yi, zi);
        //cout << "dist calc -> " << distanciaAtual << endl;
        //if(distanciaAtual == 0){
            //cout << "**********************************************************************************" << endl;
            //cout << "**********************************************************************************" << endl;
            //cout << "**********************************************************************************" << endl;
            //cout << "x -> " << vertices[i].x << "t -> " << vertices[i].y << "z -> "<< vertices[i].z << endl;
            //continue;
        //}
        if(distanciaAtual < distanciaMinima){
            if ((abs(zi - configuracao.getAlturaRealsense()/*alturaRealsense*/) > INTERV_CHAO) && (distanciaAtual > configuracao.getLarguraBraco()/*DIST_MIN_RS*/) && (distanciaAtual < configuracao.getProfundidadeMaxima()/*DIST_MAX_RS*/))
            {
                indiceMenorPonto = i;
                distanciaMinima = distanciaAtual;
            }
        }
    }

    float n_pontos_obtaculo_quadrante_1 = 0;
    float n_pontos_obtaculo_quadrante_2 = 0;
    float n_pontos_obtaculo_quadrante_3 = 0;
    float n_pontos_obtaculo_quadrante_4 = 0;

    /*Segunda varredura na nuvem de pontos*/
    for (int i = 0; i < pontos->size(); i++)
    {
        float xi = vertices[i].x;
        float yi = vertices[i].y;
        float zi = vertices[i].z;
        float distanciaAtual = calculaDistancia(xi, yi, zi);

        if(abs(distanciaAtual - distanciaMinima) < INTERV_OBSTACULO){   //Identifica pontos proximos ao ponto mais proximo do usuario
            int quadrante = convertePontoQuadrante(xi, yi);

            switch(quadrante){
                case 1:
                    n_pontos_obtaculo_quadrante_1 ++;
                    break;
                case 2:
                    n_pontos_obtaculo_quadrante_2 ++;
                    break;
                case 3:
                    n_pontos_obtaculo_quadrante_3 ++;
                    break;
                case 4:
                    n_pontos_obtaculo_quadrante_4 ++;
                    break;
            }
        }
    }

    int intensidade = converteDistanciaIntensidade_rs(distanciaMinima);
    if(n_pontos_obtaculo_quadrante_1 > MIN_PONTOS_QUADRANTE){
        m1.setIntensity(intensidade);
        cout << "1 ";
    }
    else{
        m1.setIntensity(0);
    }

    if(n_pontos_obtaculo_quadrante_2 > MIN_PONTOS_QUADRANTE){
        m2.setIntensity(intensidade);
        cout << "2 ";
    }
    else{
        m2.setIntensity(0);
    }

    if(n_pontos_obtaculo_quadrante_3 > MIN_PONTOS_QUADRANTE){
        m3.setIntensity(intensidade);
        cout << "3 ";
    }
    else{
        m3.setIntensity(0);
    }

    if(n_pontos_obtaculo_quadrante_4 > MIN_PONTOS_QUADRANTE){
        m4.setIntensity(intensidade);
        cout << "4 ";
    }
    else{
        m4.setIntensity(0);
    }

    std::cout << "\tdist - " << distanciaMinima << std::endl;
    std::cout << "\tQ1 - " << n_pontos_obtaculo_quadrante_1 << std::endl;
    std::cout << "\tQ2 - " << n_pontos_obtaculo_quadrante_2 << std::endl;
    std::cout << "\tQ3 - " << n_pontos_obtaculo_quadrante_3 << std::endl;
    std::cout << "\tQ4 - " << n_pontos_obtaculo_quadrante_4 << std::endl;

}

std::pair<int,int> Processadora::convertePontoPixel(float x, float y, float z){
    //nao esta feita
    std::pair<int,int> pixel;
    pixel.first = 0;
    pixel.second = 0;
    return pixel;
}

float Processadora::calculaDistancia(float x, float y, float z){
    return sqrt(x*x + y*y + z*z);
}

int Processadora::convertePixelQuadrante(std::pair<int,int> pixel){
    int halfWidth = rs_sensor.get_img_width()/2;
    int halfHeight = rs_sensor.get_img_height()/2;

    if(pixel.first > halfWidth && pixel.second > halfHeight){
        return 1;
    }
    else if(pixel.first > halfWidth && pixel.second < halfHeight){
        return 2;
    }
    else if(pixel.first < halfWidth && pixel.second > halfHeight){
        return 3;
    }
    else if(pixel.first < halfWidth && pixel.second < halfHeight){
        return 4;
    }
    return -1;
}

int Processadora::convertePontoQuadrante(float x, float y){
    if(x > 0 && y > 0){
        return 1;
    }
    else if(x < 0 && y > 0){
        return 2;
    }
    else if(x < 0 && y < 0){
        return 3;
    }
    else if(x > 0 && y < 0){
        return 4;
    }
    return -1;
}

int Processadora::converteDistanciaIntensidade_rs(float distancia){
    /*Mapeia os valores de distância no invervalo 0-255 (PWM)*/
    float coef_ang = -255/(DIST_MAX_RS - DIST_MIN_RS);
    int intensidade = coef_ang*(distancia - DIST_MIN_RS) + 255;  //Equacao fundamental da reta.
    if(intensidade > 255)
        intensidade = 255;
    else if(intensidade < 0)
        intensidade = 0;

    return intensidade;
}
int Processadora::converteDistanciaIntensidade_ll(float distancia){
    /*Mapeia os valores de distância no invervalo 0-255 (PWM)*/
    float coef_ang = -255/(DIST_MAX_LL - DIST_MIN_LL);
    int intensidade = coef_ang*(distancia - DIST_MIN_LL) + 255;  //Equacao fundamental da reta.
    if(intensidade > 255)
        intensidade = 255;
    else if(intensidade < 0)
        intensidade = 0;

    return intensidade;
}
