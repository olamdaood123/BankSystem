#pragma once
#include<iostream>
#include"clsScreens.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include "clsUnit.h"
using namespace std;

class clsShowTotalBalanceScreen :protected clsScreens
{
private:
	static void PrintTotalBalance(clsBankClient& C)
{
	cout << "| " << left << setw(15) << C.AccountNumber();
	cout << "| " << left << setw(20) << C.FullName();
	cout << "| " << left << setw(20)  << C.AccountBalance;
}

public:

	static void ShowTotalBalance()
	{
		
		
		
		       vector<clsBankClient> vClient = clsBankClient::GetClientsList();
			   string Title = "BALANCE LEST ";
			   string SubTite = " ( " + to_string(vClient.size()) + " )Client(s) ";
			   _DrawScreenHeader(Title, SubTite);

				cout << left << setw(8) << "\n================================================\n";
				cout << "| " << left << setw(15) << " AccountNumber";
				cout << "| " << left << setw(20) << " Name ";
				cout << "| " << left << setw(20) << "Balance ";
				cout <<left<< setw(8) << "\n================================================\n";

				double TotalBalance = clsBankClient::GetTotalBalances();
				if (vClient.size()==0)
		{
			cout << "\nNO CLIENT ADVILABLE IN THE SYSTEM ";
		}
		else
		{
			for (clsBankClient& C : vClient)
			{
				PrintTotalBalance(C);
				cout << endl;
			}
		}
		cout << left << setw(8) << "\n================================================\n";
		cout << "\n\t\tTotalBalance = " << TotalBalance;
		cout << "\n\t\t( " << clsUnit::NumberToText(TotalBalance) << " )";
	}
};

