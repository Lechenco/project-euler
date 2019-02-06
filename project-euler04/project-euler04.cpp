#include <iostream>
#include <set>

using namespace std;

int isPalindrome(int number) {
    int divisor1 = 100000;
    int divisor2 = 10;
    for(; divisor2 <= divisor1; divisor1 /= 10, divisor2 *= 10){
        if((number % divisor2) * 10 / divisor2  == (number / divisor1) % 10 )
            continue;
        else
            return 0;
    }
    return 1;
}

void generatePalindromes(std::set<int> &palindromes){
    for(int i = 100; i < 1000; i++) {
        for(int j = 100; j < 1000; j++) {
            if(isPalindrome(i*j))
                palindromes.insert(i*j);
        }
    }
}


int main(){
    int t;
    cin >> t;
    std::set<int> palindromes;

    generatePalindromes(palindromes);

    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;

        cout << *(--palindromes.lower_bound(n)) << "\n";
    }
    return 0;
}