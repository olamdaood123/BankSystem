#pragma once
#include<iostream>
#include"clsScreens.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
class clsShowFindClientScreen:protected clsScreens
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
	static void ShowFindClientScreen()
	{
		if (!CheckAccessRight(clsUser::enPermission::pFind))
		{
			return;
		}
		_DrawScreenHeader("FIND CLIENT");
		string AccountNumber = "";
		cout << "\nENTER ACCOUNT NUMBER : ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nACCOUNT NOMBER IS NOT FOUND. ENTER ANOTHER ONE : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		if (!Client.IsEmpty())
		{
			cout << "\nCLIENT FOUND .";
		}
		else
		{
			cout << "\nCLIENT NOT FOUND .";
		}
		_Print(Client);
	}
};

