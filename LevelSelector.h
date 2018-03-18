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

    LevelSelector() {
        buttons.emplace_back(width / 2, height / 10 * 6, "Level 1"s, 1, true);
        buttons.emplace_back(width / 2, height / 10 * 7, "Level 2"s, 2, true);
        buttons.emplace_back(width / 2, height / 10 * 8, "Level 3"s, 3, true);
    }

    void show() {
        //text("Select to play from level 1"s, width/2-75/2, height/10*6-20);
        for (Button b : buttons) {
            b.show();
        }
    }

    int pressed(int x, int y) {
        for (Button b : buttons) {
            int action = b.pressed(x, y);
            if (action != -2) {
                return action;
            }
        }
    }
};

#endif //IGRCA_LEVELSELECTOR_H
