//
// Created by Bogdan Zarnescu on 05.05.2022.
//

#include "Money.h"

Money::Money() {
    this->ron500 = 10;
    this->ron200 = 10;
    this->ron100 = 10;
    this->ron50 = 15;
    this->ron20 = 15;
    this->ron10 = 15;
    this->ron5 = 25;
    this->ron1 = 40;
}

Money::Money(int ron500, int ron200, int ron100, int ron50, int ron20, int ron10, int ron5, int ron1) {
    this->ron500 = ron500;
    this->ron200 = ron200;
    this->ron100 = ron100;
    this->ron50 = ron50;
    this->ron20 = ron20;
    this->ron10 = ron10;
    this->ron5 = ron5;
    this->ron1 = ron1;
}

int Money::getRon500() {
    return this->ron500;
}

int Money::getRon200() {
    return this->ron200;
}

int Money::getRon100() {
    return this->ron100;
}

int Money::getRon50() {
    return this->ron50;
}

int Money::getRon20() {
    return this->ron20;
}

int Money::getRon10() {
    return this->ron10;
}

int Money::getRon5() {
    return this->ron5;
}

int Money::getRon1() {
    return this->ron1;
}

void Money::setRon500(int ron500) {
    this->ron500 = ron500;
}

void Money::setRon200(int ron200) {
    this->ron200 = ron200;
}

void Money::setRon100(int ron100) {
    this->ron100 = ron100;
}

void Money::setRon50(int ron50) {
    this->ron50 = ron50;
}

void Money::setRon20(int ron20) {
    this->ron20 = ron20;
}

void Money::setRon10(int ron10) {
    this->ron10 = ron10;
}

void Money::setRon5(int ron5) {
    this->ron5 = ron5;
}

void Money::setRon1(int ron1) {
    this->ron1 = ron1;
}

Money &Money::operator=(const Money &money) {
    this->setRon500(money.ron500);
    this->setRon200(money.ron200);
    this->setRon100(money.ron100);
    this->setRon50(money.ron50);
    this->setRon20(money.ron20);
    this->setRon10(money.ron10);
    this->setRon5(money.ron5);
    this->setRon1(money.ron1);
    return *this;
}

bool Money::operator==(const Money &money) {
    return ((this->ron500 == money.ron500) and (this->ron200 == money.ron200) and (this->ron100 == money.ron100) and (this->ron50 == money.ron50) and (this->ron20 == money.ron20) and (this->ron10 == money.ron10) and
            (this->ron5 == money.ron5) and (this->ron1 == money.ron1));
}

Money::~Money() = default;
