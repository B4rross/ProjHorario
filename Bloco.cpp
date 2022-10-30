//
// Created by inviz on 29/10/2022.
//

#include "Bloco.h"

Bloco::Bloco(string dia, int horai, int duracao, string type) {
    diaSemana=dia;
    horaIni=horai;
    horaFim=horai + duracao;
    tipo=type;
}
