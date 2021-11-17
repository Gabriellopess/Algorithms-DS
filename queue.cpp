#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *next;
};

struct Queue{
    Node *head, *tail;
    int size;
};

Node* createNode(int value){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = nullptr;
    return newNode;
}

Queue* createQueue(){
    Queue *newQueue = (Queue*) malloc(sizeof(Queue));
    newQueue->head = newQueue->tail = nullptr;
    newQueue->size = 0;
    return newQueue;
}

int isEmpty(Queue *myQueue){
    if(myQueue->tail == nullptr) return 1;
    else return 0;
    return -1;
}

void enqueue(int value, Queue *myQueue){
    Node *node = createNode(value);
    if(isEmpty(myQueue)){
        myQueue->head = myQueue->tail = node;
    }
    else{
        myQueue->tail->next = node;
        myQueue->tail = node;
    }

    myQueue->size++;
}

void dequeue(Queue *myQueue){
    if(isEmpty(myQueue)){
        cout << "Nothing to dequeue" << endl;
        return;
    }

    Node *temp = myQueue->head;
    myQueue->head = myQueue->head->next;
    
    if(myQueue->head == nullptr) myQueue->tail == nullptr;
    
    free(temp);
    if(myQueue->size == 1){
        myQueue->tail = myQueue->head;
    }
    myQueue->size--;
}

int main(){
    Queue *myQ = createQueue();

    enqueue(3, myQ);
    dequeue(myQ);
    enqueue(7, myQ);
    enqueue(5, myQ);
    dequeue(myQ);
    enqueue(10, myQ);

    cout << "Head: " << myQ->head->val << endl;
    cout << "Tail: " << myQ->tail->val << endl;

    dequeue(myQ);

    cout << "Head: " << myQ->head->val << endl;
    cout << "Tail: " << myQ->tail->val << endl;
    
    return 0;
}