#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};
vector<string> SplitString(string Line, string Seperator) {
    vector<string> result;
    short pos = 0;
    string Word = "";
    while ((pos = Line.find(Seperator)) != string::npos) {
        Word = Line.substr(0, pos);
        if (Word != "") {
            result.push_back(Word);
        }
        Line.erase(0, pos + Seperator.length());
    }
    if (Line != "") {
        result.push_back(Line);
    }
    return result;
}
sClient ConvertLinetoRecord(string Line , string Seperator = "#//#") {
    vector<string> vString = SplitString(Line, Seperator);
    sClient Client;
    Client.AccountNumber = vString[0];
    Client.PinCode = vString[1];
    Client.Name = vString[2];
    Client.Phone = vString[3];
    Client.AccountBalance = stod(vString[4]);
    return Client;
}
void PrintClientRecord(sClient Client)
{
    cout << "\n\nThe following is the extracted client record:\n";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code : " << Client.PinCode;
    cout << "\nName : " << Client.Name;
    cout << "\nPhone : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}
int main() {
    string stLine = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";
    cout << "\nLine Record is:\n";
    cout << stLine;
    sClient Client = ConvertLinetoRecord(stLine);
    PrintClientRecord(Client);
    return 0;
}