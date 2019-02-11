#include <iostream>
#include <string>

using namespace std;

int largestProduct(string num, int k) {
    int largest = 0;

    for (int i = 0; i < num.size() - k; i++) {
        int aux = 1;
        for(int j = 0; j < k; j++) {
            aux *= num[i+j] - 48;
        }
        if (aux > largest) {
            largest = aux;
        }
    }
    return largest;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        string num;
        cin >> num;

        cout << largestProduct(num, k) << "\n";
    }
    return 0;
}
