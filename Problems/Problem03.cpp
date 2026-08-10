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
int SumRows(int arr[3][3]  , short Rows, short Cols) {
    int sum = 0;
    for (short i = 0; i < Cols; i++) {
        sum += arr[Rows][i];
    }
    return sum;
}

void FillSumArray(int Sum[3] , int arr[3][3]  , short Rows, short Cols) {
    for (short i = 0; i < Cols; i++) {
      Sum[i] =  SumRows( arr , i , Cols);
    }
}

void PrintEachRowSum( int Sum[3] , short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        printf("Row %d sum = %d \n", i + 1 , Sum[i]);
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout <<setw(3) << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
int main() {
    srand((unsigned)time(NULL));

    int arr[3][3];
    int Sum[3];

    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "\n The following is a 3x3 random matrix:\n";

    PrintMatrix(arr, 3, 3);

    cout << "\nThe following are the sum of each row in the matrix:\n";

    FillSumArray(Sum , arr , 3, 3);

    PrintEachRowSum(Sum , 3 , 3);

    return 0;
}