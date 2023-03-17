

template<class T>
/// Lista cu elemente generice, cu reprezentare pe array ce functioneaza ca vectorul din STL
/// @tparam T: tipul de element continut in lista
class List{

private:
    T* list;
    int capacity{};
    int numberOfElements{};
public:

    List();

    List(T*, int, int);

    List(List<T>&);

    ~List();

    List<T>& operator=(const List<T>&);

    bool operator==(const List<T>&);

    void add(T);

    int size() const;

    int getCapacity() const;

    bool empty();

    void insert(int, T);

    T getElem(int);

    void deleteElem(int);

};

template<class T>
/// Constructor implicit; initializeaza datele membre;
/// @tparam T tipul elementelor din lista
List<T>::List()
{
    this->list = new T[1];
    this->capacity = 1;
    this->numberOfElements = 0;
}

template<class T>
/// Constructor cu parametri;
/// \param paramList pointer la lista;
/// \param paramCapacity capacitatea listei;
/// \param paramNumberOfElements numarul de elemente continute in lista;
List<T>::List(T *paramList, int paramCapacity, int paramNumberOfElements)
{
    this->list = new T[paramCapacity];
    for(int  i = 0; i < paramNumberOfElements; i++)
        this->list[i] = paramList[i];

    this->capacity = paramCapacity;

    this->numberOfElements = paramNumberOfElements;
    delete []list;
}

template<class T>
/// Constructor de copiere;
/// \tparam T tipul elementelor din lista;
/// \param paramList lista;
List<T>::List(List<T> &paramList)
{

    if(this->list != nullptr)
    {
        delete[] this->list;
        this->list = nullptr;
    }

    this->list = new T[paramList.capacity];
    for(int i = 0; i < paramList.capacity; i++)
        this->list[i] = paramList.list[i];

    this->capacity = paramList.capacity;
    this->numberOfElements = paramList.numberOfElements;

    delete []this->list;
}

template<class T>
/// Destructor pentru lista
/// \tparam T tipul elementelor din lista
List<T>::~List<T>()
{
    delete[] this->list;
    this->capacity = 0;
    this->numberOfElements = 0;
}

template<class T>
/// Operator de atribuire; creeaza o noua lista ( egal cu o lista data)
/// \tparam T tipul elementelor din lista;
/// \param paramList lista ce urmeaza a fi copiata;
/// \return aceasta lista, dupa ce modificarile au fost efectuate cu succes
List<T>& List<T>::operator=(const List<T> &paramList)
{

    if(this == &paramList)
        return *this;

    this->list = new T[paramList.capacity];
    for(int i = 0; i < paramList.capacity; i++)
        this->list[i] = paramList.list[i];

    this->capacity = paramList.capacity;
    this->numberOfElements = paramList.numberOfElements;

    return *this;

}

template<class T>
/// Operator ==, compara doua liste;
/// \tparam T tipul elementelor din lista;
/// \param paramList lista cu care se va compara lista initiala;
/// \return true/false;
bool List<T>::operator==(const List<T>& paramList)
{

    if(this->capacity != paramList.capacity)
        return false;

    if(this->numberOfElements!= paramList.numberOfElements)
        return false;

    for(int i = 0; i < this->numberOfElements; i++)
        if(this->list[i] != paramList.list[i])
            return false;

    return true;

}

template<class T>
///Adauga un element la lista;
/// \tparam T tipul elementului;
/// \param elem elementul;
void List<T>::add(T elem)
{

    if(this->numberOfElements >= this->capacity)
    {
        this->capacity *= 2;
        T* aux = new T[capacity];

        for(int i = 0; i < this->numberOfElements; i++)
            aux[i] = this->list[i];

        delete[] this->list;
        this->list = aux;
    }

    this->list[this->numberOfElements] = elem;
    this->numberOfElements++;

}

template<class T>
/// Gaseste numarul de eleemnte din lista;
/// \tparam T tipul elemetelor din lista;
/// \return numarul elementelor din lista;
int List<T>::size() const
{
    return this->numberOfElements;
}

template<class T>
/// Gaseste capacitatea listei;
/// \tparam T tipul elementelor din lista;
/// \return capacitatea listei;
int List<T>::getCapacity() const
{
    return this->capacity;
}

template<class T>
/// Verifica daca lista este goala;
/// \tparam T tipul elementelor din lista;
/// \return true/false;
bool List<T>::empty()
{

    if(this->numberOfElements == 0)
        return true;
    else return false;

}

template<class T>
/// Insereaza un element la pozitia iteratorului;
/// \tparam T tipul elementelor din lista;
/// \param iterator iteratorul;
/// \param elem elementul;
void List<T>::insert(int iterator, T elem)
{

    this->numberOfElements++;
    for(int i = this->numberOfElements; i > iterator; i--)
        this->list[i] = this->list[i - 1];
    this->list[iterator] = elem;

}

template<class T>
/// Gaseste elementul de pe o pozitie data;
/// \tparam T tipul elementelor din lista;
/// \param iterator pozitia;
/// \return elementul de pe pozitia iterator;
T List<T>::getElem(int iterator)
{
    return this->list[iterator];
}

template<class T>
/// Sterge un element de pe o pozitie;
/// \tparam T tipul elementelor din lista;
/// \param iterator pozitia;
void List<T>::deleteElem(int iterator)
{

    for(int i = iterator; i < this->numberOfElements - 1; i++)
        this->list[i] = this->list[i + 1];
    this->numberOfElements--;

}
