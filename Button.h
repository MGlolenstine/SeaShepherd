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
    bool centered;
public:
    Button(){}

    Button(int x, int y, int width, int height, PString displayText, int action) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->displayText = displayText;
        this->action = action;
        this->centered = false;
    }

    Button(int x, int y, PString displayText, int action, bool center) {
        this->x = x;
        this->y = y;
        this->width = textWidth(displayText) + 40;
        if (center) {
            this->x = x - (textWidth(displayText) + 40) / 2;
        }
        this->height = 20;
        this->displayText = displayText;
        this->action = action;
        this->centered = center;
    }

    void show() {
        fill(255);
        rect(x, y, width, height);
        fill(0);
        if(centered) {
            text(displayText, x + 20, y + height / 2 + 2);
        }else{
            text(displayText, x, y);
        }
    }

    PVector getPosition() {
        return PVector(x, y);
    }

    int getWidth() {
        return width;
    }

    int getHeight() {
        return height;
    }

    int pressed(int x, int y) {
        if (x > this->x && x < this->x + width) {
            if (y > this->y && y < this->y + height) {
                return action;
            }
        }
        return -2;
    }
};


#endif //IGRCA_BUTTON_H
