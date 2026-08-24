#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
using namespace std;
string ReadString() {
    string S1;
    cout << "Enter your string \n";
    getline(cin, S1);
    return S1;
}
string LowerAllString(string S1)
{

    for (short i = 0; i < S1.length(); i++)
    {

            S1[i] = tolower(S1[i]);

    }
    return S1;
}
string UpperAllString(string S1)
{

    for (short i = 0; i < S1.length(); i++)
    {

        S1[i] = toupper(S1[i]);

    }
    return S1;
}
int main()
{
    string S1 = ReadString();
    cout << "\nString after upper:\n";
    S1 = UpperAllString(S1);
    cout << S1;
    cout << "\nString after lower:\n";
    S1 = LowerAllString(S1);
    cout << S1;
    return 0;
}