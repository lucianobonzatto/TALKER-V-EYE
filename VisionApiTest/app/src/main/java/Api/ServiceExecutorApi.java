/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Api;

import Model.ApiImage;
import Service.AudioPlayer;

import java.awt.image.BufferedImage;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.ObjectOutputStream;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;
import javax.imageio.ImageIO;

/**
 * @author kamir
 */
public class ServiceExecutorApi implements Runnable {

    private OutputStreamWriter writer = null;
    private InputStreamReader reader = null;
    private Socket socket;
    private int idType, heightPixel, widthPixel, heightImage, widthImage;

    public ServiceExecutorApi() {
    }

    public ServiceExecutorApi(Socket socket) throws IOException {
        this.socket = socket;
    }

    @Override
    public void run() {
        try {
            this.writer = new OutputStreamWriter(socket.getOutputStream(), StandardCharsets.UTF_8);
            this.reader = new InputStreamReader(socket.getInputStream(), StandardCharsets.UTF_8);

            StringBuilder sb = new StringBuilder();
            int temp;

            while ((temp = reader.read()) != -1) {
                sb.append((char)temp);
            }
            sb.deleteCharAt(sb.length() -1); //removendo o 0 que é enviado pelo socket como termino do envio
            System.out.println("data from socket: " + sb.toString());
            String dataStr = sb.toString();
            String[] dataArray = dataStr.split(",");

            idType = Integer.parseInt(dataArray[0]);

            List<ApiImage> imagesList;
            if(idType == 0){
                imagesList = new ServiceVisionApi().detectionLocalizedObjects();
            } else {
                imagesList = new ServiceVisionApi().detectionUniqueObject(dataArray);
            }
            System.out.println("BETWEEN API \n\n\n ");

            if (!imagesList.isEmpty()) {
                String pathMp3File = new ServiceTextToSpeechApi(imagesList).generateAudioFromText();
                //new AudioPlayer().play(pathMp3File);
                AudioPlayer.playAudioWithBash("play /home/lukn23/TALKER-V-EYE/VisionApiTest/app/new_output.mp3");
                System.out.println(pathMp3File);
            } else {
                AudioPlayer.playAudioWithBash("play /home/lukn23/TALKER-V-EYE/VisionApiTest/app/audio_nenhum_identificado.mp3");
                System.out.println("Não foi identificado um objeto");
            }
            socket.close();
            writer.close();
            reader.close();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }

}
