//
// Created by inviz on 04/11/2022.
//

#ifndef UNTITLED_PEDIDO_H
#define UNTITLED_PEDIDO_H
#include <string>

using namespace std;
class Pedido {
    string aluno;
    string uc;
    string turmaAtual;
    string turmaDesejada;
    string tipo;
public:
    Pedido();
    Pedido(string aluno_, string uc_, string tA, string tD, string a);
    Pedido(string aluno_, string uc_, string tA, string a);
    void operator=(Pedido& pedido);
    string get_nome() const;
    string get_uc() const;
    string get_turmaA() const;
    string get_turmaD() const;
    string get_tipo() const;
};



#endif //UNTITLED_PEDIDO_H
