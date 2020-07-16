#include <cstdlib>
#include <iostream>
#include "list.h"

using namespace std;

LinkedList::LinkedList(){
   head = NULL;
   tail = NULL;
   currentSize = 0;
   
}

void LinkedList::deleteFront(){
    
    if(head == tail){
        head = tail = NULL;
        currentSize--;
        return;
    }
    else{
        head = head->next;
        currentSize--;
    }
}

void LinkedList::deleteLast(){

    // check for empty list
    if(head == NULL){
        return;
    }
    // check if only one element in list
    if(head == tail){
        deleteFront();
    }

    Node *current = new Node();
    Node *previous = NULL;
    current = head;

    while(current != tail){
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
    tail = previous;
    currentSize--;


}

void LinkedList::addNode(int addData){
    Node *n = new Node();

    n->data = addData;
    n->next = NULL;

    if (head == NULL){
        head = tail = n;
        currentSize++;
        return;
    }

    tail->next = n; // connects last node to new node
    tail = n;       // makes tail point to new node
    currentSize++;
    
}

void LinkedList::deleteNode(int delData){
    Node *delPtr = new Node();
    Node *current = new Node();
    Node *previous = new Node();

    current = head;

    // Check if there is only one node in the list
   if(head == tail){
       head = tail = NULL;
       currentSize--;
       return;
   }

    // traverse the list 
    while(current != NULL && current->data != delData){
        previous = current;            //temp is trailing tail;
        current = current->next;
    }

    // check if value was not found
    if(current == NULL){
        cout << "No data/node of value " << delData << " was in the list\n";
    }
    // check if we are at end of list
    if (current == tail){
        delPtr = current;
        tail = previous;
        delete delPtr;
        currentSize--;
        return;
    }
    if (current == head){
        delPtr = current;
        head = head->next;
        delete delPtr;
        currentSize--;
        return;
    }

    delPtr = current;
    current = current->next;
    previous->next = current;
    
    
    delete delPtr;
    currentSize--;
    cout <<"Node " << delData << " was deleted\n";


}

void LinkedList::addFront(int addData){
    Node *n = new Node();

    n->data = addData;
    n->next = NULL;

    // when adding at the beginning of the list
    // if the list is empty pointing to NULL it 
    // does not matter since n->next will point to 
    // null if head->NULL so the if statement can be 
    // removed. 
    
    if(head != NULL){
        n->next = head;
        head = n;
    }
    else{
        head = n;
        tail = n;
    }
    currentSize += 1;
}

void LinkedList::addNodeAtPos(int pos, int addData){

    if(head == NULL){
        addNode(addData);
        return;
    }
    if(pos > currentSize){
        cout << "invalid position\n";
        return;
    }
    if (pos == 1){
        addFront(addData);
        return;
    }
    Node *n = new Node();
    Node *current = new Node();
    Node *previous = new Node();

    current = head;
    for(int i = 1; i < pos; i++){
        previous = current;
        current = current->next;
    }
    n->data = addData;
    previous->next = n;
    n->next = current;
    currentSize++;

}


void LinkedList::printList(){
    Node *temp = new Node();

    if(head == NULL){
        cout << "Empty list\n";
        return;
    }
    temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
    cout << "head: " << head->data << " " << "tail: " << tail->data << endl;
    cout << "current size: " << currentSize << endl;
}