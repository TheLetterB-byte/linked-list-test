#include <iostream>
#include <new>
#include "linkedlist.h"
using namespace std;

LinkedList::LinkedList(){
    first = NULL;
    last = NULL;
}

LinkedList::~LinkedList(){
    while (first != NULL){
        Node* temp = first;
        first = first->next;
        delete[] temp;
    }
    last = NULL;
}

void LinkedList::insertAtBack(int valueToInsert){
    Node* x = new Node();
    x->next = NULL;
    x->val = valueToInsert;
    if (first == NULL){
        first = x;
    }else {
        Node* temp = first;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = x;
    }
}

bool LinkedList::removeFromBack(){
    Node* temp = first;
    if (temp == nullptr){
        return false;
    } else if(temp->next == nullptr){
        return false;
    }
    while (temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = nullptr;

    return true;
}

void LinkedList::print(){
    Node* temp = first;
    while(temp != NULL){
        cout << temp->val << ',';
        temp = temp->next;
    }
}

bool LinkedList::isEmpty(){
    Node* temp = first;
    if (temp == NULL) {
        return true;
    } else {
        return false;
        delete[] temp;
    }
}

int LinkedList::size(){
    Node* temp = first;
    int count = 0;
    while (temp != NULL){
        count++;
        temp = temp ->next;
    }
    return count;
}

void LinkedList::clear(){
    Node* temp = first;
    Node* t = NULL;
    while (temp != NULL){
        temp = temp->next;
        delete[] temp;
        temp = t;
    }
    first = NULL;
}

void LinkedList::insertAtFront(int valueToInsert){
    Node *frontval = new Node();
    frontval->val = valueToInsert;
    frontval->next = first;
    first = frontval;
}

bool LinkedList::removeFromFront(){
    if (first == NULL){
        return false;
    }
    first = first->next;
    return true;
}