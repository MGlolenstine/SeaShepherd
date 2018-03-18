//
// Created by notyours on 17/03/18.
//

#ifndef IGRCA_LEVEL2_H
#define IGRCA_LEVEL2_H

#include "Atol.h"
#include "SouthSeaBoat.h"
#include "VegovecBoat.h"

class SouthSea {
public:
    std::vector<SouthSeaBoat> boats;
    std::vector<Atol> atols;
    VegovecBoat boat = VegovecBoat(PImage());
    explicit SouthSea(int amountOfBoats, int amountOfBergs) {
        PImage img = loadImage("boats/southsea.png");
        for (int i = 0; i < amountOfBoats; i++) {
            boats.emplace_back(img);
        }
        img = loadImage("boats/atol.png");
        for (int i = 0; i < amountOfBergs; i++) {
            atols.emplace_back(img);
        }
        img = loadImage("boats/ladja_vegovec.png");
        boat = VegovecBoat(img);
    }

    void show() {
        fill(0);
        for (auto &ab : boats) {
            ab.show();
        }
        for (auto &atol : atols) {
            atol.show();
        }
        boat.show();
        fill(0);
        text(boat.getScore(), 16, 16);
    }

    void move(const bool flags[]) {
        boat.move(flags);
        PVector loc = boat.getLocation();
        for (auto &boa : boats) {
            boa.update(loc);
            boa.move(boat.getLocation());
        }
        for(const Atol &ib : atols){
            if(boat.checkHitAtol(ib)){
                removeBerg(ib);
                break;
            }
        }
        for(const SouthSeaBoat &ab : boats){
            if(boat.checkHitBoat(ab)){
                removeBoat(ab);
                break;
            }
        }
    }

    void removeBerg(Atol ib){
        std::vector<Atol> tmp;
        PVector loc1 = ib.getLocation();
        for(Atol lp : atols){
            PVector loc2 = lp.getLocation();
            if(dist(loc1, loc2)>16) {
                tmp.push_back(lp);
            }
        }
        atols = tmp;
    }

    void removeBoat(SouthSeaBoat ab){
        std::vector<SouthSeaBoat> tmp;
        PVector loc1 = ab.getLocation();
        for(SouthSeaBoat lp : boats){
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

    int getPoints() {
        return stoi(boat.getScore().getText());
    }
};

class Level2 {
    int amountOfBoats = 15;
    int amountOfBergs = 15;
    SouthSea *ss = nullptr;
public:
    void show() {
        //println("Showing boats"s);
        if (ss == nullptr) {
            ss = new SouthSea(amountOfBoats, amountOfBergs);
        }
        ss->show();
    }

    void keyPressed(const bool flags[]) {
        ss->move(flags);
    }

    bool nextLevel(){
        return ss->boats.empty();
    }

    bool dead(){
        return ss->dead();
    }

    int getPoints() {
        ss->getPoints();
    }
};

#endif //IGRCA_LEVEL2_H
