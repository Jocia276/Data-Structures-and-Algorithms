//
// Created by casia on 21.05.2022.
//

#include "Event.h"

#include <utility>

Event::Event() {
    this->name = "";
    this->location = "";
    this->noPatricipant = 0;
}

Event::Event(string nume, string locatie, int nrParticipanti) {
    this->name = std::move(nume);
    this->location = std::move(locatie);
    this->noPatricipant = nrParticipanti;
}

Event::Event(const Event &e) {
    this->name = e.name;
    this->location = e.location;
    this->noPatricipant = e.noPatricipant;
}

Event::~Event() {

}

string Event::getName() {
    return this->name;
}

string Event::getLocation() {
    return this->location;
}

int Event::getNoParticipant() const {
    return this->noPatricipant;
}

void Event::setName(string nume) {
    this->name = std::move(nume);
}

void Event::setLocation(string locatie) {
    this->location = std::move(locatie);
}

void Event::setUsers(int nrParticipanti) {
    this->noPatricipant = nrParticipanti;
}

Event &Event::operator=(const Event &e) {
    this->name = e.name;
    this->location = e.location;
    this->noPatricipant = e.noPatricipant;
    return *this;
}

bool Event::operator==(const Event &e) const {
    if (this->name == e.name && this->location == e.location && this->noPatricipant == e.noPatricipant)
        return true;
    return false;
}

bool Event::operator<(const Event &e) const {
    return this->noPatricipant < e.noPatricipant;
}

bool Event::operator>(const Event &e) const {
    return e < *this;
}

bool Event::operator!=(const Event &e) const {
    return !(e == *this);
}

ostream &operator<<(ostream &os, const Event &e) {
    os << "Nume: " << e.name << "; ";
    os << "Locatie: " << e.location << "; ";
    os << "Numar de participanti: " << e.noPatricipant << endl;
    return os;
}
