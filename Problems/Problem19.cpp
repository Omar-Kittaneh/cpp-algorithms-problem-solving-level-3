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
int PrintMinNumberInMatrix(int Matrix1[3][3], int Number, short Rows,short Cols)
{
    int min = Matrix1[0][0];
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] < min) {
                min = Matrix1[i][j];
            }
        }
    }
    return min;
}
int PrintMaxNumberInMatrix(int Matrix1[3][3], int Number, short Rows,short Cols)
{
    int max = Matrix1[0][0];
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] > max) {
                max = Matrix1[i][j];
            }
        }
    }
    return max;
}
int main() {
    srand((unsigned) time(NULL));

    int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);
    cout << "\nMinimum number in matrix is ";
    cout << PrintMinNumberInMatrix(Matrix1, 3, 3, 3);

    cout << "\nMax number in matrix is " ;
    cout << PrintMaxNumberInMatrix(Matrix1, 3, 3, 3);


    return 0;
}