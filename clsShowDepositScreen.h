#pragma once
#include<iostream>
#include"clsScreens.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;

class clsShowDepositScreen :protected clsScreens
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
	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\n ENTER ACCOUNT NUMBER :";
		AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;
	}

public:

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("DEPOSIT SCREEN");
		string AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n Client " << AccountNumber << " IS NOT FOUND ,ENTER ANOTHER ONE : ";
			AccountNumber = _ReadAccountNumber();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_Print(Client);

		double Amount = 0;
		cout << "\nPLEASE ENTER DEPOSIT AMOUNT : ";
		Amount = clsInputValidate::ReadDblNumber();
		if (Amount<0)
		{
			cout << "\n INVAILED AMOUNT ,PLEASE ENTER A POSITIVE NUMBER :";
			Amount = clsInputValidate::ReadDblNumber();

		}
		cout << "\n ARE YOU SURE YOU WANT PERFORM THIS TRANSACTION ?";
		char Answer = 'n';
		cin >> Answer;
		if (toupper(Answer)=='Y')
		{
			Client.Deposit(Amount);
			cout << "\nAMPUNT DEPOSIT SUCCESSFULY ";
			cout << "\nNEW BALANCE IS :" << Client.AccountBalance;
		}
		else
		{
			cout << "\nOPERATION WAS CANCELLED !!!!";
		}
	}
};

