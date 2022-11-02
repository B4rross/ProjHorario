//
// Created by inviz on 31/10/2022.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include "GestorDeHorarios.h"

GestorDeHorarios::GestorDeHorarios(){

}

void GestorDeHorarios::readFiles() {
    ifstream inputFile1;
    ifstream inputFile2;
    inputFile1.open(R"(C:\Users\inviz\Downloads\schedule\students_classes.csv)");
    inputFile2.open(R"(C:\Users\inviz\Downloads\schedule\classes_per_uc.csv)");
    //inputFile3.open(R"(C:\Users\inviz\Downloads\schedule\classes.csv)");
    string line;
    BST arvore;
    vector<TurmaHo> turmasHo;
    while (getline(inputFile1, line)) {
        int codEst;
        string nomeEst;
        string codUC;
        string codTurma;
        string temp;

        stringstream inputString(line);

        getline(inputString, temp, ',');
        codEst = atoi(temp.c_str());
        cout<<"------------"<<endl<<codEst<<endl;
        getline(inputString, nomeEst, ',');
        cout<<nomeEst<<endl;
        getline(inputString, codUC, ',');
        cout<<codUC<<endl;
        getline(inputString, codTurma, ',');
        cout<<codTurma<<endl<<"------------"<<endl;


        UCTurma turma(codUC,codTurma);

        Student estudante(codEst,nomeEst,turma);
        arvore.insert(estudante);
        line = "";

    }
/*
    while (getline(inputFile2, line)) {
        string codUC;
        string codTurma;


        stringstream inputString(line);

        getline(inputString, codUC, ',');
        cout<<"------------"<<endl<<codUC<<endl;
        getline(inputString, codTurma, ',');
        cout<<codTurma<<endl;

        UCTurma turma(codUC,codTurma);
        TurmaHo turmaHo(turma);
        horarios.push_back(turmaHo);

        line = "";

    }
/*
    while (getline(inputFile3, line)) {
        string diaSemana;
        float horaIni;
        float duracao;
        string tipo;
        string codUC;
        string codTurma;
        string temp;

        stringstream inputString(line);

        getline(inputString, codUC, ',');
        cout<<"------------"<<endl<<codUC<<endl;
        getline(inputString, codTurma, ',');
        cout<<codTurma<<endl;
        getline(inputString, diaSemana, ',');
        cout<<diaSemana<<endl;

        getline(inputString, temp, ',');
        horaIni = atof(temp.c_str());
        getline(inputString, temp, ',');
        duracao = atof(temp.c_str());

        getline(inputString, tipo, ',');
        cout<<tipo<<endl;

        UCTurma turma(codUC,codTurma);
        Bloco bloco(diaSemana,horaIni,duracao,tipo);

        TurmaHo turmaHo(turma);

        for (TurmaHo &turminha : horarios){
            if (turmaHo==turminha){
                turminha.pushback(bloco);
                break;
            }
            else continue;
        }

        line = "";

    }
*/
}