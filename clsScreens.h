#pragma once
#include<iostream>
#include"clsDate.h"
#include<iomanip>
#include"clsUser.h"
#include"Global.h"
using namespace std;

class clsScreens
{
protected:
	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		
		cout << setw(37) << left << "" << "*************************************************************\n";
		cout << setw(37) << left << "" << "\t\t\t\t" << Title << endl;
		if (SubTitle != "")
		{
			cout << setw(37) << left << "" << "\t\t\t\t" << SubTitle << endl;
		}
		cout << setw(37) << left << "" << "*************************************************************\n";
	   
		cout << setw(37) << left << "" << clsDate::DateToString(clsDate());
		
		 cout << setw(37) << left << "" << "User : " << CurrentUser.UserName<<endl;
		 cout << setw(37) << left << "" << "*************************************************************\n";
	}

	static bool CheckAccessRight(clsUser::enPermission permission)
	{
		if (CurrentUser.CheckAccessPermission(permission))
		{
			return true;
		}
		else
		{
			cout << setw(37) << left << "" << "*************************************************************\n"<<endl;
			cout << setw(37) << left << "" << "\t\t ACESS DENIED ! CONTACT YOUR ADMIN . \n"<<endl;
			cout << setw(37) << left << "" << "*************************************************************\n";
			return false;
		}
	}

};

