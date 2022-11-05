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
    inputFile1.open(R"(C:\Users\inviz\CLionProjects\untitled\students_classes.csv)");
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
        string b = turma.getBoth();
        Student estudante(codEst, nomeEst, turma);
        students.insert(estudante);
        if(ocuTurmas.count(b)>0) {
            int i = ocuTurmas[b];
            i++;
            ocuTurmas[b] = i;
        }
        else ocuTurmas[b] = 1;



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
        Bloco bloco(diaSemana, horaIni, duracao, tipo, codTurma, codUC);

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
    inputFile1.open(R"(C:\Users\inviz\CLionProjects\untitled\turmas pedidos.csv)");
    string line2;
    getline(inputFile1, line2,'\n');
    line2 = "";

    while (getline(inputFile1, line2,'\n')) {
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
        else if (tipo=="a") {


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
            cout<<"UC/Turma:"<<bloco.get_uc()<<'/'<<bloco.get_turma()<<endl;
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
        while(!(pedidos.empty())){
        Pedido pedido = pedidos.front();
        Student& student = students.find(pedido.get_nome());
        if (pedido.get_tipo() == "a") {
            UCTurma turma(pedido.get_uc(), pedido.get_turmaA());
            if (can_add(student, turma)) {
                student.add_turma(turma);
            }
            pedidos.pop();
        } else if (pedido.get_tipo() == "r") {
            UCTurma turma(pedido.get_uc(), pedido.get_turmaA());
            (students.find(pedido.get_nome())).remove_turma(turma);
            pedidos.pop();
        } else if (pedido.get_tipo() == "s") {
            list<Pedido> requests;
            UCTurma turma(pedido.get_uc(),pedido.get_turmaD());
            requests.push_back(pedido);
            string nome = pedido.get_nome();
            pedidos.pop();
            while(!(pedidos.empty())&&(pedidos.front().get_tipo()=="s")&&(pedidos.front().get_nome()==nome)){
                requests.push_back(pedidos.front());
                pedidos.pop();
            }
            swap(student, requests);


        }
    }
    ofstream file;
    file.open("results.txt");
    vector<Student> estudantes=students.iterate();
    for (Student student : estudantes) {
        int num=student.get_cod();
        string cod = to_string(num);
        string nome=student.get_nome();

        list<UCTurma> turmas = student.get_turmas();
        for(UCTurma turma : turmas){
            string uc = turma.getUC();
            string t = turma.getTurma();
            string final = cod+','+nome+','+uc+','+t;
            file<<final<<'\n';
        }
    }
}

bool GestorDeHorarios::can_add(Student &student, UCTurma turma) {
    if (ocuTurmas[turma.getBoth()]+1>25) return false;
    for (TurmaHo turmaHo : horarios){
        if ((turmaHo.get_turma()).getUC()==turma.getUC()){
            if (ocuTurmas[(turmaHo.get_turma()).getBoth()]-ocuTurmas[turma.getBoth()]>2 || ocuTurmas[turma.getBoth()]-ocuTurmas[(turmaHo.get_turma()).getBoth()]>2) return false;
        }
    }
    map<std::string, int> map1;
    map1["Monday"] = 0;
    map1["Tuesday"] = 1;
    map1["Wednesday"] = 2;
    map1["Thursday"] = 3;
    map1["Friday"] = 4;
    vector<vector<Bloco>> horario (5);
    for (UCTurma ucTurma : student.get_turmas()){
        for(TurmaHo turmaHo : horarios){
            if (ucTurma==turmaHo.get_turma()){
                for(Bloco bloco :turmaHo.get_bloco()){
                    horario[map1[bloco.get_dia()]].push_back(bloco);
                }
            }
        }
    }
    int max=0;
    int min=0;
    string dia;
    for(TurmaHo turmaHo : horarios){
        if(turma==turmaHo.get_turma()){
            for(Bloco bloco : turmaHo.get_bloco()){
                if(bloco.get_tipo()=="TP"||bloco.get_tipo()=="PL"){
                    max=bloco.get_horaF();
                    min=bloco.get_horaI();
                    dia=bloco.get_dia();
                    break;
                }
            }
            break;
        }
    }
    for(Bloco bloco : horario[map1[dia]]){
        if ((min>bloco.get_horaI()&&min<bloco.get_horaF())||(max>bloco.get_horaI()&&max<bloco.get_horaF())) return false;
    }
    return true;
}

void GestorDeHorarios::swap(Student &student, list<Pedido> requests) {
    map<std::string, int> map1;
    map1["Monday"] = 0;
    map1["Tuesday"] = 1;
    map1["Wednesday"] = 2;
    map1["Thursday"] = 3;
    map1["Friday"] = 4;
    vector<vector<Bloco>> horario (5);
    for (UCTurma ucTurma : student.get_turmas()){
        for(TurmaHo turmaHo : horarios){
            if (ucTurma==turmaHo.get_turma() && !(contains(requests,ucTurma))){
                for(Bloco bloco :turmaHo.get_bloco()){
                    horario[map1[bloco.get_dia()]].push_back(bloco);
                }
            }
        }
    }
    for(Pedido& pedido : requests) {
        int max = 0;
        int min = 0;
        string dia;
        UCTurma ucturmaD(pedido.get_uc(),pedido.get_turmaD());
        for (TurmaHo turmaHo: horarios) {
            if (ucturmaD == turmaHo.get_turma()) {
                for (Bloco bloco: turmaHo.get_bloco()) {
                    if (bloco.get_tipo() == "TP" || bloco.get_tipo() == "PL") {
                        max = bloco.get_horaF();
                        min = bloco.get_horaI();
                        dia = bloco.get_dia();
                        break;
                    }
                }
                break;
            }
        }
        bool flag=true;
        for (Bloco bloco: horario[map1[dia]]) {
            if ((min > bloco.get_horaI() && min < bloco.get_horaF()) ||
                (max > bloco.get_horaI() && max < bloco.get_horaF()) && (bloco.get_tipo() == "TP" || bloco.get_tipo() == "PL"))
                flag=false;
                break;
        }
        if(flag) {
            Bloco bloco(dia,min,max,"TP","","");
            horario[map1[dia]].push_back(bloco);
            UCTurma ucturmaA(pedido.get_uc(),pedido.get_turmaA());
            student.remove_turma(ucturmaA);
            student.add_turma(ucturmaD);

        }
    }
}

bool GestorDeHorarios::contains(list<Pedido> lista, UCTurma& turma){
    for(const Pedido& pedido : lista){
        UCTurma ucturma(pedido.get_uc(),pedido.get_turmaA());
        if(ucturma==turma) return true;
    }
    return false;
}

void GestorDeHorarios::inserir_pedido() {
    string tipo;
    string uc;
    string nome;
    string turmaA;
    string turmaD;
    cout << "Insira um pedido seguindo as instruções:\n";
    cout << "Tipo de pedido ('a' para adicionar turma, 'r' para remover turma, 's' para trocar turmas:\n";
    cin>>tipo;
    cout << "Nome do aluno:\n";
    cin>>nome;
    cout << "Unidade curricular:\n";
    cin>>uc;
    if(tipo=="r" || tipo=="s"){
        cout << "Turma atual:\n";
        cin>>turmaA;
    }
    if(tipo=="a" || tipo=="s"){
        cout << "Turma desejada:\n";
        cin>>turmaA;
    }
    Pedido pedido(tipo,nome,uc,turmaA,turmaD);
    pedidos.push(pedido);
}



