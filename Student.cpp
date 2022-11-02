//
// Created by inviz on 30/10/2022.
//

#include "Student.h"

Student::Student() {
}

Student::Student(int codigo, string nome, list<UCTurma> list) {
    codEst=codigo;
    nomeEst=nome;
    turmas=list;
}

Student::Student(int codigo, string nome, UCTurma turma) {
    codEst=codigo;
    nomeEst=nome;
    turmas.clear();
    turmas.push_back(turma);
}
bool Student::operator<(const Student &student2) const{
    return (codEst < student2.codEst);
}



void Student::pushback(const Student &student2) {
    turmas.push_back(student2.get_turma());
}

int Student::get_cod() const{
    return codEst;
}

string Student::get_nome() const{
    return nomeEst;
}

UCTurma Student::get_turma() const{
    return turmas.front();
}

list<UCTurma> Student::get_turmas() const{
    return list<UCTurma>();
}




