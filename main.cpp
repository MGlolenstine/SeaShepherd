#include "P5c.h"
#include "MainMenu.h"
#include "LevelSelector.h"
#include "Level1.h"

using namespace std;

/*
   -1 - main menu
    0 - Level Selection
    1 - Level 1
    2 - Level 2
    3 - Level 3
*/
int currentScene = -1;

MainMenu mm;
LevelSelector ls;
Level1 l1;

void setup() {
    name("Sea Sheperd");
    size(800, 600);
    mm = MainMenu();
    ls = LevelSelector();
    background(51);
}

void draw() {
    background(51);
    fill(255);
    text("CurentScene: "s+currentScene, 0, 10);
    if(currentScene == -1){
        mm.show();
    }else if(currentScene == 0){
        ls.show();
    }else if(currentScene == 1){
        l1.show();
    }
}

void mousePressed() {
    if(currentScene == -1){
        int action = mm.pressed(mouseX, mouseY);
        if(action == 0){
            println("Going to level selector!"s);
            currentScene = 0;
        }
        if(action == 1){
            println("Going to level 1!"s);
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
    if(currentScene == 1){
        l1.keyPressed();
    }else if(currentScene == 2){

    }else if(currentScene == 3){

    }
}