#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const string FileName = "Client.txt";
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
    getline(cin >> ws, client.AccountNumber);
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
void AddDataToFile(string FileName , string stDataLine) {
    ofstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);
    if (MyFile.is_open()) {
        MyFile << stDataLine << endl;
        MyFile.close();
    }
}
void AddNewClient() {
    sClient Client ;
    Client = ReadNewClient();
    AddDataToFile(FileName,ConvertRecordToLine(Client));
}
void AddClients() {
  char AddMore = 'Y';
    do {
          system("cls");
        cout << "Adding New Client:\n\n";
        AddNewClient();
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> AddMore;
    }while (toupper(AddMore) == 'Y');
}
int main() {
    AddClients();
    return 0;
}