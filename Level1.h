//
// Created by notyours on 05/01/18.
//

#ifndef IGRCA_LEVEL1_H
#define IGRCA_LEVEL1_H


class Level1 {
    PVector pos;
    PVector vel;
public:
    Level1(){
        pos = PVector(width/2, height/2);
        vel.random2D();
        vel.mult(5);
    }
    void show(){
        ellipse(pos.x, pos.y, 5, 5);
        if(pos.x > width || pos.x < 0){
            vel.x = -vel.x;
        }
        if(pos.y > height || pos.y < 0){
            vel.y = -vel.y;
        }
        pos.add(vel);
    }

    void keyPressed(){

    }

    void mousePressed(){

    }
};


#endif //IGRCA_LEVEL1_H
