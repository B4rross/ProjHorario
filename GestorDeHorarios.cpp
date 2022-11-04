//
// Created by inviz on 31/10/2022.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
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
        Bloco bloco(diaSemana, horaIni, duracao, tipo, codUC);

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
void GestorDeHorarios::readPedidos() {
    ifstream inputFile1;
    inputFile1.open(R"(C:\Users\inviz\Downloads\turmas pedidos.csv)");
    string line2;
    getline(inputFile1, line2,'\r');
    line2 = "";

    while (getline(inputFile1, line2,'\r')) {

        string aluno;
        string uc;
        string turmaAtual;
        string turmaDesejada;
        stringstream inputString(line2);

        string tipo;
        getline(inputString, tipo, ',');

        if (tipo=="s") {


            getline(inputString, aluno, ',');
            getline(inputString, uc, ',');
            getline(inputString, turmaAtual, ',');
            getline(inputString, turmaDesejada, ',');

            Pedido pedido(aluno, uc, turmaAtual, turmaDesejada,tipo);
            pedidos.push(pedido);

            line2 = "";
        }
        else if (tipo=="r") {


            getline(inputString, aluno, ',');
            getline(inputString, uc, ',');
            getline(inputString, turmaAtual, ',');
            getline(inputString, turmaDesejada, ',');

            Pedido pedido(aluno, uc, turmaAtual, turmaDesejada,tipo);
            pedidos.push(pedido);

            line2 = "";
        }
        else if (tipo=="r") {


            getline(inputString, aluno, ',');
            getline(inputString, uc, ',');
            getline(inputString, turmaAtual, ',');
            getline(inputString, turmaDesejada, ',');

            Pedido pedido(aluno, uc, turmaAtual, turmaDesejada, tipo);
            pedidos.push(pedido);

            line2 = "";
        }
    }
}
void GestorDeHorarios::readFiles() {
    readStudents();
    readClassesperUc();
    readClasses();
    readPedidos();
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

void GestorDeHorarios::listar_alunosUc(string uc) const{
    vector<Student> temp = students.iterate();
    cout<<"Alunos inscritos na cadeira:"<<uc<<endl;
    for (Student& student : temp){
        if (student.is_in_uc(uc)){
            cout<<student.get_nome()<<endl;
        }
    }
}

void GestorDeHorarios::listar_alunosTurma(string turma) const{
    vector<Student> temp = students.iterate();
    cout<<"Alunos inscritos na turma:"<<turma<<endl;
    for (Student& student : temp){
        if (student.is_in_turma(turma)){
            cout<<student.get_nome()<<endl;
        }
    }
}

void GestorDeHorarios::listar_alunosAno(char ano) const{
    vector<Student> temp = students.iterate();
    cout<<"Alunos inscritos no "<<ano<<"º ano:"<<endl;
    for (Student& student : temp){
        if (student.is_in_ano(ano)){
            cout<<student.get_nome()<<endl;
        }
    }
}

void GestorDeHorarios::listar_horario(string aluno) {
    map<std::string, int> map1;
    map1["Monday"] = 0;
    map1["Tuesday"] = 1;
    map1["Wednesday"] = 2;
    map1["Thursday"] = 3;
    map1["Friday"] = 4;
    Student student = students.find(aluno);
    vector<vector<Bloco>> blocos (5);
    for (UCTurma ucTurma : student.get_turmas()){
        for(TurmaHo turmaHo : horarios){
            if (ucTurma==turmaHo.get_turma()){
                for(Bloco bloco :turmaHo.get_bloco()){
                    blocos[map1[bloco.get_dia()]].push_back(bloco);
                }
            }
        }
    }

    for(int i = 0; i<5; i++){
        vector<Bloco> vetor = blocos[i];
        switch (i) {
            case 0:cout<<"-----MONDAY----"<<endl;break;
            case 1:cout<<"-----TUESDAY----"<<endl;break;
            case 2:cout<<"-----WEDNESDAY----"<<endl;break;
            case 3:cout<<"-----THURSDAY----"<<endl;break;
            case 4:cout<<"-----FRIDAY----"<<endl;break;
        }
        sort(vetor.begin(),vetor.end());
        for (Bloco bloco : vetor) {
            cout<<"UC:"<<bloco.get_uc()<<endl;
            cout<<"Tipo:"<<bloco.get_tipo()<<endl;
            cout<<bloco.get_horaI()<<'-'<<bloco.get_horaF()<<endl;
        }
    }

}

void GestorDeHorarios::listar_alunos_nmrUC(int i) const{
    vector<Student> temp = students.iterate();
    cout<<"Alunos inscritos em mais de "<<i<<" UC's:"<<endl;
    for (Student& student : temp){
        if (student.get_nmr_uc()>i){
            cout<<student.get_nome()<<endl;
        }
    }
}

void GestorDeHorarios::processarPedidos() {
    Pedido pedido;
    pedido = pedidos.pop();
    UCTurma turma = horarios.pop_back();
}





