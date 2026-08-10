#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols)
{
    short Counter = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Counter++;
            arr[i][j] = Counter;
        }
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
void TransposeMatrix(int arr[3][3], int arrTransposed[3][3] , short Rows, short Cols) {
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arrTransposed[i][j] = arr[j][i];
        }

    }
}

using namespace std;

int main() {
    srand((unsigned)time(NULL));
    int arr[3][3];
    int arrTransposed[3][3];
    FillMatrixWithOrderedNumbers(arr, 3, 3);
    cout << "\nThe following is a 3x3 ordered matrix:\n";
    PrintMatrix(arr, 3, 3);
    cout << "The Following is the transposed matrix:\n";
    TransposeMatrix(arr, arrTransposed , 3 , 3);
    PrintMatrix( arrTransposed , 3 , 3);
    return 0;
}