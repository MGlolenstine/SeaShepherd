//
// Created by notyours on 17/03/18.
//

#ifndef IGRCA_LEVEL2_H
#define IGRCA_LEVEL2_H

#include "Atol.h"
#include "SouthSeaBoat.h"
#include "VegovecBoat.h"

//class VegovecBoat {
//    float x;
//    float y;
//    float z;
//    float mult;
//    int score = 0;
//    PImage img;
//public:
//    VegovecBoat(PImage img) {
//        x = width / 2;
//        y = height / 2;
//        z = 0;
//        mult = 1;
//        this->img = img;
//    }
//
//    void show() {
//        image(img, x - 16, y - 16, 32, 32);
//    }
//
//    PVector getLocation() {
//        PVector loc;
//        loc.x = x;
//        loc.y = y;
//        loc.z = z;
//        return loc;
//    }
//
//    void move(const bool flags[]) {
//        if (flags[0]) {
//            y -= 5*mult;
//        }
//        if (flags[1]) {
//            x -= 5*mult;
//        }
//        if (flags[2]) {
//            y += 5*mult;
//        }
//        if (flags[3]) {
//            x += 5*mult;
//        }
//        if(x > width){
//            x-=width;
//        }
//        if(x < 0){
//            x+=width;
//        }
//        if(y > height){
//            y-=height;
//        }
//        if(y < 0){
//            y+=height;
//        }
//    }
//
//    bool checkHitBerg(Atol ib){
//        if(dist(ib.getLocation(), getLocation())< 32){
//            mult*=0.8;
//            return true;
//        }
//        return false;
//    }
//
//    bool checkHitBoat(SouthSeaBoat ab){
//        if(dist(ab.getLocation(), getLocation())< 32){
//            mult*=1.05f;
//            score++;
//            return true;
//        }
//        return false;
//    }
//
//    PString getScore(){
//        return ""s+score;
//    }
//};

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
        //text("Amount of boats: "s + (int) boats.size(), 0, 20);
        //println("Amount of boats: "s+(int) boats.size());
        for (auto &ab : boats) {
            //println("Drawing boat at "s+ab.getLocation().x+", "+ab.getLocation().y);
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
};

class Level2 {
    int amountOfBoats = 15;
    int amountOfBergs = 15;
    SouthSea *ac = nullptr;
public:
    void show() {
        //println("Showing boats"s);
        if (ac == nullptr) {
            ac = new SouthSea(amountOfBoats, amountOfBergs);
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

#endif //IGRCA_LEVEL2_H
