//
// Created by notyours on 17/03/18.
//

#ifndef IGRCA_ATOL_H
#define IGRCA_ATOL_H


class Atol {
    PVector pos;
    PVector dir;
    PImage img;
    float rotation = 0;
    bool shown = false;
    long timeLived = 0;
public:
    Atol(PImage img) {
        pos.x = random(0, width);
        pos.y = random(0, height);
        pos.z = 0;
        rotation = random(0, 360);
        dir.random2D();
        dir.normalize();
        dir.mult(2);
        this->img = img;
    }

    void show() {
        image(img, pos.x-16, pos.y-16, 32+timeLived/30, 32+timeLived/30);
        timeLived++;
    }

    PVector getLocation() {
        return pos;
    }

    void setLocation(PVector pos1){
        pos.x = pos1.x;
        pos.y = pos1.y;
        pos.z = pos1.z;
    }
};

#endif //IGRCA_ATOL_H
