//
// Created by casia on 09.05.2022.
//

#ifndef SDA_PROIECT_USERINTERFACE_H
#define SDA_PROIECT_USERINTERFACE_H
#include "Service.h"

class UserInterface {
private:
    Service srv;
public:
    ///Constructor implicit, fara parametri;
    UserInterface();

    /// Constructor cu parametri;
    /// \param srv service-ul;
    explicit UserInterface(const Service& srv);

    ///Destructor;
    ~UserInterface();

    /// Afiseaza meniul principal;
    static void showmenu();

    /// Ruleaza aplicatia;
    void runApp();

    /// Lista predefinita de utilizatori;
    void usersList();

    /// Multime predefinita de evenimente;
    void events();

    /// Afiseaza meniul pentru utilizatori;
    static void usersMenu();

    /// Afiseaza meniul pentru prietenie;
    static void friendshipMenu();

    /// Afiseaza meniul pentru mesaje;
    static void messagesMenu();

    /// Afiseaza meniul pentru evenimente;
    static void eventsMenu();

private:
    /// Adauga un utilizator;
    void addUser();

    /// Actualizeaza un utilizator;
    void updateUser();

    /// Sterge un utilizator;
    void deleteUser();

    /// Afiseaza toti utilizatorii;
    void showAllUsers();

    /// Cauta un utilizator;
    void findUser();

    /// Adauga un prieten;
    void addFriend();

    /// Sterge un prieten;
    void deleteFriend();

    /// Afiseaza toate relatiile de prietenie;
    void showAllFriendships();

    /// Afiseaza toti prietenii unui utilizator;
    void showAllFriendsForAnUser();

    /// Trimite un mesaj;
    void sendMessage();

    /// Sterge un mesaj;
    void deleteMessage();

    /// Afiseaza toate mesajele;
    void showAllMessages();

    /// Afiseaza toate mesajele dintre doi utilizatori;
    void showAllMessagesBetweenTwoUsers();

    /// Adauga un eveniment;
    void addEvent();

    /// Sterge un eveniment;
    void removeEvent();

    /// Afiseaz toate evenimente in ordinea crescatoare a numarului de participanti;
    void showAllEvents();
};

#endif //SDA_PROIECT_USERINTERFACE_H
