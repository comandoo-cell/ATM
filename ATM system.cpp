#include <iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
const string ClientsFileName = "Clients.txt";
struct sClient {
    string AccountNumber = "null";
    string PinCode = "null";
    string Name = "null";
    string Phone = "null";
    double AccountBalance = 0;
    bool MarkForDelete = false;
};
void ClearScreen() {
    system("cls");
}
void ControlMenu();
void GoBackToMainMenue() {
    cout << "\n\nPress any key to go back to Main Menue...\n";
    system("pause>0");

}
vector<string> SplitString(string S1, string Delim) {
    vector<string> vString;
    short pos = 0;
    string sWord;
    while ((pos = S1.find(Delim)) != std::string::npos) {
        sWord = S1.substr(0, pos);
        if (sWord != "") {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "") {
        vString.push_back(S1);
    }
    return vString;
}
sClient ConvertLinetoRecord(string Line, string Seperator = "#//#") {
    sClient Client;
    vector<string> vClientData;
    vClientData = SplitString(Line, Seperator);
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);
    return Client;
}
string ConvertRecordToLine(sClient Client, string Seperator = "#//#") {
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}
vector<sClient> LoadCleintsDataFromFile(string FileName) {
    vector<sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open()) {
        string Line;
        sClient Client;
        while (getline(MyFile, Line)) {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}
vector<sClient> g_Clients = LoadCleintsDataFromFile(ClientsFileName);

void loginScreen() {
    cout << "----------------------------------------\n";
    cout << "            Login Screen\n";
    cout << "----------------------------------------\n";
    cout << "Do you want logout? ";
    cout << "input in  username 0.\n";
}
string ReadAccountNumber() {
    string s1;
    cout << "Enter account number ";
    cin >> s1;
    return s1;
}
string ReadPinCode() {
    string s1;
    cout << "Enter pin code ";
    cin >> s1;
    return s1;
}
bool findByAccountNumber(string accountnumber,string pincode, vector<sClient>Vclinet, sClient& client) {
    for (sClient& C : Vclinet) {
        if (accountnumber == C.AccountNumber&&pincode == C.PinCode) {
            client = C;
            return true;
        }
    }
    return false;
}

vector<sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients) {
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    string DataLine;
    if (MyFile.is_open()) {
        for (sClient C : vClients) {
            if (C.MarkForDelete == false) {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}
sClient g_client1;
bool login() {
    ClearScreen();
    loginScreen();
    string accountnumber, pincode;

    vector<sClient>& loading = g_Clients;
    sClient client;
    while (true) {
        accountnumber = ReadAccountNumber();
        pincode = ReadPinCode();
        if (findByAccountNumber(accountnumber, pincode, loading, client)) {
            g_client1 = client;
            ClearScreen();
            ControlMenu();
            return true;
        }

        cout << "invalid Username/Passwprd\n";
    }


}
void ShowMainMenu() {
    cout << "============================================\n";
    cout << "           ATM MAIN MENUE SCREEN            \n";
    cout << "============================================\n";
    cout << "     [1] Quick Withdraw.\n";
    cout << "     [2] Normal Withdraw.\n";
    cout << "     [3] Deposit.\n";
    cout << "     [4] Check Balance.\n";
    cout << "     [5] Logout.\n";
    cout << "============================================\n";

}
int ReadNumber() {
    int number;
    do {
        cout << "choose do you want to do? [1 to 5]\n";
        cin >> number;
        if (number < 1 || number>5) {
            cout << "invalid number \n";
        }
    } while (number < 1 || number>5);
    return number;
}
int ReadQuickWithdraw() {
    int number;
    do {
        cout << "choose do you want to do? [1 to 8]\n";
        cin >> number;
        if (number < 1 || number>8) {
            cout << "invalid number \n";
        }
    } while (number < 1 || number>8);
    return number;
}
int ReadNormalWithdraw() {
    int number;
    do {
        cout << "Enter an ammount multiple of 5's ?";
        cin >> number;
        if (number % 5 != 0) {
            cout << "Invalid number ";
        }
    } while (number % 5 != 0);
    return number;
}
int ReadDeposit() {
    int number;
    do {
        cout << "Enter a positive deposit amount ?";
        cin >> number;
        if (number <1) {
            cout << "Invalid number ";
        }
    } while (number <1);
    return number;
}
void QuickWithdrawMenu() {
    cout << "============================================\n";
    cout << "           Quick Withfraw Screen            \n";
    cout << "============================================\n";
    cout << "     [1] 20 \t\t\t[2] 50\n";
    cout << "     [3] 100\t\t\t[4] 200\n";
    cout << "     [5] 400\t\t\t[6] 600\n";
    cout << "     [7] 800\t\t\t[8] 1000\n";
    cout << "     [9] Exit.\n";
    cout << "============================================\n";
}
void NormalWithdrawMenu() {
    cout << "============================================\n";
    cout << "           Normal Withfraw Screen            \n";
    cout << "============================================\n";
}
void DepositMenue() {
    cout << "============================================\n";
    cout << "           Deposit Screen            \n";
    cout << "============================================\n";
}
void CheckBalanceMenu() {
    cout << "============================================\n";
    cout << "           Check Balance Screen            \n";
    cout << "============================================\n";
}
void UpdateClientBalance() {
    for (sClient& C : g_Clients) {
        if (C.AccountNumber == g_client1.AccountNumber) {
            C.AccountBalance = g_client1.AccountBalance;
            break;
        }
    }
    SaveCleintsDataToFile(ClientsFileName, g_Clients);
}

void QuickWithdaw() {
    QuickWithdrawMenu();
    cout << "Total Balance: " << g_client1.AccountBalance << endl;

    int number;
    do {
        number = ReadQuickWithdraw();
        if (number == 9)
            return;
    } while (false);

    double amount = 0;
    switch (number) {
    case 1: amount = 20; break;
    case 2: amount = 50; break;
    case 3: amount = 100; break;
    case 4: amount = 200; break;
    case 5: amount = 400; break;
    case 6: amount = 600; break;
    case 7: amount = 800; break;
    case 8: amount = 1000; break;
    }

    if (amount > g_client1.AccountBalance) {
        cout << "You don’t have enough balance.\n";
        return;
    }

    g_client1.AccountBalance -= amount;

    UpdateClientBalance();

    cout << "\nWithdrawal successful! New Balance: " << g_client1.AccountBalance << endl;
}
void NormalWithdraw(){
 
    NormalWithdrawMenu();
    cout << "Total Balance: " << g_client1.AccountBalance << endl;
    int number;
    do {
        number = ReadNormalWithdraw();
        if (number > g_client1.AccountBalance) {
            cout << "You don’t have enough balance.\n";
           
        }
    } while (number > g_client1.AccountBalance);
    g_client1.AccountBalance -= number;
    UpdateClientBalance();
    cout << "\nWithdrawal successful! New Balance: " << g_client1.AccountBalance << endl;
}
void Deposit() {
    DepositMenue();
    int number = ReadDeposit();
    g_client1.AccountBalance += number;
    UpdateClientBalance();
    cout << "\nWithdrawal successful! New Balance: " << g_client1.AccountBalance << endl;

}
void CheckBalance() {
    CheckBalanceMenu();
    cout << "Total Balance: " << g_client1.AccountBalance << endl;
}

void ControlMenu() {
    do {
        ShowMainMenu();
        int number = ReadNumber();
        switch (number) {
        case 1: {
            ClearScreen();
            QuickWithdaw();
            GoBackToMainMenue();
            break;
        }
        case 2: {
            ClearScreen();
            NormalWithdraw();
            GoBackToMainMenue();
            break;
        }
        case 3: {
            ClearScreen();
            Deposit();
            GoBackToMainMenue();
            break;
        }
        case 4: {
            ClearScreen();
            CheckBalance();
            GoBackToMainMenue();
            break;
        }
        case 5: {
            ClearScreen();
            login();
            break;
        }
        }
    } while (true);
}
int main()
{
    login();
   
}

