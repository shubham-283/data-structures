#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> matrixInputRows(int n ,int m){
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

vector<vector<int>> matrixInputCols(int n ,int m){
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrixByRows = matrixInputRows(n, m);
    vector<vector<int>> matrixByCols = matrixInputCols(n, m);
    cout << "Matrix input by rows:" << endl;
    for (const auto& row : matrixByRows) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

}   