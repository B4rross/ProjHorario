//
// Created by inviz on 30/10/2022.
//

#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H

#include <string>
#include <list>
#include "UCTurma.h"

using namespace std;
class Student {
    int codEst;
    string nomeEst;
    list<UCTurma> turmas;
public:
    Student(int codigo, string nome, list<UCTurma> list);


};


#endif //UNTITLED_STUDENT_H
