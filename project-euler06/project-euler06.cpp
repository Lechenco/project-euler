#include <iostream>

using namespace std;

long sumOfSquares(int n){
    long res = 0;
    for (int i = 1; i <= n; i++) {
        res += i*i;
    }
    return res;
}

long squareOfSum(int n){
    long res = 0;
    for (int i = 1; i <= n; i++) {
        res += i;
    }
    return res*res;
}

long squareSumDifference(int n){
    long res = sumOfSquares(n) - squareOfSum(n);
    return res < 0? -res : res;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;

        cout << squareSumDifference(n) << "\n";
    }
    return 0;
}