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
int main() {
    srand((unsigned) time(NULL));

    int Matrix1[3][3];

    FillMatrixWithRandomNumbers(Matrix1, 3, 3);

    cout << "\nMatrix1:\n";

    PrintMatrix(Matrix1, 3, 3);

    printf("\nSummation of Matrix1 is: %d", SumMatrix(Matrix1, 3, 3));
    
    return 0;
}