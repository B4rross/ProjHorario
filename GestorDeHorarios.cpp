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
    //inputFile2.open(R"(C:\Users\inviz\Downloads\schedule\classes_per_uc.csv)");
    //inputFile3.open(R"(C:\Users\inviz\Downloads\schedule\classes.csv)");
    string line1;
    BST arvore;
    //vector<TurmaHo> turmasHo;
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
        cout << "------------" << endl << codEst << endl;
        getline(inputString, nomeEst, ',');
        cout << nomeEst << endl;
        getline(inputString, codUC, ',');
        cout << codUC << endl;
        getline(inputString, codTurma, ',');
        cout << codTurma << endl << "------------" << endl;


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
        cout<<"------------"<<endl<<codUC<<endl;
        getline(inputString, codTurma, ',');
        cout<<codTurma<<endl;

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
        cout << "------------" << endl << codUC << endl;
        getline(inputString, codTurma, ',');
        cout << codTurma << endl;
        getline(inputString, diaSemana, ',');
        cout << diaSemana << endl;

        getline(inputString, temp, ',');
        horaIni = atof(temp.c_str());
        cout << horaIni << endl;
        getline(inputString, temp, ',');
        duracao = atof(temp.c_str());
        cout << duracao << endl;

        getline(inputString, tipo, ',');
        cout << tipo << endl << "-----------" << endl;

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
