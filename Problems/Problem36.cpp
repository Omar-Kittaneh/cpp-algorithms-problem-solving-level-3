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
short CountWords(string S1) {
   short Count = 0,pos=0;
    string Word,delim = " ";
    while ((pos = S1.find(delim)) != std::string::npos) {
        Word = S1.substr(0,pos);
        if (Word != "") {
            Count++;
        }
        S1.erase(0,pos + delim.length());
    }
    if ( S1 != "") {
        Count++;
    }
    return Count;
}
int main() {
    string S1 = ReadString();
    cout << "\nThe number of words in your string is: ";
    cout << CountWords(S1);
    return 0;
}