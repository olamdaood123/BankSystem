#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreens.h"
#include "clsInputValidate.h"
#include"clsShowDepositScreen.h"
#include"clsShowWithdrawScreen.h"
#include"clsShowTotalBalanceScreen.h"
#include"clsShowTransferScreen.h"
#include"clsShowTransferLogScreen.h"
using namespace std;

class clsTransactionMenu:protected clsScreens
{
private:
	enum enTransactionMenuOption
	{
		eDEPOSIT = 1,
		eWITHDRAW = 2,
		eTOTALBALANCE = 3,
		eTRANSFER=4,
		eTransferLog=5,
		eCOBACKTOMAINMENU = 6
	};
	static short _ReadTransactionOption()
	{
		short Option = 0;
		cout << "\n WHAT DO YOU WANT TO DO ?";
		Option = clsInputValidate::ReadIntNumberBetween(1, 6, "\nENTER NUMBER BETWEEN(1 => 6) :");
		return Option;
	}
	
	static void _ShowDepositScreen()
	{
		clsShowDepositScreen::ShowDepositScreen();
	}
	static void _ShowWithdrawScreen()
		{
		clsShowWithdrawScreen::ShowWithDrawScreen();
		}
	static void _ShowTotalBalanceScreen()
	{
		clsShowTotalBalanceScreen::ShowTotalBalance();
	}
	static void _ShowTransferScreen()
	{
		clsShowTransferScreen::ShowTransferScreen();
	}
	static void _ShowTransferLogScreen()
	{
		clsShowTransferLogScreen::ShowTransferLogScreen();
	}
	static void GoBackToTransactionMenu()
	{
		cout << "\n\nPRESS ANY KEY TO GO BACK YO TRANSACTION MENUE >>>...";
		system("pause>0");
		ShowTransactionMenu();
	}
	static void _PerformTransactionOption(enTransactionMenuOption TransactionOption)
	{
		switch (TransactionOption)
		{
		case enTransactionMenuOption::eDEPOSIT:
				system("cls");
				_ShowDepositScreen();
				GoBackToTransactionMenu();
				break;
		case enTransactionMenuOption::eWITHDRAW:
			system("cls");
			_ShowWithdrawScreen();
			GoBackToTransactionMenu();
			break;
		case enTransactionMenuOption::eTOTALBALANCE:
			system("cls");
			_ShowTotalBalanceScreen();
			GoBackToTransactionMenu();
			break;
		case enTransactionMenuOption::eTRANSFER:
			system("cls");
			_ShowTransferScreen();
			GoBackToTransactionMenu();
			break;
		case enTransactionMenuOption::eTransferLog:
			system("cls");
			_ShowTransferLogScreen();
			GoBackToTransactionMenu();
			break;
		case enTransactionMenuOption::eCOBACKTOMAINMENU:
		{

		}
			
		}
	}
public:
	static void ShowTransactionMenu()
	{
		if (!CheckAccessRight(clsUser::enPermission::pShowClientLest))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("TRANSACTION MENUE");
		cout << setw(37) << left << "" << "==============================================\n";
		cout << setw(37) << left << "" << "[1] DEPOSET              .\n";
		cout << setw(37) << left << "" << "[2] WITHDRAW             .\n";
		cout << setw(37) << left << "" << "[3] TOTALBALANCE         .\n";
		cout << setw(37) << left << "" << "[4] TRANSFER             .\n";
		cout << setw(37) << left << "" << "[5] TRANSFER LOG         .\n";
		cout << setw(37) << left << "" << "[6] CO BACK TO MAIN MENU .\n";
		cout << setw(37) << left << "" << "==============================================\n";
		_PerformTransactionOption(enTransactionMenuOption(_ReadTransactionOption()));
	}
};

