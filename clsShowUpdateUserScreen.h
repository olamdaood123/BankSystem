#pragma once
#include<iostream>
#include "clsScreens.h"
#include"clsUser.h"
using namespace std;
class clsShowUpdateUserScreen:protected clsScreens
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
	static int _ReadPermissionToSet()
	{
		char Answer = 'n';

		int Permission = 0;
		cout << "\nDO YOU WANT TO GIVE FULL ACCESS? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			return -1;
		}
		else
		{
			cout << "\nDO YOU WANT TO GIVE ACCESS TO : ";
			cout << "\n[1] SHOW CLIENT LEST ? ";
			cin >> Answer;
			if (toupper(Answer) == 'Y')
			{
				Permission += clsUser::enPermission::pShowClientLest;
			}

			cout << "\n[2] ADD NEW CLIENT LEST ? ";
			cin >> Answer;
			if (toupper(Answer) == 'Y')
			{
				Permission += clsUser::enPermission::pAddNew;
			}
			cout << "\n[3] DELET CLIENT  ? ";
			cin >> Answer;
			if (toupper(Answer) == 'Y')
			{
				Permission += clsUser::enPermission::pDelete;
			}
			cout << "\n[4] UPDATE CLIENT  ? ";
			cin >> Answer;
			if (toupper(Answer) == 'Y')
			{
				Permission += clsUser::enPermission::pUpdate;
			}
			cout << "\n[5] FINDUSER? ";
			cin >> Answer;
			if (toupper(Answer) == 'Y')
			{
				Permission += clsUser::enPermission::pFind;
			}
			cout << "\n[6] TRANSACTION  ? ";
			cin >> Answer;
			if (toupper(Answer) == 'Y')
			{
				Permission += clsUser::enPermission::pTransaction;
			}
			cout << "\n[7] SHOW MANAGE USER ? ";
			cin >> Answer;
			if (toupper(Answer) == 'Y')
			{
				Permission += clsUser::enPermission::pManageUser;
			}

			cout << "\n[8] SHOW LOGIN REGISTER ? ";
			cin >> Answer;
			if (toupper(Answer) == 'Y')
			{
				Permission += clsUser::enPermission::pLoginRegester;
			}

			return Permission;
		}

	}

	
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "ENTER First NAME : ";
		User.FirstName = clsInputValidate::ReadString();
		cout << "ENTER LAST NAME : ";
		User.LastName = clsInputValidate::ReadString();
		cout << "ENTER EMAIL : ";
		User.Email = clsInputValidate::ReadString();
		cout << "ENTER PHONE  : ";
		User.Phone = clsInputValidate::ReadString();
		cout << "ENTER PASSWORD : ";
		User.Password = clsInputValidate::ReadString();
		cout << "ENTER PERMISSIOMN  : ";
		User.Permissions = _ReadPermissionToSet();
	}
public:
	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("UPDATE USER");
	
		cout << "\n ENTER USER NAME : ";
		string UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\n THIS USER NAME ALREADY USING ,ENTER ANOTHER ONE : ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		_Print(User);
		char Answer = 'n';
		cout << "\n ARE YOU SURE YOU WANT TO UPDATE USER ? ";
		cin >> Answer;
		if (toupper(Answer)=='Y')
		{
			cout << "\nUPDATE USER INFO : ";
			_ReadUserInfo(User);
			clsUser::enSaveResults SaveResult = User.Save();
			switch (SaveResult)
			{
			case clsUser::enSaveResults::svSucceeded:
				cout << "\nUSER UPDATED SUCCESSFULY ";
				_Print(User);
				break;
			case clsUser::enSaveResults::svFaildEmptyObject:
				cout << "\n ERROR USER WASN'T UPDATE PECAUSE IT'S EMPTY !!!";

			}


		}
		else
		{
			cout << "\n UPSATED CANCELLED !!!";
		}
	}
};

