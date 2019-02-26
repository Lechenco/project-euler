#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
unsigned long long int mod = 1e9 +7;

unsigned long long int  latticePaths(int n, int m) {
    unsigned long long int matriz[n][m];

    for (int col=0; col < n; col++) {
        for (int row=0; row < m; row++) {
            matriz[col][row] = (col ? matriz[col -1][row] : 1) +
                                (row ? matriz[col][row -1] : 1);
            matriz[col][row] %= mod;
        }
    }

    return matriz[n -1][m -1];
}

int main() {
    int t;
    cin >> t;

    for (int i= 0; i < t; i++) {
        int n, m;
        cin >> n;
        cin >> m;

        cout << latticePaths(n, m) << "\n";
    }

    return 0;
}
