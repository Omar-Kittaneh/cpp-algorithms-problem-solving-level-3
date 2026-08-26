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
char InvertLetterCase(char c) {
    return  isupper(c) ? tolower(c) : toupper(c);
}
string ReadString() {
    string S1;
    cout << "Enter your string \n";
    getline(cin, S1);
    return S1;
}
short CountLetter(string S1,char c , bool MatchCase = true) {
    short Count=0;
    for(short i=0;i<S1.length();i++) {
        if (MatchCase) {
            if (S1[i] == c) {
                Count++;
            }
        }
        else {
            if (tolower(S1[i]) == tolower(c)) {
                Count++;
            }
        }
    }
    return Count;
}

int main() {
    string S1 = ReadString();
    char Ch1 = ReadChar();
    cout << "\nLetter \'" << Ch1 << "\' Count = " <<
    CountLetter(S1, Ch1);
    cout << "\nLetter \'" << Ch1 << "\' ";
    cout << "Or \'" << InvertLetterCase(Ch1) << "\' ";
    cout << " Count = " << CountLetter(S1, Ch1, false);
    return 0;
}