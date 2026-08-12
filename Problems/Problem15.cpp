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
int ReadNumber() {
    int number;
    cout << "\nEnter a number to count in matrex: \n";
   cin >> number;
    return number;
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
int main() {
    srand((unsigned) time(NULL));

    int Matrix1[3][3] ;
    int NumberToCount;

    FillMatrixWithRandomNumbers(Matrix1, 3, 3);

    cout << "\nMatrix1:\n";

    PrintMatrix(Matrix1, 3, 3);
    NumberToCount = ReadNumber();

    printf("\nNumber %d  count in matrex: %d\n",NumberToCount , NumberCountInMatrix(Matrix1, NumberToCount, 3, 3));
    return 0;
}