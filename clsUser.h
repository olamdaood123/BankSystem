#pragma once // íãäÚ ÊßÑÇÑ ÊÖãíä Çáãáİ İí ÇáãÔÑæÚ áÊÌäÈ ÃÎØÇÁ ÇáÊÚÑíİ ÇáãßÑÑ
#include <iostream> // ãßÊÈÉ ÇáÅÏÎÇá æÇáÅÎÑÇÌ ÇáÃÓÇÓíÉ
#include <string> // ãßÊÈÉ ÇáÊÚÇãá ãÚ ÇáäÕæÕ
#include "clsPerson.h" // ßáÇÓ ÇáÃÈ ÇáĞí íÍÊæí Úáì ÇáãÚáæãÇÊ ÇáÔÎÕíÉ (ÇáÇÓã¡ ÇáåÇÊİ¡ ÇáÎ)
#include "clsString.h" // ãßÊÈÉ ÃÏæÇÊ ãÚÇáÌÉ ÇáäÕæÕ ÇáÎÇÕÉ ÈäÇ
#include <vector> // áÇÓÊÎÏÇã ÇáãÕİæİÇÊ ÇáÏíäÇãíßíÉ (ÇáäÇŞáÇÊ)
#include <fstream> // ááÊÚÇãá ãÚ ŞÑÇÁÉ æßÊÇÈÉ ÇáãáİÇÊ (Users.txt)
#include"clsUnit.h"
using namespace std; // áÊÌäÈ ßÊÇÈÉ std:: ŞÈá ßá ÃãÑ

// ÇáßáÇÓ íÑË ãä clsPerson áíÔãá ÈíÇäÇÊ ÇáÔÎÕ + ÈíÇäÇÊ ÇáÏÎæá ááäÙÇã
class clsUser : public clsPerson
{
private: // ÃÚÖÇÁ ÎÇÕÉ: ÍãÇíÉ ÇáÈíÇäÇÊ ãä ÇáæÕæá ÇáÎÇÑÌí ÇáãÈÇÔÑ

    // Enum áÊÍÏíÏ æÖÚ ÇáßÇÆä - Private: áÃä ãäØŞ "ÇáÍÇáÉ" ÏÇÎáí æáÇ íÌÈ ÊÛííÑå ãä ÇáÎÇÑÌ
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode; // ãÊÛíÑ íÍİÙ ÍÇáÉ ÇáßÇÆä ÇáÍÇáíÉ
    string _UserName; // ÇÓã ÇáãÓÊÎÏã
    string _Password; // ßáãÉ ÇáãÑæÑ
    int _Permissions; // ÕáÇÍíÇÊ ÇáãÓÊÎÏã (ÑŞã íãËá ÇáÕáÇÍíÇÊ)

    bool _MarkedForDelete = false; // ãÊÛíÑ ãäØŞí íÍÏÏ ÅĞÇ ßÇä ÇáãÓÊÎÏã ãØáæÈ ÍĞİå ãä Çáãáİ
    struct stLoginRegisterRecord;
    // Static: áÃäåÇ æÙíİÉ "ÊÍæíá" ÊÎáŞ ßÇÆäÇğ ãä äÕ (áÇ ÊÍÊÇÌ áßÇÆä ÍÇáí áÊÚãá)
    // Private: ÊÓÊÎÏãåÇ ÏÇáÉ ÇáŞÑÇÁÉ ãä Çáãáİ İŞØ ßÃÏÇÉ ãÓÇÚÏÉ
    static clsUser _ConvertLineToUserObject(string Line, string Separator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Separator); // ÊŞØíÚ ÇáÓØÑ ÇáÈÑãÌí ÈäÇÁğ Úáì ÇáİÇÕá

        // ÅÑÌÇÚ ßÇÆä ÌÏíÏ ÈæÖÚ ÇáÊÍÏíË UpdateMode ãÚ ÊãÑíÑ ÇáÈíÇäÇÊ
        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4],clsUnit::DecryptText( vUserData[5]), stoi(vUserData[6]));
    }


    // Static: áÃäåÇ ÊÃÎĞ ÈíÇäÇÊ ßÇÆä æÊÍæáåÇ áäÕ (ãÓÊŞáÉ Úä ÇáÜ instance ÇáÍÇáí)
    // Private: ÊÓÊÎÏã İŞØ ÚäÏ ÇáÑÛÈÉ İí ÇáßÊÇÈÉ ÏÇÎá Çáãáİ
    static string _ConvertUserObjectToLine(clsUser User, string Separator = "#//#")
    {
        string UserRecord = "";
        UserRecord += User.FirstName + Separator; // ÏãÌ ÇáÇÓã ÇáÃæá
        UserRecord += User.LastName + Separator; // ÏãÌ ÇáßäíÉ
        UserRecord += User.Email + Separator; // ÏãÌ ÇáÈÑíÏ
        UserRecord += User.Phone + Separator; // ÏãÌ ÇáåÇÊİ
        UserRecord += User.UserName + Separator; // ÏãÌ ÇÓã ÇáãÓÊÎÏã
        UserRecord +=clsUnit::EncryptionText( User.Password)+ Separator; // ÏãÌ ßáãÉ ÇáãÑæÑ
        UserRecord += to_string(User.Permissions); // ÊÍæíá ÇáÕáÇÍíÇÊ áäÕ æÏãÌåÇ

        return UserRecord; // ÅÑÌÇÚ ÇáÓØÑ ßÇãáÇğ ááÍİÙ
    }

    // Static: áÌáÈ ÌãíÚ ÇáãÓÊÎÏãíä ãä Çáãáİ (æÙíİÉ ÚÇãÉ ááäÙÇã)
    // Private: áÖãÇä Ãä ÇáßáÇÓ åæ ÇáãÊÍßã ÇáæÍíÏ İí ØÑíŞÉ ŞÑÇÁÉ ãáİÇÊå
    static  vector <clsUser> _LoadUsersDataFromFile()
    {
        vector <clsUser> vUsers;
        fstream MyFile;
        MyFile.open("Users.txt", ios::in); // İÊÍ Çáãáİ İí æÖÚ ÇáŞÑÇÁÉ

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line)) // ŞÑÇÁÉ Çáãáİ ÓØÑÇğ ÈÓØÑ
            {
                clsUser User = _ConvertLineToUserObject(Line); // ÊÍæíá ÇáÓØÑ áßÇÆä
                vUsers.push_back(User); // ÅÖÇİÉ ÇáßÇÆä ááãÕİæİÉ
            }
            MyFile.close(); // ÅÛáÇŞ Çáãáİ
        }
        return vUsers; // ÅÑÌÇÚ ŞÇÆãÉ ÇáãÓÊÎÏãíä
    }

  
    // Static: áÃäåÇ ÊÍİÙ ŞÇÆãÉ ãÓÊÎÏãíä ßÇãáÉ æáÇ ÊÑÊÈØ ÈÈíÇäÇÊ ßÇÆä æÇÍÏ İŞØ
    // Private: æÙíİÉ ÊäÙíãíÉ ÏÇÎáíÉ ááÍİÙ
    static void _SaveUsersDataToFile(vector <clsUser> vUsers)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out); // İÊÍ Çáãáİ ÈæÖÚ ÇáßÊÇÈÉ (ãÓÍ æÅÚÇÏÉ ßÊÇÈÉ)

        string DataLine;
        if (MyFile.is_open())
        {
            for (clsUser U : vUsers) // ÇáãÑæÑ Úáì ßá ãÓÊÎÏã İí ÇáŞÇÆãÉ
            {
                if (U.MarkedForDeleted() == false) // áÇ äßÊÈ ÇáãÓÊÎÏã ÇáĞí Êã æÓãå ááÍĞİ
                {
                    DataLine = _ConvertUserObjectToLine(U); // ÊÍæíá ÇáßÇÆä áÓØÑ äÕí
                    MyFile << DataLine << endl; // ßÊÇÈÉ ÇáÓØÑ İí Çáãáİ
                }
            }
            MyFile.close();
        }
    }

  
    // Non-Static: áÃäåÇ ÊÚÏá ÈíÇäÇÊ "åĞÇ" ÇáãÓÊÎÏã (this) İí Çáãáİ
    // Private: áßí áÇ íÊã ÇÓÊÏÚÇÄåÇ ÅáÇ Úä ØÑíŞ ÏÇáÉ Save() ÇáÑÓãíÉ
     void _Update()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile(); // ÊÍãíá ßá ÇáÈíÇäÇÊ ÇáÍÇáíÉ

        for (clsUser& U : _vUsers) // ÇáÈÍË Úä ÇáãÓÊÎÏã ÇáÍÇáí İí ÇáŞÇÆãÉ
        {
            if (U.UserName == UserName)
            {
                U = *this; // ÊÍÏíË ÈíÇäÇÊå İí ÇáŞÇÆãÉ ÈÇáÈíÇäÇÊ ÇáÍÇáíÉ
                break;
            }
        }
        _SaveUsersDataToFile(_vUsers); // ÍİÙ ÇáŞÇÆãÉ ÇáãÍÏËÉ İí Çáãáİ
    }

    // Non-Static: ÊÖíİ ÈíÇäÇÊ ÇáãÓÊÎÏã ÇáÍÇáí "åĞÇ" Åáì äåÇíÉ Çáãáİ
    // Private: ÌÒÁ ãä ãäØŞ ÏÇáÉ Save
    void _AddNew()
    {
        _AddDataLineToFile(_ConvertUserObjectToLine(*this)); // ÊÍæíá ÇáÍÇáí áÓØÑ æÅÖÇİÊå
    }

    // Non-Static: æÙíİÉ ÊŞäíÉ ÊİÊÍ Çáãáİ æÊÖíİ ÓØÑÇğ İí ÂÎÑå
    // Private: ÎÏãÉ ÏÇÎáíÉ ÈÓíØÉ
    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app); // æÖÚ ÇáÅáÍÇŞ (Append)

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl; // ÇáßÊÇÈÉ İí äåÇíÉ Çáãáİ
            MyFile.close();
        }
    }

    // Static: áÅäÔÇÁ ßÇÆä İÇÑÛ íãËá "áÇ íæÌÏ ãÓÊÎÏã" (Utility)
    // Private: ÊÓÊÎÏã ÏÇÎáíÇğ ÚäÏ İÔá ÇáÈÍË
    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    string _prepareLoginInRecord(string Separator = "#//#")
    {
        string LoginRecord = "";
        LoginRecord += clsDate::GetSystemDateTimeString() + Separator;
        LoginRecord += UserName + Separator;
        LoginRecord +=clsUnit::EncryptionText(Password)+ Separator;
        LoginRecord += to_string(Permissions);
        return LoginRecord;
    }
   
    static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Separator = "#//#")
    {
        stLoginRegisterRecord LoginRegisterRecord;
        vector<string> vLoginRegisterRecord = clsString::Split(Line, Separator);
        LoginRegisterRecord.DateTime = vLoginRegisterRecord[0];
        LoginRegisterRecord.UserName = vLoginRegisterRecord[1];
        LoginRegisterRecord.PassWord =clsUnit::DecryptText( vLoginRegisterRecord[2]);
        LoginRegisterRecord.Permission = stoi(vLoginRegisterRecord[3]);
        return LoginRegisterRecord;
    }
public: // ÃÚÖÇÁ ÚÇãÉ: ãÊÇÍÉ ááãÈÑãÌ ÇáĞí íÓÊÎÏã ÇáßáÇÓ
    enum enPermission
    {
        eALL=-1,pShowClientLest=1,pAddNew=2,pDelete=4,pUpdate=8,pFind=16,pTransaction=32,pManageUser=64,pLoginRegester=128
    };
    bool CheckAccessPermission(enPermission Permission)
    {
        if (this->Permissions==enPermission::eALL)
        {
            return true;
        }
        if ((Permission&this->Permissions)==Permission)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Constructor: ÚÇã áÊãßíä ÅäÔÇÁ ßÇÆäÇÊ ãÓÊÎÏãíä
    clsUser(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string UserName, string Password,
        int Permissions) :
        clsPerson(FirstName, LastName, Email, Phone) // ÇÓÊÏÚÇÁ ãÔíÏ ÇáÃÈ
    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }

    // Public: áİÍÕ ÅĞÇ ßÇä ÇáßÇÆä İÇÑÛÇğ (íÓÊÎÏã ááÊÃßÏ ÈÚÏ ÚãáíÉ ÇáÈÍË)
    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    // Public: áãÚÑİÉ ÍÇáÉ æÓã ÇáÍĞİ
    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    // Setters & Getters: ááÊÍßã İí ÇáæÕæá ááãÊÛíÑÇÊ ÇáãÍãíÉ
    string GetUserName()
    {
        return _UserName;
    }
    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }
    // Property: ÊÓåíá ÇáÊÚÇãá ãÚ UserName ßãÊÛíÑ ãÈÇÔÑ
    __declspec(property(get = GetUserName, put = SetUserName)) string UserName;

    void SetPassword(string Password)
    {
        _Password = Password;
    }
    string GetPassword()
    {
        return _Password;
    }
    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }
    int GetPermissions()
    {
        return _Permissions;
    }
    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

    // Static: ááÈÍË Úä ãÓÊÎÏã ÈÇáÇÓã (äÓÊÏÚíåÇ ÈÇÓã ÇáßáÇÓ ãÈÇÔÑÉ)
    // Public: áÊãßíä ÇáäÙÇã ãä ÇáÚËæÑ Úáì Ãí ãÓÊÎÏã İí ŞÇÚÏÉ ÇáÈíÇäÇÊ
    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in); // ŞÑÇÁÉ

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                if (User.UserName == UserName) // ÅĞÇ ÊØÇÈŞ ÇáÇÓã
                {
                    MyFile.close();
                    return User; // äÑÌÚ ÇáßÇÆä ÇáãØáæÈ
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject(); // ÅÑÌÇÚ ßÇÆä İÇÑÛ ÅĞÇ áã äÌÏ ÇáãÓÊÎÏã
    }

    // Static Find (Overloading): ááÈÍË ÈÇáÇÓã æßáãÉ ÇáãÑæÑ (ÊÓÌíá ÇáÏÎæá)
    static clsUser Find(string UserName, string Password)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

       
            if (MyFile.is_open())
            {
                string Line;
                while (getline(MyFile, Line))
                {
                    clsUser User = _ConvertLineToUserObject(Line);
                    if (User.UserName == UserName && User.Password == Password)
                    {
                        MyFile.close();
                        return User;
                    }
                }
                MyFile.close();
            }
        return _GetEmptyUserObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

    // Non-Static: áÃä ÇáÍİÙ íÚÊãÏ Úáì ÍÇáÉ "åĞÇ" ÇáßÇÆä æÈíÇäÇÊå (this)
    // Public: åí ÇáãÍÑß ÇáÃÓÇÓí áÍİÙ Ãí ÚãáíÉ ÅÖÇİÉ Ãæ ÊÚÏíá
    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }
        case enMode::UpdateMode: // ÍÇáÉ ÊÚÏíá ãÓÊÎÏã ãæÌæÏ
        {
            
                _Update();

                return enSaveResults::svSucceeded;
            
               break;
        }
        case enMode::AddNewMode: // ÍÇáÉ ÅÖÇİÉ ãÓÊÎÏã ÌÏíÏ
        {
            if (clsUser::IsUserExist(_UserName)) // ÇáÊÃßÏ ãä ÚÏã ÊßÑÇÑ ÇÓã ÇáãÓÊÎÏã
            {
                return enSaveResults::svFaildUserExists;
            }
            else
            {
                _AddNew();
                _Mode = enMode::UpdateMode; // ÊÍæíá ÇáÍÇáÉ áÊÍÏíË ÈÚÏ ÇáÅÖÇİÉ ÈäÌÇÍ
                return enSaveResults::svSucceeded;
            }
            break;
        }
        }
    }

    // Static: ááÊÍŞŞ ãä æÌæÏ ãÓÊÎÏã Ïæä ÇáÍÇÌÉ áÅäÔÇÁ ßÇÆä (ÎÏãÉ ÚÇãÉ)
    static bool IsUserExist(string UserName)
    {
        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    // Non-Static: áÃäåÇ ÊÍĞİ "åĞÇ" ÇáãÓÊÎÏã ÇáÍÇáí ãä ÇáäÙÇã
    // Public: áÅÊÇÍÉ ÎíÇÑ ÇáÍĞİ áãÓÊÎÏãí ÇáäÙÇã
    bool Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile(); // ÊÍãíá ßá ÇáÈíÇäÇÊ

        for (clsUser& U : _vUsers) // ÇáÈÍË Úä ÇáÍÇáí
        {
            if (U.UserName == _UserName)
            {
                U._MarkedForDelete = true; // æÓãå ááÍĞİ
                break;
            }
        }
        _SaveUsersDataToFile(_vUsers); // ÅÚÇÏÉ ßÊÇÈÉ Çáãáİ ÈÏæä ÇáãÓÊÎÏã ÇáãÍĞæİ
        *this = _GetEmptyUserObject(); // ÊÍæíá ÇáßÇÆä ÇáÍÇáí İí ÇáĞÇßÑÉ áİÇÑÛ
        return true;
    }

    // Static: áÊÌåíÒ ßÇÆä ÌÏíÏ ÈæÖÚ "ÇáÅÖÇİÉ" (AddNewMode)
    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    // Static: áÌáÈ ŞÇÆãÉ ÌãíÚ ÇáãÓÊÎÏãíä áÚÑÖåÇ İí ÌÏæá ãËáÇğ
    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }
    
    
    /* ÏÇáÉ RegisterLoginIn:
  - ÈÑÇíİÊ/ÈÈáß: ÚÇÏÉ Êßæä ÈÑÇíİÊ áÃäåÇ ÊõÓÊÏÚì ÂáíÇğ ÚäÏ äÌÇÍ ÊÓÌíá ÇáÏÎæá.
  - ää ÓÊÇÊíß: áÃäåÇ ÊÎÕ "ÇáãÓÊÎÏã ÇáÍÇáí" ÇáĞí ÓÌá ÏÎæáå ÇáÂä. */
    void RegisterLoginIn()
    {
        string DataLine = _prepareLoginInRecord(); // ÊÌåíÒ ÓØÑ ÈíÇäÇÊ ÊÓÌíá ÇáÏÎæá.
        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::out | ios::app); // İÊÍ ãáİ ÓÌáÇÊ ÇáÏÎæá ááÅÖÇİÉ İí ÂÎÑå.
        if (MyFile.is_open())
        {
            MyFile << DataLine << endl; // ßÊÇÈÉ ÇáÓØÑ İí Çáãáİ.
            MyFile.close(); // ÅÛáÇŞ Çáãáİ.
        }
    }

    /* struct stLoginRegisterRecord:
       - æÙíİÊåÇ: åíßá ÈíÇäÇÊ (æÚÇÁ) áÊÎÒíä ÊİÇÕíá ÓÌá ÇáÏÎæá ÇáæÇÍÏ áíÓåá ÇáÊÚÇãá ãÚå ÏÇÎá ÇáÈÑäÇãÌ. */
    struct stLoginRegisterRecord
    {
        string DateTime;  // æŞÊ æÊÇÑíÎ ÇáÏÎæá.
        string UserName;  // ÇÓã ÇáãÓÊÎÏã.
        string PassWord;  // ßáãÉ ÇáãÑæÑ.
        int Permission;   // ÕáÇÍíÇÊ ÇáãÓÊÎÏã.
    };

    /* ÏÇáÉ GetLoginRegisterList:
       - ÈÈáß: áÊÊãßä ÔÇÔÇÊ ÚÑÖ ÇáÓÌáÇÊ (Admin Screens) ãä ãäÇÏÇÊåÇ.
       - ÓÊÇÊíß: áÃäåÇ æÙíİÉ "ÚÇãÉ" ÊÌáÈ ßá ÇáÓÌáÇÊ ãä Çáãáİ¡ æáÇ ÊÍÊÇÌ áÈíÇäÇÊ ãÓÊÎÏã ãÚíä áÊÚãá. */
    static vector <stLoginRegisterRecord> GetLoginRegisterList()
    {
        vector<stLoginRegisterRecord> vLoginRegisterRecord; // äÇŞá (Vector) áÊÎÒíä ŞÇÆãÉ ÇáÓÌáÇÊ.
        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::in); // İÊÍ Çáãáİ ÈæÖÚíÉ ÇáŞÑÇÁÉ (in).
        if (MyFile.is_open())
        {
            string Line;
            stLoginRegisterRecord LoginRegisterRecord;
            while (getline(MyFile, Line)) // ŞÑÇÁÉ Çáãáİ ÓØÑÇğ ÈÓØÑ ÍÊì ÇáäåÇíÉ.
            {
                LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line); // ÊÍæíá ÇáÓØÑ ÇáäÕí Åáì åíßá ÈíÇäÇÊ (Record).
                vLoginRegisterRecord.push_back(LoginRegisterRecord); // ÅÖÇİÉ ÇáÓÌá ááŞÇÆãÉ.
            }
            MyFile.close(); // ÅÛáÇŞ Çáãáİ ÈÚÏ ÇáÇäÊåÇÁ.
        }
        return vLoginRegisterRecord; // ÅÑÌÇÚ ÇáŞÇÆãÉ ßÇãáÉ.
    }
};









