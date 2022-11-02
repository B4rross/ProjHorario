//
// Created by inviz on 31/10/2022.
//

#ifndef UNTITLED_BST_H
#define UNTITLED_BST_H


#include "Student.h"

class BST {
    struct Node{
        Student student;
        Node* right;
        Node* left;
    };

    static Node* create(const Student& data) {
        Node *temp = new Node();
        temp->student = data;
        temp->right = temp->left = NULL;
        return temp;
    }

    Node* root;

public:
    BST();
    explicit BST(Student student_);
    bool find(const Student& x);
    bool find(const Student& x, Node* &t);
    bool insert(const Student& x);
    bool insert(const Student& x, Node* &t);
};


#endif //UNTITLED_BST_H
