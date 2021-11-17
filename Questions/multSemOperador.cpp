#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int multiply(int x, int y){
    int aux = x, counterX = 0, counterY = 0;
    if(x == 0 || y == 0) return 0;
    else if(x < 0 || y < 0){
        if(x < 0 && y > 0){
            aux = y;
            for(int i = -1; i > x; i--){
                aux += y;
            }
            aux = aux - (aux + aux);
            return aux;  
        }
        else if(x > 0 && y < 0){
            for(int i = -1; i > y; i--){
                aux += x;
            }
            aux = aux - (aux + aux);
            return aux;
        }
        else if(x < 0 && y < 0){
            for(int i = -1; i > y; i--){
                aux += x;
            }
            aux = aux - (aux + aux);
            return aux;
        }
    }
    else{
        for(int i = 1; i < y; i++){
            aux += x;
        }
        return aux;  
    }
}

int main() {
    int x = 0, y = 0, answer;
    cin >> x;
    cin >> y;
    while(x != -100){
        answer = multiply(x, y);
        cout << "Multiplied: " << answer << endl;
        cin >> x;
        cin >> y;
    }
    
    return 0;
}
