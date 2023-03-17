//
// Created by casia on 17.05.2022.
//

#ifndef SDA_PROIECT_ABC_H
#define SDA_PROIECT_ABC_H

#include "ABCNode.h"
#include "iostream"

using namespace std;

template<class T>
/// Clasa ce defineste un arbore binar de cautare;
/// \tparam T tipul elementelor din arbore;
class ABC {
private:
    /// radacina arborelui binar de caautare;
    ABCNode<T> *root;

    /// Adauga un element/nod in arbore
    /// \param root radacina arborelui;
    /// \param elem elementul;
    void add(ABCNode<T> *root, T elem);

    /// Sterge un element/nod din arbore;
    /// \param root radacina arborelui;
    /// \param elem elementul;
    void deleteNode(ABCNode<T> *root, T elem);

    /// Gaseste nodul/elementul cu cea mai mica valoare;
    /// \param node radacina arborelui;
    /// \return nodul/elementul cu cea mai mica valoare;
    ABCNode<T> *minValueNode(ABCNode<T> *node);

    /// Cauta un element;
    /// \param current nodul curent;
    /// \param elem elementul;
    /// \param parent nodul parinte;
    void searchKey(ABCNode<T> *&current, T elem, ABCNode<T> *&parent);

    /// Gaseste marimea arborelui;
    /// \param node radacina arborelui;
    /// \return marimea arborelui;
    int size(ABCNode<T> *node);

    /// Afiseaza elementele arborelui;
    /// \param node radacina arborelui;
    void print(ABCNode<T> *node);

public:

    ///Constructor implicit, fara parametri;
    ABC();

    /// Adauga un element;
    /// \param elem elementul;
    void add(T elem);

    /// Sterge un element;
    /// \param elem elementul;
    void deleteElem(T elem);

    /// Gaseste elementul cu valoarea cea mai mica;
    /// \return pointer la elementul cu valoarea cea mai mica;
    ABCNode<T> *findMin();

    /// Gaseste elementul cu valoarea cea mai mare;
    /// \return pointer la elementul cu valoarea cea mai mare;
    ABCNode<T> *findMax();

    /// Cauta un element in arbore;
    /// \param elem elementul cautat;
    void search(T elem);

    /// Marimea arborelui;
    int size();

    /// afiseaza arborele;
    void printTree();
};


template<class T>
void ABC<T>::add(ABCNode<T> *root, T elem) {
    if (elem > root->info) {
        if (!root->right) {
            root->right = new ABCNode<T>(elem);
        } else { add(root->right, elem); }
    } else {
        if (!root->left) {
            root->left = new ABCNode<T>(elem);
        } else {
            add(root->left, elem);
        }
    }

}

template<class T>
void ABC<T>::deleteNode(ABCNode<T> *root, T elem) {
    ABCNode<T> *parent = nullptr;
    ABCNode<T> *current = root;

    searchKey(current, elem, parent);
    if (current == nullptr) {
        return;
    }
    if (current->left == nullptr && current->right == nullptr) {
        if (current != root) {
            if (parent->left == current) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
        } else {
            root = nullptr;
        }
        free(current);
    } else if (current->left && current->right) {
        ABCNode<T> *successor = minValueNode(current->right);

        T val = successor->info;

        deleteNode(root, successor->info);

        current->info = val;
    } else {

        ABCNode<T> *child = (current->left) ? current->left : current->right;

        if (current != root) {
            if (current == parent->left) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        } else {
            root = child;
        }
        free(current);
    }
}

template<class T>
ABCNode<T> *ABC<T>::minValueNode(ABCNode<T> *node) {
    ABCNode<T> *current = node;
    while (current && current->left != nullptr) current = current->left;
    return current;
}

template<class T>
void ABC<T>::searchKey(ABCNode<T> *&current, T elem, ABCNode<T> *&parent) {
    while (current != nullptr && current->info != elem) {
        parent = current;
        if (elem < current->info) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
}

template<class T>
int ABC<T>::size(ABCNode<T> *node) {
    if (node == nullptr) return 0;
    else return (size(node->left) + 1 + size(node->right));
}

template<class T>
void ABC<T>::print(ABCNode<T> *node) {
    if (!node) {
        return;
    }
    print(node->left);
    cout << node->info << " ";
    print(node->right);
}

template<class T>
void ABC<T>::add(T elem) {
    if (!root) {
        root = new ABCNode<T>(elem);
    } else {
        this->add(root, elem);
    }
}

template<class T>
void ABC<T>::deleteElem(T elem) {
    this->deleteNode(root, elem);
}

template<class T>
ABCNode<T> *ABC<T>::findMin() {
    ABCNode<T> *min = root;
    while (min->left) {
        min = min->left;
    }
    return min;
}

template<class T>
ABCNode<T> *ABC<T>::findMax() {
    ABCNode<T> *max = root;
    while (max->right) {
        max = max->right;
    }
    return max;

}

template<class T>
ABC<T>::ABC() {
    this->root = nullptr;
}

template<class T>
int ABC<T>::size() {
    return this->size(root);
}

template<class T>
void ABC<T>::printTree() {
    if (!root) { return; }
    print(root);
    cout << endl;
}

template<class T>
void ABC<T>::search(T elem) {
    this->searchKey(nullptr, elem, nullptr);
}

#endif //SDA_PROIECT_ABC_H
