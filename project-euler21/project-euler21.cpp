#include <iostream>
#include <cmath>
#define DIM 100001
using namespace std;

int divisorsSum[DIM];
int sumAmicableNumbers[DIM];


int divisorSumInt(int n) {
    int sum = 1;
    int limit = sqrt(n);

    for (int i = 2; i < limit; i++) {
        sum += n % i == 0 ? i + n / i : 0;
    }
    return sum;
}

int isAmicable(int a, int b) {
    if (b >= DIM) {
        return divisorSumInt(b) == a;
    }

    return divisorsSum[a] == b && divisorsSum[b] == a
        && a != b;
}

void fillDivisorsSumVector() {
    for (int i = 1; i < DIM; i++)
        divisorsSum[i] = divisorSumInt(i);
}

void fillSumAmicableNumbersVector() {
    sumAmicableNumbers[1] = 0;
    for (int i = 2; i < DIM; i++) {
        sumAmicableNumbers[i] = sumAmicableNumbers[i -1] + 
             (isAmicable(i, divisorsSum[i]) ? i : 0);
    }
}

int main() {
    int t0;
    cin >> t0;

    fillDivisorsSumVector();
    fillSumAmicableNumbersVector();

    while (t0--) {
        int n;
        cin >> n;

        cout << sumAmicableNumbers[n] << endl;
    }

    return 0;
}
