//
// Created by Bogdan Zarnescu on 05.05.2022.
//

#include "Service.h"
#include <iostream>

Service::Service() = default;

Service::Service(RepoInFile &repoInFile1, RepoInFileMoney &repoInFileMoney1) {
    this->repoInFile = repoInFile1;
    this->repoInFileMoney = repoInFileMoney1;
}

void Service::create(Ticket ticket) {
    this->repoInFile.addTicketInFile(ticket);
}

void Service::update(Ticket oldTicket, Ticket newTicket) {
    this->repoInFile.updateFromFile(oldTicket, newTicket);
}

void Service::delete1(Ticket ticket) {
    this->repoInFile.deleteFromFile(ticket);
}

Ticket Service::getById(int id) {
    return this->repoInFile.getTicketByIdFromFile(id);
}

vector<Ticket> Service::getAll() {
    return this->repoInFile.getAllFromFile();
}

int Service::buyTicket(int id, int noTickets, int bills500, int bills200, int bills100, int bills50, int bills20, int bills10, int bills5, int bills1) {
    int price = noTickets * this->repoInFile.getTicketByIdFromFile(id).getPrice(), sum = 500 * bills500 + 200 * bills200 + 100 * bills100 + 50 * bills50 + 20 * bills20 + 10 * bills10 + 5 * bills5 + bills1;
    if(this->repoInFile.find(this->repoInFile.getTicketByIdFromFile(id))) {
        if(sum < price) {
            cout << "The amount introduced is not enough!";
            return 0;
        }
        int change = sum - price;
        int change1 = change;
        int chg500 = min(change1 / 500, this->repoInFileMoney.getMoneyFromFile().getRon500());
        int newBills500 = this->repoInFileMoney.getMoneyFromFile().getRon500() - chg500 + bills500;
        change1 -= 500 * chg500;

        int chg200 = min(change1 / 200, this->repoInFileMoney.getMoneyFromFile().getRon200());
        int newBills200 = this->repoInFileMoney.getMoneyFromFile().getRon200() - chg200 + bills200;
        change1 -= 200 * chg200;

        int chg100 = min(change1 / 100, this->repoInFileMoney.getMoneyFromFile().getRon100());
        int newBills100 = this->repoInFileMoney.getMoneyFromFile().getRon100() - chg100 + bills100;
        change1 -= 100 * chg100;

        int chg50 = min(change1 / 50, this->repoInFileMoney.getMoneyFromFile().getRon50());
        int newBills50 = this->repoInFileMoney.getMoneyFromFile().getRon50() - chg50 + bills50;
        change1 -= 50 * chg50;

        int chg20 = min(change1 / 20, this->repoInFileMoney.getMoneyFromFile().getRon20());
        int newBills20 = this->repoInFileMoney.getMoneyFromFile().getRon20() - chg20 + bills20;
        change1 -= 20 * chg20;

        int chg10 = min(change1 / 10, this->repoInFileMoney.getMoneyFromFile().getRon10());
        int newBills10 = this->repoInFileMoney.getMoneyFromFile().getRon10() - chg10 + bills10;
        change1 -= 10 * chg10;

        int chg5 = min(change1 / 5, this->repoInFileMoney.getMoneyFromFile().getRon5());
        int newBills5 = this->repoInFileMoney.getMoneyFromFile().getRon5() - chg5 + bills5;
        change1 -= 5 * chg5;

        int chg1 = min(change1, this->repoInFileMoney.getMoneyFromFile().getRon1());
        int newBills1 = this->repoInFileMoney.getMoneyFromFile().getRon1() - chg1 + bills1;
        change1 -= chg1;

        Ticket ticket = this->repoInFile.getTicketByIdFromFile(id);
        Ticket newTicket = ticket;
        newTicket.setStock(newTicket.getStock() - noTickets);
        Money money(newBills500, newBills200, newBills100, newBills50, newBills20, newBills10, newBills5, newBills1);
        this->repoInFile.updateFromFile(ticket, newTicket);
        this->repoInFileMoney.updateMoneyFromFile(money);

        if(change1 == 0) {
            cout << "The change has been made!";
            return change;
        } else {
            cout << "The maximum possible change has been made!";
            return sum - change;
        }

    } else {
        return 0;
    }
}

vector<Ticket> Service::getAllTicketsFromGivenDay(string day) {
    vector<Ticket> tickets;
    for(Ticket &ticket: this->repoInFile.getAllFromFile()) {
        if(ticket.getDay() == day) {
            tickets.push_back(ticket);
        }
    }
    return tickets;
}

Money Service::getAllMoney() {
    return this->repoInFileMoney.getMoneyFromFile();
}

void Service::updateMoney(Money money) {
    this->repoInFileMoney.updateMoneyFromFile(money);
}

Service::~Service() = default;
