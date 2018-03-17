//
// Created by notyours on 17/03/18.
//

#ifndef IGRCA_PIRATE_H
#define IGRCA_PIRATE_H


class Pirate {
    PVector pos;
    PVector dir;
    PImage img;
    bool shown = false;
public:
    Pirate(PImage img) {
        pos.x = random(0, width);
        pos.y = random(0, height);
        pos.z = 0;
        this->img = img;
    }

    void show() {
        if(shown) {
            image(img, int(pos.x - 16), int(pos.y - 16), 32, 32);
        }else{
            if(random(0, 1000) < 3){
                image(img, int(pos.x - 16), int(pos.y - 16), 32, 32);
                fill(0, 255, 0, 50);
                stroke(0);
                ellipse(pos.x, pos.y, 100, 100);
                ellipse(pos.x, pos.y, 75, 75);
                ellipse(pos.x, pos.y, 50, 50);
                ellipse(pos.x, pos.y, 25, 25);
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
        dir = vb;
        dir.sub(pos);
        dir.normalize();
        //300 pixlov stran = stop
        dir.mult(2*25/dist(pos, vb));
        if(pos.x > width-16 || pos.x < 16){
            dir.x = 0;
        }
        if(pos.y < 16 || pos.y > height-16){
            dir.y = 0;
        }
        pos.add(dir);
    }
};


#endif //IGRCA_PIRATE_H
