#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long findLargestPrimeFactor(long n) {
    long largestPrime = 2;
    
    while(n % 2 == 0) {
        n /= 2;
    }

    int i;
    for(i = 3; i < sqrt(n); i += 2) {
        while(n % i == 0) {
            n /= i;
            largestPrime = i;
        }
    }
    while (n % i == 0) {
        n /= i;
        largestPrime = i;
    }
        
    return n > 2 ? n : largestPrime;
    
}

int main(){
    int t;
    cin >> t;
    
    for(int a0 = 2; a0 < t; a0++){
        long n;
        // cin >> n;
        n = a0;
        
        long ans = findLargestPrimeFactor(n);
        cout << n << ": " << ans << "\n";
        
    }
    return 0;
}