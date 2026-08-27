#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
string ReadString() {
    string S1;
    cout << "Enter your string \n";
    getline(cin, S1);
    return S1;
}
vector<string> SplitString(string S1,string delim ) {
    vector<string> vString;
    short pos=0;
    string Word;
    while ((pos = S1.find(delim)) != std::string::npos) {
        Word = S1.substr(0,pos);
        if (Word != "") {
          vString.push_back(Word);
         }
        S1.erase(0,pos + delim.length());
    }
    if ( S1 != "") {
        vString.push_back(S1);
    }
    return vString;
}
void PrintVector( vector<string>& vString ) {
    cout << "\nTokens = " << vString.size() << endl;
    for (const string& s : vString) {
        cout << s << endl;
    }
}
int main() {
    vector<string> vString;
    vString = SplitString(ReadString(), ",");
   PrintVector(vString);
    return 0;
}