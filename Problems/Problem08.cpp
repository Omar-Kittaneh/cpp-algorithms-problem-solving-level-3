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

void MultiplyMatrex(int arr1[3][3] , int arr2[3][3] , int arrMultiply[3][3] ) {
    for (short i = 0; i < 3; i++) {
        for (short j = 0; j < 3; j++) {
            arrMultiply[i][j] = arr1[i][j] * arr2[i][j];
        }
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout <<setw(4) << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    srand((unsigned)time(NULL));

    int arr1[3][3] , arr2[3][3] , arrMultiply[3][3];

    FillMatrixWithRandomNumbers(arr1, 3, 3);

    FillMatrixWithRandomNumbers(arr2, 3, 3);

    cout << "\nMatrix1:\n";

    PrintMatrix(arr1, 3, 3);

    cout << "\nMatrix2:\n";

    PrintMatrix(arr2, 3, 3);

    cout << "\nResults:\n";

    MultiplyMatrex(arr1, arr2, arrMultiply);

    PrintMatrix(arrMultiply, 3, 3);

    return 0;
}
