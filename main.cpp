#include <iostream>
#include <stdlib.h>
#include "GestorDeHorarios.h"

using namespace std;
int main(){
    int n;
    GestorDeHorarios h;
    h.readFiles();
    //Aqui devemos chamar a fun��o enviar_dados() que envia os dados dos ficheiros para as estruturas\n;
    do{
        cout<<"Opcao 1: Listar turmas\n";
        cout<<"Opcao 2: Listar UCs\n";
        cout<<"Opcao 3: Listar estudantes\n";
        cout<<"Opcao 4: Pedidos de mudanca de turmas/UCs de um estudante(horario)\n";
        cout<<"Opcao 5: Sair do programa\n";
        cout<<"Insira a sua opcao: ";
        cin>>n;

        if(n==1){
            int x;
            do{
                cout<<"Opcao 1: Listar todas as turmas\n";
                cout<<"Opcao 2: Listar as turmas selecionadas pelo utilizador\n";
                cout<<"Opcao 3: Listar o total de alunos por turma/ano\n";
                cout<<"Opcao 4: Sair das turmas\n";
                cout<<"Insira a sua opcao: ";
                cin>>x;
                system("cls");
                switch(x){
                    case 1:

                        cout<<"-------------------------------------------\n";
                        break;
                    case 2:
                        cout<<"Aqui devemos chamar fun��o listar_turmas_selecionadas()\n";
                        cout<<"-------------------------------------------\n";
                        break;
                    case 3:
                        cout<<"Aqui devemos chamar fun��o listar_alunos_turma()\n";
                        cout<<"-------------------------------------------\n";
                        break;
                    default:
                        cout<<"Introduza uma opcao valida\n";
                        cout<<"-------------------------------------------\n";
                }
            }
            while(x!=4);
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
                        h.listar_Uc();
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
                cout<<"Opcao 1: Listar os dados de todos os estudantes\n";
                cout<<"Opcao 2: Listar os dados dos estudantes selecionados pelo utilizador\n";
                cout<<"Opcao 3: Listar todas as UCs de um estudante(horario)\n";
                cout<<"Opcao 4: Sair dos estudantes\n";
                cout<<"Insira a sua opcao: ";
                cin>>z;
                system("cls");
                switch(z){
                    case 1:
                        cout<<"Aqui devemos chamar fun��o listar_estudantes()\n";
                        cout<<"-------------------------------------------\n";
                        break;
                    case 2:
                        cout<<"Aqui devemos chamar fun��o listar_estudantes_selecionados()\n";
                        cout<<"-------------------------------------------\n";
                        break;
                    case 3:
                        cout<<"Aqui devemos chamar fun��o listar_UCs_estudante()\n";
                        cout<<"-------------------------------------------\n";
                        break;
                    default:
                        cout<<"Introduza uma opcao valida\n";
                        cout<<"-------------------------------------------\n";
                }
            }
            while(z!=4);
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

