#include <cmath>
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

short NumberCountInMatrix(int arr[3][3],int NumberToCount , short Rows, short Cols) {
    short count = 0;
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            if (arr[i][j] == NumberToCount) {
                count++;
            }
        }
    }
    return count;
}
bool IsSparseMatrix(int arr[3][3], short Rows, short Cols) {
    short MatrixSize = Rows * Cols;
    return (NumberCountInMatrix(arr, 0, Rows, Cols) >= ceil((float)MatrixSize / 2)) ;
}
int main() {
    srand((unsigned) time(NULL));

    int Matrix1[3][3] = {
        {0,8,12},
        {0,4,5},
        {0,0,0}
    };

    cout << "\nMatrix1:\n";

    PrintMatrix(Matrix1, 3, 3);

    if (IsSparseMatrix(Matrix1, 3, 3))
        cout << "\nYes: It is Sparse\n";
    else
        cout << "\nNo: It's NOT Sparse\n";

    return 0;
}