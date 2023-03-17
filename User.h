//
// Created by casia on 09.05.2022.
//

#ifndef SDA_PROIECT_USER_H
#define SDA_PROIECT_USER_H

#include <string>
#include <ostream>
#include <istream>

using namespace std;

class User {
private:
    int id;
    string name;
    int age;
public:

    /// Constructor fara parametri, initializeaza datele membre cu valori default;
    User();

    /// Constructor cu parametri;
    /// \param id id-ul utilizatorului;
    /// \param name numele utilizatorului;
    /// \param age varsta utilizatorului;
    User(int id, string name, int age);

    /// Constructor de copiere;
    /// \param u utilizatorul ce este copiat;
    User(const User &u);

    /// Destructor;
    ~User();

    /// Acceseaza id-ul utilizatorului;
    /// \return id-ul utilizatorului;
    int getId() const;

    /// Acceseaza numele utlizatorului;
    /// \return numele utilizatorului;
    string getName();

    /// Acceseaza varsta utilizatorului;
    /// \return varsta utilizatorului;
    int getAge() const;

    /// Seteaza id-ul utilizatorului cu un id dat;
    /// \param id id-ul dat;
    void setId(int id);

    /// Seteaza numele utilizatorului cu un nume dat;
    /// \param name numele dat;
    void setName(string name);

    /// Seteaza varsta utlizatorului cu o varsta data;
    /// @param age varsta data;
    void setAge(int age);

    /// Operator de atribuire; creeaza un nou utilizator ( egal cu un utlizator dat)
    /// \param u utilizatorul
    /// \return un utilizator
    User &operator=(const User &u);

    /// Compara doi utilizatori ( cel curent si un nou utilizator )
    /// \param u utilizatorul
    /// \return true, daca cei doi utilizatori sunt egali; false, in caz contrar;
    bool operator==(const User &u) const;

    /// Compara doi utilizatori ( cel curent si un nou utilizator )
    /// \param u utilizatorul
    /// \return true, daca cei doi utilizatori nu sunt egali; false, in caz contrar;
    bool operator!=(const User &u) const;

    /// Compara doi utilizatori ( cel curent si un nou utilizator )
    /// \param u utilizatorul
    /// \return true, daca primul utilizator este mai mic decat al doilea; false, in caz contrar
    bool operator<(const User &u) const;

    /// Compara doi utilizatori ( cel curent si un nou utilizator )
    /// \param u utilizatorul
    /// \return true, daca primul utilizator este mai mare decat al doilea; false, in caz contrar
    bool operator>(const User &u) const;

    /// Compara doi utilizatori ( cel curent si un nou utilizator )
    /// \param u utilizatorul
    /// \return true, daca primul utilizator este mai mic sau egal cu al doilea; false, in caz contrar
    bool operator<=(const User &u) const;

    /// Compara doi utilizatori ( cel curent si un nou utilizator )
    /// \param u utilizatorul
    /// \return true, daca primul utilizator este mai mare sau egal cu al doilea; false, in caz contrar
    bool operator>=(const User &u) const;

    /// Incarca un utilizator dintr-un stream de intrare
    /// \param os stream-ul de intrare
    /// \param u utilizatorul
    /// \return un utilizator
    friend ostream &operator<<(ostream &os, const User &u);

    /// Salveaza un produs intr-un stream de iesire
    /// \param is stream-ul de iesire
    /// \param u utilizatorul
    /// \return streamul de iesire(incarcat cu informatii despre utilizator)
    friend istream &operator>>(istream &is, User &u);

};


#endif //SDA_PROIECT_USER_H
