//
// Created by inviz on 31/10/2022.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "GestorDeHorarios.h"

GestorDeHorarios::GestorDeHorarios(){

}

void GestorDeHorarios::readStudents() {
    ifstream inputFile1;
    inputFile1.open(R"(C:\Users\inviz\Downloads\schedule\students_classes.csv)");
    string line1;

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
        students.insert(estudante);
        line1 = "";

    }
}
void GestorDeHorarios::readClassesperUc() {
    ifstream inputFile1;
    inputFile1.open(R"(C:\Users\inviz\Downloads\schedule\classes_per_uc.csv)");
    string line2;
    getline(inputFile1, line2);
    line2 = "";

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

    string line3;
    getline(inputFile1, line3);
    line3 = "";
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


        UCTurma turma(codTurma, codUC);
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

void GestorDeHorarios::listar_Turmas(const function<bool(TurmaHo,TurmaHo)>& func) const{
    vector<TurmaHo> temp = horarios;
    sort(temp.begin(),temp.end(),func);
    for (TurmaHo turma : temp){
        cout<<"----------------"<<endl;
        cout<<"Uc:"<<(turma.get_turma().getUC())<<endl;
        cout<<"Turma:"<<(turma.get_turma().getTurma())<<endl;
    }
}

void GestorDeHorarios::listar_alunos() const{
    vector<Student> temp = students.iterate();

    for (Student& student : temp){
        cout<<student.get_nome()<<'|';
    }


}



