//
// Created by notyours on 05/01/18.
//

#ifndef IGRCA_LEVEL1_H
#define IGRCA_LEVEL1_H

struct Location{
    float x;
    float y;
    float z;
};

class AntarcticBoat{
    float x;
    float y;
    float z;
    PImage img;
public:
    AntarcticBoat(PImage img){
        x = 0;
        y = 0;
        z = 0;
        this->img = img;
    }
    void show(){
        image(img, x, y, 32, 32);
    }

    Location getPosition(){
        Location loc;
        loc.x = x;
        loc.y = y;
        loc.z = z;
        return loc;
    }
};

class Antarctic{
    std::vector<AntarcticBoat> boats;
public:
    Antarctic(PImage img){
        // TODO: Add boats
        boats.push_back(AntarcticBoat(img));
    }
    void show(){
        for(AntarcticBoat ab : boats){
            ab.show();
        }
    }
};

class Level1 {
    Antarctic *ac = nullptr;
public:
    void show(){
        if(ac == nullptr){
            ac = new Antarctic(loadImage("boats/antarctic.png"));
        }
        ac->show();
    }

    void keyPressed(){

    }

    void mousePressed(){

    }
};

#endif //IGRCA_LEVEL1_H
