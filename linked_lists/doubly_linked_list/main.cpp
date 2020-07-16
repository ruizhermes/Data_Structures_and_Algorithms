#include <iostream>
#include "doubly_linked_list.h"

using namespace std;


int main(){

    doublyLinkedList list;

    list.push(10);
    list.push(20);

    list.addElement(30);
    list.printList();

    list.pop();
    list.pop();
    list.pop();
    list.pop();
    list.printList();

    return 0;
}