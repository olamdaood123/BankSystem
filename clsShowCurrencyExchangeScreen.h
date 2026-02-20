#pragma once
#include<iostream>
#include"clsScreens.h"
#include"clsInputValidate.h"
#include"clsShowCurrencyExchangeScreen.h"
#include"clsShowListCurrency.h"
#include"clsShowFindCurrency.h"
#include"clsShowUpdateCurrencyRate.h"
#include"clsCurrencyCalculate.h"
class clsShowCurrencyExchangeScreen:protected clsScreens
{

	enum enCurrencyOption
	{
		eLISTCURRENCIES=1,
		eFINDCURRENCY=2,
		eUPDATERATE=3,
		eCURRANCYCALCU=4,
		eMAINMENU=5

	};


	static void _LISTCURRENCIES()
	{
		clsShowListCurrency::ShoeCurrencyLest();
	}
	static void _FINDCURRENCY()
	{
		clsShowFindCurrency::ShowFindCurrency();
	}
	static void _UPDATERATE()
	{
		clsShowUpdateCurrencyRate::ShowUpdateCurrencyRate();
	}
	static void _CURRANCYCALCULATOR()
	{
		clsCurrencyCalculate::ShowCurrencyCalculate();
	}
	
	 
	static void _GoBackToCurrencyMenu()
	{
		cout <<endl<< setw(37) << left << "" << "PRESS ANY KEY TO CO BACK YO CURRENCY MENU >>>>...";
		system("pause>0");
		ShowCurrencyExchangeMenu();
	}
	static short ReadCurrencyOption()
	{
		cout << setw(37) << left << "" << "WHAT DO YOU WANT TO DO ? ";
		short Option = clsInputValidate::ReadIntNumberBetween(1, 5, "CHOOSE NUM BETWEN ( 1 ==> 5 )");
		return Option;
	}
	static void _PerformCurrencyOption(enCurrencyOption CurrencyOption)
	{
		switch (CurrencyOption)
		{
		case enCurrencyOption::eLISTCURRENCIES:
			system("cls");
			_LISTCURRENCIES();
			_GoBackToCurrencyMenu();
			break;

		case enCurrencyOption::eFINDCURRENCY:
			system("cls");
			_FINDCURRENCY();
			_GoBackToCurrencyMenu();
			break;

		case enCurrencyOption::eUPDATERATE:
			system("cls");
			_UPDATERATE();
			_GoBackToCurrencyMenu();
			break;

		case enCurrencyOption::eCURRANCYCALCU:
			system("cls");
			_CURRANCYCALCULATOR();
			_GoBackToCurrencyMenu();
			break;

		case enCurrencyOption::eMAINMENU:
		{

		}
		}
	}

public:
	static void ShowCurrencyExchangeMenu()
	{
		system("cls");
		_DrawScreenHeader("CURRENCY EXCHANGE");
		cout << setw(37) << left << "" << "===========================================================\n";
		cout << setw(37) << left << "" << "[1] LIST CURRENCIES     .\n";
		cout << setw(37) << left << "" << "[2] FIND CURRENCY       .\n";
		cout << setw(37) << left << "" << "[3] UPDATE RATE         .\n";
		cout << setw(37) << left << "" << "[4] CURRANCY CALCULATOR .\n";
		cout << setw(37) << left << "" << "[5] MAIN MENU           .\n";
		cout << setw(37) << left << "" << "===========================================================\n";
		_PerformCurrencyOption(enCurrencyOption(ReadCurrencyOption()));
	}
};

