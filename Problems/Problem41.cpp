#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
vector<string> SplitString(string S1, string Delim ) {
   vector<string> vString;
   string word = "";
    short pos = 0;
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
string ReverseWordInString(string S1) {
    string word = "";
    vector<string> vString = SplitString(S1, " ");
    vector<string>::iterator iter = vString.end();
    while (iter != vString.begin()) {
        iter--;
        word += *iter + " ";
    }
    word = word.substr(0, word.length() - 1);
    return word;
}
int main() {
     string s = "Kittaneh Omar TheKing Helo";
    cout << ReverseWordInString(s);
    
    return 0;
}