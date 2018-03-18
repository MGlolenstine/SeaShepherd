//
// Created by notyours on 18/03/18.
//

#ifndef IGRCA_QUESTIONBOX_H
#define IGRCA_QUESTIONBOX_H

class QuestionBox{
    PVector pos;
    PVector size;
    PString question;

    QuestionBox(PString question){
        this->question = question;
        size.x = textWidth(question)+40;
        size.y = size.x;
        pos = PVector(width/2 - size.x/2, height/2 - size.y/2);
    }

    void show(){
        rect(pos.x, pos.y, size.x, size.y);
    }
};

#endif //IGRCA_QUESTIONBOX_H
