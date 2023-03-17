#include "ABC.h"
#include "Event.h"
template<class T>
class RepoEvent{
private:
    ABC<T> elems;
public:

    /// Constructor fara parametri;
    RepoEvent();

    /// Constructor cu parametri; creeaza o multime;
    /// \param elem arbore binar de cautare de elemente de tip T;
    explicit RepoEvent(ABC<T> elem);

    /// Constructor de copiere;
    /// \param r repository-ul ce este copiat;
    RepoEvent(const RepoEvent& r);

    /// Destructor;
    ~RepoEvent();

    /// Adauga un element in multime;
    /// \param elem elementul de tipul T;
    void addEvent(const T& elem);

    /// Sterge un eveniment din multime;
    /// \param elem elementul de tip T;
    void removeEvent(const T& elem);

    /// Acceseaza marimea repository-ului;
    /// \return marimea repository-ului;
    int repoEventSize();

    /// Acceseaza toate elementele;
    void getAll();

};

template<class T>
RepoEvent<T>::RepoEvent() {

}

template<class T>
RepoEvent<T>::RepoEvent(ABC<T> elem) {
    this->elems = elem;
}

template<class T>
RepoEvent<T>::RepoEvent(const RepoEvent &r) {
    this->elems = r.elems;
}

template<class T>
RepoEvent<T>::~RepoEvent() {

}

template<class T>
void RepoEvent<T>::addEvent(const T &elem) {
    this->elems.add(elem);
}

template<class T>
void RepoEvent<T>::removeEvent(const T &elem) {
    this->elems.deleteElem(elem);
}

template<class T>
int RepoEvent<T>::repoEventSize() {
    return this->elems.size();
}

template<class T>
void RepoEvent<T>::getAll() {
    this->elems.printTree();
}
