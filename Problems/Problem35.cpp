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
void PrintOneWordOnLine(string S1) {
   short pos = 0;
    string delim = " ";
    string Word;
    while ((pos = S1.find(delim)) != std::string::npos) {
         Word = S1.substr(0, pos);
        if (Word != "") {
            cout << Word << endl ;
        }
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "") {
        cout << S1 << endl;
    }
}
int main() {
   string S1 = ReadString();
     PrintOneWordOnLine(S1);

    return 0;
}