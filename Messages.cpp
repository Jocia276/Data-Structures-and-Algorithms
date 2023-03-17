//
// Created by casia on 19.05.2022.
//

#include "Messages.h"

#include <utility>

Messages::Messages() {

}

Messages::Messages(const User &u1, const User &u2, string msg) {
    this->u1 = u1;
    this->u2 = u2;
    this->message = std::move(msg);
}

Messages::Messages(const Messages &msg) {
    this->u1 = msg.u1;
    this->u2 = msg.u2;
    this->message = msg.message;
}

Messages &Messages::operator=(const Messages &m) {
    this->u1 = m.u1;
    this->u2 = m.u2;
    this->message = m.message;
    return *this;
}

bool Messages::operator==(const Messages &m) const {
    if (this->u1 == m.u1 && this->u2 == m.u2 && this->message == m.message) return true;
    else return false;
}

Messages::~Messages() {

}


string Messages::getMessage() {
    return this->message;
}


void Messages::setMessage(string msg) {
    this->message = std::move(msg);
}

istream &operator>>(istream &is, Messages &m) {
    User u1;
    is >> u1;
    m.setFirstUser(u1);

    User u2;
    is >> u2;
    m.setSecondUser(u2);

    string text;
    is >> text;

    return is;
}

User Messages::getFirstUser() {
    return this->u1;
}

User Messages::getSecondUser() {
    return this->u2;
}

void Messages::setFirstUser(const User &uu1) {
    this->u1 = uu1;
}

void Messages::setSecondUser(const User &uu2) {
    this->u2 = uu2;
}

