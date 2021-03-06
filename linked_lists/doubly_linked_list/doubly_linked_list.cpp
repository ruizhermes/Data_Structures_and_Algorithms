#include <iostream>
#include "doubly_linked_list.h"

using namespace std;

doublyNode::doublyNode(){
    this->data = 0;
    prev = NULL;
    next = NULL;
}

doublyNode::doublyNode(int data){
    this->data = data;
    prev = NULL;
    next = NULL;
}

doublyLinkedList::doublyLinkedList(){
    head = NULL;
    tail = NULL;
    currentCount = 0;
}


void doublyLinkedList::addElement(int addData){

    doublyNode *newNode = new doublyNode();
    newNode -> data = addData;

    // Check if empty list
    if(head == NULL){
        head = newNode;
        tail = newNode;
        currentCount++;
        return;
    }


    newNode->next = NULL;
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
    currentCount++;
}

void doublyLinkedList::printList(){

    doublyNode *current = new doublyNode();

    if(head == NULL){
        cout << "Empyt list\n";
        return;
    }

    current = head;
    
    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    
    cout << "current list size: " << currentCount << endl;
}

void doublyLinkedList::push(int addData){
    doublyNode *newNode = new doublyNode();
    newNode->data = addData;


    if(head == NULL){
        head = tail = newNode;
        currentCount++;
        return;
    }

    head->prev = newNode;
    newNode->prev = NULL;
    newNode->next = head;
    head = newNode;
    currentCount++;
}

void doublyLinkedList::pop(){

    doublyNode *popNode = new doublyNode();
    

    if(head == NULL){
        return;
    }

    if(head == tail){
        head = tail = NULL;
        currentCount--;
        return;
    }
    popNode = head;
    head = popNode->next;
    head->prev = NULL;
    currentCount--;
    delete popNode;
    

}

void doublyLinkedList::createListFromArray(int A[], int size){

    doublyNode *newNode = new doublyNode();
    newNode -> data = A[0];

    head = newNode;
    tail = newNode;
    currentCount++;

    for(int i=1; i < size; i++){
        doublyNode *newNode = new doublyNode();
        newNode->data = A[i];
        newNode->next = NULL;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        currentCount++;
    }

}

void doublyLinkedList::reverseLinkedList(){

    doublyNode *current = new doublyNode();
    doublyNode *temp = new doublyNode();

    if(head == NULL){
        cout << "Empty List";
        return;
    }

    current = head;

    while(current != NULL){
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = current->prev;

        // checks if last element in List and assigs it as 
        // the new head of the list
        if(current != NULL && current->next == NULL){ 
            head = current;
        }
    }

}