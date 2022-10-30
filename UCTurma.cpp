//
// Created by inviz on 29/10/2022.
//

#include "UCTurma.h"

UCTurma::UCTurma(string uc, string turma) {
    codUC=uc;
    codTurma=turma;
}

string UCTurma::getUC() {
    return codUC;
}

string UCTurma::getTurma() {
    return codTurma;
}
