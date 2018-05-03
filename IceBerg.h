//
// Created by notyours on 17/03/18.
//

#ifndef IGRCA_ICEBERG_H
#define IGRCA_ICEBERG_H


#include "P5c.h"

class IceBerg {
    PVector pos;
    PVector dir;
    PImage img;
    bool shown = false;
public:
    IceBerg(PImage img) {
        pos.x = random(0, width);
        pos.y = random(0, height);
        pos.z = 0;
        dir.random2D();
        dir.normalize();
        dir.mult(2);
        this->img = img;
    }

    void show() {
        image(img, pos.x - 16, pos.y - 16, 32, 32);
    }

    PVector getLocation() {
        return pos;
    }

    void move(){
        PVector tmp = pos.copy();
        if(tmp.x > width || tmp.x < 0){
            dir.x *= -1;
        }
        if(tmp.y > height || tmp.y < 0){
            dir.y *= -1;
        }
        tmp.add(dir);
        pos = tmp.copy();
    }

    void setLocation(PVector vector) {
        pos.x = vector.x;
        pos.y = vector.y;
        pos.z = vector.z;
    }
};


#endif //IGRCA_ICEBERG_H
