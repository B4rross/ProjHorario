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
    long codEst;
    string nomeEst;
    list<UCTurma> turmas;
public:
    Student();
    Student(int codigo, string nome, list<UCTurma> list);
    Student(int codigo, string nome, UCTurma turma);
    long get_cod() const;
    string get_nome() const;
    UCTurma get_turma() const;
    list<UCTurma> get_turmas() const;
    bool operator< (const Student& student2) const;
    void pushback(const Student &student2);
    bool is_in_turma(string turma) const;
    bool is_in_uc(string uc) const;

};


#endif //UNTITLED_STUDENT_H
