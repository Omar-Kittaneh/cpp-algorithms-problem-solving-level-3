#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
using namespace std;
enum enWhatToCount{SmallLetters = 0, CapitalLetters = 1 , All = 2};
string ReadString() {
    string S1;
    cout << "Enter your string \n";
    getline(cin, S1);
    return S1;
}
short CountLetters(string S1 , enWhatToCount WhatToCount = enWhatToCount::All) {
    short Count = 0;
  if (WhatToCount == enWhatToCount::All) {
      return S1.length();
  }
    for (short i = 0; i < S1.length(); i++) {
         if (isupper(S1[i]) && WhatToCount == enWhatToCount::CapitalLetters ) {
        Count++;
        }
        else if (islower(S1[i]) && WhatToCount == enWhatToCount::SmallLetters ) {
            Count++;
        }
    }
    return Count;
}
short CountCapitalLetters(string S1) {
    short Count = 0;
    for (short i = 0; i < S1.length(); i++) {
        if (isupper(S1[i])) {
            Count++;
        }
    }
   return Count;
}
short CountSmallLetters(string S1) {
    short Count = 0;
    for (short i = 0; i < S1.length(); i++) {
        if (islower(S1[i])) {
            Count++;
        }
    }
    return Count;
}
int main()
{
    string S1 = ReadString();
    cout << "\nString Length = " << S1.length();
    cout << "\nCapital Letters Count= " << CountCapitalLetters(S1);
    cout << "\nSmall Letters Count= " << CountSmallLetters(S1);
    cout << "\n\nMethod 2\n";
    cout << "\nString Length = " << CountLetters(S1);
    cout << "\nCapital Letters Count= " << CountLetters(S1,
    enWhatToCount::CapitalLetters);
    cout << "\nSmall Letters Count= " <<
    CountLetters(S1,enWhatToCount::SmallLetters );
    return 0;
}