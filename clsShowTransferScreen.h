#pragma once
#include<iostream>
#include"clsScreens.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
class clsShowTransferScreen:protected clsScreens
{
	static void _PrintClient(clsBankClient& Client)
	{
		cout <<endl<< setw(37) << left << "" << "CLIENT CARD: \n";
		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "FULL NAME      : " << Client.FullName() << endl;
		cout << setw(37) << left << "" << "ACCOUNT NUMBER : " << Client.AccountNumber() << endl;
		cout << setw(37) << left << "" << "BALANCE        : " << Client.AccountBalance<<endl;
		cout << setw(37) << left << "" << "============================================\n";
	}
	static string _ReadAccountNumber(string Message="")
	{
		string AccountNumber;

		cout << endl << setw(37) << left << "" << Message;
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << endl << setw(37) << left << "" << "ACCOUNT NUMBER IS NOT FOUND ,CHOOSE ANOTHER ONE :";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}
	static float _ReadAmount(clsBankClient SoursClient)
	{
		float Amount = 0;
		cout << setw(37) << left << "" << "ENTER AMOUNT :";
		Amount = clsInputValidate::ReadFloatNumber();
		while (Amount > SoursClient.AccountBalance)
		{
			cout << endl << setw(37) << left << "" << "AMOUNT EXCEEDS THE AVAILABLE BALANCE ,ENTER ANOTHER ONE : ";
			Amount = clsInputValidate::ReadFloatNumber();
		}
		return Amount;

	}
public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("TRANSFER SCREEN");
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("ENTER ACCOUNT NUMBER TO TRANSER FROM : "));
		_PrintClient(SourceClient);
		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("ENTER ACCOUNT NUMBER TO TRANSER To : "));
		_PrintClient(DestinationClient);
		float Amount = _ReadAmount(SourceClient);
		cout << endl << setw(37) << left << "" << "ARE YOU SURE YOU WANT TO PERFORM THIS OPERATION ? ";
		char Answer = 'n';
		cin >> Answer;
		if (toupper(Answer)=='Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
			{
				cout << endl << setw(37) << left << "" << "TRANSFER DONE SUCCESSFULLY ";
			}
			else
			{
				cout << endl << setw(37) << left << "" << "TRANSFER FAILD !!!!";
			}
		}
		else
		{
			cout << endl << setw(37) << left << "" << "TRANCFER CANCELED !!!!";
		}
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
	}
};

