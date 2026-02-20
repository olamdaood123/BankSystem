#pragma once
#include<iostream>
#include<iomanip>
#include"clsUser.h"
#include<fstream>
#include<string>
#include"clsScreens.h"
#include"clsString.h"
#include"Global.h"
using namespace std;
class clsShowLoginRegisterScreen:protected clsScreens
{
	
	static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord& LoginRegisterRecord)
	{
		cout << "| " << setw(37) << left << LoginRegisterRecord.DateTime;
		cout << "| " << setw(15) << left << LoginRegisterRecord.UserName;
		cout << "| " << setw(15) << left << LoginRegisterRecord.PassWord;
		cout << "| " << setw(15) << left << LoginRegisterRecord.Permission;
	}

public:
	static void ShowLoginRegisterScreen()
	{
		if (!CheckAccessRight(clsUser::enPermission::pShowClientLest))
		{
			return;
		}
		vector<clsUser::stLoginRegisterRecord>vLoginRegisterRecord =clsUser::GetLoginRegisterList() ;
		_DrawScreenHeader("LOGIN REGISTER",to_string(vLoginRegisterRecord.size())+"Record(s)");
		cout << setw(37) << left  << "\n=====================================================================================\n";
		cout << "| " << setw(37) << left << "Date/Time";
		cout << "| " << setw(15) << left << "UserName";
		cout << "| " << setw(15) << left << "PassWord";
		cout << "| " << setw(15) << left << "Permission";
		cout << setw(37) << left << "\n======================================================================================\n";
		
		if (vLoginRegisterRecord.size()==0)
		{
			cout << setw(37) << left << "" << "";
		}
		else
		{
			for (clsUser::stLoginRegisterRecord& Record : vLoginRegisterRecord)
			{
				_PrintLoginRegisterRecordLine(Record);
				cout << endl;
			}
		}
		cout << setw(37) << left << "\n======================================================================================\n";
	}
};

