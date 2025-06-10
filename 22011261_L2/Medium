/*
ID : 22011261
Name : Lee Pei Lin
Problem : Find a peak element in a 2D matrix
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    
    int startCol = 0, endCol = cols - 1;

    while (startCol <= endCol) {
        int midCol = startCol + (endCol - startCol) / 2;
        int maxRow = 0;

        for (int i = 0; i < rows; i++) {
            if (mat[i][midCol] > mat[maxRow][midCol]) {
                maxRow = i;
            }
        }

        bool leftIsBigger = (midCol - 1 >= 0) && (mat[maxRow][midCol - 1] > mat[maxRow][midCol]);
        bool rightIsBigger = (midCol + 1 < cols) && (mat[maxRow][midCol + 1] > mat[maxRow][midCol]);

        if (!leftIsBigger && !rightIsBigger) {
            return {maxRow, midCol};
        } else if (leftIsBigger) {
            endCol = midCol - 1;
        } else {
            startCol = midCol + 1;
        }
    }

    return {-1, -1};
}

int main() {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    if (rows <= 0 || cols <= 0) {
        cout << "Invalid matrix dimensions!" << endl;
        return 1;
    }

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter matrix elements row by row:" << endl;
    for (int i = 0; i < rows; ++i) {
        cout << "Row " << i + 1 << " (space separated): ";
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<int> peak = findPeakGrid(matrix);

    cout << "Peak element found at index: " << peak[0] + 1 << ", " << peak[1] + 1 << endl;
    cout << "Peak value: " << matrix[peak[0]][peak[1]] << endl;

    return 0;
}
