#include <bits/stdc++.h>
using namespace std;

class node{

    public:

        int data;
        node *next;
        node *prev;

} *head = NULL, *tail = NULL;

node *createNode(int n){

    node *newNode = new node();
    newNode->data = n;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;

}

void pushHead(int n){

    node *newNode = createNode(n);

    if(!head){

        head = tail = newNode;
        return;

    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;

}

void pushTail(int n){

    node *newNode = createNode(n);

    if(!tail){

        head = tail = newNode;
        return;

    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;

}

void popHead(){

    if(!head){

        return;

    }

    else if(head == tail){

        head = tail = NULL;
        delete(head);
        return;

    }

    node *curr = head;
    head = head->next;
    head->prev = NULL;

    delete(curr);

}

void popTail(){

    if(!tail){

        return;

    }

    else if(head == tail){

        head = tail = NULL;
        delete(head);
        return;

    }

    node *curr = tail;
    tail = tail->prev;
    tail->next = NULL;

    delete(curr);

}

void pop(int n){

    if(!head){

        return;

    }

    else if(n == head->data){

        popHead();
        return;

    }

    else if(n == tail->data){

        popTail();
        return;

    }

    node *curr = head;

    while(curr && curr->data != n){

        curr = curr->next;

    }

    if(!curr){
        
        cout << "hehe" << endl;
        return;

    }

    curr->next->prev = curr->prev;
    curr->prev->next = curr->next;
    delete(curr);

}

void printAll(){

    node *curr = head;

    while(curr){

        cout << curr->data << " ";
        curr = curr->next;

    }

    cout << endl;

}

int main(){

    pushHead(10);
    pushHead(20);
    pushHead(30);
    pushHead(40);
    printAll();

    pushTail(50);
    pushTail(60);
    pushTail(70);
    pushTail(80);
    printAll();

    pop(80);
    pop(69);

    printAll();

}