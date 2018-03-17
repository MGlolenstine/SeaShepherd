#include "P5c.h"
#include "MainMenu.h"
#include "LevelSelector.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"

using namespace std;

/*
   -1 - main menu
    0 - Level Selection
    1 - Level 1
    2 - Level 2
    3 - Level 3
*/
int currentScene = -1;

bool flag[4];

MainMenu mm;
LevelSelector ls;
Level1 l1;
Level2 l2;
Level3 l3;
PImage bg;

void setup() {
    name("Sea Sheperd");
    size(800, 600);
    mm = MainMenu();
    ls = LevelSelector();
    background(51);
    bg = loadImage("boats/vegova_logo.png");
}

void draw() {
    background(51);
    image(bg, 0, 0, width, height);
    fill(255);
    if(currentScene == -1){
        mm.show();
    }else if(currentScene == 0){
        ls.show();
    }else if(currentScene == 1){
        l1.show();
    }else if(currentScene == 2){
        l2.show();
    }else if(currentScene == 3){
        l3.show();
    }else if(currentScene == 4){
        fill(0);
        //text("Cestitke, zmagal si!"s, width/2, height/2);
    }
    if(currentScene == 1){
        l1.keyPressed(flag);
        if(l1.nextLevel()){
            currentScene++;
        }
    }else if(currentScene == 2){
        l2.keyPressed(flag);
        if(l2.nextLevel()){
            currentScene++;
        }
    }else if(currentScene == 3){
        l3.keyPressed(flag);
        if(l3.nextLevel()){
            currentScene++;
        }
    }
}

void mousePressed() {
    if(currentScene == -1){
        int action = mm.pressed(mouseX, mouseY);
        if(action == 0){
            //println("Going to level selector!"s);
            currentScene = 0;
        }
        if(action == 1){
            //println("Going to level 1!"s);
            currentScene = 1;
        }
    }else if(currentScene == 0){
        int action = ls.pressed(mouseX, mouseY);
        if(action == 1){
            currentScene = 1;
        }else if(action == 2){
            currentScene = 2;
        }else if(action == 3){
            currentScene = 3;
        }
    }
}

void keyPressed(){
    if(key == 'w'){
        flag[0] = true;
    }else if(key == 'a'){
        flag[1] = true;
    }else if(key == 's'){
        flag[2] = true;
    }else if(key == 'd'){
        flag[3] = true;
    }
}


void keyReleased(){
    if(key == 'w'){
        flag[0] = false;
    }else if(key == 'a'){
        flag[1] = false;
    }else if(key == 's'){
        flag[2] = false;
    }else if(key == 'd'){
        flag[3] = false;
    }
}