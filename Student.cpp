//
// Created by inviz on 30/10/2022.
//

#include <algorithm>
#include "Student.h"

Student::Student() {
    uccounter=0;
}

Student::Student(int codigo, string nome, list<UCTurma> list) {
    codEst=codigo;
    nomeEst=nome;
    turmas=list;
    uccounter=0;
}

Student::Student(int codigo, string nome, UCTurma turma) {
    codEst=codigo;
    nomeEst=nome;
    turmas.clear();
    turmas.push_back(turma);
    uccounter=0;
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
    return turmas;
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

void Student::inc_uc() {
    uccounter++;
}

int Student::get_nmr_uc() const {
    return uccounter;
}

void Student::remove_turma(const UCTurma &turma2) {
    turmas.erase(find(turmas.begin(),turmas.end(),turma2));
}



