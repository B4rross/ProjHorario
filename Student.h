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
    Student();
    Student(int codigo, string nome, list<UCTurma> list);
    Student(int codigo, string nome, UCTurma turma);
    int get_cod() const;
    string get_nome() const;
    UCTurma get_turma() const;
    list<UCTurma> get_turmas() const;
    bool operator< (const Student& student2) const;
    void pushback(const Student &student2);

};


#endif //UNTITLED_STUDENT_H
