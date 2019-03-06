#include <iostream>
#include <algorithm>

using namespace std;

int **matriz;

int getMax(int a, int b) {
    return a > b ? a : b;
}

int getMaximumPathSum(int size, int line, int pos) {
    if (line < size -1) {
        int right = getMaximumPathSum(size, line +1, pos +1);
        int left = getMaximumPathSum(size, line +1, pos);
        // printf("line: %d pos: %d right: %d left: %d\n", line, pos, right, left);

        return matriz[line][pos] + getMax(left, right);
    }

    return matriz[line][pos];
}

int main() {
    int t;
    cin >> t;

    while (t) {
        int size;
        int pos = 0;
        cin >> size;

        matriz = (int**)malloc(sizeof(int*) * size);

        for (int i = 0, j = 0; i < size; i++) {
            matriz[i] = (int*)malloc(sizeof(int) * size);
            j = 0;
            while(j <= i){
                cin >> matriz[i][j];
                j++;
            }
        }

        cout << getMaximumPathSum(size, 0, 0) << endl;

        t--;
    }

    return 0;
}
