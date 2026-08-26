#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
using namespace std;
char ReadChar() {
    char c;
    cout << "\nEnter a character: \n";
    cin >> c;
    return c;
}
char InvertLetter(char c) {
    return  isupper(c) ? (c = tolower(c)) : (c = toupper(c));
}
int main()
{
    char Ch1 = ReadChar();
    cout << "\nChar after inverting case:\n";
    Ch1 = InvertLetter(Ch1);
    cout << Ch1 << endl;
    return 0;
}