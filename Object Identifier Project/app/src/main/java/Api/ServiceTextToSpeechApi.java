/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Api;
// Imports the Google Cloud client library

import Model.ApiImage;
import com.google.cloud.texttospeech.v1.AudioConfig;
import com.google.cloud.texttospeech.v1.AudioEncoding;
import com.google.cloud.texttospeech.v1.SsmlVoiceGender;
import com.google.cloud.texttospeech.v1.SynthesisInput;
import com.google.cloud.texttospeech.v1.SynthesizeSpeechResponse;
import com.google.cloud.texttospeech.v1.TextToSpeechClient;
import com.google.cloud.texttospeech.v1.VoiceSelectionParams;
import com.google.protobuf.ByteString;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author kamir
 */
public class ServiceTextToSpeechApi {

    /*PENSAR POSTERIORMENTE NO TRATAMENTO DE ERROS*/
    private SynthesisInput input;
    private VoiceSelectionParams voice;
    private AudioConfig audioConfig;
    private List<ApiImage> imagesList = new ArrayList<>();
    private StringBuilder stringBuilder = new StringBuilder();

    public ServiceTextToSpeechApi() throws IOException {
        initGenerateAudioFromText();
    }

    public ServiceTextToSpeechApi(List<ApiImage> imagesList) throws IOException {
        this.imagesList = imagesList;
        initGenerateAudioFromText();
    }

    public String generateAudioFromText() {
        String pathFile = "";
        try (TextToSpeechClient textToSpeechClient = TextToSpeechClient.create()) {
            // Perform the text-to-speech request on the text input with the selected voice parameters and
            // audio file type
            SynthesizeSpeechResponse response
                    = textToSpeechClient.synthesizeSpeech(input, voice, audioConfig);

            // Get the audio contents from the response
            ByteString audioContents = response.getAudioContent();

            // Write the response to the output file.
            try (OutputStream out = new FileOutputStream("new_output.mp3")) {
                out.write(audioContents.toByteArray());
                System.out.println("Audio content written to file \"new_output.mp3\"");
                pathFile = "new_output.mp3";
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

        return pathFile;
    }

    private void initGenerateAudioFromText() throws IOException {
        for (ApiImage image : imagesList) {
            stringBuilder.append(image.getObjectName()).append(",");
        }
        stringBuilder = stringBuilder.deleteCharAt(stringBuilder.length() - 1); //delete the last comma

        // Set the text input to be synthesized
        //this.input = SynthesisInput.newBuilder().setText("Hello, Camilo!").build(); //Ao invés de ser um array de strings, tem que ser uma string grande separada por virgula
        this.input = SynthesisInput.newBuilder().setText(stringBuilder.toString()).build();

        // Build the voice request, select the language code ("en-US") and the ssml voice gender
        // ("neutral")
        this.voice
                = VoiceSelectionParams.newBuilder()
                        .setLanguageCode("en-US")
                        .setSsmlGender(SsmlVoiceGender.NEUTRAL)
                        .build();

        // Select the type of audio file you want returned
        this.audioConfig
                = AudioConfig.newBuilder().setAudioEncoding(AudioEncoding.MP3).build();

    }
}
