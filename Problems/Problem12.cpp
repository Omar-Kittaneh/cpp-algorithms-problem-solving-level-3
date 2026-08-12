#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 10);
        }
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            printf(" %0*d ", 2, arr[i][j]);

        }
        cout << "\n";
    }
}

bool AreEqualMatrices(int arr1[3][3], int arr2[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            if (arr1[i][j] != arr2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    srand((unsigned) time(NULL));

    int Matrix1[3][3], Matrix2[3][3];

    FillMatrixWithRandomNumbers(Matrix1, 3, 3);

    FillMatrixWithRandomNumbers(Matrix2, 3, 3);

    cout << "\nMatrix1:\n";

    PrintMatrix(Matrix1, 3, 3);

    cout << "\nMatrix2:\n";

    PrintMatrix(Matrix2, 3, 3);

    if (AreEqualMatrices(Matrix1, Matrix2, 3, 3)) {
        cout << "\nYES: Matrices are equal";
    }
    else cout << "\nNO: Matrices are NOT equal";

    return 0;
}