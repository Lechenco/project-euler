#include <iostream>
#define DIM 100001
using namespace std;

int divisorsSum[DIM];
int isNAbundant[DIM];

int divisorSumInt(int n) {
    int sum = 1;

    for (int i = 2; i*i < n; i++) {
        sum += n % i == 0 ? i + n / i : 0;
    }
    return sum;
}

int isAbundant(int n) {
    return divisorsSum[n] > n;
}

void fillDivisorsSumVector() {
    divisorsSum[1] = 1;
    isNAbundant[1] = 0;
    for (int i = 2; i < DIM; i++) {
        divisorsSum[i] = divisorSumInt(i);
        isNAbundant[i] = isAbundant(i);
    }
}

string canNBeSumOfTwoAbundantNumbers(int n) {
    int num1 = 12;

    while (num1 < n) {
        if (isNAbundant[n - num1]) return "YES";
        num1++;
        while (!isNAbundant[num1] && num1++);
    }

    return "NO";
}

int main() {
    int t0;
    cin >> t0;
    fillDivisorsSumVector();

    while (t0--) {
        int n;
        cin >> n;

        cout << canNBeSumOfTwoAbundantNumbers(n) << endl;
    }

    return 0;
}
