/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Api;

import Model.ApiImage;
import com.google.cloud.vision.v1.AnnotateImageRequest;
import com.google.cloud.vision.v1.AnnotateImageResponse;
import com.google.cloud.vision.v1.BatchAnnotateImagesResponse;
import com.google.cloud.vision.v1.Feature;
import com.google.cloud.vision.v1.Image;
import com.google.cloud.vision.v1.ImageAnnotatorClient;
import com.google.cloud.vision.v1.LocalizedObjectAnnotation;
import com.google.protobuf.ByteString;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

/**
 * @author kamir
 */
public class ServiceVisionApi {

    private List<AnnotateImageRequest> requests = new ArrayList<>();
    private List<ApiImage> imagesList = new ArrayList<>();

    public ServiceVisionApi() throws IOException {
        initDetectionLocalizedObjects();
    }

    public List<ApiImage> detectionLocalizedObjects() {
        try (ImageAnnotatorClient vision = ImageAnnotatorClient.create()) {

            // Performs label detection on the image file
            BatchAnnotateImagesResponse response = vision.batchAnnotateImages(this.requests);
            List<AnnotateImageResponse> responses = response.getResponsesList();

            // Display the results
            for (AnnotateImageResponse res : responses) {
                for (LocalizedObjectAnnotation entity : res.getLocalizedObjectAnnotationsList()) {
                    ApiImage image = new ApiImage();
                    image.setObjectName(entity.getName());
                    image.setObjectConfidence(entity.getScore());
                    image.setVertexList(entity.getBoundingPoly().getNormalizedVerticesList());
                    imagesList.add(image);
                    //for debug
                    System.out.format("Object name: %s%n", entity.getName());
                    System.out.format("Confidence: %s%n", entity.getScore());
                    System.out.format("Normalized Vertices:%n");
                    entity
                            .getBoundingPoly()
                            .getNormalizedVerticesList()
                            .forEach(vertex -> System.out.format("- (%s, %s)%n", vertex.getX(), vertex.getY()));
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return imagesList;
    }

    private void initDetectionLocalizedObjects() throws IOException {
        // Initialize client that will be used to send requests. This client only needs to be created
        // once, and can be reused for multiple requests. After completing all of your requests, call
        // the "close" method on the client to safely clean up any remaining background resources.

        // The path to the image file to annotate
        //String fileName = "./resources/wakeupcat.jpg";
        //String fileName = "C:\\Users\\kamir\\Documents\\NetBeansProjects\\VisionApiTest\\app\\src\\main\\resources\\wakeupcat.jpg";
        String fileName = "/home/lukn23/TALKER-V-EYE/VisionApiTest/app/src/main/resources/teste.jpg";

        // Reads the image file into memory
        Path path = Paths.get(fileName);
        byte[] data = Files.readAllBytes(path);
        ByteString imgBytes = ByteString.copyFrom(data);

        // Builds the image annotation request
        Image img = Image.newBuilder().setContent(imgBytes).build();
        Feature feat = Feature.newBuilder().setType(Feature.Type.OBJECT_LOCALIZATION).build();
        AnnotateImageRequest request
                = AnnotateImageRequest.newBuilder().addFeatures(feat).setImage(img).build();
        requests.add(request);
    }

    public List<ApiImage> detectionUniqueObject(String[] detectedPixelArray) {
        int heightPixel, widthPixel, heightImage, widthImage;
        heightPixel = Integer.parseInt(detectedPixelArray[1]);
        widthPixel = Integer.parseInt(detectedPixelArray[2]);
        heightImage = Integer.parseInt(detectedPixelArray[3]);
        widthImage = Integer.parseInt(detectedPixelArray[4]);

        float normalizedHeight = (float) heightPixel / heightImage;
        float normalizedWidth = (float) widthPixel / widthImage;

        try (ImageAnnotatorClient vision = ImageAnnotatorClient.create()) {
            // Performs label detection on the image file
            BatchAnnotateImagesResponse response = vision.batchAnnotateImages(this.requests);
            List<AnnotateImageResponse> responses = response.getResponsesList();

            // Display the results
            for (AnnotateImageResponse res : responses) {
                for (LocalizedObjectAnnotation entity : res.getLocalizedObjectAnnotationsList()) {
                    boolean matchObject = true;
                    ApiImage image = new ApiImage();
                    image.setObjectName(entity.getName());
                    image.setObjectConfidence(entity.getScore());
                    image.setVertexList(entity.getBoundingPoly().getNormalizedVerticesList());
                    //For the case of identify the detected object, is added to the list only if the pixel detected is inside boudingbox
                    /* A ordem dos pontos tomando o id da lista est� ilustrada a baixo
                    0  -----  1
                    |         |
                    |         |
                    3 ------- 2
                    */
                    if(normalizedHeight < image.getVertexList().get(0).getY()
                            || normalizedHeight < image.getVertexList().get(1).getY()
                            || normalizedHeight > image.getVertexList().get(2).getY()
                            || normalizedHeight > image.getVertexList().get(3).getY()) {
                        matchObject = false;
                    }
                    if (normalizedWidth < image.getVertexList().get(0).getX()
                            || normalizedWidth < image.getVertexList().get(3).getX()
                            || normalizedWidth > image.getVertexList().get(1).getX()
                            || normalizedWidth > image.getVertexList().get(2).getX()) {
                        matchObject = false;
                    }
                    if (matchObject) {
                        imagesList.add(image);
                    }

                    //For debug
                    System.out.format("Object name: %s%n", entity.getName());
                    System.out.format("Confidence: %s%n", entity.getScore());
                    System.out.format("Normalized Vertices:%n");
                    entity
                            .getBoundingPoly()
                            .getNormalizedVerticesList()
                            .forEach(vertex -> System.out.format("- (%s, %s)%n", vertex.getX(), vertex.getY()));
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return imagesList;
    }
}
