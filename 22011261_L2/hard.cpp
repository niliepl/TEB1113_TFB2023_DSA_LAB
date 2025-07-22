/*
ID : 22011261
Name : Lee Pei Lin
Problem : A Boolean matrix
*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

void updateMatrix(int matrix[][MAX_SIZE], int row, int column, bool rowMark[], bool columnMark[])
{
    cout << "\nOutput:\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (rowMark[i] || columnMark[j])
            {
                matrix[i][j] = 1;
            }
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int row, column;

    cout << "Input:\n";
    cout << "Row: ";
    cin >> row;
    cout << "Column: ";
    cin >> column;

    int matrix[MAX_SIZE][MAX_SIZE];
    bool rowMark[MAX_SIZE] = {false};
    bool columnMark[MAX_SIZE] = {false};

    cout << "\nElement Matrix:\n";
    for (int i = 0; i < row; i++)
    {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < column; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1)
            {
                rowMark[i] = true;
                columnMark[j] = true;
            }
        }
    }

    updateMatrix(matrix, row, column, rowMark, columnMark);

    return 0;
}
