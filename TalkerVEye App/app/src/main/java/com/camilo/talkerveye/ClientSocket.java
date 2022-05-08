package com.camilo.talkerveye;

import android.app.Activity;
import android.widget.Toast;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.nio.charset.StandardCharsets;

public class ClientSocket extends Thread{
    private int outPort;
    private String ip;
    private String heightPerson;
    private String armLengthPerson;
    private String maxDepth;
    private Activity activity;

    public ClientSocket(String ip, String outPort, String heightPerson, String armLengthPerson, String maxDepth, Activity activity) {
        this.ip = ip;
        this.outPort = Integer.parseInt(outPort);
        this.heightPerson= heightPerson;
        this.armLengthPerson = armLengthPerson;
        this.maxDepth = maxDepth;
        this.activity = activity;
    }

    @Override
    public void run() {
        super.run();
        initClientSocket();
    }


    private void initClientSocket() {
        try (java.net.Socket socket = new java.net.Socket(this.ip, this.outPort)) {

            InputStream input = socket.getInputStream();
            OutputStream output = socket.getOutputStream();

            OutputStreamWriter writer = new OutputStreamWriter(output, StandardCharsets.UTF_8);
            InputStreamReader reader = new InputStreamReader(input, StandardCharsets.UTF_8);

            //Envio no formato dado1,dado2
            String dataToSend = heightPerson +
                    "," +
                    armLengthPerson +
                    maxDepth;
            writer.write(dataToSend);
            writer.flush();

        } catch(IOException e) {
            e.printStackTrace();
            activity.runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    Toast.makeText(activity, "Erro no socket: " + e.getMessage(), Toast.LENGTH_SHORT).show();
                }
            });
        }
    }

    //Socket já é fechado ao final da execução, esse try esconde um finally que encerra o socket
}
