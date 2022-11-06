//
// Created by inviz on 31/10/2022.
//

#ifndef UNTITLED_GESTORDEHORARIOS_H
#define UNTITLED_GESTORDEHORARIOS_H


#include <vector>
#include <functional>
#include <queue>
#include <map>
#include "BST.h"
#include "TurmaHo.h"
#include "Pedido.h"

class GestorDeHorarios {
    BST students;
    vector<TurmaHo> horarios;
    queue<Pedido> pedidos;
    map<string,int> ocuTurmas;
public:
    GestorDeHorarios();
    void readStudents();
    void readClassesperUc();
    void readClasses();
    void readPedidos();
    void readFiles();
    void processarPedidos();

    void listar_Turmas(const function<bool(TurmaHo,TurmaHo)>& func) const;
    void listar_alunosTurma(string Turma) const;
    void listar_alunosUc(string uc) const;
    void listar_alunosAno(char ano) const;
    void listar_horario(string aluno) ;
    void listar_alunos_nmrUC(int i)const;
    bool can_add(Student& student, UCTurma turma);
    void swap(Student &student, list<Pedido> requests);
    bool contains(list<Pedido> lista, UCTurma& turma);

    void inserir_pedido();

    bool contains(list<UCTurma> lista, UCTurma &turma);
};


#endif //UNTITLED_GESTORDEHORARIOS_H
