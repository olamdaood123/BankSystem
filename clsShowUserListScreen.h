#pragma once
#include<iostream>
#include<iomanip>
#include"clsUser.h"
#include "clsScreens.h"
using namespace std;
class clsShowUserListScreen:protected clsScreens
{
private:
	static void _PrintUserRecordLine(clsUser& User)
	{
		cout << setw(8) << left << "" << "| " << setw(12) << left << User.UserName;
		cout << "| " << setw(25) << left << User.FullName();
		cout << "| " << setw(12) << left << User.Phone;
		cout << "| " << setw(20) << left << User.Email;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(12) << left << User.Permissions;
	}
public:
	static void ShowUserListScreen()
	{
		vector<clsUser>vUser = clsUser::GetUsersList();
		string Title = "USER LIST ";
		string SubTitle = "( " + to_string(vUser.size()) + " ) USER(S)";
		_DrawScreenHeader(Title, SubTitle);
		
		cout << setw(8) << left << "" << setw(12) << left << "\n\t========================================================";
		cout<<"====================================================== = \n";
		cout << setw(8) << left << "" << "| " << setw(12) << left << "UserName";
		cout << "| " << setw(25) << left << "FullName";
		cout << "| " << setw(12) << left << "Phone";
		cout << "| " << setw(20) << left << "Email";
		cout << "| " << setw(10) << left << "Password";
		cout << "| " << setw(12) << left << "Permissions";
		cout << setw(8) << left << "" << setw(12) << left << "\n\t=========================================================";
		cout<<"======================================================\n";
		if (vUser.size()==0)
		{
			cout << "\n\t\tNO USER AVAILABLE IN THES SYSTRM !!!!";
		}
		else
		{
			for (clsUser& U : vUser)
			{
				_PrintUserRecordLine(U);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << setw(12) << left << "\n\t===========================================================";
		cout<<"====================================================\n";
	}
};

