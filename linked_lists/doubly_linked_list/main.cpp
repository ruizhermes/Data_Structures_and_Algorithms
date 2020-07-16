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

    int A[5] = {1, 3, 4, 5, 6};

    doublyLinkedList list2;

    list2.createListFromArray(A, 5);
    list2.printList();

    list2.addElement(24);
    list2.printList();

    list2.reverseLinkedList();
    list2.printList();
    return 0;
}