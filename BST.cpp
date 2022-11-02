//
// Created by inviz on 31/10/2022.
//

#include "BST.h"


bool BST::find(const Student &x) {
    return find(x,root);
}


bool BST::find(const Student &x, BST::Node *&t) {
    if ( t == NULL )
        return NULL;
    else if (x < t->student) {
        return find(x, t->left);
    } else if (t->student < x)
        return find(x, t->right);
    else return t;
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
}

BST::BST(Student student_) {
    root = create(student_);
}




