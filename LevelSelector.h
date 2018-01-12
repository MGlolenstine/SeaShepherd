//
// Created by notyours on 05/01/18.
//

#ifndef IGRCA_LEVELSELECTOR_H
#define IGRCA_LEVELSELECTOR_H

#include <vector>
#include "Button.h"
#include "P5c.h"

class LevelSelector {
    std::vector<Button> buttons;
public:

    LevelSelector(){
        buttons.push_back(Button(width/2-75/2, height/10*6, 75, 25, "Select to play from Level 1"s, 1));
        buttons.push_back(Button(width/2-75/2, height/10*7, 75, 25, "Level 2"s, 2));
        buttons.push_back(Button(width/2-75/2, height/10*8, 75, 25, "Level 3"s, 3));
    }

    void show(){
        text("Select to play from level 1"s, width/2-75/2, height/10*6-20);
        for(Button b : buttons){
            b.show();
        }
    }

    int pressed(int x, int y){
        for(Button b : buttons){
            int action = b.pressed(x, y);
            if(action != -2){
                return action;
            }
        }
    }
};

#endif //IGRCA_LEVELSELECTOR_H
