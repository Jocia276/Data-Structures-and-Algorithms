//
// Created by casia on 19.05.2022.
//

#ifndef SDA_PROIECT_MESSAGES_H
#define SDA_PROIECT_MESSAGES_H


#include "User.h"
#include <vector>
using namespace std;

class Messages {
private:
    User u1;
    User u2;
    string message;
public:

    ///Constructor fara parametri;
    Messages();

    /// Constructor cu parametri; creeaza un mesaj;
    /// \param u1 primul utilizator
    /// \param u2 al doilea utilizator
    /// \param msg mesajul
    Messages(const User& u1, const User& u2, string msg);

    /// Constructor de copiere;
    /// \param msg messajul ce este copiat;
    Messages(const Messages& msg);

    ///Destructor;
    ~Messages();

    /// Acceseaza primul utilizator;
    /// \return primul utilizator;
    User getFirstUser();

    /// Seteaza primul utilizator cu un utilizator dat;
    /// \param uu1 utilizatorul dat
    void setFirstUser(const User& uu1);

    /// Acceseaza al doilea utilizator;
    /// \return al doilea utilizator;
    User getSecondUser();

    /// Seteaza al doilea utilizator cu un utilizator dat;
    /// \param uu2 utilizatorul dat;
    void setSecondUser(const User& uu2);

    /// Acceseaza un mesaj;
    /// \return mesajul;
    string getMessage();

    /// Seteaza un mesaj cu un mesaj dat;
    /// \param msg mesajul dat;
    void setMessage(string msg);

    /// Operator de atribuire; creeaza un nou mesaj(egal cu un mesaj dat)
    /// \param m mesajul dat;
    /// \return noul mesaj;
    Messages& operator=(const Messages& m);

    /// Compara doua mesaje (cel curent cu un mesaj nou)
    /// \param m mesajul curent;
    /// \return true/false
    bool operator==(const Messages& m) const;

    /// Salveaza un mesaj intr-un stream de iesire
    /// \param is stream-ul de iesire
    /// \param m mesajul
    /// \return streamul de iesire(incarcat cu informatii despre mesaj)
    friend istream& operator>>(istream& is, Messages& m);
};


#endif //SDA_PROIECT_MESSAGES_H
