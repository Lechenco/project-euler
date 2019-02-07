#include <iostream>

using namespace std;

int smallestMultiple(int n) {
    int res, i;
    int finish = 0;

    res = n % 2 && n != 1 ? n +1 : n;

    while(1) {
        for (i = 1; i <= n; i++) {
            if (res % i != 0) {
                break;
            }
        }
        if(i == n +1)
            break;
        res += 2;
    }
    return res;

}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;

        cout << smallestMultiple(n) << "\n";
    }
    return 0;
}