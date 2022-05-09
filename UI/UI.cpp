//
// Created by Bogdan Zarnescu on 05.05.2022.
//

#include "UI.h"
#include <iostream>

using namespace std;

UI::UI() = default;

UI::UI(Service &service1) {
    this->service = service1;
}

void UI::runMenu() {
    bool ok = true;
    while (ok) {
        cout << endl;
        cout << "1. Add a ticket." << endl;
        cout << "2. Delete a ticket." << endl;
        cout << "3. Update a ticket." << endl;
        cout << "4. Buy a ticket." << endl;
        cout << "5. Show all tickets a from given day." << endl;
        cout << "6. Update money from the bank." << endl;
        cout << "s. Show all tickets." << endl;
        cout << "m. Show the money from the bank." << endl;
        cout << "x. Exit." << endl;
        char option;
        cout << "Give option: ";
        cin >> option;
        switch (option) {
            case '1': {
                this->addTicket();
                break;
            }
            case '2': {
                this->deleteTicket();
                break;
            }
            case '3': {
                this->updateTicket();
                break;
            }
            case '4': {
                this->buyTicket();
                break;
            }
            case '5': {
                this->showAllTicketsFromGivenDay();
                break;
            }
            case '6': {
                this->updateMoney();
                break;
            }
            case 's': {
                this->showAllTickets();
                break;
            }
            case 'm': {
                this->showAllBills();
                break;
            }
            case 'x':
                ok = false;
                break;
            default:
                cout << "Wrong option! Try again!" << endl;
        }
    }
}

void UI::addTicket() {
    int id, price, stock;
    string code, day;
    cout << "Give id: ";
    cin >> id;
    cout << "Give code: ";
    cin >> code;
    cout << "Give day: ";
    cin >> day;
    cout << "Give price: ";
    cin >> price;
    cout << "Give stock: ";
    cin >> stock;

    Ticket ticket(id, code, day, price, stock);
    this->service.create(ticket);
}

void UI::showAllTickets() {
    for(Ticket &ticket: this->service.getAll()) {
        cout << "Ticket." << ticket.getId() << ": code(" << ticket.getCode() << "), day(" << ticket.getDay() << "), price(" << ticket.getPrice() << "), stock(" << ticket.getStock() << ")" << endl;
    }
}

void UI::deleteTicket() {
    int id;
    cout << "Give id to be deleted: ";
    cin >> id;
    for(Ticket &ticket: this->service.getAll()) {
        if(ticket.getId() == id) {
            this->service.delete1(ticket);
        }
    }
}

void UI::updateTicket() {
    int id, id1, price1, stock1;
    cout << "Give id for the ticket to be updated: ";
    cin >> id;
    string code1, day1;
    cout << "Give the new id: ";
    cin >> id1;
    cout << "Give the new code: ";
    cin >> code1;
    cout << "Give the new day: ";
    cin >> day1;
    cout << "Give the new price: ";
    cin >> price1;
    cout << "Give the new stock: ";
    cin >> stock1;
    Ticket ticket(id1, code1, day1, price1, stock1);
    for(Ticket &ticket1: this->service.getAll()) {
        if(ticket1.getId() == id) {
            this->service.update(ticket1, ticket);
        }
    }
}

void UI::buyTicket() {
    int id, noTickets, bills500, bills200, bills100, bills50, bills20, bills10, bills5, bills1;
    cout << "Give id for the ticket to be bought: ";
    cin >> id;
    Ticket ticket = this->service.getById(id);
    cout << "Give the number of tickets wanted: ";
    cin >> noTickets;
    cout << "Enter the amount of money(500RON, 200RON, 100RON, 50RON, 20RON, 10RON, 5RON, 1RON), in line: " << endl;
    cout << "500RON bills: ";
    cin >> bills500;
    cout << "200RON bills: ";
    cin >> bills200;
    cout << "100RON bills: ";
    cin >> bills100;
    cout << "50RON bills: ";
    cin >> bills50;
    cout << "20RON bills: ";
    cin >> bills20;
    cout << "10RON bills: ";
    cin >> bills10;
    cout << "5RON bills: ";
    cin >> bills5;
    cout << "1RON bills: ";
    cin >> bills1;
    cout << this->service.buyTicket(id, noTickets, bills500, bills200, bills100, bills50, bills20, bills10, bills5, bills1);
}

void UI::showAllTicketsFromGivenDay() {
    string day;
    cout << "Give the day you are looking for: ";
    cin >> day;
    vector<Ticket> tickets = this->service.getAllTicketsFromGivenDay(day);
    for(Ticket &ticket: tickets) {
        cout << "Ticket." << ticket.getId() << ": code(" << ticket.getCode() << "), day(" << ticket.getDay() << "), price(" << ticket.getPrice() << "), stock("  << ticket.getStock() << ")" << endl;
    }
}

void UI::showAllBills() {
    cout << "The money from the bank: " << endl;
    Money money = this->service.getAllMoney();
    cout << "500RON bills: " << money.getRon500() << endl;
    cout << "200RON bills: " << money.getRon200() << endl;
    cout << "100RON bills: " << money.getRon100() << endl;
    cout << "50RON bills: " << money.getRon50() << endl;
    cout << "20RON bills: " << money.getRon20() << endl;
    cout << "10RON bills: " << money.getRon10() << endl;
    cout << "5RON bills: " << money.getRon5() << endl;
    cout << "1RON bills: " << money.getRon1() << endl;
}

void UI::updateMoney() {
    int bills500, bills200, bills100, bills50, bills20, bills10, bills5, bills1;
    cout << "Give the bils500: ";
    cin >> bills500;
    cout << "Give the bils200: ";
    cin >> bills200;
    cout << "Give the bils100: ";
    cin >> bills100;
    cout << "Give the bils50: ";
    cin >> bills50;
    cout << "Give the bils20: ";
    cin >> bills20;
    cout << "Give the bils10: ";
    cin >> bills10;
    cout << "Give the bils5: ";
    cin >> bills5;
    cout << "Give the bils1: ";
    cin >> bills1;
    Money money(bills500, bills200, bills100, bills50, bills20, bills10, bills5, bills1);
    this->service.updateMoney(money);
}

UI::~UI() = default;
