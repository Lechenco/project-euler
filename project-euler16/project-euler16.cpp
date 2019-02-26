#include <cmath>
#include <iostream>

using namespace std;

int powerDigitSum(int n) {
    long double power = pow((long double)2, (long double)n);
    int len = (int) (floor(log10(power)) + 1);
    int sum = 0;

    char * buff = new char[len +1];

    sprintf(buff, "%0.Lf", power);

    int i = 0;
    while (i < len) {
        sum +=  buff[i] - '0';
        i++;
    }

    return sum;
}

int main() {
    int t;
    cin >> t;

    for (int a0 = 0; a0 < t; a0++) {
        int n;
        cin >> n;

        cout << powerDigitSum(n) << endl;
    }
   
    return 0;
}
