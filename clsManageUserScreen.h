#pragma once
#include<iostream>
#include"clsScreens.h"
#include"clsInputValidate.h"
#include"clsShowUserListScreen.h"
#include"clsShowAddNewUserScreen.h"
#include"clsShowDeleteUserScreen.h"
#include"clsShowUpdateUserScreen.h"
#include"clsShowFindUserScreen.h"
using namespace std;
class clsManageUserScreen: protected clsScreens
{
private:
	enum enManageUserOption
	{
		eListUser=1,
		eAddNewUser=2,
		eDeleteUser=3,
		eUpdateUser=4,
		eFindUser =5,
		eMainMenu=6

	};

	static void _ShowUserListScreen()
	{
		clsShowUserListScreen::ShowUserListScreen();
	}
	static void _ShowAddNewUserScreen()
	{
		clsShowAddNewUserScreen::ShowAddNewUserScreen();
	}
	static void _ShowDeleteUserScreen()
	{
		clsShowDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _ShowUpdateUserScreen()
	{
		clsShowUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _ShowFindUserScreen()
	{
		clsShowFindUserScreen::ShowFindUserScreen();
	}

	static short _ReadManageUserOption()
	{
		short Option = 0;
		cout << "\nWHAT DO YOU WANT TO DO ? ";
		Option = clsInputValidate::ReadIntNumberBetween(1, 6, "INVAILED NUMBER, ENTER NUMBER BETWEN (1 => 6) :");
		return Option;
	}
	static void _GoBackToManageUserScreen()
	{
		cout << "\n\n PRESS ANY KEY TO GO BACK TO MANAGE USER SCREEN >>>...";
		system("pause>0");
		ShowManageUserScreen();
	}
	static void _PerformManageUserOption(enManageUserOption ManageUserOption)
	{
		switch (ManageUserOption)
		{

		case enManageUserOption::eListUser:
			system("cls");
			_ShowUserListScreen();
			_GoBackToManageUserScreen();
			break;

		case enManageUserOption::eAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUserScreen();
			break;
		case enManageUserOption::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUserScreen();
			break;
		case enManageUserOption::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUserScreen();
			break;
		case enManageUserOption::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUserScreen();
			break;
		case enManageUserOption::eMainMenu:
		{

		}
		}
	}
public:
	static void ShowManageUserScreen()
	{
		if (!CheckAccessRight(clsUser::enPermission::pShowClientLest))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("MANAGE USER ");
		cout << setw(37) << left << "" << "===============================================\n";
		cout << setw(37) << left << "" << "[1] List User .  \n";
		cout << setw(37) << left << "" << "[2] Add New User . \n";
		cout << setw(37) << left << "" << "[3] Delete User . \n";
		cout << setw(37) << left << "" << "[4] Update User . \n";
		cout << setw(37) << left << "" << "[5] Find User .   \n";
		cout << setw(37) << left << "" << "[6] Main Menu .  \n";
		cout << setw(37) << left << "" << "===============================================\n";
		_PerformManageUserOption(enManageUserOption(_ReadManageUserOption()));
	}
};

