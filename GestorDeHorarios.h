//
// Created by inviz on 31/10/2022.
//

#ifndef UNTITLED_GESTORDEHORARIOS_H
#define UNTITLED_GESTORDEHORARIOS_H


#include <vector>
#include "BST.h"
#include "TurmaHo.h"

class GestorDeHorarios {
    BST students;
    vector<TurmaHo> horarios;
    //queue<Pedido> pedidos;
public:
    GestorDeHorarios();
    void readStudents();
    void readClassesperUc();
    void readClasses();
    void readFiles();

};


#endif //UNTITLED_GESTORDEHORARIOS_H
