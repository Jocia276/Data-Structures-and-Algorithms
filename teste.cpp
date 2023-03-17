#include "teste.h"
#include "Repository.h"
#include "Service.h"
#include <cassert>


void teste(){
    testeLista();
    testeUser();
    testeRepoTemplate();
    testeArbore();
    testeRepoEvents();
}

void testeLista(){

    /// lista de numere de tip intreg

    List<int> numbers;
    assert(numbers.size() == 0);
    assert(numbers.getCapacity() == 1);

    numbers.add(5);
    numbers.add(8);
    numbers.add(7);
    numbers.add(70);
    numbers.add(9);
    numbers.add(20);

    assert(numbers.size() == 6);
    assert(numbers.getElem(2) == 7);

    numbers.deleteElem(2);

    assert(numbers.getElem(2) == 70);
    assert(numbers.size() == 5);
    assert(numbers.empty() == 0);

    numbers.insert(3, 45);

    assert(numbers.getElem(3) == 45);
    assert(numbers.size() == 6);

    /// lista de utilizatori

    List<User> users;

    User u1(1, "Maria", 52);
    User u2(2, "Mia", 18);
    User u3(3, "Marian", 54);

    users.add(u1);
    users.add(u2);
    users.add(u3);

    assert(users.size() == 3);

    assert(users.getElem(1) == u2);
    assert(users.getElem(1).getAge() == 18);

    users.deleteElem(0);
    assert(users.size() == 2);
    assert(users.getElem(0) == u2);

    User u4(4, "Carina", 10);
    users.insert(0, u4);
    assert(users.size() == 3);

    /// Lista de prietenii

    List<Friendship> friendships;

    Friendship f(u1, u2);
    Friendship f1(u3, u4);
    Friendship f2(u1, u3);
    Friendship f3(u2, u3);

    friendships.add(f);
    friendships.add(f1);
    friendships.add(f2);
    friendships.add(f3);

    assert(friendships.size() == 4);
    assert(friendships.getElem(3) == f3);
    assert(friendships.getElem(3).getFirstUser() == u2);

    friendships.deleteElem(2);

    assert(friendships.size() == 3);
    assert(friendships.getElem(2) == f3);

    friendships.deleteElem(0);
    friendships.deleteElem(1);
    friendships.deleteElem(2);

    assert(friendships.empty() == 1);

    /// Lista de mesaje

    List<Messages> mesaje;

    Messages m(u1, u2, "Hei!");
    Messages m1(u2, u1, "Hello!");
    Messages m2(u3, u4, "Buenos dias!");
    Messages m3(u1, u3, "Bounjour!");

    mesaje.add(m);
    mesaje.add(m1);
    mesaje.add(m2);

    assert(mesaje.size() == 3);
    assert(mesaje.getElem(1) == m1);
    assert(mesaje.getElem(2).getMessage() == "Buenos dias!");

    mesaje.deleteElem(2);
    assert(mesaje.size() == 2);
    assert(mesaje.empty() == 0);

    mesaje.insert(0, m3);
    assert(mesaje.getElem(0) == m3);
}

void testeArbore(){

    /// arbore binar de cautare pentru numere de tip intreg

    ABC<int> abc;

    abc.add(1);
    abc.add(14);
    abc.add(9);
    abc.add(10);
    abc.add(90);
    abc.add(4);
    abc.add(8);

    assert(abc.size() == 7);
    assert(abc.findMax()->getInfo() == 90);
    assert(abc.findMin()->getInfo() == 1);

    abc.deleteElem(8);

    assert(abc.size() == 6);}

void testeUser(){
    User u1;
    assert(u1.getName().empty());
    assert(u1.getAge() == 0);

    User u2(1, "Maria", 27);
    assert(u2.getId() == 1);
    assert(u2.getName() == "Maria");
    assert(u2.getAge() == 27);

    u2.setId(110);
    u2.setName("Ionel");
    u2.setAge(7);
    assert(u2.getId() == 110);
    assert(u2.getName() == "Ionel");
    assert(u2.getAge() == 7);

    User u3(3, "Anastasia", 15);
    User u4=u3; //se apeleaza constructorul de copiere
    assert(u4.getAge() == 15);
    assert(u4.getName() == "Anastasia");

    u4 = u2; // se apeleaza operator=
    assert(u4.getName() =="Ionel");
    assert(u4.getAge() == 7);

    User uu1(11, "Marian", 10);
    User uu2(12, "Mariana", 11);
    User uu3(13, "Maria", 12);
    User uu4(14, "Mari", 20);

    List<User> utilizatori;
    utilizatori.add(uu1);
    utilizatori.add(uu2);
    utilizatori.add(uu3);
    utilizatori.add(uu4);

    assert(utilizatori.size() == 4);
    assert(utilizatori.getElem(2).getAge() == 12);
    assert(utilizatori.getElem(3).getName() == "Mari");

    utilizatori.deleteElem(3);
    utilizatori.deleteElem(0);
    assert(utilizatori.size() == 2);
    assert(utilizatori.getElem(0).getAge() == 11);
    assert(utilizatori.getElem(1).getAge() == 12);
}

void testeRepoTemplate(){
    Repo<User> repo;
    assert(repo.repoSize() == 0);

    User uu1(1, "Marian", 10);
    User uu2(2, "Mariana", 11);
    User uu3(3, "Maria", 12);
    User uu4(4, "Mari", 20);
    repo.addElem(uu1);
    repo.addElem(uu2);
    repo.addElem(uu3);
    repo.addElem(uu4);

    assert(repo.repoSize() == 4);

    repo.deleteElem(uu4);
    repo.deleteElem(uu3);

    assert(repo.repoSize() == 2); // uu1, uu2

    assert(repo.findElem(uu1) == 1);
    assert(repo.findElem(uu3) == 0);

    User us(11, "Horia", 24);
    repo.addElem(us);
    repo.updateElem(uu1, us);
    assert(repo.findElem(uu1) == 0);
    assert(repo.findElem(us) == 1);
}

void testeRepoEvents(){
    RepoEvent<Event> repo;
    assert(repo.repoEventSize() == 0);

    Event e1("Party", "Royal", 50);
    repo.addEvent(e1);
    assert(repo.repoEventSize() == 1);

    Event e2("sss", "Cluj", 25);
    Event e3("sssdkj", "Cluj", 20);

    repo.addEvent(e2);
    repo.addEvent(e3);

    assert(repo.repoEventSize() == 3);

    repo.removeEvent(e2);

    assert(repo.repoEventSize() == 2);

}