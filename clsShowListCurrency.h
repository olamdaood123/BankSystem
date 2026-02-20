#pragma once
#include<iostream>
#include"clsScreens.h"
#include<iomanip>
#include<vector>
#include"clsCurrency.h"
using namespace std;
class clsShowListCurrency:protected clsScreens
{
	static
		void _print(clsCurrency& Currency)
	{
		cout << setw(37) << left << " ";
		cout << left << "| " << setw(30) << Currency.Country();
		cout << left << "| " << setw(7) << Currency.CurrencyCode();
		cout << left << "| " << setw(40) << Currency.CurrencyName();
		cout << left << "| " << setw(15) << Currency.Rate();
	}

public:
	static void ShoeCurrencyLest()
	{
		vector<clsCurrency> vCurrency=clsCurrency::GetCurrencyList();
		string Title = "CURRENCY LIST ";
		string SubTitle = "( " + to_string(vCurrency.size()) + " ) CURRENCY(S) ";
		_DrawScreenHeader(Title, SubTitle);
		cout << endl << setw(37) << left << " "<<"=============================================================================================\n";
		cout << endl << setw(37) << left << " ";
		cout << left << "| " << setw(30) << "COUNTRY";
		cout << left << "| " << setw(7) << "C_CODE";
		cout << left << "| " << setw(40) << "C_NAME";
		cout << left << "| " << setw(15) << "C_RATE";
		cout << endl << setw(37) << left << " " << "=============================================================================================\n";
		for (clsCurrency& C : vCurrency)
		{
			_print(C);
			cout << endl;
		}
		cout << endl << setw(37) << left << " " << "=============================================================================================\n";
	}



};

