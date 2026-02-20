#pragma once
#include<iostream>
#include"clsScreens.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
using namespace std;

class clsShowUpdateCurrencyRate:protected clsScreens
{
	static float _ReadRate()
	{
		cout << setw(37) << left << "" << "ENTER NEW RATE : ";
		float Rate = clsInputValidate::ReadFloatNumber();
		return Rate;
	}
	static void _printCurrency(clsCurrency& Currency)
	{
		cout << endl << setw(37) << left << "CURRENCY CARD : ";
		cout << endl << setw(37) << left << "==================================================";
		cout<<endl << setw(37) << left << "COUNTRY   : " << Currency.Country();
		cout <<endl<< setw(37) << left << "CODE      : " << Currency.CurrencyCode();
		cout<<endl << setw(37) << left << "NAME      : " << Currency.CurrencyName();
		cout<<endl << setw(37) << left << "RATE      : " << Currency.Rate();
	}


public:
	static void ShowUpdateCurrencyRate()
	{
		_DrawScreenHeader("UPDATE RATE");
		cout<<endl << setw(37) << left << "" << "PLEASE ENTER CURRENCY CODE : ";
		string CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << endl << setw(37) << left << "CURRENCY IS NOT FOUND ,CHOOSE ANOTHER ONE ";
			CurrencyCode = clsInputValidate::ReadString();
		}
		clsCurrency Currency = Currency.FindByCurrencyCode(CurrencyCode);
		_printCurrency(Currency);
		cout << endl << setw(37) << left << "ARE YOU SURE YOU WANT TO UPDATE THE RATE OF THIS CURRENCY ? ";
		char Answer = 'n';
		cin >> Answer;
		if (toupper(Answer)=='Y')
		{
			cout << endl << setw(37) << left << "UPDATE CURRENCY RATE : ";
			cout << endl << setw(37) << left << "===========================================" << endl;
			Currency.UpdateRate(_ReadRate());
			cout << endl << setw(37) << left << "CURRENCY UPDATE SUCCESSFULLY ";
			_printCurrency(Currency);
		}
		else
		{
			cout << endl << setw(37) << left << "UPDATE RATE CANCELED !!!!!";

		}

	}
};

