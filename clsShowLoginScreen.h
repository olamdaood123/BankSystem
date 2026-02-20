#pragma once
#include<iostream>
#include"clsScreens.h"
#include"clsInputValidate.h"
#include"clsUser.h"
#include "clsMainScreen.h"
#include"Global.h"

using namespace std;

class clsShowLoginScreen:protected clsScreens
{
public:
	static bool _Login()
	{
		bool LoginFeild = false;
		short counter = 0;
		do
		{
			if (LoginFeild)
			{
				counter++;
				cout << setw(37) << left << "" << "INVALID USER NAME OR PASSWORD !!!\n";
				cout << setw(37) << left << "" << "YOU HAVE " <<3- counter << " TRIALS TO LOGIN ."<<endl;
					

			}
			if (counter == 3)
			{
				cout << endl << setw(37) << left << "" << "YOU ARE LOKKED AFTER 3 FAILD TRAILS !!!!";
				return false;

			}
			cout << setw(37) << left << "" << "ENTER USER NAME : ";
			string UserName = clsInputValidate::ReadString();
			cout << setw(37) << left << "" << "ENTER PASSWORD : ";
			string PassWord = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, PassWord);
			LoginFeild = CurrentUser.IsEmpty();
			

		} while (LoginFeild);

		CurrentUser.RegisterLoginIn();
		clsMainScreen::ShowMainMenuScreen();
		return true;
	}
public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("LOGIN SCREEN ");
		return _Login();
		

	}
};

