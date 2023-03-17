//
// Created by casia on 09.05.2022.
//

#ifndef SDA_PROIECT_SERVICE_H
#define SDA_PROIECT_SERVICE_H
#include "Repository.h"
#include "Friendship.h"
#include "Messages.h"
#include "RepoEvent.h"

class Service {
private:
    Repo<User> repo;
    Repo<Friendship> repoF;
    Repo<Messages> repoM;
    RepoEvent<Event> repoE;
public:

    ///Constructor fara parametri;
    Service();

    /// Constructor cu parametri;
    /// \param repo repository pentru clasa "User";
    /// \param repof repository pentru clasa "Friendship";
    /// \param repoM repository pentru clasa "Message";
    Service(const Repo<User>& repo, const Repo<Friendship>& repof, const Repo<Messages>& repom, const RepoEvent<Event>& repoe);

    /// Destructor;
    ~Service();

    /// Adauga un utilizator;
    /// \param id ID-ul utilizatorului;
    /// \param nume numele utilizatorului;
    /// \param varsta varsta utilizatorului;
    void addUser(int id, string nume, int varsta);

    /// Sterge un utilizator dupa ID;
    /// \param id ID-ul utilizatorului;
    void deleteUser(int id);

    /// Actualizeaza un utilizator dupa ID;
    /// \param id ID-ul utilizatorului;
    /// \param idNou noul ID al utilizatorului;
    /// \param numeNou noul nume al utilizatorului;
    /// \param varstaNoua noua varsta a utilizatorului;
    void update(int id, string numeNou, int varstaNoua);

    /// Cauta un utilizator dupa ID, nume si varsta;
    /// \param id ID-ul utilizatorului;
    /// \param nume numele utilizatorului;
    /// \param varsta varsta utilizatorului;
    /// \return true, daca utlilizatorul a fost gasit; false, in caz contrar;
    bool find(int id, string nume, int varsta);

    /// Cauta un utilizator dupa ID;
    /// \param id ID-ul utilizatorului;
    /// \return true, daca utlilizatorul a fost gasit; false, in caz contrar;
    bool findUserById(int id);

    /// \return un vector ce contine toti utilizatorii;
    vector<User> getAllUsers();

    /// Calculeaza numarul utilizatorilor;
    /// \return numarul utilizatorilor;
    int getNumberOfUsers();

    /// Acceseaza un utilizator de pe o pozitie;
    /// \param i pozitia;
    /// \return utilizatorul;
    User getUser(int i);

    /// Adauga o relatie de prietenie intre doi utilizatori;
    /// \param u1 primul utilizator;
    /// \param u2 al doilea utilizator;
    void addFriendship(const User& u1, const User& u2);

    /// Sterge o prietenie dintre doi utilizatori;
    /// \param u1 primul utilizator;
    /// \param u2 al doilea utilizator;
    void deleteFriendship(const User& u1, const User& u2);

    /// \return un vector ce contine toate relatiile de prietenie;
    vector<Friendship> getAllFrienships();

    /// \return un vector ce contine toti prietenii unui utilizator;
    vector<User> getFriendsForAnUser(int id);

    /// Trimite un mesaj de la un utilizator la altul;
    /// \param u1 primul utilizator;
    /// \param u2 al doilea utilizator;
    /// \param info mesajul;
    void sendMessage(const User& u1, const User& u2, string info);

    /// Sterge un mesaj dintre 2 utilizatori;
    /// \param u1 primul utilizator;
    /// \param u2 al doilea utilizator;
    /// \param info mesajul;
    void deleteMessage(const User& u1, const User& u2, string info);

    /// \return un vector ce contine toate mesajele;
    vector<Messages> getAllMessages();

    /// Verifica daca 2 utilizatori sunt prieteni;
    /// \param id ID-ul primului utilizator;
    /// \param id2 ID-ul celui de-al doilea utilizator;
    /// \return true, daca cei doi utilizatori sunt prieteni; false, in caz contrar;
    bool isAFriend(int id, int id2);

   /// \return un vector ce contine toate mesajele dintre doi utilizatori;
   vector<Messages> getAllMsgBetweenTwoUsers(const User& u1, const User& u2);

   /// Adauga un eveniment;
   /// \param nume numele evenimentului;
   /// \param locatie locatia evenimentului;
   /// \param nrParticipanti numarul de participanti la eveniment;
   void addEvent(string nume, string locatie, int nrParticipanti);

   /// Sterge un eveniment;
   /// \param nume numele evenimentului;
   /// \param locatie locatia evenimentului;
   /// \param nrParticipanti numarul de participanti la eveniment;
   void deleteEvent(string nume, string locatie, int nrParticipanti);

   /// Acceseaza toate evenimentele;
   void getAllEvents();
};

#endif //SDA_PROIECT_SERVICE_H
