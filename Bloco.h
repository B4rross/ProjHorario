//
// Created by inviz on 29/10/2022.
//

#ifndef UNTITLED_BLOCO_H
#define UNTITLED_BLOCO_H
#include <string>

using namespace std;

class Bloco {
    string diaSemana;
    string uc;
    float horaIni;
    float horaFim;
    string tipo;
    string turma;
public:
    Bloco(string dia, float horai, float duracao, string t, string ucc, string turma);
    string get_dia() const;
    string get_uc() const;
    string get_turma() const;
    string get_tipo() const;
    float get_horaI() const;
    float get_horaF() const;

    bool operator< (const Bloco& student2) const;

};


#endif //UNTITLED_BLOCO_H
