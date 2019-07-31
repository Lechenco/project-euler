#include<iostream>
#include<vector>
#include<cmath>
#define N 5000

using namespace std;
typedef unsigned long long int ulll;

vector<ulll> nDigitFibonacciNumbers;

ulll nDigitPos(ulll n) {
    if (n == 1) return 1; 

    // using phi = 1.6180339887498948 
    return ceil((n * log10(1.6180339887498948)) - ((log10(5)) / 2));  
}


void fillNDigitFibonacciNumbersVector() {
    int i = 0;
    int aux = 0;
    while (aux < N) {
        i++;
        if (nDigitPos(i) > aux) {
            aux = nDigitPos(i);
            nDigitFibonacciNumbers.push_back(i);
        }
    }
}


int main() {
    int t0;
    cin >> t0;

    fillNDigitFibonacciNumbersVector();

    while (t0--) {
        ulll n;
        cin >> n;

         cout << nDigitFibonacciNumbers[n -1] << endl;
    }

    return 0;
}
