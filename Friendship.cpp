//
// Created by casia on 15.05.2022.
//

#include "Friendship.h"

Friendship::Friendship() {

}

Friendship::Friendship(User u1, User u2) {
    this->u1 = u1;
    this->u2 = u2;
}

Friendship::Friendship(const Friendship &f) {
    this->u1 = f.u1;
    this->u2 = f.u2;
}

Friendship::~Friendship() {

}

User Friendship::getFirstUser() {
    return this->u1;
}

User Friendship::getSecondUser() {
    return this->u2;
}

void Friendship::setFirstUser(const User &u) {
    this->u1 = u;
}

void Friendship::setSecondUser(const User &u) {
    this->u2 = u;
}

bool Friendship::operator==(const Friendship &f) const {
    if (this->u1 == f.u1 && this->u2 == f.u2)
        return true;
    return false;
}

Friendship &Friendship::operator=(const Friendship &f) {
    this->u1 = f.u1;
    this->u2 = f.u2;
    return *this;
}

bool Friendship::operator!=(const Friendship &f) const {
    return !(f == *this);
}

istream &operator>>(istream &is, Friendship &f) {
    User u1;
    is >> u1;
    f.setFirstUser(u1);

    User u2;
    is >> u2;
    f.setSecondUser(u2);

    return is;
}

