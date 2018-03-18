//
// Created by notyours on 18/03/18.
//

#ifndef IGRCA_QUESTIONBOX_H
#define IGRCA_QUESTIONBOX_H

class QuestionBox{
    PVector pos{};
    PVector size{};
    PString question{};
    Button correct = Button(static_cast<int>(size.x / 5 + pos.x), static_cast<int>(size.y - 5), "Correct"s, 1, true);
    Button wrong = Button(static_cast<int>(size.x / 5 * 3 + pos.x), static_cast<int>(size.y - 5), "Incorrect"s, 0, true);
    bool answer = false;
    VegovecBoat *b = nullptr;
public:
    QuestionBox(const PString &question, bool answer, VegovecBoat *b){
        this->question = question;
        size.x = textWidth(question)+40;
        size.y = size.x;
        pos = PVector(width/2 - size.x/2, height/2 - size.y/2);
        correct = Button(static_cast<int>(size.x / 5 + pos.x), static_cast<int>(pos.y+size.y - 25), "Correct"s, 1, true);
        wrong = Button(static_cast<int>(size.x / 5 * 4 + pos.x), static_cast<int>(pos.y+size.y - 25), "Incorrect"s, 0, true);
        this->answer = answer;
        this->b = b;
    }

    void show(){
        fill(255);
        rect(pos.x, pos.y, size.x, size.y);
        fill(0);
        text(question, static_cast<int>((pos.x + size.x / 2)-textWidth(question)/2), pos.y+15);
        wrong.show();
        correct.show();
    }

    int clicked(int mouseX, int mouseY){
        if(correct.pressed(mouseX, mouseY) != -2){
            if(answer){
                return 1;
            }else{
                return 0;
            }
        }
        if(wrong.pressed(mouseX, mouseY) != -2){
            if(!answer){
                return 1;
            }else{
                return 0;
            }
        }
        return -1;
    }
};

#endif //IGRCA_QUESTIONBOX_H
