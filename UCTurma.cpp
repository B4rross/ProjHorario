//
// Created by inviz on 29/10/2022.
//

#include "UCTurma.h"

UCTurma::UCTurma(string uc, string turma) {
    codUC=uc;
    codTurma=turma;
}

string UCTurma::getUC() const{
    return codUC;
}

string UCTurma::getTurma() const{
    return codTurma;
}

UCTurma::UCTurma() {
}

bool UCTurma::operator==(const UCTurma &turma) const {
    return (codUC==turma.getUC() && codTurma==turma.getTurma());
}
bool UCTurma::operator<(const UCTurma &turma) const {
    return (codTurma<turma.getTurma());
}

string UCTurma::getBoth() const {
    return codUC+"/"+codTurma;
}
