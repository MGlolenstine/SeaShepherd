//
// Created by notyours on 17/03/18.
//

#ifndef IGRCA_VEGOVECBOAT_H
#define IGRCA_VEGOVECBOAT_H

#include <utility>
#include <map>

class VegovecBoat;

#include "IceBerg.h"
#include "AntarcticBoat.h"
#include "Atol.h"
#include "SouthSeaBoat.h"
#include "Pirate.h"
#include "ChinaSeaBoat.h"
#include "QuestionBox.h"

#define BERG_HIT 5
#define ATOL_HIT 10
#define PIRATE_CORRECT 20
#define PIRATE_WRONG -20


class VegovecBoat {
    float x;
    float y;
    float z;
    float mult;
    int score = 0;
    PImage img;
    int health = 100;
    QuestionBox qb = QuestionBox("Placeholder"s, true, nullptr);
    std::map<std::string, bool> questions;
public:
    bool question = false;

    VegovecBoat(PImage img) {
        x = width / 2;
        y = height / 2;
        z = 0;
        mult = 1;
        this->img = std::move(img);
        health = 100;
        questions.emplace("C/C++ is a shit programming language", true);
        questions.emplace("             sqrt(9) = 4            ", false);
        questions.emplace("       Is Java crossplatform?       ", true);
        questions.emplace(" Can a man go 8 days without sleep? ", true);
    }

    void show() {
        image(img, static_cast<int>(x - 16), static_cast<int>(y - 16), 32, 32);
        if (question) {
            qb.show();
        }
        fill(0);
        text(""s+getHealth(), width-textWidth(""s+getHealth()), height);
    }

    PVector getLocation() {
        PVector loc;
        loc.x = x;
        loc.y = y;
        loc.z = z;
        return loc;
    }

    void move(const bool flags[]) {
        if(question){return;}
        if (flags[0]) {
            y -= 5 * mult;
        }
        if (flags[1]) {
            x -= 5 * mult;
        }
        if (flags[2]) {
            y += 5 * mult;
        }
        if (flags[3]) {
            x += 5 * mult;
        }
        if (x > width) {
            x -= width;
        }
        if (x < 0) {
            x += width;
        }
        if (y > height) {
            y -= height;
        }
        if (y < 0) {
            y += height;
        }
    }

    bool checkHitBerg(IceBerg ib) {
        if (dist(ib.getLocation(), getLocation()) < 32) {
            mult *= 0.8;
            health -= BERG_HIT;
            return true;
        }
        return false;
    }

    bool checkHitAtol(Atol ib) {
        if (dist(ib.getLocation(), getLocation()) < 32) {
            mult *= 0.8;
            health -= ATOL_HIT;
            return true;
        }
        return false;
    }

    bool checkHitBoat(AntarcticBoat ab) {
        if (dist(ab.getLocation(), getLocation()) < 32) {
            mult *= 1.05f;
            score++;
            return true;
        }
        return false;
    }

    bool checkHitBoat(SouthSeaBoat ab) {
        if (dist(ab.getLocation(), getLocation()) < 32) {
            mult *= 1.05f;
            score++;
            return true;
        }
        return false;
    }

    bool checkHitBoat(ChinaSeaBoat ab) {
        if (dist(ab.getLocation(), getLocation()) < 32) {
            score++;
            return true;
        }
        return false;
    }

    bool checkHitPirate(Pirate pi) {
        if (dist(pi.getLocation(), getLocation()) < 32) {
            auto item = questions.begin();
            std::advance( item, random(questions.size()));
            qb = QuestionBox(""s+item->first, item->second, this);
            question = true;
            return true;
        }
        return false;
    }

    void addRemoveHealth(float change) {
        health += change;
    }

    PString getScore() {
        return ""s + score;
    }

    int getHealth() {
        return health;
    }

    void mousePressed(int mouseX, int mouseY){
        if(question) {
            int ans = qb.clicked(mouseX, mouseY);
            if(ans==1){
                addRemoveHealth(PIRATE_CORRECT);
                score+20;
                question = false;
            }else if(ans == 0){
                addRemoveHealth(PIRATE_WRONG);
                score-20;
                question = false;
            }
        }
    }

    void setHealth(int health1){
        health = health1;
    }

    void setLocation(PVector pos){
        x = pos.x;
        y = pos.y;
        z = pos.z;
    }

    void setScore(int score1){
        score = score1;
    }
};

#endif //IGRCA_VEGOVECBOAT_H
