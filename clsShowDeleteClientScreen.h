#pragma once
#include <iostream>
#include"clsScreens.h";
#include"clsBankClient.h"
using namespace std;
class clsShowDeleteClientScreen:protected clsScreens
{
private:
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
public:
	static void ShowDeleteClientScreen()
	{
		if (!CheckAccessRight(clsUser::enPermission::pDelete))
		{
			return;
		}
		_DrawScreenHeader("DELET CLIENT ");

		cout << "\nENTER ACCOUNT NUMBER ";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n ACCOUNT NUMBER IS Not USING, ENTER ANUTHOR ONE ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		char Answer = 'n';
		_Print(Client);
		cout << "\n ARE YOU SURE YOU WANT TO DELET THIS CLIENT ? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			if (Client.Delete())
			{
				cout << "\nCLIENT DELETED SUCCESSFULLY ";
				Client.Print();
			}
			else
			{
				cout << "\nCLIENT WAS NOT DELETED !!!";
			}
		}
		else
		{
			cout << "\n DELETE CLIENT CANCELED !!!";
		}
	}
};

