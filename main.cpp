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
    win = Button(width / 2, height - 25, PString("Cestitke, zmagal si"s), -1, true);
    lose = Button(width / 2, height - 25, PString("Vec srece prihodnjic"s), -1, true);
    nameInput = TextInput(width / 3, 15, width / 3, 20);
}

void draw() {
    background(51);
    image(bg[currentScene + 1], 0, 0, width, height);
    fill(255);
    if (currentScene == -1) {
        mm.show();
    } else if (currentScene == 0) {
        ls.show();
    } else if (currentScene == 1) {
        l1.show();
    } else if (currentScene == 2) {
        l2.show();
    } else if (currentScene == 3) {
        l3.show();
    } else if (currentScene == 4) {
        nameInput.setPoints(points);
        nameInput.show();
        if (won) {
            win.show();
        } else {
            lose.show();
        }
    } else if (currentScene == 5) {
        // TODO: Replay
    }
    if (currentScene == 1) {
        l1.keyPressed(flag);
        if (l1.dead()) {
            currentScene = 4;
            nameInput.reset();
            won = false;
        }
        if (l1.nextLevel()) {
            currentScene++;
            points += l1.getPoints();
            l1 = Level1();
        }
    } else if (currentScene == 2) {
        l2.keyPressed(flag);
        if (l2.dead()) {
            currentScene = 4;
            nameInput.reset();
            won = false;
        }
        if (l2.nextLevel()) {
            currentScene++;
            points += l2.getPoints();
            l2 = Level2();
        }
    } else if (currentScene == 3) {
        l3.keyPressed(flag);
        if (l3.dead()) {
            currentScene = 4;
            nameInput.reset();
            won = false;
        }
        if (l3.nextLevel()) {
            currentScene++;
            nameInput.reset();
            points += l3.getPoints();
            l3 = Level3();
        }
    }
}

void resetToPrev() {
    ifstream file1("continue.txt");
    string line;
    println("Opening files"s);
    if (file1.is_open()) {
        getline(file1, line);
        println("Choosing the level"s);
        if ((""s + line).split(':').at(1).getText() == "1") {
            l1.setup();
            int score = 0;
            int health = 0;
            while (getline(file1, line)) {
                if ((""s + line).split(':').at(0).getText() == "goal") {
                    string posns = (""s + line).split(':').at(1).getText();
                    vector<PString> poss = PString(posns).split(',');
                    PVector pos = PVector(atoi(poss.at(0).getText().c_str()), atoi(poss.at(1).getText().c_str()),
                                          atoi(poss.at(2).getText().c_str()));
                    l1.addBoat(pos);
                } else if ((""s + line).split(':').at(0).getText() == "hurdle") {
                    string posns = (""s + line).split(':').at(1).getText();
                    vector<PString> poss = PString(posns).split(',');
                    PVector pos = PVector(atoi(poss.at(0).getText().c_str()), atoi(poss.at(1).getText().c_str()),
                                          atoi(poss.at(2).getText().c_str()));
                    l1.addBerg(pos);
                } else if ((""s + line).split(':').at(0).getText() == "health") {
                    string heal = (""s + line).split(':').at(1).getText();
                    health = atoi(heal.c_str());
                } else if ((""s + line).split(':').at(0).getText() == "score") {
                    string scor = (""s + line).split(':').at(1).getText();
                    score = atoi(scor.c_str());
                } else if ((""s + line).split(':').at(0).getText() == "pos") {
                    string posns = (""s + line).split(':').at(1).getText();
                    vector<PString> poss = PString(posns).split(',');
                    PVector pos = PVector(atoi(poss.at(0).getText().c_str()), atoi(poss.at(1).getText().c_str()),
                                          atoi(poss.at(2).getText().c_str()));
                    l1.addPlayer(health, score, pos);
                }
            }
            l1.info();
            currentScene = 1;
        } else if ((""s + line).split(':').at(1).getText() == ("2")) {
            l2.setup();
            int score = 0;
            int health = 0;
            while (getline(file1, line)) {
                if ((""s + line).split(':').at(0).getText() == "goal") {
                    string posns = (""s + line).split(':').at(1).getText();
                    vector<PString> poss = PString(posns).split(',');
                    PVector pos = PVector(atoi(poss.at(0).getText().c_str()), atoi(poss.at(1).getText().c_str()),
                                          atoi(poss.at(2).getText().c_str()));
                    l2.addBoat(pos);
                } else if ((""s + line).split(':').at(0).getText() == "hurdle") {
                    string posns = (""s + line).split(':').at(1).getText();
                    vector<PString> poss = PString(posns).split(',');
                    PVector pos = PVector(atoi(poss.at(0).getText().c_str()), atoi(poss.at(1).getText().c_str()),
                                          atoi(poss.at(2).getText().c_str()));
                    l2.addBerg(pos);
                } else if ((""s + line).split(':').at(0).getText() == "health") {
                    string heal = (""s + line).split(':').at(1).getText();
                    health = atoi(heal.c_str());
                } else if ((""s + line).split(':').at(0).getText() == "score") {
                    string scor = (""s + line).split(':').at(1).getText();
                    score = atoi(scor.c_str());
                } else if ((""s + line).split(':').at(0).getText() == "pos") {
                    string posns = (""s + line).split(':').at(1).getText();
                    vector<PString> poss = PString(posns).split(',');
                    PVector pos = PVector(atoi(poss.at(0).getText().c_str()), atoi(poss.at(1).getText().c_str()),
                                          atoi(poss.at(2).getText().c_str()));
                    l2.addPlayer(health, score, pos);
                }
            }
            currentScene = 2;
        } else if ((""s + line).split(':').at(1).getText() == ("3")) {
            l3.setup();
            int score = 0;
            int health = 0;
            while (getline(file1, line)) {
                if ((""s + line).split(':').at(0).getText() == "goal") {
                    string posns = (""s + line).split(':').at(1).getText();
                    vector<PString> poss = PString(posns).split(',');
                    PVector pos = PVector(atoi(poss.at(0).getText().c_str()), atoi(poss.at(1).getText().c_str()),
                                          atoi(poss.at(2).getText().c_str()));
                    l3.addBoat(pos);
                } else if ((""s + line).split(':').at(0).getText() == "hurdle") {
                    string posns = (""s + line).split(':').at(1).getText();
                    vector<PString> poss = PString(posns).split(',');
                    PVector pos = PVector(atoi(poss.at(0).getText().c_str()), atoi(poss.at(1).getText().c_str()),
                                          atoi(poss.at(2).getText().c_str()));
                    l3.addBerg(pos);
                } else if ((""s + line).split(':').at(0).getText() == "health") {
                    string heal = (""s + line).split(':').at(1).getText();
                    health = atoi(heal.c_str());
                } else if ((""s + line).split(':').at(0).getText() == "score") {
                    string scor = (""s + line).split(':').at(1).getText();
                    score = atoi(scor.c_str());
                } else if ((""s + line).split(':').at(0).getText() == "pos") {
                    string posns = (""s + line).split(':').at(1).getText();
                    vector<PString> poss = PString(posns).split(',');
                    PVector pos = PVector(atoi(poss.at(0).getText().c_str()), atoi(poss.at(1).getText().c_str()),
                                          atoi(poss.at(2).getText().c_str()));
                    l3.addPlayer(health, score, pos);
                }
            }
            currentScene = 3;
        }
        println("Closing files"s);
        file1.close();
        println("Removing files"s);
//        remove("continue.txt");
    }
}

void mousePressed() {
    if (currentScene == -1) {
        int action = mm.pressed(mouseX, mouseY);
        if (action == 0) {
            currentScene = 0;
        }
        if (action == 1) {
            currentScene = 1;
        }
        if (action == 2) {
            // Continue
            resetToPrev();
        }
        if (action == 3) {
            // Replay last gameplay
        }
    } else if (currentScene == 0) {
        int action = ls.pressed(mouseX, mouseY);
        if (action == 1) {
            currentScene = 1;
        } else if (action == 2) {
            currentScene = 2;
        } else if (action == 3) {
            currentScene = 3;
        }
    } else if (currentScene == 3) {
        l3.mousePressed(mouseX, mouseY);
    } else if (currentScene == 4) {
        nameInput.clicked(mouseX, mouseY);
        if (won) {
            if (win.pressed(mouseX, mouseY) == -1) {
                currentScene = 0;
            }
        } else {
            if (lose.pressed(mouseX, mouseY) == -1) {
                currentScene = 0;
            }
        }
    }
}

void keyPressed() {
    if (currentScene == 4) {
        nameInput.keyTyped(key);
    }
    if (key == 'w') {
        flag[0] = true;
    } else if (key == 'a') {
        flag[1] = true;
    } else if (key == 's') {
        flag[2] = true;
    } else if (key == 'd') {
        flag[3] = true;
    }
    if (currentScene == 1 || currentScene == 2 || currentScene == 3)
        if (key == 'q') {
            ofstream file1("continue.txt");
            if (file1.is_open()) {
                if (currentScene == 1) {
                    file1 << "level:1" << endl;
                    vector<string> pos = *l1.info();
                    for (const string &s : pos) {
                        //println(""s+s);
                        file1 << s << endl;
                    }
                } else if (currentScene == 2) {
                    file1 << "level:2" << endl;
                    vector<string> pos = *l2.info();
                    for (const string &s : pos) {
                        //println(""s+s);
                        file1 << s << endl;
                    }
//                    l2.info();
                } else if (currentScene == 3) {
                    file1 << "level:3" << endl;
                    vector<string> pos = *l3.info();
                    for (const string &s : pos) {
                        //println(""s+s);
                        file1 << s << endl;
                    }
//                    l3.info()
                }
                file1.flush();
                file1.close();
                cout << "You can continue this session by pressing on continue next time you play.";
                exit(0);
            }
        }
}

void keyReleased() {
    if (key == 'w') {
        flag[0] = false;
    } else if (key == 'a') {
        flag[1] = false;
    } else if (key == 's') {
        flag[2] = false;
    } else if (key == 'd') {
        flag[3] = false;
    }
}