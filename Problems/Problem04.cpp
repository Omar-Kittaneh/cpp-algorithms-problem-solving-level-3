#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int RandomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

int SumCol(int arr[3][3] , short Rows, short Cols) {
    int sum = 0;
    for (short i = 0; i < Rows; i++) {
        sum += arr[i][Cols];
    }
    return sum;
}

void PrintEachColSum(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        printf("Row %d sum = %d \n", i + 1 , SumCol(arr, Rows, i));
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
int main() {
    srand((unsigned)time(NULL));

    int arr[3][3];

    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "\n The following is a 3x3 random matrix:\n";

    PrintMatrix(arr, 3, 3);

    cout << "\nThe following are the sum of each col in the matrix:\n";

    PrintEachColSum(arr, 3, 3);

    return 0;
}