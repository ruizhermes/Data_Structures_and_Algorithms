#include <iostream>

using namespace std;

struct Stack
{
    int size;
    int top;
    int *s;
};

void Push(struct Stack *s, int value);
void Create(struct Stack *st);
void DisplayStack(struct Stack st);

int Pop(struct Stack *st);
int Peek(struct Stack st, int index);
int isFull(struct Stack st);
int isEmpty(struct Stack st);
int stackTop(struct Stack st);

int main(){
    
    struct Stack newStack;
    int popV;

    Create(&newStack);
    Push(&newStack, 10);
    Push(&newStack, 20);
    Push(&newStack, 30);
    Push(&newStack, 40);
    Push(&newStack, 50);
    Push(&newStack, 60);
    DisplayStack(newStack);

    popV = Pop(&newStack);
    popV = Pop(&newStack);
    
    DisplayStack(newStack);

    cout << "Peek value: " << Peek(newStack, 2) << endl;
    cout << "is Full : " << isFull(newStack);

    popV = Pop(&newStack);
    popV = Pop(&newStack);
    popV = Pop(&newStack);
    popV = Pop(&newStack);

    DisplayStack(newStack);
}
int stackTop(struct Stack st){

    if(!isEmpty(st)){
        return st.s[st.top];
    }
    return -1;
}


int Peek(struct Stack st, int index){

    int peekVal = -1;

    if(st.top - index + 1 < 0){
        cout << "Invalid Position " << endl;
    }
    else{
        peekVal = st.s[st.top - index+1];
    }
    return peekVal;
}

int isFull(struct Stack st){
    if(st.top == st.size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct Stack st){
    if(st.top == -1){
        return 1;
    }
    return 0;
}


int Pop(struct Stack *st){
    int popValue = -1;

    if(st->top == -1){
        cout << "Stack Underflow" << endl;
    }
    else{
        popValue = st->s[st->top];
        st->top--;
    }
    return popValue;
}

void Push(Stack *st, int value){

    if(st->top == st->size-1){
        cout << "Stack Overflow" <<endl;
    }
    else{
        st->top++;
        st->s[st->top] = value;
    }
}

void Create(struct Stack *st){

    cout << "Enter stack size: ";
    cin >> st->size;

    st->top = -1;
    st->s = new int[st->size]; 
}

void DisplayStack(struct Stack st){

    for(int i = st.top; i>=0; i--){
        cout << st.s[i] << " "; 
    }
    cout << endl;
}