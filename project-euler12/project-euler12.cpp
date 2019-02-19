#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#define PRIMES 200

using namespace std;

bool *A;

void generatePrimes(int n) {
    A = (bool*)malloc(sizeof(bool) * (n +1));

    for (int i =0; i < n +1; i++)
        A[i] = true; 

    for (int i = 2; i < sqrt(n); i++) {
        if(A[i]) {
            for (int j = i*i; j < n +1; j += i) {
                A[j] = false;
            }
        }
    }
}

int numberDivisors(int number) {
    int count = 1;
    float squareRoot = sqrt(number);
    int copy = number;

    if (number == 1) return 1;

    for (int i = 2; i <= copy && i <= PRIMES; i++) {
        if (A[i]) {
            int aux = 0;
            while(number % i == 0){
                aux++;
                number /= i;
            }
            count *= aux +1;
        }
    }

    return count;
}

int firstTriangleNumber(int n) {
    int ans = 0;
    bool finish = false;

    for (int i = 1; !finish; i++) {
        ans += i;
        finish = numberDivisors(ans) > n;
        // cout << ans << ": " << numberDivisors(ans) << "\n";
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    generatePrimes(PRIMES);

    for(int a0 = 0; a0 < t; a0++) {
        int n;
        cin >> n;
        
        // numberDivisors(n);
        // firstTriangleNumber(n);
        cout << firstTriangleNumber(n) << "\n";
    }

    return 0;
}
