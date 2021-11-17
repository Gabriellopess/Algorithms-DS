#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *next = NULL;
};

void insert(int value, Node *cursor){
    //insere na lista logo após o elemento do cursor
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = cursor->next;
    cursor->next = newNode;
}

Node* getElementByIndex(Node *head, int pos){
    Node *cursor = head;
    int i = 0;
    while(i < pos && cursor->next != NULL){
        cursor = cursor->next;
        i++;
    }
    return cursor;
}

Node* getElementByValue(Node *head, int value){
    Node *cursor = head;
    while(cursor->next != NULL && cursor->next->val != value){
        cursor = cursor->next;
    }
    return cursor->next;
}

void removeElement(Node *cursor){
    //remove o elemento do cursor->next
    Node *p = cursor->next;
    cursor->next = p->next;
    int value = p->val;
    free(p);
}

void printList(Node *init){
    while(init != NULL){
        cout << init->val << " ";
        init = init->next;
    }
    cout << endl;
}

int main(){
    int pos = 3;
    Node *head = (Node*) malloc(sizeof(Node));
    head->val = 1;
    head->next = NULL;
    
    insert(2, head);
    insert(7, head);
    insert(5, head);
    insert(8, head);
    insert(3, head);
    printList(head);

    Node *test = getElementByIndex(head, pos);
    cout << test->val << " at Index: " << pos << endl;

    Node *test2 = getElementByValue(head, 8);
    cout <<"Value: " << test2->val << " &: " << test2 << endl;

    removeElement(getElementByIndex(head, 1));
    printList(head);

    return 0;
}