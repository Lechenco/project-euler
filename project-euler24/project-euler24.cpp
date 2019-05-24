#include <iostream>
#include <vector>

using namespace std;
string original = "abcd";
vector<string> lexicographic;

void lexigraphRecursivo(string actual, int start, int end) {
    if (start >= end)
        return;
    lexigraphRecursivo(actual, start+1, end);
    if (start+1 == end) {
        string copyActual = actual;
        copyActual[start] = actual[end];
        copyActual[end] = actual[start];
        lexicographic.push_back(copyActual);
        cout << copyActual << endl;
        lexigraphRecursivo(copyActual, start +1, copyActual.size() -1);
    }
    lexigraphRecursivo(actual, start, end-1);
}

void fillLexicographicVector() {
    lexicographic.push_back(original);
    lexigraphRecursivo(original, 0, original.size() -1);
    cout << "HAaa " << original << endl;
}

int main() {
    int t0;
    cin >> t0;
    fillLexicographicVector();
    while(t0--) {
        int n;
        cin >> n;

        cout << n << endl;
    }
    return 0;
}
