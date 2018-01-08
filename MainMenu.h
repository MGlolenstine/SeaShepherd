//
// Created by notyours on 04/01/18.
//

#ifndef IGRCA_MAINMENU_H
#define IGRCA_MAINMENU_H


#include "Button.h"

class MainMenu {
    std::vector<Button*> buttons;
public:

    MainMenu(){
        buttons.push_back(new Button(width/2-75/2, height/10*6, 75, 25, "Level selector"s, 0));
        buttons.push_back(new Button(width/2-75/2, height/10*7, 75, 25, "Play"s, 1));
    }

    void show(){
        for(Button *b : buttons){
            b->show();
        }
    }

    int pressed(int x, int y){
        for(Button *b : buttons){
            int action = b->pressed(x, y);
            if(action != -2){
                println("Returning: "s+action);
                return action;
            }
        }
    }
};


#endif //IGRCA_MAINMENU_H
