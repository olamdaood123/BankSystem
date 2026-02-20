#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsScreens.h"
#include"clsBankClient.h"
using namespace std;

class clsShowUpdateClientScreen :protected clsScreens
{
private :
	static 	void _Print(clsBankClient& C) // ØÈÇÚ
	{
		cout << "\nClient Card:";
		cout << "\n_____________________________________";
		cout << "\nFirstName   : " << C.FirstName;
		cout << "\nLastName    : " << C.LastName;
		cout << "\nFull Name   : " << C.FullName();
		cout << "\nEmail       : " << C.Email;
		cout << "\nPhone       : " << C.Phone;
		cout << "\nAcc. Number : " << C.AccountNumber();
		cout << "\nPassword    : " << C.PinCode;
		cout << "\nBalance     : " << C.AccountBalance;
		cout << "\n____________________________________\n";
	}
	
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "ENTER FIRST NAME : ";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "ENTER LAST NAME : ";
		Client.LastName = clsInputValidate::ReadString();
		cout << "ENTER EMAIL : ";
		Client.Email = clsInputValidate::ReadString();
		cout << "ENTER PHONE  : ";
		Client.Phone = clsInputValidate::ReadString();
		cout << "ENTER PIN CODE : ";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "ENTER ACCOUNT BALANCE : ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();
	}
	
public:
	static void ShowUpdateClientScreen()

		{
		if (!CheckAccessRight(clsUser::enPermission::pUpdate))
		{
			return;
		}
		     _DrawScreenHeader("UPDATE CLIENT");
			cout << "\nENTER ACCOUNT NUMBER ";
			string AccountNumber = clsInputValidate::ReadString();
			while (!clsBankClient::IsClientExist(AccountNumber))
			{
				cout << "\n INVAILED ACCOUNT NUMBER ENTER ANUTHOR ONE ";
				AccountNumber = clsInputValidate::ReadString();
			}
			clsBankClient Client = clsBankClient::Find(AccountNumber);
			Client.Print();
			char Answer = 'n';
			cout << "\n DO YOU WANT TO UPDATE THIS CLIENT ";
			cin >> Answer;
			if (toupper(Answer) == 'Y')
			{
				_ReadClientInfo(Client);
				clsBankClient::enSaveResults SaveResult = Client.Save();
				switch (SaveResult)
				{
				case clsBankClient::enSaveResults::svSucceeded:
					cout << "\nClient update successfully";
					_Print(Client);
					break;
				case clsBankClient::enSaveResults::svFaildEmptyObject:
					cout << "\n Client Don't Updated because it is empty object ";
					break;


				}

			}
			else
			{
				cout << "\nUPDATED CANCELED !!!!!!!!!!!!!";
			}
	}
};

