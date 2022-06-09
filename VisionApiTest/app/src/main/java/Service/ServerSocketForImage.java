/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Service;

import Api.ServiceExecutorApi;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
/**
 * @author kamir
 */
public class ServerSocketForImage extends Thread { //Server Socket 

    private String ip;
    private int port = 9090;

    public ServerSocketForImage() {
    }

    public void run() {
        System.out.println("Initializing Server on port " + port);
        try (ServerSocket server = new ServerSocket(port)) {
            while (!Thread.currentThread().isInterrupted()) {
                System.out.println("waiting a connection");
                Socket socket = server.accept();
                System.out.println("Message received on port " + port);

                ExecutorService singleExecutor = Executors.newSingleThreadExecutor();
                singleExecutor.execute(new ServiceExecutorApi(socket));
//                socket.close();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        System.out.println("saiu da thread");
    }
}
