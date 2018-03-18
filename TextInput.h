//
// Created by LifEorDeatH on 18.3.2018.
//

#ifndef IGRCA_TEXTINPUT_H
#define IGRCA_TEXTINPUT_H

class TextInput {
    PString string = ""s;
    PVector pos;
    PVector size;
    Button submit;
    int lengthDisplayed = 10;
public:
    TextInput() {}

    TextInput(int x, int y, int w, int h) {
        pos = PVector(x, y);
        size = PVector(w, h);
        lengthDisplayed = (size.x - 2)/textWidth(PString("1"));
        submit = Button();
    }

    void show() {
        fill(255);
        rect(pos.x, pos.y, size.x, size.y);
        fill(0);
        if(string.length() == 0){
            text("Vnesi svoje ime..."s, pos.x + 1, pos.y + 15);
        }
        if(string.length() > lengthDisplayed) {
            PString tmpstring = string.substr(string.length() - lengthDisplayed, lengthDisplayed);
            text(tmpstring, pos.x + 1, pos.y + 15);
        }else{
            text(string, pos.x + 1, pos.y + 15);
        }
    }

    void keyTyped(char key) {
        if(key == 8){
            string = string.substr(0, string.length()-1);
        }else {
            string = string + key;
        }
    }
};

#endif //IGRCA_TEXTINPUT_H
