package com.camilo.talkerveye.activity;

import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.camilo.talkerveye.ClientSocket;
import com.camilo.talkerveye.R;

public class MainActivity extends AppCompatActivity {
    private EditText ipEditText;
    private EditText portEditText;
    private EditText heightEditText;
    private EditText armLengthEditText;
    private Button sendButton;
    private TextView tutorialTextView;

    private SharedPreferences sharedPreferences;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ipEditText = findViewById(R.id.ipEditText);
        portEditText = findViewById(R.id.portEditText);
        heightEditText = findViewById(R.id.heightEditText);
        armLengthEditText = findViewById(R.id.armLengthEditText);
        sendButton = findViewById(R.id.sendButton);
        tutorialTextView = findViewById(R.id.tutorialTextView);

        sharedPreferences = getSharedPreferences(String.valueOf(R.string.preference_configuration), Activity.MODE_PRIVATE);

        sendButton.setOnClickListener(view -> {
            String ip = ipEditText.getText().toString();
            String port = portEditText.getText().toString();
            String height = heightEditText.getText().toString();
            String armLength = armLengthEditText.getText().toString();
            if(!ip.isEmpty() &&
                    !port.isEmpty() &&
                    !height.isEmpty() &&
                    !armLength.isEmpty()) {

                    if(sharedPreferences != null){
                        SharedPreferences.Editor editor = sharedPreferences.edit();
                        editor.putString(String.valueOf(R.string.preference_configuration_ip), ip);
                        editor.putString(String.valueOf(R.string.preference_configuration_port), port);
                        editor.putString(String.valueOf(R.string.preference_configuration_height), height);
                        editor.putString(String.valueOf(R.string.preference_configuration_arm_length), armLength);
                        editor.apply();
                    }
                    Toast.makeText(this, "teste: " + ip + port, Toast.LENGTH_SHORT).show();
                    ClientSocket clientSocket = new ClientSocket(ip,
                            port,
                            height,
                            armLength);
                    clientSocket.start();
            } else {
                Toast.makeText(this, "É necessário preencher todos os campos", Toast.LENGTH_SHORT).show();
            }
        });

    }

    @Override
    protected void onResume() {
        super.onResume();

        if (sharedPreferences != null) {
            String ip = sharedPreferences.getString(String.valueOf(R.string.preference_configuration_ip), "");
            String port = sharedPreferences.getString(String.valueOf(R.string.preference_configuration_port), "");
            String height = sharedPreferences.getString(String.valueOf(R.string.preference_configuration_height), "");
            String armLength = sharedPreferences.getString(String.valueOf(R.string.preference_configuration_arm_length), "");

            ipEditText.setText(ip);
            portEditText.setText(port);
            heightEditText.setText(height);
            armLengthEditText.setText(armLength);
        }

    }
}