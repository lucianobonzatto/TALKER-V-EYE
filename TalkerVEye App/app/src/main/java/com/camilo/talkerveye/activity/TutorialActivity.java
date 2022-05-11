package com.camilo.talkerveye.activity;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.Toast;

import com.camilo.talkerveye.R;

public class TutorialActivity extends AppCompatActivity {
    private ImageView volButtonFirstComm;
    private ImageView volButtonSecondComm;
    private ImageView volButtonThirdComm;

    private ImageView volButtonFirstUse;
    private ImageView volButtonSecondUse;
    private ImageView volButtonThirdUse;
    private ImageView volButtonForthUse;
    private ConstraintLayout mainTutorialLayout;

    private int countAudioPlayer = 1;

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

        mainTutorialLayout = findViewById(R.id.mainTutorialLayout);

        //This part is for run the audio when click in any part of screen
        mainTutorialLayout.setOnClickListener(view -> {
            switch (countAudioPlayer) {
                case 1:
                    executeFirstComm(volButtonFirstComm.getRootView());
                    break;
                case 2:
                    executeSecondComm(volButtonSecondComm.getRootView());
                    break;
                case 3:
                    executeThirdComm(volButtonThirdComm.getRootView());
                    break;
                case 4:
                    executeFirstUse(volButtonFirstUse.getRootView());
                    break;
                case 5:
                    executeSecondUse(volButtonSecondUse.getRootView());
                    break;
                case 6:
                    executeThirdUse(volButtonThirdUse.getRootView());
                    break;
                case 7:
                    executeForthUse(volButtonForthUse.getRootView());
                    countAudioPlayer = 0; //Ao sair do switch/case, o countAudioPlayer++ irá volta-lo para 1
                    break;
            }
            countAudioPlayer++;
        });

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