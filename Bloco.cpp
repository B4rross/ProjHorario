//
// Created by inviz on 29/10/2022.
//

#include "Bloco.h"

Bloco::Bloco(string dia, float horai, float duracao, string type, string ucc, string turmaa) {
    diaSemana=dia;
    horaIni=horai;
    horaFim=horai + duracao;
    tipo=type;
    uc=ucc;
    turma=turmaa;
}

bool Bloco::operator<(const Bloco &bloco2) const {
    return (horaIni<bloco2.get_horaI());
}

float Bloco::get_horaI() const {
    return horaIni;
}

float Bloco::get_horaF() const {
    return horaFim;
}

string Bloco::get_dia() const {
    return diaSemana;
}

string Bloco::get_uc() const {
    return uc;
}

string Bloco::get_tipo() const {
    return tipo;
}

string Bloco::get_turma() const {
    return turma;
}
