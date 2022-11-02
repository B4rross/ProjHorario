//
// Created by inviz on 31/10/2022.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include "GestorDeHorarios.h"

GestorDeHorarios::GestorDeHorarios(){

}

void GestorDeHorarios::readStudents() {
    ifstream inputFile1;
    inputFile1.open(R"(C:\Users\inviz\Downloads\schedule\students_classes.csv)");
    string line1;
    BST arvore;
    getline(inputFile1, line1);
    line1 = "";

    while (getline(inputFile1, line1)) {
        int codEst;
        string nomeEst;
        string codUC;
        string codTurma;
        string temp;

        stringstream inputString(line1);

        getline(inputString, temp, ',');
        codEst = atoi(temp.c_str());

        getline(inputString, nomeEst, ',');

        getline(inputString, codUC, ',');

        getline(inputString, codTurma, ',');



        UCTurma turma(codUC, codTurma);

        Student estudante(codEst, nomeEst, turma);
        arvore.insert(estudante);
        line1 = "";

    }
}
void GestorDeHorarios::readClassesperUc() {
    ifstream inputFile1;
    inputFile1.open(R"(C:\Users\inviz\Downloads\schedule\classes_per_uc.csv)");

    string line2="";
    while (getline(inputFile1, line2)) {
        string codUC;
        string codTurma;


        stringstream inputString(line2);

        getline(inputString, codUC, ',');

        getline(inputString, codTurma, ',');


        UCTurma turma(codUC,codTurma);
        TurmaHo turmaHo(turma);
        horarios.push_back(turmaHo);

        line2 = "";

    }
}
void GestorDeHorarios::readClasses() {
    ifstream inputFile1;
    inputFile1.open(R"(C:\Users\inviz\Downloads\schedule\classes.csv)");

    string line3 = "";

    while (getline(inputFile1, line3)) {
        string diaSemana;
        float horaIni;
        float duracao;
        string tipo;
        string codUC;
        string codTurma;
        string temp;

        stringstream inputString(line3);

        getline(inputString, codUC, ',');

        getline(inputString, codTurma, ',');

        getline(inputString, diaSemana, ',');


        getline(inputString, temp, ',');
        horaIni = atof(temp.c_str());

        getline(inputString, temp, ',');
        duracao = atof(temp.c_str());


        getline(inputString, tipo, ',');


        UCTurma turma(codUC, codTurma);
        Bloco bloco(diaSemana, horaIni, duracao, tipo);

        TurmaHo turmaHo(turma);

        for (TurmaHo &turminha: horarios) {
            if (turmaHo == turminha) {
                turminha.pushback(bloco);
                break;
            } else continue;
        }

        line3 = "";

    }
}

void GestorDeHorarios::readFiles() {
    readStudents();
    readClassesperUc();
    readClasses();
}

void GestorDeHorarios::listar_Uc() const{
    string uc;
    for(TurmaHo turmaHo : horarios){
        if(uc==""){
            uc="a";
            continue;
        }
        else if((turmaHo.get_turma()).getUC()!=uc) {
            cout << (turmaHo.get_turma()).getUC() << endl;
            uc=turmaHo.get_turma().getUC();
        }
    }
}


