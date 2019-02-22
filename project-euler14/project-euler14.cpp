#include <bits/stdc++.h>
#define LIMIT 500001

using namespace std;
typedef unsigned long long int longInt;

// map<long, long> collatzValues;
// Using a Array is much better than a Map
longInt *valuesMem = new longInt[LIMIT];
longInt *results = new longInt[LIMIT];

longInt collatzSequenceSteps(longInt n) {
    longInt key = n;
    longInt count = 0;

     do {
        if (n < LIMIT && valuesMem[n] != 0) {
            break;
        } 
        if (n % 2) {
        n = 3*n +1;
        } else {
            n = n/2;
        }
        count++;
    } while (n > 1);

    valuesMem[key] = count + valuesMem[n];
    return valuesMem[key];
}

void populateArrays() {
    for (int i = 2; i < LIMIT; i++) {
        collatzSequenceSteps(i);
    } 
    for (int i = 2; i < LIMIT; i++) {
        if (valuesMem[i] >= valuesMem[results[i -1]]) {
            results[i] = i;
        } else {
            results[i] = results[i -1];
        }
    }
}

int main() {
    longInt t;
    cin >> t;
    memset(valuesMem, 0, sizeof(valuesMem));
    memset(results, 0, sizeof(results));
    results[1] = 1;

    populateArrays();

    for (longInt a0 = 0; a0 < t; a0++){
        longInt n;
        cin >> n;

        cout << results[n] << "\n";

    }

    delete[] valuesMem;
    delete[] results;
    
    return 0;
}
