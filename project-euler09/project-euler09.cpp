 #include <iostream>

 using namespace std;

int isPythagoreanTriplet(int a, int b, int c) {
    int pythagorean = (a*a + b*b == c*c) ||  (a*a + c*c == b*b) ||
        (c*c + b*b == a*a);
    int unequal = (a < b && b < c) || (b < a && a < c) || 
        (c < b && b < a) || (b < c && c < a) ||
        (c < a && a < b) || (a < c && c < b);

    return pythagorean && unequal;
}

int specialCase(int a, int b, int c, int greater) {
    return isPythagoreanTriplet(a, b, c) 
        && a*b*c > greater;
}

int specialPythagoreanTriplet(int n) {
    int greater = -1;

    for (int a = n -3; a > 0; a--) {
        float b = (n*n - 2*n*a) / (2*n - 2*a);
        if (b - (int)b != 0 || b < 0) {
            continue;
        }
        // Clean up b decimal aproximation
        int bint = (int)b;
        int c = n -a -bint;
        if (specialCase(a, bint, c, greater)) {
            greater = a*bint*c;
        }
    }

    return greater;
}

int main() {
    int t;
    cin >> t;
    for (int a0 = 0; a0 < t; a0++) {
        int n;
        cin >> n;

        cout << specialPythagoreanTriplet(n) << "\n";
    }
}
