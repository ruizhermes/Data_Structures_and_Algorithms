#ifndef LIST_H
#define LIST_H

// Node 
class Node {
    private: 
        int data;
        Node *next;
    
    // make LinkedList a friend of Node to access
    // the Node Class private data
    friend class LinkedList;
    
};

// LinkedList Class
class LinkedList{
    private:
        Node *head;
        Node *tail;
        int currentSize;
    
    public:
        LinkedList();
        void addNode(int addData);
        void deleteNode(int delData);
        void addFront(int addValue);
        void addNodeAtPos(int pos, int addData);
        void printList();
        void deleteFront();
        void deleteLast();
        int getListSize(){return currentSize;}

};


#endif