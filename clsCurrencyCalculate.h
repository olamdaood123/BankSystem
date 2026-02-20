#pragma once
#include<iostream>
#include"clsScreens.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
using namespace std;

class clsCurrencyCalculate:protected clsScreens
{
	static float _ReadAmount()
	{
		cout << endl << setw(37) << left << "" << "ENTER AMOUNT TO EXCHANGE : ";
		float Amount = 0;
		Amount = clsInputValidate::ReadFloatNumber();
		return Amount;
	}
	static clsCurrency _GetCurrency(string Message)
	{
		string CurrencyCode = "";
		cout<<endl << setw(37) << left << "" << Message;
		CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout<<endl << setw(37) << left << "" << "INVAILED CURRENCY CODE ,ENTER ANUTHER ONE : ";
			CurrencyCode = clsInputValidate::ReadString();
		}
		clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);
		return Currency;
	}
	static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency USD")
	{
		cout << endl << setw(37) << left << "" << Title << endl;
		cout << endl << setw(37) << left << "" << "==================================================";
		cout << endl << setw(37) << left << "" << "COUNTRY        : " << Currency.Country();
		cout << endl << setw(37) << left << "" << "CURRENCY CODE  : " << Currency.CurrencyCode();
		cout << endl << setw(37) << left << "" << "NAME           : " << Currency.CurrencyName();
		cout << endl << setw(37) << left << "" << "REAT(1$)       : " << Currency.Rate();
		cout << endl << setw(37) << left << "" << "===================================================";
	}

	static void _PrintCalculationResults(float Amount, clsCurrency Currency1,clsCurrency Currency2)
	{
		_PrintCurrencyCard(Currency1,"CONVERT FROM : ");
		float AmountInUSD = Currency1.ConvertToUSD(Amount);
		cout<<endl << setw(37) << left << "" << Amount << "  " << Currency1.CurrencyCode() << " = " << AmountInUSD << " USD";
		if (Currency2.CurrencyCode()=="USD")
		{
			return;
		}
		
		cout << endl << setw(37) << left << "" << "CONVERTING FROM USD TO : ";
		_PrintCurrencyCard(Currency2, " TO : ");
		float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);
		cout << endl << setw(37) << left << "" << Currency1.CurrencyCode() << " = " << AmountInCurrency2 << " " << Currency2.CurrencyCode();
		
	}

public:
	static void ShowCurrencyCalculate()
	{
		char Continue = 'y';
		
		while (toupper(Continue) == 'Y')
		{
			system("cls");
			_DrawScreenHeader("CURRENCY CALCULATE");
			clsCurrency CurrencyFrom = _GetCurrency("PLEASE ENTER CURRENCY1 CODE : ");
			clsCurrency CurrencyTo = _GetCurrency("PLEASE ENTER CURRENCY TO : ");
			float Amount = _ReadAmount();
			_PrintCalculationResults(Amount, CurrencyFrom, CurrencyTo);
			cout<<endl << setw(37) << left << "" << "DO YOU WANT TO PERFORM ANOTHER CALCULATE ? ";
			cin >> Continue;
		}
		
	}
};

