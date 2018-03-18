//
// Created by LifEorDeatH on 18.3.2018.
//

#ifndef IGRCA_SCOREBOARD_H
#define IGRCA_SCOREBOARD_H

#include <map>

using namespace std;
class Scoreboard{
    PString path;
    std::map<string, string> scores;
public:
    Scoreboard(PString path){
        this->path = path;
    }

    void show(){
        fill(255);
        rect(width/7, 50, width/7*5, height - 100);
    }

    void addResult(PString name, int points){
        ofstream os = ofstream(path.getText(), ios::app);
        os<<name.getText()<<":"<<points<<endl;
        os.close();
    }

    void getResults(){
        scores.clear();
        ifstream is;
        is.open(path.getText());
        if(!is){
            cerr << "Unable to open file "<<path.getText()<<endl;
            exit(1);
        }
        string x = "";
        while(is >> x){
            vector<PString> splot = PString(x).split(':');
            if(splot.at(0).length() > 0 && splot.at(1).length() > 0)
                scores.emplace(splot.at(0).getText(), splot.at(1).getText());
        }
        for (std::map<string,string>::iterator it=scores.begin(); it!=scores.end(); ++it)
            cout << it->first << " => " << it->second << endl;
    }
};

#endif //IGRCA_SCOREBOARD_H
