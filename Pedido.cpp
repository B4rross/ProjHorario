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

Pedido& Pedido::operator=(Pedido &pedido) {
    return pedido;
}
