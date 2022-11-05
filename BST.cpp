//
// Created by inviz on 31/10/2022.
//

#include <iostream>
#include <mmcobj.h>
#include <vector>
#include "BST.h"


Student& BST::find(const Student &x) {
    return find(x,root);
}


Student& BST::find(const Student &x, BST::Node *&t) {
    if ( t == NULL )
        throw "Utilizador nao encontrado";
    else if (x < t->student) {
        return find(x, t->left);
    } else if (t->student < x)
        return find(x, t->right);
    else return t->student;
}

bool BST::insert(const Student &x) {
    return insert (x,root);
}

bool BST::insert(const Student &x, BST::Node *&t) {
    if ( t == NULL ) {
        t = create(x);
        return true;
    }
    else if ( x < t->student)
        return insert(x, t->left);
    else if (t->student < x)
        return insert(x, t->right);
    else{
        t->student.pushback(x);
        return true;
    }
}

BST::BST() {
    root=NULL;
}

BST::BST(Student student_) {
    root = create(student_);
}

vector<Student> BST::iterate(bstit it) const{
    vector<Student> temp;
    while (!it.isEnd())
        temp.push_back(it.curr()->student),it.next();
    return temp;
}

vector<Student> BST::iterate() const{
    bstit it(root);
    return iterate(it);
}

Student &BST::find(string x) {
    return find(x,root);
}

Student &BST::find(string x, BST::Node *&t) {
    if ( t == NULL )
        throw "Utilizador nao encontrado";
    else if (x < (t->student).get_nome()) {
        return find(x, t->left);
    } else if ((t->student).get_nome() < x)
        return find(x, t->right);
    else return t->student;
}