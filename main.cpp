#include "Tests/tests.h"
#include "UI/UI.h"

using namespace std;

int main() {
    testAll();
    RepoInFile repoInFile(R"(/Users/bogdanzarnescu/Desktop/Facultate-OOP/Lab-10-live/tickets.txt)");
    RepoInFileMoney repoInFileMoney(R"(/Users/bogdanzarnescu/Desktop/Facultate-OOP/Lab-10-live/money.txt)");
    Service service(repoInFile, repoInFileMoney);
    UI ui(service);
    ui.runMenu();
    return 0;
}
