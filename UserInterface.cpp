//
// Created by casia on 09.05.2022.
//
#include <iostream>

using namespace std;

#include "UserInterface.h"
#include "Exceptions.h"

UserInterface::UserInterface() {

}

UserInterface::UserInterface(const Service &srv) {
    this->srv = srv;
}

UserInterface::~UserInterface() {

}

void UserInterface::usersMenu() {
    cout << " " << endl;
    cout << " ---- Meniu UTILIZATORI ---- " << endl;
    cout << " " << endl;
    cout << "1. Adauga un utilizator." << endl;
    cout << "2. Sterge un utilizator. " << endl;
    cout << "3. Actualizeaza un utilizator. " << endl;
    cout << "4. Gaseste un utilizator. " << endl;
    cout << "5. Afiseaza toti utilizatorii." << endl;
    cout << "r. Inapoi la meniul principal. " << endl;
    cout << " " << endl;
}

void UserInterface::friendshipMenu() {
    cout << " " << endl;
    cout << "---- Meniu PRIETENIE ----" << endl;
    cout << " " << endl;
    cout << "6. Adauga un prieten." << endl;
    cout << "7. Sterge un prieten." << endl;
    cout << "8. Afiseaza toate prieteniile." << endl;
    cout << "9. Afiseaza toti prietenii unui utilizator. " << endl;
    cout << "r. Inapoi la meniul principal. " << endl;
    cout << " " << endl;
}

void UserInterface::messagesMenu() {
    cout << " " << endl;
    cout << " ---- Meniu MESAJE ----" << endl;
    cout << " " << endl;
    cout << "10. Trimite un mesaj. " << endl;
    cout << "11. Afiseaza toate mesajele. " << endl;
    cout << "12. Sterge un mesaj." << endl;
    cout << "13. Afiseaza mesajele dintre doi utilizatori." << endl;
    cout << "r. Inapoi la meniul principal. " << endl;
    cout << " " << endl;
}

void UserInterface::eventsMenu() {
    cout << " " << endl;
    cout << "---- Meniu EVENIMENTE ----" << endl;
    cout << " " << endl;
    cout << "14. Adauga eveniment." << endl;
    cout << "15. Sterge eveniment." << endl;
    cout << "16. Afiseaza toate evenimentele." << endl;
    cout << "r. Inapoi la meniul principal. " << endl;
    cout << " " << endl;
}

void UserInterface::showmenu() {
    cout << "---- MENIU PRINCIPAL ----" << endl;
    cout << " " << endl;
    cout << "a. Meniu UTILIZATORI." << endl;
    cout << "b. Meniu PRIETENIE. " << endl;
    cout << "c. Meniu MESAJE." << endl;
    cout << "d. Meniu EVENIMENTE." << endl;
    cout << "x. Exit." << endl;
    cout << " " << endl;
}

void UserInterface::runApp() {
    string opt, option;
    events();
    usersList();
    while (true) {
        showmenu();
        cout << "Introduceti optiunea : ";
        cin >> opt;
        if (opt == "a") {
            while (true) {
                usersMenu();
                cout << "Introduceti optiunea: ";
                cin >> option;
                if (option == "1") {
                    addUser();
                } else if (option == "2") {
                    deleteUser();
                } else if (option == "3") {
                    updateUser();
                } else if (option == "4") {
                    findUser();
                } else if (option == "5") {
                    showAllUsers();
                } else if (option == "r") {
                    cout << " ";
                    break;
                } else cout << "Optiune invalida! " << endl;
            }
        } else if (opt == "b") {
            while (true) {
                friendshipMenu();
                cout << "Introduceti optiunea: ";
                cin >> option;
                if (option == "6") {
                    addFriend();
                } else if (option == "7") {
                    deleteFriend();
                } else if (option == "8") {
                    showAllFriendships();
                } else if (option == "9") {
                    showAllFriendsForAnUser();
                } else if (option == "r") {
                    cout << " ";
                    break;
                } else cout << "Optiune invalida! " << endl;
            }
        } else if (opt == "c") {
            while (true) {
                messagesMenu();
                cout << "Introduceti optiunea: ";
                cin >> option;
                if (option == "10") {
                    sendMessage();
                } else if (option == "11") {
                    showAllMessages();
                } else if (option == "12") {
                    deleteMessage();
                } else if (option == "13") {
                    showAllMessagesBetweenTwoUsers();
                } else if (option == "r") {
                    cout << " ";
                    break;
                } else cout << "Optiune invalida! " << endl;

            }
        } else if (opt == "d") {
            while (true) {
                eventsMenu();
                cout << "Introduceti optiunea: ";
                cin >> option;
                if (option == "14") {
                    addEvent();
                } else if (option == "15") {
                    removeEvent();
                } else if (option == "16") {
                    showAllEvents();
                } else if (option == "r") {
                    cout << " ";
                    break;
                } else cout << "Optiune invalida! " << endl;
            }
        } else if (opt == "x") {
            cout << " ";
            break;
        } else cout << "Optiune invalida!";
    }
}

void UserInterface::addUser() {
    int id;
    string name;
    int age;

    cout << "Introduceti ID-ul: ";
    cin >> id;
    cout << "Introduceti numele: ";
    std::getline(std::cin >> std::ws, name);
    cout << "Introduceti varsta: ";
    cin >> age;

    try {
        this->srv.addUser(id, name, age);
        cout << "Adaugarea a fost efectuata cu succes! " << endl;
    }
    catch (MyException &re) {
        cout << re.getMessage();
    }
}

void UserInterface::deleteUser() {
    int id;

    cout << "Introduceti ID-ul: ";
    cin >> id;

    try {
        this->srv.deleteUser(id);
        cout << "Stergerea a fost efectuata cu succes! " << endl;
    }
    catch (MyException &re) {
        cout << re.getMessage();
    }
}

void UserInterface::updateUser() {
    int id;

    cout << "Introduceti ID-ul: ";
    cin >> id;

    string newName;
    int newAge;

    cout << "Introduceti noul nume: ";
    std::getline(std::cin >> std::ws, newName);
    cout << "Introduceti noua varsta: ";
    cin >> newAge;

    try {
        this->srv.update(id, newName, newAge);
        cout << "Actualizarea a fost efectuata cu succes!" << endl;
    }
    catch (MyException &re) {
        cout << re.getMessage();
    }
}

void UserInterface::findUser() {
    int id;
    string name;
    int age;

    cout << "Introduceti ID-ul: ";
    cin >> id;
    cout << "Introduceti numele: ";
    std::getline(std::cin >> std::ws, name);
    cout << "Introduceti varsta: ";
    cin >> age;

    bool ok;
    ok = this->srv.find(id, name, age);
    if (ok == 1) cout << "Utilizatorul exista!" << endl;
    else cout << "Utilizatorul nu exista!" << endl;
}

void UserInterface::showAllUsers() {
    vector<User> result = this->srv.getAllUsers();
    for (auto &i: result) {
        cout << "ID: " << i.getId() << ";    Nume: " << i.getName()
             << ";    Varsta: " << i.getAge() << ";" << endl;
    }
}

void UserInterface::usersList() {
    this->srv.addUser(1, "Casi Apostol", 19);
    this->srv.addUser(2, "Bia Anton", 19);
    this->srv.addUser(3, "Cristina Bagacean", 19);
    this->srv.addUser(4, "Sorana Barbulet", 20);
    this->srv.addUser(5, "Ioana Onisoru", 19);
    this->srv.addUser(6, "Stefania Vartic", 21);
    this->srv.addUser(7, "Mara Olariu", 18);
    this->srv.addUser(8, "Irina Mihalachi", 20);
    this->srv.addUser(9, "Stefana Barliba", 21);
    this->srv.addUser(10, "Maria Adumitroae", 19);
    this->srv.addUser(11, "Eliza Nechita", 9);
    this->srv.addUser(12, "Sebi Nechita", 17);
    this->srv.addUser(13, "Elena Nechita", 40);
    this->srv.addUser(14, "Mihaela Apostol", 47);
    this->srv.addUser(15, "Razvan Nechita", 25);

    User u1(1, "Casi Apostol", 19);
    User u2(2, "Bia Anton", 19);
    User u3(3, "Cristina Bagacean", 19);
    User u4(4, "Sorana Barbulet", 20);
    User u5(5, "Ioana Onisoru", 19);
    User u6(6, "Stefania Vartic", 21);
    User u7(7, "Mara Olariu", 18);
    User u8(8, "Irina Mihalachi", 20);
    User u9(9, "Stefana Barliba", 21);
    User u10(10, "Maria Adumitroae", 19);
    User u11(11, "Eliza Nechita", 9);
    User u12(12, "Sebi Nechita", 17);
    User u13(13, "Elena Nechita", 40);
    User u14(14, "Mihaela Apostol", 47);
    User u15(15, "Razvan Nechita", 25);

    this->srv.addFriendship(u1, u2);
    this->srv.addFriendship(u1, u3);
    this->srv.addFriendship(u2, u3);
    this->srv.addFriendship(u4, u5);
    this->srv.addFriendship(u6, u7);
    this->srv.addFriendship(u5, u6);
    this->srv.addFriendship(u4, u12);
    this->srv.addFriendship(u11, u12);
    this->srv.addFriendship(u10, u11);
    this->srv.addFriendship(u8, u13);
    this->srv.addFriendship(u9, u15);
    this->srv.addFriendship(u10, u14);
    this->srv.addFriendship(u11, u15);
    this->srv.addFriendship(u8, u10);
    this->srv.addFriendship(u7, u9);
    this->srv.addFriendship(u1, u13);
    this->srv.addFriendship(u13, u14);
    this->srv.addFriendship(u1, u14);

    this->srv.sendMessage(u1, u2, "Buna! Iti doresc o zi minunata!");
    this->srv.sendMessage(u2, u1, "Buna! Si tie la fel!");
    this->srv.sendMessage(u4, u5, "Ce zi frumoasa afara! Nu crezi?");
    this->srv.sendMessage(u5, u4, "Ba da! Ar fi bine sa mergeme la o plimbare!");
    this->srv.sendMessage(u4, u5, "Cu bicicletele?");
    this->srv.sendMessage(u5, u4, "Da, sunt de acord.");
    this->srv.sendMessage(u1, u3, "Hei!");
    this->srv.sendMessage(u3, u2, "Hello!");
    this->srv.sendMessage(u9, u15, "Ai vazut campionatul de fotbal de anul acesta?");
    this->srv.sendMessage(u15, u9, "M-am uitat doar la un meci.");
    this->srv.sendMessage(u13, u1, "Am plecat pana la magazin.");
    this->srv.sendMessage(u1, u13, "Te rog, cumpara-mi si mie o ciocolata.");
    this->srv.sendMessage(u13, u1, "Bine!");
}

void UserInterface::events() {
    this->srv.addEvent("Training Public Speacking", "CCS", 40);
    this->srv.addEvent("Training Marketing", "CCS", 50);
    this->srv.addEvent("Balul bobocilor", "Cluj Arena", 125);
    this->srv.addEvent("Prezentare de carte", "CCS", 25);
}

void UserInterface::addFriend() {

    try {
        int id1, id2;

        cout << "Introduceti ID-ul dumneavoastra: ";
        cin >> id1;

        for (int i = 0; i < this->srv.getNumberOfUsers(); i++) {
            if (this->srv.getAllUsers()[i].getId() == id1) {
                User u1 = this->srv.getUser(i);
                cout << "Introduceti ID-ul viitorului prieten: ";
                cin >> id2;
                for (int j = 0; j < this->srv.getNumberOfUsers(); j++) {
                    if (this->srv.getAllUsers()[j].getId() == id2) {
                        User u2 = this->srv.getUser(j);
                        this->srv.addFriendship(u1, u2);
                    }
                }
            }
        }
        cout << "Adaugarea a fost efectuata cu succes!" << endl;
    }
    catch (MyException &re) {
        cout << re.getMessage();
    }

}


void UserInterface::deleteFriend() {

    try {
        int id1, id2;
        vector<User> result;

        cout << "Introduceti ID-ul dumneavoastra: ";
        cin >> id1;

        for (int i = 0; i < this->srv.getNumberOfUsers(); i++) {
            if (this->srv.getAllUsers()[i].getId() == id1) {
                User u1 = this->srv.getUser(i);
                cout << "Introduceti ID-ul prietenului: ";
                cin >> id2;
                for (int j = 0; j < this->srv.getNumberOfUsers(); j++) {
                    if (this->srv.getAllUsers()[j].getId() == id2) {
                        User u2 = this->srv.getUser(j);
                        this->srv.deleteFriendship(u1, u2);
                    }
                }
            }
        }
        cout << "Stergerea a fost efectuata cu succes!" << endl;
    }
    catch (MyException &re) {
        cout << re.getMessage();
    }
}

void UserInterface::showAllFriendships() {
    vector<Friendship> result = this->srv.getAllFrienships();
    for (auto &i: result) {
        cout << i.getFirstUser().getName() << " (ID: " << i.getFirstUser().getId()
             << "; Varsta: " << i.getFirstUser().getAge() << ") ---------> " << i.getSecondUser().getName()
             << " (ID: " << i.getSecondUser().getId() << "; Varsta: " << i.getSecondUser().getAge() << ");" << endl;
    }
}

void UserInterface::showAllFriendsForAnUser() {
    int id;
    cout << "Introduceti ID-ul utilizatorului: ";
    cin >> id;

    vector<User> result = this->srv.getFriendsForAnUser(id);

    for (int i = 0; i < this->srv.getAllUsers().size(); i++) {
        if (this->srv.getAllUsers()[i].getId() == id) {
            User u = this->srv.getUser(i);
            if (result.empty()) {
                cout << "User-ul cu ID-ul " << u.getId() << ", numele: " << u.getName() << " si varsta: "
                     << u.getAge() << " nu are prieteni." << endl;
            } else {
                cout << "Prietenii user-ului cu ID-ul " << u.getId() << ", numele: " << u.getName()
                     << " si varsta: "
                     << u.getAge() << " sunt:" << endl;
                for (auto &j: result) {
                    cout << "ID: " << j.getId() << ", nume: " << j.getName() << ", varsta: " << j.getAge() << endl;
                }
            }
        }
    }
}

void UserInterface::sendMessage() {
    try {
        int id1, id2;
        string msg;

        cout << "Introduceti-va ID-ul: ";
        cin >> id1;

        for (int i = 0; i < this->srv.getAllUsers().size(); i++) {
            if (this->srv.getAllUsers()[i].getId() == id1) {
                User u1 = this->srv.getUser(i);
                cout << "Cui doriti sa-i trimiteti un mesaj? Introduceti id-ul persoanei: ";
                cin >> id2;
                for (int j = 0; j < this->srv.getAllUsers().size(); j++) {
                    if (this->srv.getAllUsers()[j].getId() == id2) {
                        User u2 = this->srv.getUser(j);
                        bool ok = this->srv.isAFriend(id1, id2);
                        if (ok == 1) {
                            cout << "Introduceti mesajul: ";
                            std::getline(std::cin >> std::ws, msg);
                            this->srv.sendMessage(u1, u2, msg);
                        } else
                            throw MyException(
                                    "Nu puteti trimite mesaje unei persoane cu care nu sunteti prieten! \n");
                    }
                }
            }

        }
    }
    catch (MyException &re) {
        cout << re.getMessage();
    }

}

void UserInterface::showAllMessages() {
    vector<Messages> result = this->srv.getAllMessages();
    for (auto &i: result) {
        cout << i.getFirstUser().getName() << " -> "
             << i.getSecondUser().getName() << " : " <<
             i.getMessage() << endl;
    }
}

void UserInterface::deleteMessage() {

    int id1, id2;
    string mesaj;
    cout << "Introduceti-va ID-ul: ";
    cin >> id1;
    for (int i = 0; i < this->srv.getNumberOfUsers(); i++) {
        if (this->srv.getAllUsers()[i].getId() == id1) {
            User u1 = this->srv.getUser(i);
            cout << "Introduceti al ID-ul prietenului cu care ati conversat: ";
            cin >> id2;
            for (int j = 0; j < this->srv.getNumberOfUsers(); j++) {
                if (this->srv.getAllUsers()[j].getId() == id2) {
                    User u2 = this->srv.getUser(j);
                    vector<Messages> msg = this->srv.getAllMsgBetweenTwoUsers(u1, u2);
                    if (msg.empty()) {
                        cout << "Nu exista mesaje intre " << u1.getName() << " si " << u2.getName() << endl;
                    } else {
                        cout << " " << endl;
                        cout << "Mesajele dintre " << u1.getName() << " si " << u2.getName() << " sunt: " << endl;
                        cout << " " << endl;
                        for (auto &k: msg) {
                            cout << k.getFirstUser().getName() << ": " << k.getMessage() << endl;
                        }
                        cout << endl;
                        cout << "!!! Puteti sterge doar mesajele trimise de dumneavoastra! (" << u1.getName() << ")"
                             << endl;
                        cout << "Introduceti mesajul pe care doriti sa il stergeti: ";
                        std::getline(std::cin >> std::ws, mesaj);
                        this->srv.deleteMessage(u1, u2, mesaj);
                    }
                }
            }
        }
    }
}

void UserInterface::showAllMessagesBetweenTwoUsers() {
    int id1, id2;
    cout << "Introduceti primul ID: ";
    cin >> id1;
    for (int i = 0; i < this->srv.getNumberOfUsers(); i++) {
        if (this->srv.getAllUsers()[i].getId() == id1) {
            User u1 = this->srv.getUser(i);
            cout << "Introduceti al doilea ID: ";
            cin >> id2;
            for (int j = 0; j < this->srv.getNumberOfUsers(); j++) {
                if (this->srv.getAllUsers()[j].getId() == id2) {
                    User u2 = this->srv.getUser(j);
                    vector<Messages> msg = this->srv.getAllMsgBetweenTwoUsers(u1, u2);
                    cout << u1.getName() << " <------> " << u2.getName() << ": " << endl;
                    if (msg.empty()) {
                        cout << "Nu exista mesaje!" << endl;
                    } else {
                        for (auto &k: msg) {
                            cout << k.getFirstUser().getName() << ": " << k.getMessage() << endl;
                        }
                    }
                }
            }
        }
    }

}

void UserInterface::addEvent() {
    string nume, locatie;
    int nrParticipanti;
    cout << "Introduceti numele evenimentului: ";
    std::getline(std::cin >> std::ws, nume);
    cout << "Introduceti locatia evenimentului: ";
    std::getline(std::cin >> std::ws, locatie);
    cout << "Introduceti numarul de participanti admisi: ";
    cin >> nrParticipanti;
    this->srv.addEvent(nume, locatie, nrParticipanti);
    cout << "Adaugarea a fost efectuata cu succes!" << endl;
}

void UserInterface::removeEvent() {
    string nume, locatie;
    int nrParticipanti;
    cout << "Introduceti numele evenimentului: ";
    std::getline(std::cin >> std::ws, nume);
    cout << "Introduceti locatia evenimentului: ";
    std::getline(std::cin >> std::ws, locatie);
    cout << "Introduceti numarul de participanti admisi: ";
    cin >> nrParticipanti;
    this->srv.deleteEvent(nume, locatie, nrParticipanti);
    cout << "Stergerea a fost efectuata cu succes!" << endl;
}

void UserInterface::showAllEvents() {
    this->srv.getAllEvents();
}
