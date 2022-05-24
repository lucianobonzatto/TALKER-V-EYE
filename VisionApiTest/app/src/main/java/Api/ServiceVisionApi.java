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
 *
 * @author kamir
 */
public class ServiceVisionApi {

    private List<AnnotateImageRequest> requests = new ArrayList<>();
    private List<ApiImage> imagesList = new ArrayList<>();

    public ServiceVisionApi() throws IOException {
        initDetectionLocalizedObjects();
    }

    public ServiceVisionApi(byte[] imageData) throws IOException {
        initDetectionLocalizedObjects(imageData);
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
                    //for debbug
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

    private void initDetectionLocalizedObjects(byte[] imageData) throws IOException {
        // Initialize client that will be used to send requests. This client only needs to be created
        // once, and can be reused for multiple requests. After completing all of your requests, call
        // the "close" method on the client to safely clean up any remaining background resources.

        // The path to the image file to annotate
        byte[] data = imageData;
        ByteString imgBytes = ByteString.copyFrom(data);

        // Builds the image annotation request
        Image img = Image.newBuilder().setContent(imgBytes).build();
        Feature feat = Feature.newBuilder().setType(Feature.Type.OBJECT_LOCALIZATION).build();
        AnnotateImageRequest request
                = AnnotateImageRequest.newBuilder().addFeatures(feat).setImage(img).build();
        requests.add(request);

    }
}
