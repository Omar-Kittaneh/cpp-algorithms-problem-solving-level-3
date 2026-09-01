#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
const string ClientsFileName = "Client.txt";
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

string ConvertRecordToLine(sClient Client , string Seperator = "#//#") {
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}

void AddDataToFile(string ClientsFileName , vector <sClient> vClients) {
    ofstream MyFile;
    MyFile.open(ClientsFileName, ios::out);
    if (MyFile.is_open()) {
        for (sClient& C : vClients) {
            if (C.MarkForDelete == false) {
                string Client = ConvertRecordToLine(C);
                MyFile << Client << endl;
            }
        }

        MyFile.close();
    }
}

vector<string> SplitString(string S1, string Delim) {
    vector<string> vString;
    short pos = 0;
    string sWord;
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1);
    }
    return vString;
}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#") {
    sClient Client;
    vector<string> vClientData;
    vClientData = SplitString(Line , Seperator);
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client;
}

vector <sClient> LoadCleintsDataFromFile(string FileName){

        vector <sClient> vClients;
        fstream MyFile;
        MyFile.open(FileName, ios::in);
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                if (Line != "")
                {
                    sClient Client = ConvertLinetoRecord(Line);
                    vClients.push_back(Client);
                }
            }
            MyFile.close();
        }
        return vClients;
    }

void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code : " << Client.PinCode;
    cout << "\nName : " << Client.Name;
    cout << "\nPhone : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;
}

bool FindClientByAccountNumber(vector <sClient> vClients, string AccountNumber , sClient &Client) {
    for (sClient C : vClients) {
        if (C.AccountNumber == AccountNumber) {
            Client = C;
            return true;
        }
    }
    return false;
}
bool MarkForDelete(vector <sClient>& vClients, string AccountNumber ) {
    for (sClient& C : vClients) {
        if (C.AccountNumber == AccountNumber) {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}
bool DeleteClientByAccountNumber(string AccountNumber , vector <sClient>& vClients) {
    char Delete = 'n' ;
    sClient Client;
    if (FindClientByAccountNumber(vClients , AccountNumber , Client)) {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        cin >> Delete;
        if (tolower(Delete) == 'y') {
            MarkForDelete(vClients, AccountNumber);
            AddDataToFile( ClientsFileName,vClients);

            vClients = LoadCleintsDataFromFile(ClientsFileName); //Refresh Clients
            cout << "\n\nClient Deleted Successfully.";
            return true;
        }
        else {
            cout << "\n\nDelete Operation Cancelled.";
            return false;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }

}

int main() {
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);

    return 0;
}