//
// Created by notyours on 04/01/18.
//

#ifndef IGRCA_BUTTON_H
#define IGRCA_BUTTON_H


class Button {
    int x;
    int y;
    int width;
    int height;
    PString displayText;
    int action;
public:

    Button(int x, int y, int width, int height, PString displayText, int action){
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->displayText = displayText;
        this->action = action;
    }

    void show(){
        fill(255);
        rect(x, y, width, height);
        fill(0);
        text(displayText, x, y+height/2);
    }

    PVector getPosition(){
        return PVector(x, y);
    }

    int getWidth(){
        return width;
    }

    int getHeight(){
        return height;
    }

    int pressed(int x, int y){
        if(x > this->x && x < this->x+width){
            if(y > this->y && y < this->y+height){
                return action;
            }
        }
        return -2;
    }
};


#endif //IGRCA_BUTTON_H
