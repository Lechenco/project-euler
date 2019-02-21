#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string firstTenSum(vector<string> numbers) {
    int n = numbers.size();
    string sum;
    sum.resize(50, '0');
    int cOut = 0;

    for (int i = 49; i >= 0; i--) {
        int aux = 0;
        for (int j = 0; j < n; j++) {
            aux += numbers[j][i] - 48; 
        }
        cOut += aux;
        sum[i] += (cOut % 10);
        cOut /= 10;
    }

    while (cOut) {
        char c = ((cOut % 10) + 48);
        sum.insert(0, 1, c);
        cOut /= 10;
    }

    return sum.substr(0, 10);
}

int main() {
    int t;
    vector<string> numbers;
    
    cin >> t;
    for (int a0 = 0; a0 < t; a0++) {
        string n;
        cin >> n;
        numbers.push_back(n);
    }

    // cout << "Ola" << "\n";
    cout << firstTenSum(numbers) << "\n";


    return 0;
}
