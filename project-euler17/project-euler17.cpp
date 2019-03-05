#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int getDigit(int n, int pos);

static string digits[] = {"Zero", "One", "Two", "Three", 
        "Four", "Five", "Six", "Seven", "Eight", "Nine"};
static string tennies[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", 
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
static string dozens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", 
        "Sixty", "Seventy", "Eighty", "Ninety"};
static string hundreds[] = {"Hundred", "Thousand", "Million", "Billion"};

string getHundredString(int n) {
    string number = "";
    int unit = getDigit(n, 0);
    int ten = getDigit(n, 1);
    int hundred = getDigit(n, 2);

    if (hundred) {
        number += digits[hundred] + " " + hundreds[0] + " ";
    }

    if (ten == 1) {
        number += tennies[unit] + " "; 
    } else if (ten) {
        number += dozens[ten] + " ";
    }

    if (ten != 1 && unit) {
        number += digits[unit] + " ";
    }

    return number;
}

string getNumberWord(long int n, int count) {
    string numberWord = "";
    if (n) {
        numberWord += getNumberWord(n / 1000, count +1);
        numberWord += getHundredString(n % 1000);
        numberWord += (count && n % 1000 ? hundreds[count] + " ": "");
    }

    return numberWord;
}

int getDigit(int n, int pos) {
    int mod = pow(10, pos);
    return (n % (10 * mod)) / mod;
}

int main() {
    int t;
    cin >> t;

    while (t) {
        long int n;
        cin >> n;

        cout << getNumberWord(n, 0) << endl;

        t--;
    }
      
    return 0;
}
