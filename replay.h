//
// Created by notyours on 11/05/18.
//

#ifndef IGRCA_REPLAY_H
#define IGRCA_REPLAY_H

#include "P5c.h"

using namespace std;

class Replay{
public:
    PImage vegovec;
    PImage levelb[3];
    PImage levelbe[3];
    int level = 1;
    int health = 0;
    int score = 0;
    ifstream input;
    PVector player;
    vector<PVector> boats;
    vector<PVector> bergs;
    PImage bg[6];
    Replay(PImage images[]){
        vegovec = loadImage("boats/ladja_vegovec.png");
        levelb[0] = loadImage("boats/antarctic.png");
        levelbe[0] = loadImage("boats/iceberg.png");
        levelb[1] = loadImage("boats/southsea.png");
        levelbe[1] = loadImage("boats/atol.png");
        levelb[2] = loadImage("boats/chinasea.png");
        levelbe[2] = loadImage("boats/pirate.png");
        input = ifstream("replay.txt");
        for(int i = 0; i < 6; i++) {
            bg[i] = images[i];
        }
    }

    void show(int *currentScene){
        image(bg[level+1], 0, 0, width, height);
        string cur;
        boats.clear();
        bergs.clear();
        do{
            getline(input, cur);
            if(input.eof()){
                *currentScene = -1;
                return;
            }
            vector<PString> splot = PString(cur).split(':');
            if(startsWith(cur.c_str(), "goal")){
                vector<PString> splot2 = splot.at(1).split(',');
                boats.push_back(PVector(atof(splot2.at(0).getText().c_str()), atof(splot2.at(1).getText().c_str())));
            }else if(startsWith(cur.c_str(), "hurdle")){
                vector<PString> splot2 = splot.at(1).split(',');
                bergs.push_back(PVector(atof(splot2.at(0).getText().c_str()), atof(splot2.at(1).getText().c_str())));
            }else if(startsWith(cur.c_str(), "pos")){
                vector<PString> splot2 = splot.at(1).split(',');
                player = PVector(atof(splot2.at(0).getText().c_str()), atof(splot2.at(1).getText().c_str()));
            }else if(startsWith(cur.c_str(), "level")){
                level = atoi(splot.at(1).getText().c_str());
            }else if(startsWith(cur.c_str(), "health")){
                health = atoi(splot.at(1).getText().c_str());
            }else if(startsWith(cur.c_str(), "score")){
                score = atoi(splot.at(1).getText().c_str());
            }
        }while(!startsWith(cur.c_str(), "pos"));
        for(PVector pv : boats){
            image(levelb[level-1], pv.x-16, pv.y-16, 32, 32);
        }
        for(PVector pv : bergs){
            image(levelbe[level-1], pv.x-16, pv.y-16, 32, 32);
        }
        image(vegovec, player.x-16, player.y-16, 32, 32);
        text(""s+score, 16, 16);
        text(""s+health, width-32, height-32);
    }
};

#endif //IGRCA_REPLAY_H
