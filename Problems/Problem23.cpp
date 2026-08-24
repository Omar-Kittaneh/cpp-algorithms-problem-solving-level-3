#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
string ReadString() {
    string S1;
    cout << "Enter your string \n";
    getline(cin, S1);
    return S1;
}
void PrintFirstLetterOfEachWord(string S1) {
    bool firstLitter = true;
    cout << "\nFirst letter of each word is \n";
    for (int i = 0; i < S1.length(); i++) {
        if (S1[i] != ' ' && firstLitter) {
            cout << S1[i] << endl;
        }
        firstLitter = (S1[i] == ' ' ? true : false);
    }
}
int main() {

   PrintFirstLetterOfEachWord(ReadString());
    return 0;
}