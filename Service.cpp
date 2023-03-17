//
// Created by casia on 09.05.2022.
//

#include "Service.h"

#include <utility>
#include "Exceptions.h"
#include "ABC.h"

Service::Service() {

}

Service::Service(const Repo<User> &repo, const Repo<Friendship> &repof, const Repo<Messages> &repom,
                 const RepoEvent<Event> &repoe) {
    this->repo = repo;
    this->repoF = repof;
    this->repoM = repom;
    this->repoE = repoe;
}

void Service::addUser(int id, string nume, int varsta) {
    User u(id, std::move(nume), varsta);
    int ok = 1;
    for (int i = 0; i < this->getAllUsers().size(); i++) {
        if (this->getAllUsers()[i].getId() == id) ok = 0;
    }

    if (ok == 1) {
        this->repo.addElem(u);
    } else {
        throw MyException(
                "ID-ul unui utilizator trebuie sa fie unic, iar ID-ul introdus de dumneavoastra exista deja! \n ");
    }

}

void Service::deleteUser(int id) {
    bool ok = this->findUserById(id);

    if (ok == 1) {
        for (int i = 0; i < this->getNumberOfUsers(); i++) {
            if (getAllUsers()[i].getId() == id) {
                User u = this->repo.getElem(i);
                this->repo.deleteElem(u);
            }
        }
    } else {
        throw MyException("Utilizatorul nu exista in lista! \n");
    }
}

void Service::update(int id, string numeNou, int varstaNoua) {
    bool ok = this->findUserById(id);
    if (ok == 1) {
        for (int i = 0; i < this->getNumberOfUsers(); i++) {
            if (getAllUsers()[i].getId() == id) {
                User u = this->repo.getElem(i);
                User u2(id, numeNou, varstaNoua);
                bool ok2 = this->find(u2.getId(), u2.getName(), u2.getAge());
                if (ok2 == 0) {
                    this->repo.updateElem(u, u2);
                } else {
                    throw MyException("Utilizatorul exista deja in lista! \n");
                }
            }
        }
    } else {
        throw MyException("Utilizatorul dat nu exista in lista! \n");
    }
}

bool Service::find(int id, string nume, int varsta) {
    User u(id, nume, varsta);
    return this->repo.findElem(u);
}

vector<User> Service::getAllUsers() {
    return this->repo.getAll();
}

int Service::getNumberOfUsers() {
    return this->repo.getAll().size();
}

void Service::addFriendship(const User &u1, const User &u2) {
    int id = u1.getId();
    bool ok = this->findUserById(id);
    if (ok == 1) {
        int id2 = u2.getId();
        bool ok2 = this->findUserById(id2);
        if (ok2 == 1) {
            Friendship f(u1, u2);
            for (int i = 0; i < this->getAllFrienships().size(); i++) {
                if (getAllFrienships()[i].getFirstUser() == f.getFirstUser() &&
                    getAllFrienships()[i].getSecondUser() == f.getSecondUser()) {
                    throw MyException("Aceasta prietenie exista deja! \n");
                } else if (getAllFrienships()[i].getFirstUser() == f.getSecondUser() &&
                           getAllFrienships()[i].getSecondUser() == f.getFirstUser()) {
                    throw MyException("Aceasta prietenie exista deja! \n");
                }
            }
            this->repoF.addElem(f);
        } else {
            throw MyException("Utilizatorul dat nu exista in lista! \n");
        }
    } else {
        throw MyException(
                "Nu sunteti un utilizator al retelei noastre! Va rugam sa va inregistrati apasand tasta 1! \n");
    }
}

void Service::deleteFriendship(const User &u1, const User &u2) {
    int id = u1.getId();
    bool ok = this->findUserById(id);
    if (ok == 1) {
        int id2 = u2.getId();
        bool ok2 = this->findUserById(id2);
        if (ok2 == 1) {
            if (this->isAFriend(id, id2) == 1) {
                Friendship f(u1, u2);
                this->repoF.deleteElem(f);
            } else {
                throw MyException("Utilizatorii dati nu au o prietenie ce poate fi stearsa! \n");
            }
        } else {
            throw MyException("Utilizatorul dat nu exista in lista! \n");
        }
    } else {
        throw MyException(
                "Nu sunteti un utilizator al retelei noastre! Va rugam sa va inregistrati apasand tasta 1! \n");
    }
}

vector<Friendship> Service::getAllFrienships() {
    return this->repoF.getAll();
}

bool Service::findUserById(int id) {
    for (int i = 0; i < this->repo.repoSize(); i++) {
        if (repo.getElem(i).getId() == id) {
            return true;
        }
    }
    return false;
}

User Service::getUser(int i) {
    return this->repo.getElem(i);
}

vector<User> Service::getFriendsForAnUser(int id) {
    vector<Friendship> all = this->getAllFrienships();
    vector<User> result;
    for (auto &i: all) {
        if (i.getFirstUser().getId() == id) {
            result.push_back(i.getSecondUser());
        } else if (i.getSecondUser().getId() == id) {
            result.push_back(i.getFirstUser());
        }

    }
    return result;
}

bool Service::isAFriend(int id, int id2) {
    for (int i = 0; i < this->getFriendsForAnUser(id).size(); i++) {
        if (getFriendsForAnUser(id)[i].getId() == id2) {
            return true;
        }
    }
    return false;
}

void Service::sendMessage(const User &u1, const User &u2, string info) {
    Messages m(u1, u2, std::move(info));
    this->repoM.addElem(m);
}

void Service::deleteMessage(const User &u1, const User &u2, string info) {
    Messages m(u1, u2, std::move(info));
    this->repoM.deleteElem(m);
}

vector<Messages> Service::getAllMessages() {
    return this->repoM.getAll();
}

vector<Messages> Service::getAllMsgBetweenTwoUsers(const User &u1, const User &u2) {
    vector<Messages> mesaje = this->getAllMessages();
    vector<Messages> result;
    for (auto &i: mesaje) {
        if (i.getFirstUser() == u1 && i.getSecondUser() == u2) result.push_back(i);
        else {
            if (i.getFirstUser() == u2 && i.getSecondUser() == u1) {
                result.push_back(i);
            };
        }
    }
    return result;
}

void Service::addEvent(string nume, string locatie, int nrParticipanti) {
    Event e1(nume, locatie, nrParticipanti);
    this->repoE.addEvent(e1);
}

void Service::deleteEvent(string nume, string locatie, int nrParticipanti) {
    Event e1(nume, locatie, nrParticipanti);
    this->repoE.removeEvent(e1);
}

void Service::getAllEvents() {
    this->repoE.getAll();
}


Service::~Service() = default;
