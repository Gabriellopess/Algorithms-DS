#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int fibonacci(int quant){
    int counter = 0;
    if(quant == 1) return 0;
    else if(quant == 2) return 1;
    else{
        int num = 0, secNum = 1, ans = 0;
        for(int i = 2; i < quant; i++){
            ans = num + secNum;
            num = secNum;
            secNum = ans;
        }
        return ans;
    }
    
}

int main() {
    int N = 0, final = 0;
    cin >> N;
    while(N != -1){
        final = fibonacci(N);
        cout << "Fibonacci Number: " << final << endl;
        cin >> N;
    }
    
    return 0;
}
