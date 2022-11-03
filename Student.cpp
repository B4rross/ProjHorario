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
    return (nomeEst < student2.get_nome());
}



void Student::pushback(const Student &student2) {
    turmas.push_back(student2.get_turma());
}



string Student::get_nome() const{
    return nomeEst;
}

long Student::get_cod() const{
    return codEst;
}

UCTurma Student::get_turma() const{
    return turmas.front();
}

list<UCTurma> Student::get_turmas() const{
    return list<UCTurma>();
}

bool Student::is_in_turma(string turma) const {
    for(UCTurma ucturma : turmas){
        if (ucturma.getTurma()==turma) return true;
        else continue;
    }
    return false;
}

bool Student::is_in_uc(string uc) const {
    for(UCTurma ucturma : turmas){
        if (ucturma.getUC()==uc) return true;
        else continue;
    }
    return false;
}

bool Student::is_in_ano(char ano) const{
    for(UCTurma ucturma : turmas){
        if (ucturma.getTurma()[0]==ano) return true;
        else continue;
    }
    return false;
}



