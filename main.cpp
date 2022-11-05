#include <iostream>
#include <stdlib.h>
#include "GestorDeHorarios.h"

using namespace std;
int main(){
    int n;
    GestorDeHorarios h;
    h.readFiles();
    do{
        cout<<"Opcao 1: Listar turmas\n";
        cout<<"Opcao 2: Listar estudantes e horarios\n";
        cout<<"Opcao 3: Pedidos de mudanca de turmas/UCs de um estudante\n";
        cout<<"Opcao 4: Sair do programa\n";
        cout<<"Insira a sua opcao: ";
        cin>>n;

        if(n==1){
            int x;
            do{
                cout<<"Opcao 1: Listar todas as turmas por ordem crecente\n";
                cout<<"Opcao 2: Listar todas as turmas por ordem decrecente\n";
                cout<<"Opcao 3: Listar todas as turmas por ordem crecente de UC\n";
                cout<<"Opcao 4: Listar todas as turmas por ordem decrecente de UC\n";
                cout<<"Opcao 5: Sair das turmas\n";
                cout<<"Insira a sua opcao: ";
                cin>>x;

                if(x==1) {
                    auto lambda = [](TurmaHo a,TurmaHo b){
                        return ((a.get_turma()).getTurma() < (b.get_turma()).getTurma());
                    };
                    h.listar_Turmas(lambda);
                    cout << "-------------------------------------------\n";
                }
                else if (x==2) {
                    auto lambda = [](TurmaHo a,TurmaHo b){
                        return ((a.get_turma()).getTurma() > (b.get_turma()).getTurma());
                    };
                    h.listar_Turmas(lambda);
                    cout << "-------------------------------------------\n";
                }
                else if (x==3) {
                    auto lambda = [](TurmaHo a,TurmaHo b){
                        return ((a.get_turma()).getUC() < (b.get_turma()).getUC());
                    };
                    h.listar_Turmas(lambda);
                    cout << "-------------------------------------------\n";
                }
                else if (x==4) {
                    auto lambda = [](TurmaHo a,TurmaHo b){
                        return ((a.get_turma()).getUC() > (b.get_turma()).getUC());
                    };
                    h.listar_Turmas(lambda);
                    cout<<"-------------------------------------------\n";
                }
                else if(x!=5){
                    cout<<"Introduza uma opcao valida\n";
                    cout<<"-------------------------------------------\n";
                }
            }
            while(x!=5);
        }

        else if(n==2){
            int z;
            do{
                cout<<"Opcao 1: Listar estudantes em determinada UC\n";
                cout<<"Opcao 2: Listar estudantes em determinada Turma\n";
                cout<<"Opcao 3: Listar estudantes em determinado Ano\n";
                cout<<"Opcao 4: Listar estudantes em mais de n UC's\n";
                cout<<"Opcao 5: Horario do estudante desejado\n";
                cout<<"Opcao 6: Sair dos estudantes\n";
                cout<<"Insira a sua opcao: ";
                cin>>z;


                if(z==1) {
                    cout<<"Introduza UC desejada:";
                    string uc;
                    cin>>uc;
                    h.listar_alunosUc(uc);

                    cout << "-------------------------------------------\n";

                }
                else if(z==2) {
                    cout<<"Introduza Turma desejada:";
                    string turma;
                    cin>>turma;
                    h.listar_alunosTurma(turma);
                    cout << "-------------------------------------------\n";
                }
                else if(z==3) {
                    cout<<"Introduza ano desejado:";
                    char ano;
                    cin>>ano;
                    h.listar_alunosAno(ano);
                    cout << "-------------------------------------------\n";
                }
                else if(z==4){
                    cout<<"Introduza o valor de n desejado:";
                    int n;
                    cin>>n;
                    h.listar_alunos_nmrUC(n);
                    cout << "-------------------------------------------\n";
                }
                else if(z==5){
                    cout<<"Introduza o nome do Aluno desejado:";
                    string aluno;
                    cin>>aluno;
                    h.listar_horario(aluno);
                    cout << "-------------------------------------------\n";
                }

                else if(z!=6){
                    cout<<"Introduza uma opcao valida\n";
                    cout<<"-------------------------------------------\n";
                }
            }
            while(z!=6);
        }
        else if(n==3){
            int z;
            do {
                cout << "Opcao 1: Adicionar pedido\n";
                cout << "Opcao 2: Processar pedidos\n";
                cout << "Opcao 3: Sair dos pedidos\n";
                cout << "Insira a sua opcao: ";
                cin >> z;
                cout << "-------------------------------------------\n";
                if(z==1){
                    h.inserir_pedido();

                }
                else if(z==2) {
                    h.processarPedidos();
                    cout << "-------------------------------------------\n";
                }
            }while(z!=3);
        }
        else if(n!=4){
            cout<<"Introduza uma opcao valida\n";
            cout<<"-------------------------------------------\n";
        }
    }
    while(n!=4);
}

