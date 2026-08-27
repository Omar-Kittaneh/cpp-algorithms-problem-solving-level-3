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
string ReadString() {
    string S1;
    cout << "Enter your string \n";
    getline(cin, S1);
    return S1;
}
bool IsVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
short CountVowels(string S1) {
    short Count=0;
    for(short i=0;i<S1.length();i++) {
        if(IsVowel(S1[i])) {
            Count++;
        }
    }
    return Count;
}
int main() {
    string S1 = ReadString();
    cout << "\nNumber of vowels is: " << CountVowels(S1);
    return 0;
}