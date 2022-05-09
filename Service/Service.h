//
// Created by Bogdan Zarnescu on 05.05.2022.
//

#ifndef LAB_9_LIVE_SERVICE_H
#define LAB_9_LIVE_SERVICE_H

#include "../Repo/RepoInFile.h"
#include "../Repo/RepoInFileMoney.h"

class Service {
private:
    RepoInFile repoInFile;
    RepoInFileMoney repoInFileMoney;
public:
    Service();
    Service(RepoInFile &repoInFile1, RepoInFileMoney &repoInFileMoney1);
    void create(Ticket ticket);
    void update(Ticket oldTicket, Ticket newTicket);
    void delete1(Ticket ticket);
    Ticket getById(int id);
    vector<Ticket> getAll();
    Money getAllMoney();
    int buyTicket(int id, int noTickets, int bills500, int bills200, int bills100, int bills50, int bills20, int bills10, int bills5, int bills1);
    vector<Ticket> getAllTicketsFromGivenDay(string day);
    void updateMoney(Money money);
    ~Service();
};


#endif //LAB_9_LIVE_SERVICE_H
