
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long> sums;
int latestN = 0;

long sumPrimesUntilN(int n) {
    if (n <= latestN) {
        return sums[n];
    }

   bool A[n +1];

    for (int i =0; i < n +1; i++)
        A[i] = true;

    for (int i = 2; i < sqrt(n); i++) {
        if(A[i]) {
            for (int j = i*i; j < n +1; j += i) {
                A[j] = false;
            }
        }
    }

    long sum = 0;
    sums.clear();
    sums.push_back(0);
    sums.push_back(0); // Position [0] and [1]
    latestN = n;

    for(int i = 2; i < n +1; i++) {
        sum += A[i] ? i : 0;
        sums.push_back(sum);
    }

    return sum;
}

int main(){
    int t;
    cin >> t;

    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;

        cout << sumPrimesUntilN(n) << "\n";
    }

    return 0;
}
