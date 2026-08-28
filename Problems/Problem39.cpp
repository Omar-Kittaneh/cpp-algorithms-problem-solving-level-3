#include <string>
#include <iostream>
#include <vector>
using namespace std;
string JoinString( vector<string> vString, string Delim ) {
    string S1;
    for (const string& s : vString) {
        S1 += s + Delim;
    }
    return S1.substr(0,S1.length()-Delim.length());
}
int main() {
vector<string> vString = {"Omar ","Kitta ","aadsd"};
   cout << JoinString(vString," ") << endl;
    return 0;
}