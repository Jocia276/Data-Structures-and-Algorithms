//
// Created by casia on 16.05.2022.
//

#ifndef SDA_PROIECT_EXCEPTIONS_H
#define SDA_PROIECT_EXCEPTIONS_H

#include <string>
#include <utility>
using namespace std;

class MyException{
private:
    const char* message;
public:
    /// Creeaza o exceptie
    /// \param m mesajul exceptiei
    MyException(const char* m) : message(m){
    }
    const char* getMessage(){
        return message;
    }
};

#endif //SDA_PROIECT_EXCEPTIONS_H
