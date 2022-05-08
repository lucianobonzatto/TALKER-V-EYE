package com.camilo.talkerveye.activity;

import androidx.appcompat.app.AppCompatActivity;

import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;

import com.camilo.talkerveye.R;

public class TutorialActivity extends AppCompatActivity {
    private ImageView volButtonFirstComm;
    private ImageView volButtonSecondComm;
    private ImageView volButtonThirdComm;

    private ImageView volButtonFirstUse;
    private ImageView volButtonSecondUse;
    private ImageView volButtonThirdUse;
    private ImageView volButtonForthUse;

    private MediaPlayer mediaPlayer;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_tutorial);

        volButtonFirstComm = findViewById(R.id.volButtonFirstComm);
        volButtonSecondComm = findViewById(R.id.volButtonSecondComm);
        volButtonThirdComm = findViewById(R.id.volButtonThirdComm);

        volButtonFirstUse = findViewById(R.id.volButtonFirstUse);
        volButtonSecondUse = findViewById(R.id.volButtonSecondUse);
        volButtonThirdUse = findViewById(R.id.volButtonThirdUse);
        volButtonForthUse = findViewById(R.id.volButtonForthUse);


    }

    public void executeFirstComm(View view) {
        finishSound();
        mediaPlayer = MediaPlayer.create(getApplicationContext(), R.raw.first_comm_message);
        playSound();
    }

    public void executeSecondComm(View view) {
        finishSound();
        mediaPlayer = MediaPlayer.create(getApplicationContext(), R.raw.second_comm_message);
        playSound();
    }

    public void executeThirdComm(View view) {
        finishSound();
        mediaPlayer = MediaPlayer.create(getApplicationContext(), R.raw.third_comm_message);
        playSound();
    }


    public void executeFirstUse(View view) {
        finishSound();
        mediaPlayer = MediaPlayer.create(getApplicationContext(), R.raw.first_use_message);
        playSound();
    }

    public void executeSecondUse(View view) {
        finishSound();
        mediaPlayer = MediaPlayer.create(getApplicationContext(), R.raw.second_use_message);
        playSound();
    }

    public void executeThirdUse(View view) {
        finishSound();
        mediaPlayer = MediaPlayer.create(getApplicationContext(), R.raw.third_use_message);
        playSound();
    }

    public void executeForthUse(View view) {
        finishSound();
        mediaPlayer = MediaPlayer.create(getApplicationContext(), R.raw.forth_use_message);
        playSound();
    }

    private void finishSound(){
        if(mediaPlayer != null){
            mediaPlayer.release();
        }
    }
    private void playSound(){
        if(mediaPlayer != null){
            mediaPlayer.start();

            mediaPlayer.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                @Override
                public void onCompletion(MediaPlayer mp) {
                    mediaPlayer.release();
                }
            });
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        finishSound();
    }
}