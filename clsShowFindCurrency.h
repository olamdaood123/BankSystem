#pragma once
#include<iostream>
#include<iomanip>
#include"clsCurrency.h"
#include"clsScreens.h"
#include"clsInputValidate.h"
#include<vector>
using namespace std;


class clsShowFindCurrency:protected clsScreens
{
	static void _print(clsCurrency& Currency)
	{
		cout <<endl<< setw(37) << left << " ";
		cout << left << "| " << setw(30) << Currency.Country();
		cout << left << "| " << setw(7) << Currency.CurrencyCode();
		cout << left << "| " << setw(40) << Currency.CurrencyName();
		cout << left << "| " << setw(15) << Currency.Rate();
		cout << setw(37) << left << " " << endl;
	}
	static void _ShowResult(clsCurrency &Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << setw(37) << left << " " << "CURRENCY FOUND  : ";
			_print(Currency);
		}
		else
		{
			cout << setw(37) << left << " " << "COURRENCY WAS NOT FOUND !!!";
		}
	}

public:
	static void ShowFindCurrency()
	{
		_DrawScreenHeader("FIND CURRENCY");
		vector<clsCurrency> vCurrency = clsCurrency::GetCurrencyList();
		short Answer = 1;
		cout << setw(37) << left << "FIND PY : [1] CODE ,[2] COUNTRY ?";
		cin >> Answer;
		if (Answer==1)
		{
			string CurrencyCode = "";
			cout << setw(37) << left << " " << "PLEASE ENTER CURRENCY CODE : ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);
			_ShowResult(Currency);


		}
		else
		{
			string Country = "";
			cout << setw(37) << left << " " << "ENTER COUNTRY NAME : ";
			Country=clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResult(Currency);
		}

		

	}
};

