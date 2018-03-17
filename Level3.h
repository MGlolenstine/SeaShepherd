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
            cb.update(boat.getLocation());
            cb.show();
            cb.move(boat.getLocation());
        }
        for (auto &pirate : pirates) {
            pirate.update(boat.getLocation());
            pirate.show();
            pirate.move(boat.getLocation());
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
};

class Level3 {
    int amountOfBoats = 15;
    int amountOfBergs = 15;
    ChinaSea *ac = nullptr;
public:
    void show() {
        //println("Showing boats"s);
        if (ac == nullptr) {
            ac = new ChinaSea(amountOfBoats, amountOfBergs);
        }
        ac->show();
    }

    void keyPressed(const bool flags[]) {
        ac->move(flags);
    }

    bool nextLevel(){
        return ac->boats.size() == 0;
    }
};

#endif //IGRCA_LEVEL4_H
