#pragma once
#include<iostream>
#include"clsScreens.h"
class clsShowClientLestScreen :protected clsScreens
{
private:
	static void _PrintClientRecordLine(clsBankClient& C)
	{
		cout << left << "| " << setw(15) << C.AccountNumber();
		cout << left << "| " << setw(20) << C.FullName();
		cout << left << "| " << setw(20) << C.Email;
		cout << left << "| " << setw(12) << C.Phone;
		cout << left << "| " << setw(12) << C.PinCode;
		cout << left << "| " << setw(12) << C.AccountBalance;

	}

public:
	static void ShowClientLest()
	{
		if (!CheckAccessRight(clsUser::enPermission::pShowClientLest))
		{
			return;
		}
		vector<clsBankClient> vClient = clsBankClient::GetClientsList();
		string Title = "LIST CLIENT";
		string SubTitle = "( " + to_string(vClient.size()) + " )CLIENT(S)";
		_DrawScreenHeader(Title, SubTitle);
		cout << left << setw(8) << "\n==========================================================================================================\n";
		cout << "| " << left << setw(15) << "ACCOUNT NUMBER";
		cout << "| " << left << setw(20) << "CLIENT NAME ";
		cout << "| " << left << setw(20) << "EMAIL ";
		cout << "| " << left << setw(12) << "PHONE ";
		cout << "| " << left << setw(12) << "PIN CODE ";
		cout << "| " << left << setw(12) << "BALANCE ";
		cout << left << setw(8) << "\n============================================================================================================\n";
		if (vClient.size() == 0)
		{
			cout << "\n\t NO CLIENT ADVAILABLE IN THE SYSTEM";
		}
		else
		{
			for (clsBankClient& C : vClient)
			{
				_PrintClientRecordLine(C);
				cout << endl;
			}
		}
	}
};

