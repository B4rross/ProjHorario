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
        cout<<"Opcao 2: Listar es\n";
        cout<<"Opcao 3: Listar estudantes e horários\n";
        cout<<"Opcao 4: Pedidos de mudança de turmas/UCs de um estudante\n";
        cout<<"Opcao 5: Sair do programa\n";
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
            int y;
            do{
                cout<<"Opcao 1: Listar todas as UCs\n";
                cout<<"Opcao 2: Listar o total de alunos por UC\n";
                cout<<"Opcao 3: Listar os estudantes com mais de n UCs\n";
                cout<<"Opcao 4: Sair das UCs\n";
                cout<<"Insira a sua opcao: ";
                cin>>y;

                string uc;
                switch(y){

                    case 1:
                        //h.listar_alunosUc();
                        cout<<"-------------------------------------------\n";
                        break;

                    case 2:
                        cout<<"Aqui devemos chamar fun��o listar_alunos_UC()\n";
                        cout<<"-------------------------------------------\n";
                        break;
                    case 3:
                        cout<<"Aqui devemos chamar fun��o listar_estudantes_maisdenUCs()\n";
                        cout<<"-------------------------------------------\n";
                        break;

                    default:
                        cout<<"Introduza uma opcao valida\n";
                        cout<<"-------------------------------------------\n";
                }
            }
            while(y!=4);
        }
        else if(n==3){
            int z;
            do{
                cout<<"Opcao 1: Listar estudantes em determinada UC\n";
                cout<<"Opcao 2: Listar estudantes em determinada Turma\n";
                cout<<"Opcao 3: Listar estudantes em determinado Ano\n";
                cout<<"Opcao 4: Horario do estudante desejado\n";
                cout<<"Opcao 5: Sair dos estudantes\n";
                cout<<"Insira a sua opcao: ";
                cin>>z;
                system("cls");

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
                    cout<<"Introduza o nome do Aluno desejado:";
                    string aluno;
                    cin>>aluno;
                    h.listar_horario(aluno);
                    cout << "-------------------------------------------\n";
                }
                else if(z!=5){
                    cout<<"Introduza uma opcao valida\n";
                    cout<<"-------------------------------------------\n";
                }
            }
            while(z!=5);
        }
        else if(n==4){
            cout<<"Aqui devemos chamar fun��o pedidos()\n";
            cout<<"-------------------------------------------\n";
        }
        else if(n==5){
            //Aqui devemos chamar fun��o guardar_dados() que guarda os dados das estruturas nos ficheiros\n;
        }
        else{
            cout<<"Introduza uma opcao valida\n";
            cout<<"-------------------------------------------\n";
        }
    }
    while(n!=5);
}

