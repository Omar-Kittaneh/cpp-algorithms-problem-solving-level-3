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

int SumMatrix(int arr[3][3], short Rows, short Cols) {
    int sum = 0;
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    return (SumMatrix(Matrix1, Rows, Cols) == SumMatrix(Matrix2, Rows, Cols));
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
        printf("\nYes:Summation of Matrix1 and Matrix2 are the same");
    }
    else {
        printf("\nNo:Summation of Matrix1 and Matrix2 are not the same");
    }
    return 0;
}