//
// Created by inviz on 29/10/2022.
//

#include "TurmaHo.h"



TurmaHo::TurmaHo(UCTurma turma, Bloco bloco) {
    ucturma=turma;
    ucTurmaBloco.clear();
    ucTurmaBloco.push_back(bloco);
}

TurmaHo::TurmaHo() {
}


void TurmaHo::pushback(Bloco bloco) {
    ucTurmaBloco.push_back(bloco);
}

TurmaHo::TurmaHo(UCTurma turma) {
    ucturma=turma;
    ucTurmaBloco.clear();
}

bool TurmaHo::operator==(const TurmaHo &turma2) const {
    return ucturma==turma2.get_turma();
}

bool TurmaHo::operator<(const TurmaHo &turma2) const {
    return ucturma<turma2.get_turma();
}

UCTurma TurmaHo::get_turma() const{
    return ucturma;
}
