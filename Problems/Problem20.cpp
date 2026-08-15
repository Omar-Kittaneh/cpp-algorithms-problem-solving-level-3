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

bool IsPalindromeMatrix(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols/2; j++) {
            if (arr[i][j] != arr[i][Cols - j - 1]) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    srand((unsigned) time(NULL));

int Matrix1[3][3] = { {1,2,1},{5,5,5},{7,3,7} };
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);
    if (IsPalindromeMatrix(Matrix1, 3, 3))
    {
        cout << "\nYes: Matrix is Palindrome\n";
    }
    else
        cout << "\nNo: Matrix is NOT Palindrome\n";

    return 0;
}