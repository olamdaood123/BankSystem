#pragma once
#include<iostream>
#include"clsScreens.h"
#include"clsUser.h"
class clsShowFindUserScreen:protected clsScreens
{
private:
	static void _Print(clsUser& U) // ØÈÇÚ
	{
		cout << "\nUser Card:";
		cout << "\n_____________________________________";
		cout << "\nFirstName   : " << U.FirstName;
		cout << "\nLastName    : " << U.LastName;
		cout << "\nFull Name   : " << U.FullName();
		cout << "\nEmail       : " << U.Email;
		cout << "\nPhone       : " << U.Phone;
		cout << "\nUser Name   : " << U.UserName;
		cout << "\nPassword    : " << U.Password;
		cout << "\nPermission  : " << U.Permissions;
		cout << "\n____________________________________\n";
	}
public:
	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("FIND USER");
		cout << "\n ENTER USER NAME : ";
		string UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\n THIS USER NAME ALREADY USING ,ENTER ANOTHER ONE : ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		if (!User.IsEmpty())
		{
			cout << "\nUSER FOUND . ";
		}
		
		_Print(User);
	}
};

