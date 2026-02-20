#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include "clsScreens.h"
#include"clsBankClient.h"
#include"clsShowClientLestScreen.h"
#include"clsShowAddNewClientScreen.h"
#include"clsShowDeleteClientScreen.h"
#include"clsShowUpdateClientScreen.h"
#include"clsShowFindClientScreen.h"
#include"clsTransactionMenu.h"
#include"clsManageUserScreen.h"
#include"clsShowLoginRegisterScreen.h"
#include"Global.h"
#include"clsShowCurrencyExchangeScreen.h"

using namespace std;
class clsMainScreen :protected clsScreens
{
private:
	static short _ReadMainMenuOption()
	{
		short choose = 0;
		cout <<  left <<setw(37) << ""<<"WHAT DO YOU WANT TO DO (1 => 10) :";
		
		choose = clsInputValidate::ReadIntNumberBetween(1, 10, "ENTER NUMBER BETWEN 1 => 10 :");
		return choose;

	}
	enum enMainMenueOption
	{
		eSHOWALLCLIEN=1,
		eADDNEWCLIENT=2,
		eDELETECLIENT=3,
		eUPDATECLIENT=4,
		eFINDCLIENT=5,
		eTRANCACTION=6,
		eMANAGEUSER=7,
		ewLoginRegister=8,
		eCURRENCYEXCHANGE=9,
		eLOGINOUT=10
	};
	static void ShowClientLestScreen()
	{
		clsShowClientLestScreen::ShowClientLest();
	}
	static void ShowAddNewClientScreen()
	{
		clsShowAddNewClientScreen::AddNewClient();
	}
	static void ShowUpdateClientScreen()
	{
		clsShowUpdateClientScreen::ShowUpdateClientScreen();
	}
	static void ShowDeleteClientScreen()
	{
		clsShowDeleteClientScreen::ShowDeleteClientScreen();
	}
    static void ShowFindClientScreen()
	{
		clsShowFindClientScreen::ShowFindClientScreen();
	}
	static void ShowTransactionScreen()
	{
		clsTransactionMenu::ShowTransactionMenu();
	}
	static void ShowManageUserScreen()
	{
		clsManageUserScreen::ShowManageUserScreen();
	}
	static void ShowLoginRegisterScreen()
	{
		clsShowLoginRegisterScreen::ShowLoginRegisterScreen();
	}
	static void ShowCurrencyExchangeScreen()
	{
		clsShowCurrencyExchangeScreen::ShowCurrencyExchangeMenu();
	}


	static void _LoginOut()
	{
		CurrentUser = clsUser::Find("", "");
	}
	
	static void GoBackToMainMenuScreen()
	{
		cout << "\n\nPRESS ANY KEY TO GO BACK TO MAIN MENUE SCREEN >>>...";
		system("pause>0");
		ShowMainMenuScreen();
	}
	static void _PerformMainMenuOption(enMainMenueOption MainMenuOption)
	{
		switch (MainMenuOption)
		{
		case enMainMenueOption::eSHOWALLCLIEN:
			system("cls");
			ShowClientLestScreen();
			GoBackToMainMenuScreen();
			break;
		case enMainMenueOption::eADDNEWCLIENT:
			system("cls");
			ShowAddNewClientScreen();
			GoBackToMainMenuScreen();
			break;
		case enMainMenueOption::eDELETECLIENT:
			system("cls");
			ShowDeleteClientScreen();
			GoBackToMainMenuScreen();
			break;
		case enMainMenueOption::eUPDATECLIENT:
			system("cls");
			ShowUpdateClientScreen();
			GoBackToMainMenuScreen();
			break;
		case enMainMenueOption::eFINDCLIENT:
			system("cls");
			ShowFindClientScreen();
			GoBackToMainMenuScreen();
			break;
		case enMainMenueOption::eTRANCACTION:
			system("cls");
			ShowTransactionScreen();
			GoBackToMainMenuScreen();
			break;
		case enMainMenueOption::eMANAGEUSER:
			system("cls");
			ShowManageUserScreen();
			GoBackToMainMenuScreen();
			break;
		case enMainMenueOption::ewLoginRegister:
			system("cls");
			ShowLoginRegisterScreen();
			GoBackToMainMenuScreen();
			break;
		case enMainMenueOption::eCURRENCYEXCHANGE:
			system("cls");
			ShowCurrencyExchangeScreen();
			GoBackToMainMenuScreen();
			break;
		case enMainMenueOption::eLOGINOUT:
			system("cls");
			_LoginOut();
			break;
		}
	}

public:
	static void ShowMainMenuScreen()
	{
		system("cls");
		clsScreens::_DrawScreenHeader("MAIN MENU");
		cout << setw(37) << left << "" << " ======================================================= \n";
		cout << setw(37) << left << "" << "  [1] SHOW ALL CLIENT   . \n";
		cout << setw(37) << left << "" << "  [2] ADD NEW CLIENT    . \n";
		cout << setw(37) << left << "" << "  [3] DELETE CLIENT     . \n";
		cout << setw(37) << left << "" << "  [4] UPDATE CLIENT     . \n";
		cout << setw(37) << left << "" << "  [5] FIND CLIENT       . \n";
		cout << setw(37) << left << "" << "  [6] TRANCACTION       . \n";
		cout << setw(37) << left << "" << "  [7] MANAGE USER       . \n";
		cout << setw(37) << left << "" << "  [8] LOGIN REGESTER    . \n";
		cout << setw(37) << left << "" << "  [9] CURRENCY EXCHANGE . \n";
		cout << setw(37) << left << "" << "  [10] LOGIN OUT        . \n";
		cout << setw(37) << left << "" << " ======================================================= \n";
		_PerformMainMenuOption(enMainMenueOption(_ReadMainMenuOption()));
	}
};

