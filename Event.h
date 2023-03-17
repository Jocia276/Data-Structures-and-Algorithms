//
// Created by casia on 21.05.2022.
//

#ifndef SDA_PROIECT_EVENT_H
#define SDA_PROIECT_EVENT_H

#include <string>
#include <vector>
#include "User.h"

using namespace std;

class Event {
private:
    string name;
    string location;
    int noPatricipant;
public:

    ///Constructor fara parametri; initializeaza datele membre cu valori default;
    Event();

    /// Constructor cu parametri; creeaza un eveniment;
    /// \param nume numele evenimentului;
    /// \param locatie locatia evenimentului;
    /// \param nrParticipanti numarul de participanti la eveniment;
    Event(string nume, string locatie, int nrParticipanti);

    /// Constructor de copiere;
    /// \param e evenimentul ce este copiat;
    Event(const Event &e);

    /// Destructor;
    ~Event();

    /// Acceseaza numele evenimentului;
    /// \return numele evenimentului;
    string getName();

    /// Acceseaza locatia evenimentului;
    /// \return locatia evenimentului;
    string getLocation();

    /// Acceseaza numarul de participanti la eveniment;
    /// \return numarul de participanti la eveniment;
    int getNoParticipant() const;

    /// Seteaza numele evenimentului cu un nume dat;
    /// \param nume numele dat;
    void setName(string nume);

    /// Seteaza locatia evenimentului cu o locatie data;
    /// \param locatie locatia data;
    void setLocation(string locatie);

    /// Seteaza numarul de participanti cu un numar dat;
    /// \param noParticipant numarul de participanti dat;
    void setUsers(int noParticipant);

    /// Operator de atribuire; creeaza un nou eveniment ( egal cu un eveniment dat );
    /// \param e evenimentul;
    /// \return un eveniment;
    Event &operator=(const Event &e);

    /// Compara doua evenimente ( cel curent si un nou eveniment )
    /// \param e evenimentul;
    /// \return  true, daca cele doua evenimente sunt diferite; false, in caz contrar;
    bool operator!=(const Event &e) const;

    /// Compara doua evenimente ( cel curent si un nou eveniment )
    /// \param e evenimentul
    /// \return true, daca cele doua evenimente sunt egale; false, in caz contrar;
    bool operator==(const Event &e) const;

    /// Compara doua evenimente ( cel curent si un nou eveniment )
    /// \param e evenimentul
    /// \return true, daca primul eveniment este mai mic decat al doilea; false, in caz contrar;
    bool operator<(const Event &e) const;

    /// Compara doua evenimente ( cel curent si un nou eveniment )
    /// \param e evenimentul
    /// \return true, daca primul eveniment este mai mare decat al doilea; false, in caz contrar;
    bool operator>(const Event &e) const;

    /// Incarca un eveniment dintr-un stream de intrare;
    /// \param os stream-ul de intrare;
    /// \param e evenimentul;
    /// \return un eveniment;
    friend ostream &operator<<(ostream &os, const Event &e);
};


#endif //SDA_PROIECT_EVENT_H
