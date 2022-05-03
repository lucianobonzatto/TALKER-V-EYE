/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Service;

import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

/**
 *
 * @author kamir
 */
public class ServerSocketForImage extends Thread { //Server Socket 

    private String ip;
    private int port = 9090;

    private OutputStreamWriter writer = null;
    private InputStreamReader reader = null;

    public ServerSocketForImage() {
       
    }

    public void run() {
        System.out.println("Initializing Server on port " + port);
        try (ServerSocket server = new ServerSocket(port)) {
            while (!Thread.currentThread().isInterrupted()) {
                Socket socket = server.accept();
                System.out.println("Message received on port " + port);

                this.writer = new OutputStreamWriter(socket.getOutputStream(), StandardCharsets.UTF_8);
                this.reader = new InputStreamReader(socket.getInputStream(), StandardCharsets.UTF_8);

                StringBuffer segment = new StringBuffer();
                int temp;
                while ((temp = reader.read()) != -1) {
                    segment.append(temp);
                    segment.append(",");
                }
                segment.deleteCharAt(segment.length() - 1);
                System.out.println(segment.toString());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
