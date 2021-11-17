
// Node* createNode(int val){
//     Node* stackNode = (Node *)malloc(sizeof(Node));
//     stackNode->val = val;
//     stackNode->next = nullptr;
//     return stackNode;
// }

#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *next = NULL;
};

struct Stack{
    int size = 0;
    Node *top = NULL;
};

Node* createNode(int value){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = nullptr;
    return newNode;
}

Stack* createStack(){
    Stack *newStack = (Stack*) malloc(sizeof(Stack));
    newStack->top = nullptr;
    newStack->size = 0;
    return newStack;
}

void push(Node *newNode, Stack *myStack){
    newNode->next = myStack->top;
    myStack->top = newNode;
    myStack->size++;
}

void pop(Stack *myStack){
    Node *temp = myStack->top;
    myStack->top = temp->next;
    temp->next = nullptr;
    myStack->size--;
    free(temp);
}


void printStack(Stack *myStack){
    Node *temp = myStack->top;
    while(temp != NULL){
        cout << temp->val << endl;
        temp = temp->next;
    }
    cout << "--------" << endl;
}

int main(){
    Node *head = (Node*) malloc(sizeof(Node));
    Stack *myStack = createStack();
    
    
    cout <<"Size: " << myStack->size << endl;

    push(createNode(3), myStack);
    push(createNode(5), myStack);
    push(createNode(7), myStack);
    push(createNode(9), myStack);
    printStack(myStack);

    pop(myStack);
    pop(myStack);
    // push(createNode(13), myStack);
    pop(myStack);
    pop(myStack);


    printStack(myStack);

    cout <<"Size: " << myStack->size << endl;
    return 0;
}