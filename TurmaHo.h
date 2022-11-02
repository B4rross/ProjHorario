//
// Created by inviz on 29/10/2022.
//

#ifndef UNTITLED_TURMAHO_H
#define UNTITLED_TURMAHO_H


#include <list>
#include "UCTurma.h"
#include "Bloco.h"

class TurmaHo {
    UCTurma ucturma;
    list<Bloco> ucTurmaBloco;
public:
    TurmaHo();
    TurmaHo(UCTurma turma);
    TurmaHo(UCTurma turma, Bloco bloco);
    UCTurma get_turma() const;
    void pushback(Bloco bloco);
    bool operator== (const TurmaHo& turma2) const;
};


#endif //UNTITLED_TURMAHO_H
