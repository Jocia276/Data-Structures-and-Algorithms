//
// Created by casia on 15.05.2022.
//

#ifndef SDA_PROIECT_FRIENDSHIP_H
#define SDA_PROIECT_FRIENDSHIP_H

#include "User.h"

class Friendship {
private:
    User u1;
    User u2;
public:

    ///Constructorul fara parametri;
    Friendship();

    /// Constructor cu parametri; creeaza o prietenie;
    /// \param u1 primul user;
    /// \param u2 al doilea user;
    Friendship(User u1, User u2);

    /// Construcotr de copiere;
    /// \param f o prietenie;
    Friendship(const Friendship &f);

    ///Destructor;
    ~Friendship();

    /// Acceseaza primul user;
    /// \return primul user;
    User getFirstUser();

    /// Acceseaza al doilea user;
    /// \return al doilea user;
    User getSecondUser();

    /// Seteaza primul user;
    /// \param u user-ul;
    void setFirstUser(const User &u);

    /// Seteaza al doilea user;
    /// \param u user-ul;
    void setSecondUser(const User &u);

    /// Operator de atribuire; creeaza o noua prietenie ( egala cu o prietenie data);
    /// \param f prietenia
    /// \return o prietenie
    Friendship &operator=(const Friendship &f);

    /// Compara doua relatii de prietenie ( cea curenta si o noua relatie de prietenie);
    /// \param f prietenia
    /// \return true, daca cele doua relatii de prietenie sunt egale; false, in caz contrar;
    bool operator==(const Friendship &f) const;

    /// Compara doua relatii de prietenie ( cea curenta si o noua relatie de prietenie);
    /// \param f prietenia
    /// \return true, daca cele doua relatii de prietenie nu sunt egale; false, in caz contrar;
    bool operator!=(const Friendship &f) const;

    /// Salveaza o prietenie intr-un stream de iesire
    /// \param is stream-ul de iesire
    /// \param f relatia de prietenie
    /// \return streamul de iesire(incarcat cu informatii despre relatia de prietenie)
    friend istream &operator>>(istream &is, Friendship &f);

};

#endif //SDA_PROIECT_FRIENDSHIP_H
