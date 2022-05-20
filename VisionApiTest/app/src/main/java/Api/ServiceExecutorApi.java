/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Api;

import Model.ApiImage;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.util.List;

/**
 *
 * @author kamir
 */
public class ServiceExecutorApi implements Runnable {

    private OutputStreamWriter writer = null;
    private InputStreamReader reader = null;

    public ServiceExecutorApi() {
    }

    public ServiceExecutorApi(Socket socket) throws IOException {
        this.writer = new OutputStreamWriter(socket.getOutputStream(), StandardCharsets.UTF_8);
        this.reader = new InputStreamReader(socket.getInputStream(), StandardCharsets.UTF_8);
    }

    @Override
    public void run() {
        try {
            List<ApiImage> imagesList = new ServiceVisionApi().detectionLocalizedObjects();
            String pathMp3File = new ServiceTextToSpeechApi(imagesList).generateAudioFromText();
            System.out.println(pathMp3File);
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}
