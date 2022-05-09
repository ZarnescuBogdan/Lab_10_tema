//
// Created by Bogdan Zarnescu on 09.05.2022.
//

#include "RepoInFileMoney.h"
#include <fstream>

RepoInFileMoney::RepoInFileMoney() = default;

RepoInFileMoney::RepoInFileMoney(const string &filename) {
    this->filename = filename;
    ifstream f(filename);
    //while (!f.eof()) {
    //    int bills500, bills200, bills100, bills50, bills20, bills10, bills5, bills1;
    //    f >> bills500 >> bills200 >> bills100 >> bills50 >> bills20 >> bills10 >> bills5 >> bills1;
    //    Money money1(bills500, bills200, bills100, bills50, bills20, bills10, bills5, bills1);
    //    this->money = money1;
    //}
    if(!f.eof()) {
        int bills500, bills200, bills100, bills50, bills20, bills10, bills5, bills1;
        f >> bills500 >> bills200 >> bills100 >> bills50 >> bills20 >> bills10 >> bills5 >> bills1;
        Money money1(bills500, bills200, bills100, bills50, bills20, bills10, bills5, bills1);
        this->money = money1;
    }
    f.close();
}

RepoInFileMoney::~RepoInFileMoney() {
    fstream f(this->filename);
    if(f.is_open()) {
        f.close();
    }
}

void RepoInFileMoney::saveToFile() {
    ofstream g(this->filename);
    g << this->money.getRon500() << " " << this->money.getRon200() << " " <<  this->money.getRon100() << " " << this->money.getRon50() << " " << this->money.getRon20() << " " << this->money.getRon10() << " " << this->money.getRon5() << " " << this->money.getRon1();
    g.close();
}

void RepoInFileMoney::updateMoneyFromFile(Money &money1) {
    this->money = money1;
    this->saveToFile();
}

Money RepoInFileMoney::getMoneyFromFile() {
    return this->money;
}
