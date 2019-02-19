#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

vector< vector<int> > grid(20,vector<int>(20));

int checkHorizontal() {
    int ans = 0;
    for(int i = 0; i < 20; i++) {
        for(int j = 3; j < 20; j++) {
            int aux = grid[i][j] * grid[i][j -1] * grid[i][j -2] * grid[i][j -3];
            if (aux > ans)
                ans = aux;
        }
    }

    return ans;
}

int checkVertical() {
    int ans = 0;
    for(int i = 0; i < 20; i++) {
        for(int j = 3; j < 20; j++) {
            int aux = grid[j][i] * grid[j -1][i] * grid[j -2][i] * grid[j -3][i];
            if (aux > ans)
                ans = aux;
        }
    }

    return ans;
}

int checkPrimaryDiagonal() {
    int ans = 0;

    for(int i = 0; i < 17; i++) {
        for(int j = 0; j < 17; j++) {
            int aux = grid[i][j] * grid[i +1][j +1] * grid[i +2][j +2] * grid[i +3][j +3];
            if (aux > ans)
                ans = aux;
        }
    }

    return ans;
}

int checkSecundaryDiagonal() {
    int ans = 0;

    for(int i = 0; i < 17; i++) {
        for(int j = 3; j < 20; j++) {
            int aux = grid[i][j] * grid[i +1][j -1] * grid[i +2][j -2] * grid[i +3][j -3];
            if (aux > ans)
                ans = aux;
        }
    }

    return ans;
}

int largestProdutGrid() {
    int ans = checkHorizontal();
    int aux = checkVertical();

    if(aux > ans) {
        ans = aux;
    }
    
    aux = checkPrimaryDiagonal();
    if(aux > ans) {
        ans = aux;
    }

    aux = checkSecundaryDiagonal();
    if(aux > ans) {
        ans = aux;
    }

    return ans;
}

int main(){
    for(int grid_i = 0;grid_i < 20;grid_i++){
    	for(int grid_j = 0;grid_j < 20;grid_j++){
    		cin >> grid[grid_i][grid_j];
    	}
    }

    cout << largestProdutGrid() << "\n";

    return 0;
}
