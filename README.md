# TALKER-V-EYE

## Files
 
 ### Engenharia de software
 diagramas
 
 ### cTeste
 testes da parte em c
 
 ### cProject
 projeto final da parte em c

## conecções

### motores
m1 -> gpio 15

m2 -> gpio 24

m3 -> gpio 23

m4 -> gpio 14

mp -> gpio 17

### Botões
sb1 -> gpio 10

sb2 -> gpio 22

sb3 -> gpio 27

### lidar
conectado pr i2c

SDA(blue) -> gpio 2

SCL(green) -> gpio 3

### Realsense
conectada por usb C

### Celular
conectado por wifi

## Running

### c++ project
```
clean all compilation files
$ make clean
recompile the project
$ make all
run the project
$ ./TALKER-V-EYE
```

###Java Project
$ ./gradlew run

## References

 ### Realsense
 
 https://dev.intelrealsense.com/docs/code-samples
 
 ### Lidar Lite V3
 
 https://github.com/garmin/LIDARLite_RaspberryPi_Library
