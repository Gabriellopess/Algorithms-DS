#include <bits/stdc++.h>

using namespace std;

string solvePass(string sign, int tam, string *words){ //X#  X##X
    string resultList = [];
    for(int i = 0; i < tam; i++){
        if(sign[i] == (char)"X"){
            
        }
    }

}

int main(){
    int N = 0, len = 0;
    cin >> N;
    string wordsList[N], word, passSign;
    for(int i = 0; i < N; i++){
        cin >> word;
        wordsList[i] = word;
    }

    fstream file;
    file.open("senhas.in", ios::in);
    while(!file.eof()){
        file >> passSign;
        int tam = sizeof(passSign) / sizeof(string);
        string password = solvePass(passSign, tam, wordsList);
        cout << password << endl;
    }

    len = sizeof(wordsList)/sizeof(string);
    // cout << len << endl;
    for(int i = 0; i < len; i++){

    }
    
    

    return 0;
}