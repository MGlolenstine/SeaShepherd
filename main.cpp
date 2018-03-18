#include "P5c.h"
#include "MainMenu.h"
#include "LevelSelector.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "TextInput.h"

/*
   -1 - main menu
    0 - Level Selection
    1 - Level 1
    2 - Level 2
    3 - Level 3
    4 - EndGame screen
*/
int currentScene = -1;

bool flag[4];

MainMenu mm;
LevelSelector ls;
Level1 l1;
Level2 l2;
Level3 l3;
PImage bg[6];
Button win;
Button lose;
TextInput nameInput;

bool won = true;

int points = 0;

void setup() {
    name("Sea Sheperd");
    size(800, 600);
    mm = MainMenu();
    ls = LevelSelector();
    background(51);
    bg[0] = loadImage("boats/vegova_logo.png");
    bg[1] = loadImage("boats/vegova_logo.png");
    bg[2] = loadImage("boats/antarctica.jpg");
    bg[3] = loadImage("boats/southsea.jpg");
    bg[4] = loadImage("boats/chinasea.jpg");
    bg[5] = loadImage("boats/vegova_logo.png");
    win = Button(width/2, height-25, PString("Cestitke, zmagal si"s), -1, true);
    lose = Button(width/2, height-25, PString("Vec srece prihodnjic"s), -1, true);
    nameInput = TextInput(width/3, 15, width/3, 20);
}

void draw() {
    background(51);
    image(bg[currentScene+1], 0, 0, width, height);
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
        nameInput.setPoints(points);
        nameInput.show();
        if(won) {
            win.show();
        }else{
            lose.show();
        }
    }
    if(currentScene == 1){
        l1.keyPressed(flag);
        if(l1.dead()){
            currentScene = 4;
            won = false;
        }
        if(l1.nextLevel()){
            currentScene++;
            points += l1.getPoints();
            l1 = Level1();
        }
    }else if(currentScene == 2){
        l2.keyPressed(flag);
        if(l2.dead()){
            currentScene = 4;
            won = false;
        }
        if(l2.nextLevel()){
            currentScene++;
            points += l2.getPoints();
            l2 = Level2();
        }
    }else if(currentScene == 3){
        l3.keyPressed(flag);
        if(l3.dead()){
            currentScene = 4;
            won = false;
        }
        if(l3.nextLevel()){
            currentScene++;
            points += l3.getPoints();
            l3 = Level3();
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
        nameInput.clicked(mouseX, mouseY);
        if(won) {
            if (win.pressed(mouseX, mouseY) == -1) {
                currentScene = 0;
            }
        }else {
            if (lose.pressed(mouseX, mouseY) == -1) {
                currentScene = 0;
            }
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