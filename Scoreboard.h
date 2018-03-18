//
// Created by LifEorDeatH on 18.3.2018.
//

#ifndef IGRCA_SCOREBOARD_H
#define IGRCA_SCOREBOARD_H

#include <map>

using namespace std;

class Scoreboard {
    PString path;
    std::vector<string> scores;
public:
    Scoreboard() {}

    Scoreboard(PString path) {
        this->path = path;
    }

    void show() {
        int maxAmountOfScores = (height-100)/20;
        fill(255);
        rect(width / 7, 50, width / 7 * 5, height - 100);
        int counter = 0;
        pushMatrix();
        translate(width / 7, 50, 0);
        if(scores.size() > 1) {
            std::sort(scores.begin(), scores.end());
            reverse(scores.begin(), scores.end());
        }
        for(string s : scores){
            if(counter >= maxAmountOfScores){
                popMatrix();
                return;
            }
            std::vector<PString> splot = PString(s).split(':');
            fill(255);
            rect(0, counter * 20, width / 7 * 5, 20);
            fill(0);
            text(splot.at(1), 0, ((counter + 1) * 20) - 5);
            text(splot.at(0), (width / 7 * 5) - textWidth(splot.at(0)), ((counter + 1) * 20) - 5);
            counter++;
        }
        popMatrix();
    }

    void addResult(PString name, int points) {
        ofstream os = ofstream(path.getText(), ios::app);
        os << name.getText() << ":" << points << endl;
        os.close();
    }

    void getResults() {
        scores.clear();
        ifstream is;
        is.open(path.getText());
        if (!is) {
            cerr << "Unable to open file " << path.getText() << endl;
            exit(1);
        }
        string x = "";
        while (is >> x) {
            vector<PString> splot = PString(x).split(':');
            scores.emplace_back(splot.at(1).getText()+":"+splot.at(0).getText());
        }
        is.close();
    }
};

#endif //IGRCA_SCOREBOARD_H
