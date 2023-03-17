//
// Created by casia on 09.05.2022.
//

#include "User.h"

#include <utility>


User::User() {
    this->id = 0;
    this->name = "";
    this->age = 0;
}

User::User(int id, string name, int age) {
    this->id = id;
    this->name = std::move(name);
    this->age = age;
}

User::User(const User &u) {
    this->id = u.id;
    this->name = u.name;
    this->age = u.age;
}

User::~User() = default;

User &User::operator=(const User &u) {
    this->id = u.id;
    this->name = u.name;
    this->age = u.age;
    return *this;
}

bool User::operator==(const User &u) const {
    if (this->id == u.id && this->name == u.name && this->age == u.age)
        return true;
    return false;
}

bool User::operator!=(const User &u) const {
    return !(u == *this);
}

bool User::operator<(const User &u) const {
    return this->age < u.age;
}

bool User::operator>(const User &u) const {
    return u < *this;
}

bool User::operator<=(const User &u) const {
    return !(u < *this);
}

bool User::operator>=(const User &u) const {
    return !(*this < u);
}

std::ostream &operator<<(std::ostream &os, const User &u) {
    os << u.id << " ";
    os << u.name << " ";
    os << u.age << endl;
    return os;
}

istream &operator>>(istream &is, User &u) {
    int id;
    is >> id;
    u.setId(id);

    string nume;
    is >> nume;
    u.setName(nume);

    int varsta;
    is >> varsta;
    u.setAge(varsta);

    return is;
}

string User::getName() {
    return this->name;
}

int User::getAge() const {
    return this->age;
}

void User::setName(string nume) {
    this->name = std::move(nume);
}

void User::setAge(int varsta) {
    this->age = varsta;
}

void User::setId(int id1) {
    this->id = id1;
}

int User::getId() const {
    return this->id;
}
