// Each new term in the Fibonacci sequence is generated by adding the previous two terms. 
// By starting with and , the first  terms will be:

// By considering the terms in the Fibonacci sequence whose values do not exceed , 
// find the sum of the even-valued terms.

#include <iostream>

using namespace std;

unsigned long long nthFibonacci(long n) {
    unsigned long long ans = 1;
    unsigned long long aux = 1;
    unsigned long long c;
    
    if(n <= 1)
        return ans;
    
    for(long i = 2; i <= n; i++) {
        c = ans;
        ans = ans + aux;
        aux = c;
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        
        unsigned long long sum = 0;
        unsigned long long aux;
        for(long i = 2; ; i += 1) {
            aux = nthFibonacci(i);
            if(aux >= n)
                break;
            if(aux % 2 == 0)
                sum += aux;
        }
        cout << sum << "\n";
    }
    return 0;
}