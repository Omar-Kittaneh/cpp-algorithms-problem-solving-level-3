#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
char ReadChar() {
    char c;
    cout << "\nEnter a character: \n";
    cin >> c;
    return c;
}
bool IsVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
int main() {
    char Ch1 = ReadChar();
    if (IsVowel(Ch1))
        cout << "\nYES Letter \'" << Ch1 << "\' is vowel";
    else
        cout << "\nNO Letter \'" << Ch1 << "\' is NOT vowel";
    return 0;
}