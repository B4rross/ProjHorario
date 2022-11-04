//
// Created by inviz on 04/11/2022.
//

#include "Pedido.h"

Pedido::Pedido() {

}

Pedido::Pedido(string aluno_, string uc_, string tA, string tD, string t) {
    aluno=aluno_;
    uc=uc_;
    turmaAtual=tA;
    turmaDesejada=tD;
    tipo=t;
}

Pedido::Pedido(string aluno_, string uc_, string tA, string t) {
    aluno=aluno_;
    uc=uc_;
    turmaAtual=tA;

    tipo=t;
}

string Pedido::get_nome() const {
    return aluno;
}
string Pedido::get_uc() const {
    return uc;
}
string Pedido::get_turmaA() const {
    return turmaAtual;
}
string Pedido::get_turmaD() const {
    return turmaDesejada;
}

string Pedido::get_tipo() const {
    return tipo;
}

void Pedido::operator=(Pedido &pedido) {
    aluno=pedido.get_nome();
    uc=pedido.get_uc();
    turmaAtual=pedido.get_turmaA();
    turmaDesejada=pedido.get_turmaD();
    tipo=pedido.get_tipo();
}
