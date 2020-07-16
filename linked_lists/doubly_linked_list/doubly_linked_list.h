class doublyNode {

    private:
        int data;
        doublyNode *next;
        doublyNode *prev;
    public:
        doublyNode();
        doublyNode(int data);

    friend class doublyLinkedList;
};

class doublyLinkedList{

    private:
        doublyNode *head;
        doublyNode *tail;
        int currentCount;

    public:

        doublyLinkedList();
        doublyLinkedList(int data);
        
        void addElement(int addData);
        void push(int addData);
        void pop();
        void printList();
        void createListFromArray(int A[], int size);
        void reverseLinkedList();


};

