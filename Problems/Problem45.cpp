#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};
sClient ReadNewClient() {
    sClient client;
    cout << "\nEnter Account Number? ";
    getline(cin, client.AccountNumber);
    cout << "\nEnter PinCode? ";
    getline(cin, client.PinCode);
    cout << "\nEnter Name? ";
    getline(cin, client.Name);
    cout << "\nEnter Phone? ";
    getline(cin, client.Phone);
    cout << "\nEnter AccountBalance? ";
    cin >> client.AccountBalance;

   return client;
}
string ConvertRecordToLine(sClient Client , string Seperator = "#//#") {
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}
int main() {
    cout << "\nPlease Enter Client Data: \n\n";
    sClient Client;
    Client = ReadNewClient();
    cout << "\n\nClient Record for Saving is: \n";
    cout << ConvertRecordToLine(Client);
    return 0;
}