//
// Created by LifEorDeatH on 18.3.2018.
//

#ifndef IGRCA_TEXTINPUT_H
#define IGRCA_TEXTINPUT_H

#include "Scoreboard.h"

class TextInput {
    PString string = ""s;
    PVector pos;
    PVector size;
    Button submit;
    int lengthDisplayed = 10;
    bool active = false;
    Scoreboard sb = Scoreboard();
    int points = 0;
public:
    TextInput() {}

    TextInput(int x, int y, int w, int h) {
        pos = PVector(x, y);
        size = PVector(w, h);
        lengthDisplayed = (size.x - 2)/textWidth(PString("1"));
        submit = Button(pos.x+size.x+15, y, textWidth("Submit"s), 20, "Submit"s, 0);
        sb = Scoreboard("scores.txt"s);
        sb.getResults();
    }

    void show() {
        fill(0);
        text("Score: "s+points, 0, 20);
        if(active) {
            fill(255);
        }else{
            fill(200);
        }
        rect(pos.x, pos.y, size.x, size.y);
        fill(0);
        if(string.length() == 0){
            text("Vnesi svoje ime..."s, pos.x + 1, pos.y + 15);
        }
        if(string.length() > lengthDisplayed) {
            PString tmpstring = string.substr(string.length() - lengthDisplayed, lengthDisplayed);
            text(tmpstring, pos.x + 1, pos.y + 15);
        }else{
            text(string, pos.x + 1, pos.y + 15);
        }
        submit.show();
        sb.show();
    }

    void keyTyped(char key) {
        if(active) {
            if (key == 8) {
                string = string.substr(0, string.length() - 1);
            } else {
                string = string + key;
            }
        }
    }

    void clicked(int mouseX, int mouseY){
        sb.getResults();
        if(submit.pressed(mouseX, mouseY) != -2){
            sb.addResult(string, points);
            submit.setActive(false);
            sb.getResults();
        }
        if(mouseX > pos.x && mouseX < pos.x + size.x){
            if(mouseY > pos.y && mouseY < pos.y + size.y){
                active = true;
                return;
            }
        }
        active = false;
    }

    void setPoints(int points){
        this->points = points;
    }
};

#endif //IGRCA_TEXTINPUT_H
