#include <iostream>

using namespace std;

struct Node{
    Node *left = nullptr;
    int val;
    int bf;
    int hc;
    Node *right = nullptr;
};

Node* createNode(int value){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->val = value;
    newNode->bf = 0;
    newNode->hc = 0;//
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* bst_insert(int value, Node *root){
    Node *newNode = createNode(value);
    if(root == nullptr){
        root = (Node *) calloc(1, sizeof(Node));
        root = newNode;
        root->hc = 1;//
        return root;
    }
    if(newNode->val <= root->val){
        root->left = bst_insert(value, root->left);
        root->bf = root->bf - root->hc;//
        return root;
    }
    else{
        root->right = bst_insert(value, root->right);
        root->bf = root->bf + root->hc;//
        return root;
    }

    return root; //
}

Node* rotate_right(Node *root, int *rightCount){
    Node *tempRoot = root->left;
    Node *rootRight = tempRoot->right;
    tempRoot->right = root;
    root->left = rootRight;

    if(tempRoot->bf >= 0){
        root->bf = root->bf - 1;
    }
    else{
        root->bf = root->bf - 1 + tempRoot->bf;
    }
    if(root->bf <= 0){
        tempRoot->bf = tempRoot->bf - 1;
    }else{
        tempRoot->bf = tempRoot->bf - 1 - root->bf;
    }

    (*rightCount)++;
    return tempRoot;
}

Node* rotate_left(Node *root, int *leftCount){
    Node *tempRoot = root->right;
    Node *rootLeft = tempRoot->left;
    tempRoot->left = root;
    root->right = rootLeft;

    if(tempRoot->bf <= 0){
        root->bf = root->bf - 1;
    } else{
        root->bf = root->bf - 1 - tempRoot->bf;
    }
    if(root->bf >= 0){
        tempRoot->bf = tempRoot->bf - 1;
    } else{
        tempRoot->bf = tempRoot->bf - 1 + root->bf;
    }

    (*leftCount)++;
    return tempRoot;
}

Node* stage1(Node *root, int *leftCount){
    if(root->left == nullptr && root->right == nullptr){
        return root;
    }
    else if(root->right != nullptr){
        root = rotate_left(root, leftCount);
        root = stage1(root, leftCount);
    }
    else if(root->left != nullptr){
        root->left = stage1(root->left, leftCount);    
    }

    return root;//
}


void printLeftTree(int N, Node* root){
    for(int i = 0; i < N; i++){
        if(root != nullptr){
            cout << "Node: " << root->val << " | Left: ";
            if(root->left != nullptr){
                cout << root->left->val;
            } else{
                cout << "NULL";
            }
            cout << " | Right: ";
            if(root->right == nullptr)
                cout << "NULL" << endl;
            else{
                cout << root->right->val << endl;
                cout << "Went Wrong" << endl;
            }
        }
        else
            cout << "finish" << endl;
        
        root = root->left;
    }
}

Node* shiftRight(Node *Sroot, Node *Troot, int *rightCount){
    while(Sroot->val != Troot->val){
        Sroot = rotate_right(Sroot, rightCount);
    }

    return Sroot;
}

Node* shiftLeft(Node *Sroot, Node *Troot, int *leftCount){
    while(Sroot->val != Troot->val){
        Sroot = rotate_left(Sroot, leftCount);
    }

    return Sroot;
}

Node* stage2(Node *Sroot, Node *Troot, bool flag, int *leftCount, int *rightCount){
    if(flag)
        Sroot = shiftRight(Sroot, Troot, rightCount);
    else
        Sroot = shiftLeft(Sroot, Troot, leftCount);
    
    if(Sroot->left != nullptr){
        Sroot->left = stage2(Sroot->left, Troot->left, true, leftCount, rightCount);
    }
    if(Sroot->right != nullptr){
        Sroot->right = stage2(Sroot->right, Troot->right, false, leftCount, rightCount);
    }

    return Sroot;
}

void printPO(Node *root, bool *isAVL, int N, int *count){
    if(root == nullptr){
        return;
    }
    printPO(root->left, isAVL, N, count);
    printPO(root->right, isAVL, N, count);
    if((root->bf > 1 || root->bf < -1) && *isAVL){
        *isAVL = false;
    }
    cout << root->val;
    if(*count != N-1){
        cout << " ";
    }
    (*count)++;
}

int main(){
    int N, value, leftCount = 0, rightCount = 0, count = 0;
    bool isAVL = true;

    while(cin >> N){
        Node *Sroot = nullptr;
        Node *Troot = nullptr;

        for(int i = 0; i < N; i++){
            cin >> value;
            Sroot = bst_insert(value, Sroot);
        }

        for(int i = 0; i < N; i++){
            cin >> value;
            Troot = bst_insert(value, Troot);
        }

        Sroot = stage1(Sroot, &leftCount);
        Sroot = stage2(Sroot, Troot, true, &leftCount, &rightCount);

        cout << leftCount << " " << rightCount << endl;
        printPO(Troot, &isAVL, N, &count);
        cout << endl;
        if(isAVL)
            cout << "true" << endl;
        else
            cout << "false" << endl;

        // free(Sroot);
        // free(Troot);
        leftCount = 0;
        rightCount = 0;
        count = 0;
        isAVL = true;

        cout << endl;
    }
    
    return 0;
}