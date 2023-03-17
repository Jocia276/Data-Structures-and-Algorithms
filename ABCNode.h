//
// Created by casia on 17.05.2022.
//

#ifndef SDA_PROIECT_ABCNODE_H
#define SDA_PROIECT_ABCNODE_H

template<typename T>
class ABC;

template<class T>
/// Clasa generica ce descrie un nod al unui arbore binar de cautare;
/// \tparam T tipul elementelor din arbore;
class ABCNode
{
private:
    T info;
    ABCNode<T>* left;
    ABCNode<T>* right;
public:
    /// Constructor ce se reduce la o "frunza"/ la un nod al arborelui;
    /// \param info informatiile din arbore / elementele din arbore;
    explicit ABCNode(T info) : info(info) {this->left = nullptr, this->right = nullptr;}

    /// Constructor cu parametri; creeaza un arbore;
    /// \param info informatiile din arbore / elementele din arbore;
    /// \param left subarborele stang;
    /// \param right subarborele drept;
    ABCNode(T info, ABCNode<T> *left, ABCNode<T> *right) : info(info), left(left), right(right) {}

    /// Acceseaza elementele din arbore;
    /// \return elementele din arbore;
    T getInfo(){return this->info;}

    friend class ABC<T>;
};
#endif //SDA_PROIECT_ABCNODE_H
