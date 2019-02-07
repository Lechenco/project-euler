#include <iostream>
#include <vector>

using namespace std;

vector<long> primes;

long isPrime(long n) {
    for (int i = 0; i < primes.size(); i++) {
        if (n % primes[i] == 0) {
            return 0;
        }
    }
    return 1;
}

long nextPrime() {
    long next = primes[primes.size() -1] + 2;

    while(!isPrime(next)){
        next += 2;
    }
    return next;
}

long nthPrimeNumber(int n) {
    long res;

    if (n < primes.size()) {
        return primes[n-1];
    }

    for (int i = primes.size(); i < n; i++) {
        primes.push_back(nextPrime());
    }

    return primes[primes.size() -1];
}

int main(){
    int t;
    cin >> t;

    primes.push_back(2);
    primes.push_back(3);

    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;

        cout << nthPrimeNumber(n) << "\n";
    }

    return 0;
}