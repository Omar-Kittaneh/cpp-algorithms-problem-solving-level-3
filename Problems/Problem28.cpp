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
char InvertLetter(char c) {
    return  isupper(c) ? (c = tolower(c)) : (c = toupper(c));
}
string InvertAllStringLettersCase(string S1) {
    for (short i = 0; i < S1.length(); i++) {
        S1[i] = InvertLetter(S1[i]);
    }
    return S1;
}
int main()
{
    string S1 = ReadString();
    cout << "\nString after Inverting All Letters Case:\n";
    S1 = InvertAllStringLettersCase(S1);
    cout << S1 << endl;
    return 0;
}