//
// Created by inviz on 29/10/2022.
//

#ifndef UNTITLED_BLOCO_H
#define UNTITLED_BLOCO_H
#include <string>

using namespace std;

class Bloco {
    string diaSemana;
    float horaIni;
    float horaFim;
    string tipo;
public:
    Bloco(string dia, float horai, float duracao, string t);

};


#endif //UNTITLED_BLOCO_H
