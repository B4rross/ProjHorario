//
// Created by inviz on 29/10/2022.
//

#ifndef UNTITLED_UCTURMA_H
#define UNTITLED_UCTURMA_H
#include <string>

using namespace std;
class UCTurma {
    std::string codUC;
    std::string codTurma;
public:
    UCTurma(string uc, string turma);
    string getUC();
    string getTurma();
};


#endif //UNTITLED_UCTURMA_H
