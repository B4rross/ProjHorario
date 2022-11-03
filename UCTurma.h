//
// Created by inviz on 29/10/2022.
//

#ifndef UNTITLED_UCTURMA_H
#define UNTITLED_UCTURMA_H
#include <string>

using namespace std;
class UCTurma {
    string codUC;
    string codTurma;
public:
    UCTurma();
    UCTurma(string uc, string turma);
    string getUC() const;
    string getTurma() const;
    bool operator== (const UCTurma& turma) const;
    bool operator< (const UCTurma& turma) const;
};


#endif //UNTITLED_UCTURMA_H
