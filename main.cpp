#include "P5c.h"
#include "MainMenu.h"
#include "LevelSelector.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "TextInput.h"
#include "Scoreboard.h"

using namespace std;

/*
   -1 - main menu
    0 - Level Selection
    1 - Level 1
    2 - Level 2
    3 - Level 3
    4 - EndGame screen - WIN
    5 - EndGame screen - LOSE
*/
int currentScene = 4;

bool flag[4];

MainMenu mm;
LevelSelector ls;
Level1 l1;
Level2 l2;
Level3 l3;
PImage bg;
Button win;
Button lose;
TextInput nameInput;
Scoreboard sb("scores.txt"s);

void setup() {
    name("Sea Sheperd");
    size(800, 600);
    mm = MainMenu();
    ls = LevelSelector();
    background(51);
    bg = loadImage("boats/vegova_logo.png");
    win = Button(width/2, height-25, "Cestitke, zmagal si"s, -1, true);
    lose = Button(width/2, height/2, "Vec srece prihodnjic"s, -1, true);
    nameInput = TextInput(width/3, 15, width/3, 20);
    sb.getResults();
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
        nameInput.show();
        sb.show();
        win.show();
    }else if(currentScene == 5){
        lose.show();
    }
    if(currentScene == 1){
        l1.keyPressed(flag);
        if(l1.dead()){
            currentScene = 5;
        }
        if(l1.nextLevel()){
            currentScene++;
            l1 = Level1();
        }
    }else if(currentScene == 2){
        l2.keyPressed(flag);
        if(l2.dead()){
            currentScene = 5;
        }
        if(l2.nextLevel()){
            currentScene++;
            l2 = Level2();
        }
    }else if(currentScene == 3){
        l3.keyPressed(flag);
        if(l3.dead()){
            currentScene = 5;
        }
        if(l3.nextLevel()){
            currentScene++;
            l3 = Level3();
            sb.getResults();
        }
    }
}

void mousePressed() {
    if(currentScene == -1){
        int action = mm.pressed(mouseX, mouseY);
        if(action == 0){
            currentScene = 0;
        }
        if(action == 1){
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
    }else if(currentScene == 3){
        l3.mousePressed(mouseX, mouseY);
    }else if(currentScene == 4){
        if(win.pressed(mouseX, mouseY) == -1){
            currentScene = 0;
        }
    }else if(currentScene == 5){
        if(lose.pressed(mouseX, mouseY) == -1){
            currentScene = 0;
        }
    }
}

void keyPressed(){
    if(currentScene == 4){
        nameInput.keyTyped(key);
    }
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