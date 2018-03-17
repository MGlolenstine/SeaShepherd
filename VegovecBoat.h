//
// Created by notyours on 17/03/18.
//

#ifndef IGRCA_VEGOVECBOAT_H
#define IGRCA_VEGOVECBOAT_H

#include "IceBerg.h"
#include "AntarcticBoat.h"
#include "Atol.h"
#include "SouthSeaBoat.h"
#include "Pirate.h"
#include "ChinaSeaBoat.h"

class VegovecBoat {
    float x;
    float y;
    float z;
    float mult;
    int score = 0;
    PImage img;
public:
    VegovecBoat(PImage img) {
        x = width / 2;
        y = height / 2;
        z = 0;
        mult = 1;
        this->img = img;
    }

    void show() {
        image(img, x - 16, y - 16, 32, 32);
    }

    PVector getLocation() {
        PVector loc;
        loc.x = x;
        loc.y = y;
        loc.z = z;
        return loc;
    }

    void move(const bool flags[]) {
        if (flags[0]) {
            y -= 5*mult;
        }
        if (flags[1]) {
            x -= 5*mult;
        }
        if (flags[2]) {
            y += 5*mult;
        }
        if (flags[3]) {
            x += 5*mult;
        }
        if(x > width){
            x-=width;
        }
        if(x < 0){
            x+=width;
        }
        if(y > height){
            y-=height;
        }
        if(y < 0){
            y+=height;
        }
    }

    bool checkHitBerg(IceBerg ib){
        if(dist(ib.getLocation(), getLocation())< 32){
            mult*=0.8;
            return true;
        }
        return false;
    }

    bool checkHitAtol(Atol ib){
        if(dist(ib.getLocation(), getLocation())< 32){
            mult*=0.8;
            return true;
        }
        return false;
    }

    bool checkHitBoat(AntarcticBoat ab){
        if(dist(ab.getLocation(), getLocation())< 32){
            mult*=1.05f;
            score++;
            return true;
        }
        return false;
    }
    bool checkHitBoat(SouthSeaBoat ab){
        if(dist(ab.getLocation(), getLocation())< 32){
            mult*=1.05f;
            score++;
            return true;
        }
        return false;
    }
    bool checkHitBoat(ChinaSeaBoat ab){
        if(dist(ab.getLocation(), getLocation())< 32){
            mult*=1.05f;
            score++;
            return true;
        }
        return false;
    }
    bool checkHitPirate(Pirate pi){
        if(dist(pi.getLocation(), getLocation())< 32){
            //TODO: Add a question
            return true;
        }
        return false;
    }

    PString getScore(){
        return ""s+score;
    }
};

#endif //IGRCA_VEGOVECBOAT_H
