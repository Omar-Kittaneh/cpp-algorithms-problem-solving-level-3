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
    cout << "\nEnter the number to look for in matrex: \n";
    cin >> number;
    return number;
}
bool CountNumberInMatrix(int arr[3][3],int NumberToCount , short Rows, short Cols) {
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
bool IsNumberInMatrix(int Matrix1[3][3], int Number, short Rows,short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] == Number)
            {
                return true;
            };
        }
    }
    return false;
 }
int main() {
    srand((unsigned) time(NULL));

    int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);
    int NumberToLook = ReadNumber();
    //Using Count is a slower method
    if (CountNumberInMatrix(Matrix1, NumberToLook, 3, 3) > 0)
        cout << "\nYes it is there.\n";
    else
        cout << "\nNo: It's NOT there.\n";
    //This is faster mthod
    if (IsNumberInMatrix(Matrix1, NumberToLook, 3, 3))
        cout << "\nYes it is there.\n";
    else
        cout << "\nNo: It's NOT there.\n";

    return 0;
}