//
// Created by notyours on 17/03/18.
//

#ifndef IGRCA_CHINASEABOAT_H
#define IGRCA_CHINASEABOAT_H

#define frames 60

class ChinaSeaBoat {
    PVector pos;
    PVector dir;
    PImage img;
    bool shown = false;
    int framecount = frames+5;
public:
    ChinaSeaBoat(PImage img) {
        pos.x = random(0, width);
        pos.y = random(0, height);
        pos.z = 0;
        this->img = img;
    }

    void show() {
        if(shown) {
            image(img, int(pos.x - 16), int(pos.y - 16), 32, 32);
        }else{
            if(framecount < frames){
                framecount = 0;
                image(img, int(pos.x - 16), int(pos.y - 16), 32, 32);
                fill(0, 255, 0, 50);
                stroke(0);
                ellipse(pos.x, pos.y, 100, 100);
                ellipse(pos.x, pos.y, 75, 75);
                ellipse(pos.x, pos.y, 50, 50);
                ellipse(pos.x, pos.y, 25, 25);
            }else {
                if (random(0, 1000) < 3) {
                    framecount = 0;
                }
            }
        }
    }

    PVector getLocation() {
        return pos;
    }

    void update(PVector loc) {
        PVector tmp = getLocation();
        double distance = dist(loc, tmp);
        shown = distance < 300;
    }

    void move(PVector vb){
        dir = pos;
        dir.sub(vb);
        dir.normalize();
        dir.mult(2*25/dist(pos, vb));
        if(pos.x > width-16 || pos.x < 16){
            dir.x = 0;
        }
        if(pos.y < 16 || pos.y > height-16){
            dir.y = 0;
        }
        pos.add(dir);
    }

    void setLocation(PVector pos1){
        pos.x = pos1.x;
        pos.y = pos1.y;
        pos.z = pos1.z;
    }
};


#endif //IGRCA_CHINASEABOAT_H
