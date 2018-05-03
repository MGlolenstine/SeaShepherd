//
// Created by notyours on 05/01/18.
//

#ifndef IGRCA_LEVEL1_H
#define IGRCA_LEVEL1_H

#include "VegovecBoat.h"
#include "IceBerg.h"

class Antarctic {
public:
    std::vector<AntarcticBoat> boats;
    std::vector<IceBerg> icebergs;
    VegovecBoat boat = VegovecBoat(PImage());

    explicit Antarctic(int amountOfBoats, int amountOfBergs) {
        PImage img = loadImage("boats/antarctic.png");
        for (int i = 0; i < amountOfBoats; i++) {
            boats.emplace_back(img);
        }
        img = loadImage("boats/iceberg.png");
        for (int i = 0; i < amountOfBergs; i++) {
            icebergs.emplace_back(img);
        }
        img = loadImage("boats/ladja_vegovec.png");
        boat = VegovecBoat(img);
    }

    std::vector<std::string>* info(){
        //println("There is: "s+(int)boats.size()+" boats and "+(int)icebergs.size()+" icebergs.");
        auto *info = new std::vector<std::string>();
        info->push_back(("health:"s+boat.getHealth()).getText());
        info->push_back(("score:"s+boat.getScore().getText()).getText());
        PVector pos = boat.getLocation();
        info->push_back(("pos:"s+pos.x+","+pos.y+","+pos.z).getText());
        for(AntarcticBoat ab : boats){
            PVector pv = ab.getLocation();
            info->push_back(("goal:"s+ pv.x+","+pv.y+","+pv.z).getText());
        }
        for(IceBerg ic : icebergs){
            PVector pv = ic.getLocation();
            info->push_back(("hurdle:"s+ pv.x+","+pv.y+","+pv.z).getText());
        }
        return info;
    }

    void show() {
        fill(0);
        //text("Amount of boats: "s + (int) boats.size(), 0, 10);
        for (AntarcticBoat ab : boats) {
            ab.show();
        }
        for (int i = 0; i < icebergs.size(); i++) {
            icebergs.at(i).move();
            icebergs.at(i).show();
        }
        boat.show();
        fill(0);
        text(boat.getScore(), 16, 16);
    }

    void move(const bool flags[]) {
        boat.move(flags);
        PVector loc = boat.getLocation();
        for (int i = 0; i < boats.size(); i++) {
            boats.at(i).update(loc);
            boats.at(i).move(boat.getLocation());
        }
        for (IceBerg ib : icebergs) {
            if (boat.checkHitBerg(ib)) {
                removeBerg(ib);
                break;
            }
        }
        for (AntarcticBoat ab : boats) {
            if (boat.checkHitBoat(ab)) {
                removeBoat(ab);
                break;
            }
        }
    }

    void removeBerg(IceBerg ib) {
        std::vector<IceBerg> tmp;
        PVector loc1 = ib.getLocation();
        for (IceBerg lp : icebergs) {
            PVector loc2 = lp.getLocation();
            if (dist(loc1, loc2) > 16) {
                tmp.push_back(lp);
            } else {
            }
        }
        icebergs = tmp;
    }

    void removeBoat(AntarcticBoat ab) {
        std::vector<AntarcticBoat> tmp;
        PVector loc1 = ab.getLocation();
        for (AntarcticBoat lp : boats) {
            PVector loc2 = lp.getLocation();
            if (dist(loc1, loc2) > 16) {
                tmp.push_back(lp);
            } else {
            }
        }
        boats = tmp;
    }

    bool dead() {
        return boat.getHealth() <= 0;
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
        PImage img = loadImage("boats/antarctic.png");
        AntarcticBoat b = AntarcticBoat(img);
        b.setLocation(pos);
        boats.push_back(b);
    }

    void addBerg(PVector pos){
        PImage img = loadImage("boats/iceberg.png");
        IceBerg b = IceBerg(img);
        b.setLocation(pos);
        icebergs.push_back(b);
    }
};

class Level1 {
    int amountOfBoats = 10;
    int amountOfBergs = 5;
    Antarctic *ac = nullptr;
public:
    void show() {
        if (ac == nullptr) {
            ac = new Antarctic(amountOfBoats, amountOfBergs);
        }
        ac->show();
    }

    void setup(){
        ac = new Antarctic(0, 0);
    }

    void keyPressed(const bool flags[]) {
        ac->move(flags);
    }

    bool nextLevel() {
        return ac->boats.empty();
    }

    bool dead() {
        return ac->dead();
    }

    int getPoints() {
        ac->getPoints();
    }

    std::vector<std::string>* info(){
        return ac->info();
    }

    void addPlayer(int health, int score, PVector pos){
        ac->addPlayer(health, score, pos);
    }

    void addBerg(PVector pos){
        ac->addBerg(pos);
    }

    void addBoat(PVector pos){
        ac->addBoat(pos);
    }
};

#endif //IGRCA_LEVEL1_H
