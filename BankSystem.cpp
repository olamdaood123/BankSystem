
#include<iostream>
#include"clsCurrency.h"
#include"clsShowLoginScreen.h"




using namespace std;

void _print(clsCurrency& Currency)
{
	cout << "Country        :" << Currency.Country() << endl;
	cout << "CurrencyCode   :" << Currency.CurrencyCode() << endl;
	cout << "CurrencyName   :"<<Currency.CurrencyName() << endl;
	cout << "Rate (1$)      :" << Currency.Rate();
}
int main()
{
	while (true)
	{
		if (!clsShowLoginScreen::ShowLoginScreen())
		{
			break;
		}
	    
    }
	

	
	system("pause>0");
	return 0;
}