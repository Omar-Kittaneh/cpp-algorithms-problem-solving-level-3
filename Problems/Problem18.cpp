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

void PrintIntersected(int Matrix1[3][3],int Matrix2[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            int NumberToLook = Matrix1[i][j];
            if (IsNumberInMatrix(Matrix2, NumberToLook, Rows, Cols))
                cout << NumberToLook << setw(10) ;
        }
    }
}
int main() {
    srand((unsigned) time(NULL));

    int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };

    int Matrix2[3][3] = { {5,80,90},{22,77,1},{10,8,33} };

    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);

    cout << "\nMatrix2:\n";
    PrintMatrix(Matrix2, 3, 3);

    cout << "\nIntersected number are\n";
    PrintIntersected(Matrix1, Matrix2, 3, 3);
    return 0;
}