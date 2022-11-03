//
// Created by inviz on 31/10/2022.
//

#ifndef UNTITLED_BST_H
#define UNTITLED_BST_H


#include <stack>
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
    class bstit {
    private:
        // Stack to store the nodes
        // of BST
        stack<Node*> q;

    public:
        // Constructor for the class
        bstit(Node* root)
        {
            // Initializing stack
            Node* curr = root;
            while (curr != NULL)
                q.push(curr), curr = curr->left;
        }

        // Function to return
        // current element iterator
        // is pointing to
        Node* curr()
        {
            return q.top();
        }

        // Function to iterate to next
        // element of BST
        void next()
        {
            Node* curr = q.top()->right;
            q.pop();
            while (curr != NULL)
                q.push(curr), curr = curr->left;
        }

        // Function to check if
        // stack is empty
        bool isEnd()
        {
            return !(q.size());
        }
    };
    BST();
    explicit BST(Student student_);
    bool find(const Student& x);
    bool find(const Student& x, Node* &t);
    bool insert(const Student& x);
    bool insert(const Student& x, Node* &t);
    /*
    //Stack
    void initStack(Node* &t);
    Node* curr();
    void next();
    bool isEnd();
     */
    vector<Student> iterate() const;
    vector<Student> iterate(bstit it) const;


};


#endif //UNTITLED_BST_H
