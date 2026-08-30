#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
string ToLowerCase(string S1) {
    for (int i = 0; i < S1.length(); i++) {
        S1[i] = tolower(S1[i]);
    }
    return S1;
}
vector<string> splitString( string S1, string Delim) {
    string word = "" ;
    short pos = 0;
    vector<string> vString;

    while ((pos = S1.find(Delim)) != string::npos) {

        word = S1.substr(0, pos);

        if (word != "") {
            vString.push_back(word);
        }

        S1.erase(0, pos + Delim.length());

    }

    if (S1 != "") {
        vString.push_back(S1);
    }

    return vString;
}
string JoinString( vector<string> vString, string Delim) {
    string S1 = "" ;
    for (auto Iter = vString.begin(); Iter != vString.end(); ++Iter) {
        S1 += *Iter;

        if (Iter + 1 != vString.end()) {
            S1 += Delim;
        }
    }

    return S1;
}
string ReplaceWordInStringUsingSplit(string S1, string StringToReplace , string ReplaceTo , bool MatchCase = true ) {
   vector<string> vString = splitString(S1, " ");
    for (string& word : vString) {
        if (MatchCase) {
            if (word == StringToReplace) {
                word = ReplaceTo;
            }
        }
        else {
            if (ToLowerCase(word) == ToLowerCase(StringToReplace)) {
                word = ReplaceTo;
            }
        }
    }
   return  JoinString(vString," ");
}
int main() {
    string S1 = "Welcome to Jordan , Jordan is a nice country";
    string StringToReplace = "jordan";
    string ReplaceTo = "USA";
    cout << "\nOriginal String:\n" << S1;
    cout << "\n\nReplace with match case: ";
    cout << "\n" << ReplaceWordInStringUsingSplit(S1,StringToReplace, ReplaceTo);
    cout << "\n\nReplace with dont match case: ";
    cout << "\n" << ReplaceWordInStringUsingSplit(S1,StringToReplace, ReplaceTo, false);
    return 0;
}