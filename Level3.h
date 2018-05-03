//
// Created by notyours on 17/03/18.
//

#ifndef IGRCA_LEVEL4_H
#define IGRCA_LEVEL4_H

#include "Pirate.h"
#include "ChinaSeaBoat.h"
#include "VegovecBoat.h"

class ChinaSea {
public:
    std::vector<ChinaSeaBoat> boats;
    std::vector<Pirate> pirates;
    VegovecBoat boat = VegovecBoat(PImage());
    explicit ChinaSea(int amountOfBoats, int amountOfPirates) {
        PImage img = loadImage("boats/chinasea.png");
        for (int i = 0; i < amountOfBoats; i++) {
            boats.emplace_back(img);
        }
        img = loadImage("boats/pirate.png");
        for (int i = 0; i < amountOfPirates; i++) {
            pirates.emplace_back(img);
        }
        img = loadImage("boats/ladja_vegovec.png");
        boat = VegovecBoat(img);
    }

    void show() {
        fill(0);
        for (auto &cb : boats) {
            if(!boat.question) {
                cb.update(boat.getLocation());
                cb.move(boat.getLocation());
            }
            cb.show();
        }
        for (auto &pirate : pirates) {
            if(!boat.question) {
                pirate.update(boat.getLocation());
                pirate.move(boat.getLocation());
            }
            pirate.show();
        }
        boat.show();
        fill(0);
        text(boat.getScore(), 16, 16);
    }

    void move(const bool flags[]) {
        boat.move(flags);
        PVector loc = boat.getLocation();
        for(auto &pi : pirates){
            if(boat.checkHitPirate(pi)){
                removeBoat(pi);
                break;
            }
        }
        for(auto &cb : boats){
            if(boat.checkHitBoat(cb)){
                removeBoat(cb);
                break;
            }
        }
    }

    void removeBoat(Pirate pi){
        std::vector<Pirate> tmp;
        PVector loc1 = pi.getLocation();
        for(auto &pir : pirates){
            PVector loc2 = pir.getLocation();
            if(dist(loc1, loc2)>16) {
                tmp.push_back(pir);
            }
        }
        pirates = tmp;
    }

    void removeBoat(ChinaSeaBoat cb){
        std::vector<ChinaSeaBoat> tmp;
        PVector loc1 = cb.getLocation();
        for(auto &lp : boats){
            PVector loc2 = lp.getLocation();
            if(dist(loc1, loc2)>16) {
                tmp.push_back(lp);
            }
        }
        boats = tmp;
    }

    bool dead(){
        return boat.getHealth()<=0;
    }

    void mousePressed(int mouseX, int mouseY){
        boat.mousePressed(mouseX, mouseY);
    }

    int getPoints() {
        return stoi(boat.getScore().getText());
    }

    void addPlayer(int health, int score, PVector pos){
        PImage img = loadImage("boats/ladja_vegovec.png");
        boat = VegovecBoat(img);
        boat.setHealth(health);
        boat.setLocation(pos);
        boat.setScore(score);
    }

    void addBoat(PVector pos){
        PImage img = loadImage("boats/chinasea.png");
        ChinaSeaBoat b = ChinaSeaBoat(img);
        b.setLocation(pos);
        boats.push_back(b);
    }

    void addBerg(PVector pos){
        PImage img = loadImage("boats/pirate.png");
        Pirate b = Pirate(img);
        b.setLocation(pos);
        pirates.push_back(b);
    }

    std::vector<std::string>* info(){
        //println("There is: "s+(int)boats.size()+" boats and "+(int)icebergs.size()+" icebergs.");
        auto *info = new std::vector<std::string>();
        info->push_back(("health:"s+boat.getHealth()).getText());
        info->push_back(("score:"s+boat.getScore().getText()).getText());
        PVector pos = boat.getLocation();
        info->push_back(("pos:"s+pos.x+","+pos.y+","+pos.z).getText());
        for(ChinaSeaBoat ab : boats){
            PVector pv = ab.getLocation();
            info->push_back(("goal:"s+ pv.x+","+pv.y+","+pv.z).getText());
        }
        for(Pirate ic : pirates){
            PVector pv = ic.getLocation();
            info->push_back(("hurdle:"s+ pv.x+","+pv.y+","+pv.z).getText());
        }
        return info;
    }
};

class Level3 {
    int amountOfBoats = 15;
    int amountOfBergs = 15;
    ChinaSea *cs = nullptr;
public:
    void show() {
        //println("Showing boats"s);
        if (cs == nullptr) {
            cs = new ChinaSea(amountOfBoats, amountOfBergs);
        }
        cs->show();
    }

    void setup(){
        cs = new ChinaSea(0, 0);
    }

    void keyPressed(const bool flags[]) {
        cs->move(flags);
    }

    void mousePressed(int mouseX, int mouseY){
        cs->mousePressed(mouseX, mouseY);
    }

    bool nextLevel(){
        return cs->boats.empty();
    }

    bool dead(){
        return cs->dead();
    }

    int getPoints() {
        cs->getPoints();
    }

    std::vector<std::string>* info(){
        return cs->info();
    }

    void addPlayer(int health, int score, PVector pos){
        cs->addPlayer(health, score, pos);
    }

    void addBerg(PVector pos){
        cs->addBerg(pos);
    }

    void addBoat(PVector pos){
        cs->addBoat(pos);
    }
};

#endif //IGRCA_LEVEL4_H
