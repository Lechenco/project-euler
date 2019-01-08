#include <iostream>
#include <vector>

using namespace std;

long generateNextPrime(vector<long> primes) {
    long next = primes.at(primes.size() -1);
    bool looking = true;
    while(looking) {
        looking = false;
        next++;
        for(auto prime : primes) {
            if(next % prime == 0) {
                looking = true;
                break;
            }
        }
    }
    return next;
}

int main(){
    int t;
    cin >> t;
    
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        
        vector<long> primes;
        primes.push_back(2);
        
        long ans = 0;
        
        while(primes.at(primes.size() - 1) < n) {
            long nextPrime = generateNextPrime(primes);
            primes.push_back(nextPrime);
            
            if(n % nextPrime == 0) 
                ans = nextPrime;
        }
        
        cout << ans << "\n";
        
    }
    return 0;
}