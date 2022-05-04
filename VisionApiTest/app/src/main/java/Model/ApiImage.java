/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Model;

import com.google.cloud.vision.v1.NormalizedVertex;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author kamir
 */
public class ApiImage {

    private String objectName;
    private float objectConfidence;
    private List<NormalizedVertex> vertexList = new ArrayList<>();

    /* verify the order of vertex of objectBoundingBoxArray in the api resposne  */

    public ApiImage() {
    }

    public ApiImage(String objectName, float objectConfidence, List<NormalizedVertex> vertexList) {
        this.objectName = objectName;
        this.objectConfidence = objectConfidence;
        this.vertexList = vertexList;

    }

    public String getObjectName() {
        return objectName;
    }

    public void setObjectName(String objectName) {
        this.objectName = objectName;
    }

    public float getObjectConfidence() {
        return objectConfidence;
    }

    public void setObjectConfidence(float objectConfidence) {
        this.objectConfidence = objectConfidence;
    }

    public List<NormalizedVertex> getVertexList() {
        return vertexList;
    }

    public void setVertexList(List<NormalizedVertex> vertexList) {
        this.vertexList = vertexList;
    }



}
