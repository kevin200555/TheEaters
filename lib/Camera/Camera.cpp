#include "Camera.h"
#include <Arduino.h>


void CameraSetup(){
    pixy.init();
}

void CameraLoop(){
    pixy.ccc.getBlocks();
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;

    if(pixy.ccc.numBlocks){
        Serial.print("Object detected: ");
        Serial.println(pixy.ccc.numBlocks);
        for(int i = 0; i < pixy.ccc.numBlocks; i++){
            // signiture 1: blue box thing
            if(pixy.ccc.blocks[i].m_signature == 1){
                x = pixy.ccc.blocks[i].m_x;
                y = pixy.ccc.blocks[i].m_y;
                width = pixy.ccc.blocks[i].m_width;
                height = pixy.ccc.blocks[i].m_height;
                Serial.print("Blue box thing");
                Serial.print("X: "); Serial.println(x);
                Serial.print("Y: "); Serial.println(y);
                Serial.print("Width: "); Serial.println(width);
                Serial.print("Height: "); Serial.println(height);
            }
        }
    }
}