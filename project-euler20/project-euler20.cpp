#include <iostream>
#include <cmath>
#include <vector>
#define DIM 1001

using namespace std;
typedef long double ldouble;

vector<int> factorial;
int sums[DIM];

void nextNFactorial(int n) {
    int size = factorial.size();
    int carry = 0;
    for (int i = 0; i < size; i++) {
        carry += factorial[i] * n;
        factorial[i] = carry % 10;
        carry /= 10;
    }
    while (carry) {
        factorial.push_back(carry %10);
        carry /= 10;
    }
}

int sumFactorial() {
    int sum = 0;
    int size = factorial.size();

    for(int i = 0; i < size; i++) {
        sum += factorial[i];
    }
    return sum;
}

void fillSumsVector() {
    sums[0] = 1;
    sums[1] = 1;
    factorial.push_back(1);

    for(int i = 2; i < DIM; i++) {
        nextNFactorial(i);
        sums[i] = sumFactorial();
    }
}

int main() {
    int t0, n;
    cin >> t0;
    fillSumsVector();
    while (cin >> n)
    {
        cout << sums[n] << endl;
    }
    
    return 0;
}
