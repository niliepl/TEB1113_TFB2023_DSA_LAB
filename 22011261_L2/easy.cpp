/*
ID :22011261
Name :Lee Pei Lin 
Problem : Print matrix in snake pattern
*/

#include <iostream>
#include <vector>
using namespace std;

void printSnakePattern(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) return;
    int cols = matrix[0].size();
    
    for (int i = 0; i < rows; ++i) {
        if (i % 2 == 0) {  
            for (int j = 0; j < cols; ++j) {
                cout << matrix[i][j] << " ";
            }
        } else { 
            for (int j = cols - 1; j >= 0; --j) {
                cout << matrix[i][j] << " ";
            }
        }
    }
    cout << endl;
}

int main() {
    int rows, cols;
    
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    
    vector<vector<int>> matrix(rows, vector<int>(cols));
    
    cout << "Enter matrix elements row by row:" << endl;
    for (int i = 0; i < rows; ++i) {
        cout << "Row " << i+1 << " : ";
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }
    
    cout << "Snake pattern traversal: ";
    printSnakePattern(matrix);
    
    return 0;
}