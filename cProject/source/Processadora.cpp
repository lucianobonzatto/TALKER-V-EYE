#include "Processadora.h"

Processadora::Processadora() {
    m1.setPin(15);
    m2.setPin(24);
    m3.setPin(23);
    m4.setPin(14);
    mp.setPin(17);

    b1.setPin(10);
    b2.setPin(22);
    b3.setPin(27);

    m4.setIntensity(0);
    m3.setIntensity(0);
    m2.setIntensity(0);
    m1.setIntensity(0);
    mp.setIntensity(0);
    pixelProx[0] = 0;
    pixelProx[1] = 0;
    habilitado = false;

//    rs_sensor.read_img();
    usleep(1000000);

    int teste = 0;
    while(teste < 10){
        teste++;
        usleep(80000);
        std::cout << endl << "============================= " << teste << " ===============================" << endl;

        rs_sensor.read_img();
        int h = rs_sensor.get_img_height();
        int w = rs_sensor.get_img_width();

        detectaObstaculo();
        if(teste == 5){
            std::cout << "b3 -> 1" << endl;
            cv::Mat* img =  rs_sensor.get_img();

            h = rs_sensor.get_img_height();
            w = rs_sensor.get_img_width();
//            std::cout << "h " << (float)pixelProx[1]/h << "w: " << (float)pixelProx[0]/w << std::endl;
//            std::cout << "h " << (float)pixelProx[1] << " w: " << (float)pixelProx[0] << std::endl;
            sockClient.sendImageForApi(img, 1, pixelProx[1], pixelProx[0], h, w); //objeto mais proximo
 	}
    }
    m4.setIntensity(0);
    m3.setIntensity(0);
    m2.setIntensity(0);
    m1.setIntensity(0);
    mp.setIntensity(0);
}

Processadora::~Processadora() {

}

void Processadora::loop(){
    cv::Mat* img;
    int h = rs_sensor.get_img_height();
    int w = rs_sensor.get_img_width();
    int num = 0;
    String nome = "/home/lukn23/TALKER-V-EYE/cProject/img/teste"+ to_string(num) + ".jpg";

    while(1){
        if(habilitado){
            //cout << "\taltura -> " << config.getAlturaRealsense() << endl;
            //cout << "\tbraco -> " << config.getLarguraBraco() << endl;
            //cout << "\tprofMax -> " << config.getProfundidadeMaxima() << endl;

            rs_sensor.read_img();
            detectaObstaculo();
            detectaLidar();
            if( b2.getState() == 1){
//                num++;
                std::cout << "b2 -> 1" << endl;
                img =  rs_sensor.get_img();
//                nome = "/home/lukn23/TALKER-V-EYE/cProject/img/teste"+ to_string(num) + ".jpg";
//                std::cout << nome;
//                imwrite(nome, *img);
                
                sockClient.sendImageForApi(img, 0, 0, 0, h, w); //todos os objetos
            }
            else if( b3.getState() == 1){
//                num++;
                std::cout << "b3 -> 1" << endl;
                img =  rs_sensor.get_img();
//                nome = "/home/lukn23/TALKER-V-EYE/cProject/img/teste"+ to_string(num) + ".jpg";
//                std::cout << nome;
//                imwrite(nome, *img);
                
                h = rs_sensor.get_img_height();
                w = rs_sensor.get_img_width();
                std::cout << "h " << pixelProx[1]/h << "w: " << pixelProx[0]/w << std::endl;
                sockClient.sendImageForApi(img, 1, pixelProx[1], pixelProx[0], h, w); //objeto mais proximo
            }
        }

        if( b1.getState() == 1){
            m4.setIntensity(0);
            m3.setIntensity(0);
            m2.setIntensity(0);
            m1.setIntensity(0);
            mp.setIntensity(0);
            std::cout << "b1 -> 1" << endl;
            habilitado = !habilitado;
        }
    }
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
    int intensidade = converteDistanciaIntensidade_ll(dist);

    //std::cout << "\tlidar\t\t->\t" << dist << std::endl;
    //std::cout << "\tIntensidade\t\t->\t" << intensidade << std::endl;
    mp.setIntensity(intensidade);

/*    if(dist < DIST_MIN_LL || dist > DIST_MAX_LL){
        std::cout << "\tintensidade\t->\t0" << endl;
        mp.setIntensity(0);
        std::cout
    }
    else{*/
//    }
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
           // if ((abs(zi - alturaRealsense) > INTERV_CHAO) && (distanciaAtual > DIST_MIN_RS) && (distanciaAtual < DIST_MAX_RS))
//           if (abs(xi*(-1) - config.getAlturaRealsense()/100) > INTERV_CHAO) {

//           cout << "ponto -> " << xi << endl;
           if (xi>0 || abs(xi*(-1) - config.getAlturaRealsense()/100) > INTERV_CHAO) {
               if ((distanciaAtual > config.getLarguraBraco()/100) && (distanciaAtual < config.getProfundidadeMaxima())){
//                    cout << "ponto -> " << xi << "vll -> " << abs(xi*(-1) - config.getAlturaRealsense()/100) << endl;
                    indiceMenorPonto = i;
                    distanciaMinima = distanciaAtual;
                }
           }
           else{
//               cout << "ponto -> " << xi << endl;
               
           }
        }
    }

    float n_pontos_obtaculo_quadrante_1 = 0;
    float n_pontos_obtaculo_quadrante_2 = 0;
    float n_pontos_obtaculo_quadrante_3 = 0;
    float n_pontos_obtaculo_quadrante_4 = 0;

    //cout << "ponto -> " << vertices[indiceMenorPonto].x << endl;

    /*Segunda varredura na nuvem de pontos*/
    for (int i = 0; i < pontos->size(); i++)
    {
        float xi = vertices[i].x;
        float yi = vertices[i].y;
        float zi = vertices[i].z;
        float distanciaAtual = calculaDistancia(xi, yi, zi);

        if ((xi<0) && (abs(xi*(-1) - config.getAlturaRealsense()/100) < INTERV_CHAO)) {
            continue;
        }

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

    float point[3] = {vertices[indiceMenorPonto].x, vertices[indiceMenorPonto].y, vertices[indiceMenorPonto].z};

    int n_pontos_total = n_pontos_obtaculo_quadrante_1+n_pontos_obtaculo_quadrante_2+n_pontos_obtaculo_quadrante_3+n_pontos_obtaculo_quadrante_4;
/*    if(n_pontos_total > 4*MIN_PONTOS_QUADRANTE){
        rs_sensor.point2pixel(pixelProx, point);
        std::cout << "x " << point[0] << " y: " << point[1] << " z: " << point[2] << std::endl;
        std::cout << "h " << (float)pixelProx[1] << " w: " << (float)pixelProx[0] << std::endl;
    }
    else{
         pixelProx[0] = 0;
         pixelProx[1] = 0;
    }*/

    pixelProx[0] = 0;
    pixelProx[1] = 0;
    int intensidade = converteDistanciaIntensidade_rs(distanciaMinima);
    if(n_pontos_obtaculo_quadrante_1 > MIN_PONTOS_QUADRANTE){
	pixelProx[0] += 1;
        m1.setIntensity(intensidade);
    }
    else{
        m1.setIntensity(0);
    }

    if(n_pontos_obtaculo_quadrante_2 > MIN_PONTOS_QUADRANTE){
	pixelProx[0] += 20;
        m2.setIntensity(intensidade);
    }
    else{
        m2.setIntensity(0);
    }

    if(n_pontos_obtaculo_quadrante_3 > MIN_PONTOS_QUADRANTE){
	pixelProx[0] += 300;
        m3.setIntensity(intensidade);
    }
    else{
        m3.setIntensity(0);
    }

    if(n_pontos_obtaculo_quadrante_4 > MIN_PONTOS_QUADRANTE){
	pixelProx[0] += 4000;
        m4.setIntensity(intensidade);
    }
    else{
        m4.setIntensity(0);
    }

    std::cout << "x " << point[0] << " y: " << point[1] << " z: " << point[2] << std::endl;
    std::cout << "h " << (float)pixelProx[1] << " w: " << (float)pixelProx[0] << std::endl;
    std::cout << "\tdist - " << distanciaMinima << std::endl;
    std::cout << "\tQ1 - " << n_pontos_obtaculo_quadrante_1 << "\t int - " << m1.getIntensity() << std::endl;
    std::cout << "\tQ2 - " << n_pontos_obtaculo_quadrante_2 << "\t int - " << m2.getIntensity() << std::endl;
    std::cout << "\tQ3 - " << n_pontos_obtaculo_quadrante_3 << "\t int - " << m3.getIntensity() << std::endl;
    std::cout << "\tQ4 - " << n_pontos_obtaculo_quadrante_4 << "\t int - " << m4.getIntensity() << std::endl;
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
    if(x > 0 && y < 0){
        return 1;
    }
    else if(x > 0 && y > 0){
        return 2;
    }
    else if(x < 0 && y > 0){
        return 3;
    }
    else if(x < 0 && y < 0){
        return 4;
    }
    return -1;
}

int Processadora::converteDistanciaIntensidade_rs(float distancia){
    /*Mapeia os valores de distância no invervalo 0-255 (PWM)*/
    float coef_ang = -255/(config.getProfundidadeMaxima() - config.getLarguraBraco()/100);
    int intensidade = coef_ang*(distancia - config.getLarguraBraco()/100) + 255;  //Equacao fundamental da reta.
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
