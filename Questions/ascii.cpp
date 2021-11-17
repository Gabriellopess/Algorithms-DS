#include <iostream>
#include <string.h>

using namespace std;

int ascii(string name){
    int asciiSum = 0;

    for(int i = 0; i < name.length(); i++){
        asciiSum += ((int)name[i] * i);
    }

    return asciiSum;
}

int hashing(string name, int size){
    int asciiSum = 0, initPos = 0;

    asciiSum = ascii(name);

    // cout << "Soma ASCII: " << asciiSum << endl; 

    initPos = asciiSum % size;

    // cout << "InitPos: " << initPos << endl;
    return initPos;
}

int main(){
    int pos = 0;
    string name = "hoosay";

    pos = hashing(name, 207);
    cout << "Position: " << pos << endl;
    return 0;
}