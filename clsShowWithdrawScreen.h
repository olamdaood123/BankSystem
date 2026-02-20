#pragma once
#include<iostream>
#include"clsScreens.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;
class clsShowWithdrawScreen:protected clsScreens
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
	static void ShowWithDrawScreen()
	{
		_DrawScreenHeader("WITHDRAW SCREEN");
		string AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n Client " << AccountNumber << " IS NOT FOUND ,ENTER ANOTHER ONE : ";
			AccountNumber = _ReadAccountNumber();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_Print(Client);

		double Amount = 0;
		cout << "\nPLEASE ENTER WITHDRAW AMOUNT : ";
		Amount = clsInputValidate::ReadDblNumber();
		if (Amount>Client.AccountBalance)
		{
			cout << "\nCANN'T WITHDRAW ,INSUFFECIENT BALANCE !";
			cout << "\nAMOUNT TO WITHDRAW IS : " << Amount;
			cout << "\nYOUR BALANCE IS : " << Client.AccountBalance;
			cout << "\nPLEASE ENTER WITHDRAW AMOUNT : ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		
		cout << "\n ARE YOU SURE YOU WANT PERFORM THIS TRANSACTION ?";
		char Answer = 'n';
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Client.WithDraw(Amount);
			
				cout << "\nAMPUNT WITHDRAW SUCCESSFULY ";
				cout << "\nNEW BALANCE IS :" << Client.AccountBalance;
			
			
		}
		else
		{
			cout << "\nOPERATION WAS CANCELLED !!!!";
		}
	}
};

