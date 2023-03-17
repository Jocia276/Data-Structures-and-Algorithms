//
// Created by casia on 09.05.2022.
//

#ifndef SDA_PROIECT_REPOSITORY_H
#define SDA_PROIECT_REPOSITORY_H
#include "List.h"
#include <vector>
using namespace std;

template <class T>
class Repo{
private:
    List<T> elems;
public:

    ///Constructor fara parametri;
    Repo();

    /// Constructor cu parametri;
    /// \param elems elementele listei;
    explicit Repo(List<T> elems);

    /// Constructro de copiere;
    /// \param r repository-ul ce este copiat;
    Repo(const Repo& r);

    ///Destructor;
    ~Repo();

    /// Adauga un element;
    /// \param elem elementul;
    void addElem(T elem);

    /// Sterge un element;
    /// \param elem elementul;
    void deleteElem(T elem);

    /// Actualizeaza un element;
    /// \param elem vechiul element;
    /// \param newElem noul element;
    void updateElem(T elem, const T &newElem);

    /// Cauta un element;
    /// \param elem elementul;
    /// \return true, daca elementul a fost gasit; false, in caz contrar;
    bool findElem(T elem);

    /// Callculeaza lungimea repository-ului;
    /// \return lungimea repository-ului;
    int repoSize();

    /// Gaseste un element de pe o pozitie data;
    /// \param pos pozitia data;
    /// \return elementul;
    T getElem(int pos);

    /// Acceseaza toate elementele din lista;
    /// \return un vector ce contine toate elementele din lista;
    vector<T> getAll();

    ///Operator de atribuire; creeaza un nou repository(egal cu un repository dat);
    /// \param r repository-ul;
    /// \return un repository;
    Repo<T>& operator=(const Repo& r);

    /// Compara doua repository-uri (cel curent si un nou repository)
    /// \param r repositroy-ul nou
    /// \return true, daca cele doua repository-uri sunt egale; false, in caz contrar;
    bool operator==(const Repo &r) const;
};

template<class T>
Repo<T>::Repo() {
    this->elems = {};
}

template<class T>
Repo<T>::Repo(List<T> el) {
    this->elems = el;
}

template<class T>
Repo<T>::Repo(const Repo &r) {
    this->elems = r.elems;
}

template<class T>
bool Repo<T>::operator==(const Repo &r) const {
    for(int i=0; i<elems.size(); i++)
    {
        if(this->elems[i] != r.elems[i])
            return false;
    }
    return true;
}

template<class T>
Repo<T>::~Repo() {
    for (int i = 0; i < this->elems.size(); i++)
    {
        this->elems.deleteElem(i);
    }
}

template<class T>
void Repo<T>::addElem(T elem) {
    this->elems.add(elem);
}

template<class T>
void Repo<T>::deleteElem(T elem) {
    for(int i=0; i<elems.size(); i++){
        T element = elems.getElem(i);
        if(element == elem){
            this->elems.deleteElem(i);}}
}

template<class T>
void Repo<T>::updateElem(T elem, const T &newElem) {
    for (int i = 0; i < this->elems.size(); i++)
    {
        if (this->elems.getElem(i) == elem)
        {
            this->elems.deleteElem(i);
            this->elems.insert(i, newElem);
        }
    }
}

template<class T>
bool Repo<T>::findElem(T elem) {
    for(int i=0; i<elems.size(); i++){
        if(elems.getElem(i) == elem)
            return true;
    }

    return false;
}

template<class T>
vector<T> Repo<T>::getAll() {
    vector<T> result;
    for(int i=0; i<elems.size(); i++)
        result.push_back(elems.getElem(i));
    return result;
}

template<class T>
int Repo<T>::repoSize() {
    return elems.size();
}

template<class T>
T Repo<T>::getElem(int pos) {
    return elems.getElem(pos);
}

template<class T>
Repo<T> &Repo<T>::operator=(const Repo &r) {
   this->elems  = r.elems;
   return *this;
}


#endif //SDA_PROIECT_REPOSITORY_H
