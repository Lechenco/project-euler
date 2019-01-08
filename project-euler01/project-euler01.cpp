// If we list all the natural numbers below  
// that are multiples of  or , we get  and . The sum of these multiples is .
// Find the sum of all the multiples of  or  below .

#include <iostream>


using namespace std;

unsigned long long int sumDivisibleBy(int n, unsigned long long int p) {
    return n * (p / n) * ((p / n) + 1) / 2;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        unsigned long long int n;
        cin >> n;
        
        unsigned long long int sum = sumDivisibleBy(3, n - 1) + sumDivisibleBy(5, n -1) - sumDivisibleBy(15, n -1);
        
        
        cout << sum;
        cout << "\n";
    }
    return 0;
}