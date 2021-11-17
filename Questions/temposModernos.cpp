#include <iostream>
#include <string>

using namespace std;

struct Node{
    int id;
    int val;
    Node *next;
};

struct Queue{
    Node *head, *tail;
    int size;
};

struct Stack{
    int size = 0;
    Node *top = NULL;
};

Node* createNode(int id, int value){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->val = value;
    newNode->id = id;
    newNode->next = nullptr;
    return newNode;
}

Queue* createQueue(){
    //initialize empty queue;
    Queue *newQueue = (Queue*) malloc(sizeof(Queue));
    newQueue->head = newQueue->tail = nullptr;
    newQueue->size = 0;
    return newQueue;
}

Stack* createStack(){
    Stack *newStack = (Stack*) malloc(sizeof(Stack));
    newStack->top = nullptr;
    newStack->size = 0;
    return newStack;
}

int isEmpty(Queue *myQueue){
    if(myQueue->tail == nullptr) return 1;
    else return 0;
    return -1;
}

void enqueue(Node *node, Queue *myQueue){
    // Node *node = createNode(id, value);

    if(isEmpty(myQueue)){
        myQueue->head = myQueue->tail = node;
    }
    else{
        myQueue->tail->next = node;
        myQueue->tail = node;
        myQueue->tail->next = nullptr;
    }
    myQueue->size++;
}

Node* circDequeue(Queue *myQueue){
    if(isEmpty(myQueue)){
        cout << "Nothing to dequeue" << endl;
    }
    else{
        Node *temp = myQueue->tail;
        if(myQueue->size > 1){
            Node *cur = myQueue->head;
            while(cur->next->next != nullptr){
                cur = cur->next;
            }
            myQueue->tail = cur;
        }
        else{
            myQueue->tail = myQueue->head = nullptr;
        }

        myQueue->size--;
        return temp;
    }
}

Node* dequeue(Queue *myQueue){
    if(isEmpty(myQueue)){
        cout << "Nothing to dequeue" << endl;
    }
    else{
        Node *temp = myQueue->head;
        myQueue->head = myQueue->head->next;
        
        if(myQueue->head == nullptr) myQueue->tail == nullptr;
        
        if(myQueue->size == 1){
            myQueue->tail = myQueue->head;
        }

        myQueue->size--;
        return temp;
    }
}

void push(Node *newNode, Stack *myStack){
    newNode->next = myStack->top;
    myStack->top = newNode;
    myStack->size++;
}

Node *pop(Stack *myStack){
    Node *temp = myStack->top;
    myStack->top = temp->next;
    temp->next = nullptr;
    myStack->size--;
    
    return temp;
}

void schedVerifyW(Queue *circ, Stack *myStack){
    if(!isEmpty(circ)){
        if(circ->tail->val == 0){
            Node *temp = circDequeue(circ);//circ->tail
            push(temp, myStack); //push temp to stack
            cout << "/# " << "push to stack" << endl;
        }
    }
    
}

void schedVerifyFIFO(Queue *fifo, Queue *circ){
    if(!isEmpty(fifo)){
        Node *temp = dequeue(fifo);
        enqueue(createNode(temp->id, temp->val), circ);
    }
}

void runAndRotate(int tempo, Queue *circ){
    if(!isEmpty(circ)){
        circ->head->val -= tempo;
        if(circ->head->val < 0) circ->head->val = 0;
        
        cout << "/# " << "PROC " << circ->head->id << " " << circ->head->val << endl; 

        Node *temp = dequeue(circ); //tira do head
        enqueue(temp, circ); //coloca no tail

    }
    else{
        cout << "/# " << "PROC -1 -1" << endl;
    }
}

void stackUnload(Stack *myStack){
    Node *unloaded = pop(myStack);
    cout << "/# " << "UNLD " << unloaded->id << endl;
}



int main(){
    Queue *inQueue = createQueue(), *circularQueue = createQueue();
    Stack *myStack = createStack();
    int k, id = 0, value = 0;
    string status;
    cin >> k;

    do{
        cin >> status;

        if(status == "LOAD"){
            cin >> id;
            cin >> value;
            enqueue(createNode(id, value), inQueue);
            // cout << "Head: " << inQueue->head->id << " | " << inQueue->head->val << endl;
            // cout << "Tail: " << inQueue->tail->id << " | " << inQueue->tail->val << endl;
        }
        else if(status == "PROC"){
            // cout << "Deu Proc" << endl;
            schedVerifyW(circularQueue, myStack);
            schedVerifyFIFO(inQueue, circularQueue);
            runAndRotate(k, circularQueue);
        }
        else if(status == "UNLD"){
            // cout << "Dar unload" << endl;
            stackUnload(myStack);
        }
    }while(status != "END");

    cout << "Encerrou" << endl;
    
    
    return 0;
}

/* Exemplo de entrada:

2
LOAD 0 6
LOAD 1 15
PROC
LOAD 2 12
PROC
LOAD 3 12
LOAD 4 11
LOAD 5 8
PROC
LOAD 6 3
PROC
LOAD 7 7
LOAD 8 5
PROC
UNLD

*/