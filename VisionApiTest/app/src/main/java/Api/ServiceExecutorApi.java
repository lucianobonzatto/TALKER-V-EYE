/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Api;

import Model.ApiImage;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.ObjectOutputStream;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;


import java.awt.image.BufferedImage;
import java.io.File;
import javax.imageio.ImageIO;
/**
 *
 * @author kamir
 */
public class ServiceExecutorApi implements Runnable {

    private OutputStreamWriter writer = null;
    private InputStreamReader reader = null;
    private Socket socket;
    private byte[] imageData;

    public ServiceExecutorApi() {
    }

    public ServiceExecutorApi(Socket socket) throws IOException {
        this.writer = new OutputStreamWriter(socket.getOutputStream(), StandardCharsets.UTF_8);
        this.reader = new InputStreamReader(socket.getInputStream(), StandardCharsets.UTF_8);
	this.socket = socket;
    }

    @Override
    public void run() {
        try {

	   
            ArrayList<Integer> imgTempData = new ArrayList<>();
            int temp;
            while ((temp = reader.read()) != -1) {
                 imgTempData.add(temp);
            }
            
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            ObjectOutputStream oos;
            try {
		oos = new ObjectOutputStream(baos);
		oos.writeObject(imgTempData);
            } catch (IOException e) {
		e.printStackTrace();
            }
            imageData = baos.toByteArray();
	    
//            ByteArrayInputStream bis = new ByteArrayInputStream(imageData);
//            BufferedImage bImage2 = ImageIO.read(bis);
//            ImageIO.write(bImage2, "jpg", new File("output.jpg") );
//            System.out.println("image created");
                        
            socket.close();

            List<ApiImage> imagesList = new ServiceVisionApi().detectionLocalizedObjects();
            System.out.println("BETWEEN API \n\n\n ");
            if(!imagesList.isEmpty() ){
                String pathMp3File = new ServiceTextToSpeechApi(imagesList).generateAudioFromText();
                System.out.println(pathMp3File);
            } else {
                System.out.println("Não foi identificado um objeto");
            } 
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}
