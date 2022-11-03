//
// Created by inviz on 31/10/2022.
//

#ifndef UNTITLED_GESTORDEHORARIOS_H
#define UNTITLED_GESTORDEHORARIOS_H


#include <vector>
#include <functional>
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
    void listar_Turmas(const function<bool(TurmaHo,TurmaHo)>& func) const;
    void listar_alunosTurma(string Turma) const;
    void listar_alunosUc(string uc) const;
    void listar_alunosAno(char ano) const;
    void listar_horario(string aluno) ;
};


#endif //UNTITLED_GESTORDEHORARIOS_H
