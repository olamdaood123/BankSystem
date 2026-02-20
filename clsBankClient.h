

#pragma once // ÖãÇä ÚÏã ÊßÑÇÑ ÊÖãíä Çáãáİ ÃËäÇÁ ÚãáíÉ ÇáÊÌãíÚ
#include <iostream> // ãßÊÈÉ ÇáÅÏÎÇá æÇáÅÎÑÇÌ ÇáŞíÇÓíÉ
#include <string> // ãßÊÈÉ ÇáÊÚÇãá ãÚ ÇáäÕæÕ
#include "clsPerson.h" // ÊÖãíä ßáÇÓ ÇáÃÈ (ÇáÔÎÕ)
#include "clsString.h" // ãßÊÈÉ ÃÏæÇÊ ÇáäÕæÕ ÇáÎÇÕÉ ÈäÇ
#include <vector> // ãßÊÈÉ ÇáãÕİæİÇÊ ÇáÏíäÇãíßíÉ
#include <fstream> // ãßÊÈÉ ÇáÊÚÇãá ãÚ ÇáãáİÇÊ

using namespace std; // ÇÓÊÎÏÇã İÖÇÁ ÇáÃÓãÇÁ ÇáŞíÇÓí áÊÓåíá ÇáßÊÇÈÉ

// ÇáßáÇÓ íÑË ãä ßáÇÓ ÇáÔÎÕ (Public Inheritance)
class clsBankClient : public clsPerson
{
private: // ÃÚÖÇÁ ÎÇÕÉ: áÇ íãßä ÇáæÕæá ÅáíåÇ ÅáÇ ãä ÏÇÎá åĞÇ ÇáßáÇÓ İŞØ (áÍãÇíÉ ÇáÈíÇäÇÊ)

    // Enum áÊÍÏíÏ æÖÚ ÇáßÇÆä (ÌÏíÏ¡ ÊÚÏíá¡ Ãæ İÇÑÛ) - Private áÃäå ÔÃä ÏÇÎáí ááßáÇÓ
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode; // ãÊÛíÑ áÊÎÒíä æÖÚ ÇáßÇÆä ÇáÍÇáí

    string _AccountNumber; // ãÊÛíÑ ÎÇÕ áÑŞã ÇáÍÓÇÈ (áÇ íÚÏá ÈÚÏ ÇáÅäÔÇÁ)
    string _PinCode; // ãÊÛíÑ ÎÇÕ ááÑãÒ ÇáÓÑí
    float _AccountBalance; // ãÊÛíÑ ÎÇÕ ááÑÕíÏ
    bool _MarkedForDelete = false; // ãÊÛíÑ ãäØŞí áÊÍÏíÏ ãÇ ÅĞÇ ßÇä ÇáÚãíá ÓíõÍĞİ
    struct stTransferLogRecord;
    // Static: áÃäåÇ æÙíİÉ ãÕäÚ (Factory) ÊÍæá äÕ Åáì ßÇÆä æáÇ ÊÍÊÇÌ áßÇÆä ãæÌæÏ áÊÚãá
    // Private: áÃäåÇ ÊÓÊÎÏã İŞØ ãä ŞÈá ÇáÏæÇá ÇáÏÇÎáíÉ ÚäÏ ŞÑÇÁÉ Çáãáİ
    static clsBankClient _ConvertLineToClientObject(string Line, string Separator = "#//#")
    {
        vector<string> vClientData; // ãÕİæİÉ áÊÎÒíä ÇáÈíÇäÇÊ ÇáãŞØÚÉ
        vClientData = clsString::Split(Line, Separator); // ÊŞØíÚ ÇáÓØÑ ÈÇÓÊÎÏÇã ÇáİÇÕá

        // ÅÑÌÇÚ ßÇÆä ÌÏíÏ ãÈäí ÈÇáÈíÇäÇÊ ÇáãÓÊÎÑÌÉ ãä ÇáÓØÑ
        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    // Static: áÃäåÇ æÙíİÉ ÎÏãíÉ ÊÃÎĞ ßÇÆä ßãÏÎá æÊÍæáå áäÕ (ãÓÊŞáÉ Úä ÇáÜ instance ÇáÍÇáí)
    // Private: ÊÓÊÎÏãåÇ ÏÇáÉ ÇáÍİÙ İŞØ
    static string _ConvertClientObjectToLine(clsBankClient Client, string Separator = "#//#")
    {
        string stClientRecord = ""; // ÓáÓáÉ äÕíÉ áÊÌãíÚ ÇáÈíÇäÇÊ
        stClientRecord += Client.FirstName + Separator; // ÅÖÇİÉ ÇáÇÓã ÇáÃæá
        stClientRecord += Client.LastName + Separator; // ÅÖÇİÉ ÇáßäíÉ
        stClientRecord += Client.Email + Separator; // ÅÖÇİÉ ÇáÅíãíá
        stClientRecord += Client.Phone + Separator; // ÅÖÇİÉ ÇáåÇÊİ
        stClientRecord += Client.AccountNumber() + Separator; // ÅÖÇİÉ ÑŞã ÇáÍÓÇÈ
        stClientRecord += Client.PinCode + Separator; // ÅÖÇİÉ ÇáÑãÒ ÇáÓÑí
        stClientRecord += to_string(Client.AccountBalance); // ÊÍæíá ÇáÑÕíÏ áäÕ æÅÖÇİÊå

        return stClientRecord; // ÅÑÌÇÚ ÇáÓØÑ ßÇãáÇğ
    }

    // Static: áÌáÈ ŞÇÆãÉ ÇáÚãáÇÁ ãä Çáãáİ ßÈíÇäÇÊ ÚÇãÉ (áÇ ÊÎÕ ßÇÆä ÈÚíäå)
    // Private: áÖãÇä Ãä ÇáßáÇÓ åæ ÇáãÊÍßã ÇáæÍíÏ İí ÇáæÕæá ááãáİ ÇáÎÇã
    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {
        vector <clsBankClient> vClients; // ãÕİæİÉ áÊÎÒíä ÇáßÇÆäÇÊ
        fstream MyFile; // ßÇÆä ÇáÊÚÇãá ãÚ Çáãáİ
        MyFile.open("Clients.txt", ios::in); // İÊÍ ãáİ ÇáÚãáÇÁ ÈæÖÚ ÇáŞÑÇÁÉ

        if (MyFile.is_open()) // ÇáÊÃßÏ Ãä Çáãáİ İÊÍ ÈäÌÇÍ
        {
            string Line; // ãÊÛíÑ áÊÎÒíä ßá ÓØÑ ãŞÑæÁ
            while (getline(MyFile, Line)) // ŞÑÇÁÉ Çáãáİ ÓØÑÇğ ÈÓØÑ
            {
                clsBankClient Client = _ConvertLineToClientObject(Line); // ÊÍæíá ÇáÓØÑ áßÇÆä
                vClients.push_back(Client); // ÅÖÇİÉ ÇáßÇÆä ááãÕİæİÉ
            }
            MyFile.close(); // ÅÛáÇŞ Çáãáİ
        }
        return vClients; // ÅÑÌÇÚ ãÕİæİÉ ÇáÚãáÇÁ
    }

    // Static: áÃäåÇ ÊÍİÙ ãÕİæİÉ ßÇãáÉ æáÇ ÊÑÊÈØ ÈÈíÇäÇÊ ßÇÆä æÇÍÏ İŞØ
    // Private: ÊÓÊÎÏã ÏÇÎáíÇğ áÊäÙíã ÚãáíÉ ÇáßÊÇÈÉ İí Çáãáİ
    static void _SaveClientsDataToFile(vector <clsBankClient> vClients)
    {
        fstream MyFile; // ßÇÆä ÇáÊÚÇãá ãÚ Çáãáİ
        MyFile.open("Clients.txt", ios::out); // İÊÍ Çáãáİ ÈæÖÚ ÇáßÊÇÈÉ (íãÓÍ ÇáŞÏíã)

      
            string DataLine; // ãÊÛíÑ áÊÎÒíä ÇáÓØÑ ÇáãÍæá
        if (MyFile.is_open())
        {
            for (clsBankClient C : vClients) // ÇáãÑæÑ Úáì ÌãíÚ ÇáÚãáÇÁ İí ÇáãÕİæİÉ
            {
                if (C.MarkedForDeleted() == false) // ÅĞÇ áã íßä ÇáÚãíá ãæÓæãÇğ ááÍĞİ
                {
                    DataLine = _ConvertClientObjectToLine(C); // ÊÍæíá ÇáßÇÆä áÓØÑ
                    MyFile << DataLine << endl; // ßÊÇÈÉ ÇáÓØÑ İí Çáãáİ
                }
            }
            MyFile.close(); // ÅÛáÇŞ Çáãáİ
        }
    }

    // Non-Static: áÃäåÇ ÊÚÏá ÈíÇäÇÊ "åĞÇ" ÇáßÇÆä ÇáÍÇáí İí ŞÇÚÏÉ ÇáÈíÇäÇÊ (Çáãáİ)
    // Private: ÊÓÊÏÚì İŞØ ãä ÎáÇá ÏÇáÉ Save ÇáÚÇãÉ áÖãÇä ÓíÑ ÇáãäØŞ ÇáÈÑãÌí
    void _Update()
    {
        vector <clsBankClient> _vClients; // ãÕİæİÉ ãÄŞÊÉ ááÚãáÇÁ
        _vClients = _LoadClientsDataFromFile(); // ÊÍãíá ßá ÇáÚãáÇÁ ãä Çáãáİ

        for (clsBankClient& C : _vClients) // ÇáÈÍË Úä ÇáÚãíá ÇáÍÇáí İí ÇáãÕİæİÉ
        {
            if (C.AccountNumber() == AccountNumber()) // ÅĞÇ ÊØÇÈŞ ÑŞã ÇáÍÓÇÈ
            {
                C = *this; // ÇÓÊÈÏÇá ÈíÇäÇÊ ÇáÚãíá İí ÇáãÕİæİÉ ÈÈíÇäÇÊ ÇáßÇÆä ÇáÍÇáí
                break; // ÇáÎÑæÌ ãä ÇáÍáŞÉ
            }
        }
        _SaveClientsDataToFile(_vClients); // ÍİÙ ÇáãÕİæİÉ ÇáãÚÏáÉ ááãáİ
    }

    // Non-Static: ÊÖíİ ÈíÇäÇÊ "åĞÇ" ÇáÚãíá ÇáÌÏíÏ ááãáİ
    // Private: ÊÓÊÏÚì ÏÇÎáíÇğ ÈæÇÓØÉ ÏÇáÉ Save
    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this)); // ÊÍæíá ÇáßÇÆä ÇáÍÇáí áÓØÑ æÅÖÇİÊå ááãáİ
    }

    // Non-Static: æÙíİÉ ãÓÇÚÏÉ ÊİÊÍ Çáãáİ æÊÖíİ ÓØÑÇğ İí äåÇíÊå
    // Private: æÙíİÉ ÊŞäíÉ ÈÓíØÉ áÇ Êåã ÇáãÓÊÎÏã ÇáÎÇÑÌí
    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app); // İÊÍ ÈæÖÚ ÇáßÊÇÈÉ æÇáÅáÍÇŞ (Append)

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl; // ßÊÇÈÉ ÇáÓØÑ İí äåÇíÉ Çáãáİ
            MyFile.close();
        }
    }

    // Static: áÅäÔÇÁ ßÇÆä İÇÑÛ ÈÓÑÚÉ (Utility function)
    // Private: ÊÓÊÎÏã ÏÇÎá ÇáßáÇÓ áÊãËíá ÍÇáÉ "áã íÊã ÇáÚËæÑ Úáì ÇáÚãíá"
    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
    /* ÏÇáÉ _PrepareTransferLogRecord:
       - ÈÑÇíİÊ: áÃäåÇ æÙíİÉ ãÓÇÚÏÉ ÏÇÎáíÉ ááÏÇáÉ ÇáÊí ÊáíåÇ.
       - ää ÓÊÇÊíß: áÃäåÇ ÊÚÊãÏ Úáì ÈíÇäÇÊ ÇáÚãíá ÇáÍÇáí ãËá (AccountNumber).
    */
    string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient, string UserName, string Separator = "#//#")
    {
        string TransferLoginRecord = "";
        TransferLoginRecord += clsDate::GetSystemDateTimeString() + Separator; // ÊÓÌíá æŞÊ ÇáÚãáíÉ
        TransferLoginRecord += AccountNumber() + Separator; // ÑŞã ÍÓÇÈ ÇáãÑÓá
        TransferLoginRecord += DestinationClient.AccountNumber() + Separator; // ÑŞã ÍÓÇÈ ÇáãÓÊáã
        TransferLoginRecord += to_string(Amount) + Separator; // ÇáãÈáÛ ÇáãÍæá
        TransferLoginRecord += to_string(AccountBalance) + Separator; // ÑÕíÏ ÇáãÑÓá ÈÚÏ ÇáÎÕã
        TransferLoginRecord += to_string(DestinationClient.AccountBalance) + Separator; // ÑÕíÏ ÇáãÓÊáã ÈÚÏ ÇáÅÖÇİÉ
        TransferLoginRecord += UserName; // ÇÓã ÇáãæÙİ
        return TransferLoginRecord; // ÅÑÌÇÚ ÇáÓØÑ ÌÇåÒÇğ
    }

    /* ÏÇáÉ _RegisterTransferLog:
       - ÈÑÇíİÊ: áÃäåÇ ÊõÓÊÏÚì ÂáíÇğ ÏÇÎá ÏÇáÉ ÇáÊÍæíá æáÇ ÍÇÌÉ áÇÓÊÏÚÇÆåÇ ÎÇÑÌíÇğ.
       - ää ÓÊÇÊíß: áÃäåÇ ÊÓÊÏÚí ÏÇáÉ "ää ÓÊÇÊíß" æÊÎÕ ÚãáíÉ áÚãíá ãÚíä.
    */
    void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
    {
        string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName); // ÇÓÊáÇã ÇáÓØÑ ÇáãõÌåÒ
        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::out | ios::app); // İÊÍ Çáãáİ ááÅÖÇİÉ İí ÂÎÑå
        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl; // ßÊÇÈÉ ÇáÓØÑ İí ãáİ ÇáÊßÓÊ
            MyFile.close(); // ÅÛáÇŞ Çáãáİ
        }
    }
    static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line,string Separator="#//#")
    {
        vector<string >vTransfer = clsString::Split(Line, Separator);
        stTransferLogRecord TransferLogRecord;
        TransferLogRecord.DateTime = vTransfer[0];
        TransferLogRecord.SourceAccountNumber = vTransfer[1];
        TransferLogRecord.DestinationAccountBalance = vTransfer[2];
        TransferLogRecord.Amount = stof(vTransfer[3]);
        TransferLogRecord.srcBalanceAfter = stof(vTransfer[4]);
        TransferLogRecord.desBalanceAfter = stof(vTransfer[5]);
        TransferLogRecord.UserName = vTransfer[6];
        return TransferLogRecord;
    }

public: // ÃÚÖÇÁ ÚÇãÉ: íãßä áÃí ãÈÑãÌ íÓÊÎÏã ÇáßáÇÓ ÇáæÕæá ÅáíåÇ

    // Constructor: áÊåíÆÉ ÇáßÇÆä ÚäÏ ÅäÔÇÆå (Public áíÊãßä ÇáÌãíÚ ãä ÅäÔÇÁ ßÇÆäÇÊ)
    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone) // ÇÓÊÏÚÇÁ ãÔíÏ ßáÇÓ ÇáÃÈ
    {
        _Mode = Mode; // ÖÈØ ÇáæÖÚ
        _AccountNumber = AccountNumber; // ÖÈØ ÑŞã ÇáÍÓÇÈ
        _PinCode = PinCode; // ÖÈØ ÇáÑãÒ ÇáÓÑí
        _AccountBalance = AccountBalance; // ÖÈØ ÇáÑÕíÏ
    }

    // Public: áİÍÕ ãÇ ÅĞÇ ßÇä ÇáßÇÆä İÇÑÛÇğ (íÓÊÎÏãå ÇáãÈÑãÌ ÇáÎÇÑÌí ááÊÃßÏ)
    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    // Public: áãÚÑİÉ ãÇ ÅĞÇ ßÇä åĞÇ ÇáÚãíá ÓíõÍĞİ ŞÑíÈÇğ
    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    // Public: ÏÇáÉ áÇÓÊÑÌÇÚ ÑŞã ÇáÍÓÇÈ (ááŞÑÇÁÉ İŞØ¡ áÇ íæÌÏ ÏÇáÉ Set ááÍãÇíÉ)
    string AccountNumber()
    {
        return _AccountNumber;
    }

    // Set & Get áÜ PinCode: ÚÇãÉ ááÊÍßã İí ÇáÈíÇäÇÊ
    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }
    string GetPinCode()
    {
        return _PinCode;
    }
    // Property: ãíÒÉ áÊÓåíá ÇáæÕæá (ÊÌÚáß ÊÓÊÎÏã ÇáßÇÆä ßÃäå ãÊÛíÑ)
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    // Set & Get áÜ AccountBalance
    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }
   
    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;


        // Public: áØÈÇÚÉ ãÚáæãÇÊ ÇáÚãíá ÈÔßá ãäÓŞ Úáì ÇáÔÇÔÉ
        void Print()
    {
        cout << "\nClient Card:";
        cout << "\n_______";
        cout << "\nFirstName   : " << FirstName; // ÎÇÕíÉ ãæÑæËÉ ãä clsPerson
        cout << "\nLastName    : " << LastName; // ÎÇÕíÉ ãæÑæËÉ ãä clsPerson
        cout << "\nFull Name   : " << FullName(); // ÏÇáÉ ãæÑæËÉ ãä clsPerson
        cout << "\nEmail       : " << Email;
        cout << "\nPhone       : " << Phone;
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n_______\n";
    }

    // Static: áÃäß ÊÑíÏ ÇáÈÍË Úä Úãíá ŞÈá Ãä Êãáß ßÇÆä áå (ÎÏãÉ ÚÇãÉ)
    // Public: áÊãßíä ÇáãÈÑãÌ ãä ÇáÚËæÑ Úáì Ãí Úãíá İí ÇáäÙÇã
    static clsBankClient Find(string AccountNumber)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client.AccountNumber() == AccountNumber) // ÅĞÇ æÌÏäÇ ÑŞã ÇáÍÓÇÈ ÇáãØáæÈ
                {
                    MyFile.close();
                    return Client; // äÑÌÚ ßÇÆä ÇáÚãíá ÇáĞí æÌÏäÇå
                }
            }
            MyFile.close();
        }
        return _GetEmptyClientObject(); // ÅĞÇ áã äÌÏ ÇáÚãíá¡ äÑÌÚ ßÇÆä İÇÑÛ
    }

    // Static Find (Overloading): ááÈÍË æÇáÊÍŞŞ ãä ÇáÑãÒ ÇáÓÑí (Login)
    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    // Enum áäÊÇÆÌ ÇáÍİÙ: ÚÇãÉ áßí íÚÑİ ÇáãÓÊÎÏã ÇáÎÇÑÌí ÓÈÈ ÇáäÌÇÍ Ãæ ÇáİÔá
    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

    // Non-Static: áÃäåÇ ÊÍİÙ ÈíÇäÇÊ "åĞÇ" ÇáßÇÆä ÇáÍÇáí (this)
    // Public: ÇáæÙíİÉ ÇáÃåã ááãÓÊÎÏã ÇáÎÇÑÌí áÊÃßíÏ Ãí ÚãáíÉ (ÊÚÏíá Ãæ ÅÖÇİÉ)
    enSaveResults Save()
    {
        switch (_Mode) // İÍÕ æÖÚ ÇáßÇÆä ÇáÍÇáí
        {
        case enMode::EmptyMode: // ÅĞÇ ßÇä ÇáßÇÆä İÇÑÛÇğ
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }
        case enMode::UpdateMode: // ÅĞÇ ßÇä ÇáßÇÆä ãæÌæÏÇğ æäÑíÏ ÊÚÏíáå
        {
            _Update(); // ÇÓÊÏÚÇÁ ÇáÏÇáÉ ÇáÎÇÕÉ ÈÇáÊÚÏíá
            return enSaveResults::svSucceeded;
            break;
        }
        case enMode::AddNewMode: // ÅĞÇ ßÇä ßÇÆäÇğ ÌÏíÏÇğ äÑíÏ ÅÖÇİÊå
        {
            if (clsBankClient::IsClientExist(_AccountNumber)) // ÇáÊÃßÏ Ãä ÑŞã ÇáÍÓÇÈ ÛíÑ ãßÑÑ
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew(); // ÇÓÊÏÚÇÁ ÇáÏÇáÉ ÇáÎÇÕÉ ÈÇáÅÖÇİÉ
                _Mode = enMode::UpdateMode; // ÊÛííÑ æÖÚ ÇáßÇÆä áÊÚÏíá ÈÚÏ ÇáÅÖÇİÉ
                return enSaveResults::svSucceeded;
            }
            break;
        }
        }
    }

    // Static: ááÊÍŞŞ ãä æÌæÏ Úãíá ÈÇáÑŞã İŞØ Ïæä ÇáÍÇÌÉ áßÇÆä
    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client1 = clsBankClient::Find(AccountNumber); // ãÍÇæáÉ ÅíÌÇÏ ÇáÚãíá
        return (!Client1.IsEmpty()); // ÅĞÇ áã íßä İÇÑÛÇğ İÅäå ãæÌæÏ
    }


        // Non-Static: ÊÍĞİ ÇáÚãíá ÇáÍÇáí ãä ÇáäÙÇã (ÊÖÚ ÚáÇãÉ ÍĞİ Ëã ÊÍİÙ Çáãáİ)
            // Public: ãÊÇÍÉ ááãÈÑãÌ áÍĞİ ÇáÚãíá ÇáäÔØ
        bool Delete()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkedForDelete = true; // æÓã ÇáÚãíá ááÍĞİ
                break;
            }
        }
        _SaveClientsDataToFile(_vClients); // ÅÚÇÏÉ ÍİÙ Çáãáİ ÈÏæä ÇáÚãíá ÇáãæÓæã
        *this = _GetEmptyClientObject(); // ÊÕİíÑ ÈíÇäÇÊ ÇáßÇÆä ÇáÍÇáí İí ÇáĞÇßÑÉ
        return true;
    }

    // Static: ÊõÓÊÏÚì áÈÏÁ ÚãáíÉ ÅäÔÇÁ Úãíá ÌÏíÏ (ÊÌåíÒ ßÇÆä ÈæÖÚ AddNewMode)
    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    // Static: áÌáÈ ßá ÇáÚãáÇÁ ßŞÇÆãÉ æÇÍÏÉ ááÚÑÖ ÇáÚÇã
    static vector <clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    // Static: æÙíİÉ ÅÍÕÇÆíÉ ÊÍÓÈ ãÌãæÚ ÃÑÕÏÉ ßá ÇáÚãáÇÁ İí ŞÇÚÏÉ ÇáÈíÇäÇÊ
    static float GetTotalBalances()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList(); // ÌáÈ ßá ÇáÚãáÇÁ
        double TotalBalances = 0; // ãÊÛíÑ ÇáãÌãæÚ
        for (clsBankClient Client : vClients) // ÌãÚ ÇáÃÑÕÏÉ
        {
            TotalBalances += Client.AccountBalance;
        }
        return TotalBalances; // ÅÑÌÇÚ ÇáãÌãæÚ ÇáäåÇÆí
    }
    /* ÏÇáÉ Deposit:
    - ÈÈáß: áÃäåÇ ÊõÓÊÎÏã ãÈÇÔÑÉ ãä ÔÇÔÇÊ ÇáÅíÏÇÚ ÇáÎÇÑÌíÉ.
    - ää ÓÊÇÊíß: áÃäåÇ ÊÚÏá ÑÕíÏ ÍÓÇÈ ÇáÚãíá "ÇáÍÇáí" ÇáãÓÊÏÚí ááÏÇáÉ. */
    void Deposit(double Amount)
    {
        _AccountBalance += Amount; // ÅÖÇİÉ ÇáãÈáÛ ááÑÕíÏ ÇáÍÇáí ááÚãíá
        Save(); // ÍİÙ ÇáÊÚÏíá ÇáÌÏíÏ İí ãáİ ŞÇÚÏÉ ÈíÇäÇÊ ÇáÚãáÇÁ
    }

    /* ÏÇáÉ WithDraw:
       - ÈÈáß: áÃäåÇ ÊõÓÊÎÏã İí ÔÇÔÇÊ ÇáÓÍÈ æÇáÊÍæíá.
       - ää ÓÊÇÊíß: áÊÊãßä ãä ÎÕã ÇáãÈáÛ ãä ÑÕíÏ åĞÇ ÇáÚãíá ÊÍÏíÏÇğ. */
    void WithDraw(double Amount)
    {
        _AccountBalance -= Amount; // ÎÕã ÇáãÈáÛ ãä ÑÕíÏ ÇáÚãíá
        Save(); // ÍİÙ ÇáÑÕíÏ ÇáãÍÏË İí Çáãáİ
    }

    /* ÏÇáÉ Transfer:
       - ÈÈáß: áÊÊãßä ÔÇÔÉ ÇáÊÍæíá ãä ãäÇÏÇÊåÇ æÊäİíĞ ÇáÚãáíÉ.
       - ää ÓÊÇÊíß: áÃäåÇ ÚãáíÉ Èíä "ßÇÆäíä" (ÇáÚãíá ÇáÍÇáí æÇáãÓÊáã). */
    bool Transfer(float Amount, clsBankClient& DestinationClient, string UserName)
    {
        if (Amount > AccountBalance) // ÇáÊÃßÏ ÅĞÇ ßÇä ÑÕíÏ ÇáãÑÓá íßİí ááÊÍæíá
        {
            return false; // İÔá ÇáÚãáíÉ áÚÏã ßİÇíÉ ÇáÑÕíÏ
        }

        WithDraw(Amount); // ÎÕã ÇáãÈáÛ ãä ÇáÚãíá ÇáÍÇáí
        DestinationClient.Deposit(Amount); // ÅÖÇİÉ ÇáãÈáÛ áÍÓÇÈ ÇáÚãíá ÇáãÓÊáã
        _RegisterTransferLog(Amount, DestinationClient, UserName); // ÊÓÌíá ÊİÇÕíá ÇáÚãáíÉ İí ãáİ ÇáÓÌá

        return true; // äÌÇÍ ÚãáíÉ ÇáÊÍæíá
    }
    struct stTransferLogRecord
    {
        string DateTime; 
        string SourceAccountNumber;
        string DestinationAccountBalance;
        float Amount;
        float srcBalanceAfter;
        float desBalanceAfter;
        string UserName;
    };
    static vector<stTransferLogRecord> GetTransferLogList()
    {
        vector<stTransferLogRecord> vTransferLogRecord;
        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::in);
        if (MyFile.is_open())
        {
            string Line;
            stTransferLogRecord TransferLogRecord;
            while (getline(MyFile, Line))
            {
                TransferLogRecord = _ConvertTransferLogLineToRecord(Line);
                vTransferLogRecord.push_back(TransferLogRecord);
            }
            MyFile.close();
        }
        return vTransferLogRecord;
    }
};



























