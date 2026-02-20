#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsScreens.h"
using namespace std;
class clsShowAddNewClientScreen:protected clsScreens
{
private:
	static void ReadClientInfo(clsBankClient& Client)
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
	static void AddNewClient()
	{
		if (!CheckAccessRight(clsUser::enPermission::pAddNew))
		{
			return;
		}
		clsScreens::_DrawScreenHeader("ADD NEW CLIENT");
		cout << "\nENTER ACCOUNT NUMBER ";
		string AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n ACCOUNT NUMBER ALREADY USING, ENTER ANUTHOR ONE ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::GetAddNewClientObject(AccountNumber);
		ReadClientInfo(Client);
		clsBankClient::enSaveResults SaveResult = Client.Save();
		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceeded:
			cout << "\nClient saved successfully";
			_Print(Client);
			break;
		case clsBankClient::enSaveResults::svFaildEmptyObject:
			cout << "\n Client Don't saved because it is empty object ";
			break;
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
			cout << "\n Client Don't saved because AccountNumber already used  ";
			break;
		}
	}
};

