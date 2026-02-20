#pragma once
#include<iostream>
#include<iomanip>
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsScreens.h"

class clsShowAddNewUserScreen:protected clsScreens
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
	static int _ReadPermissionToSet()
	{
		char Answer = 'n';

		int Permission = 0;
		cout << "\nDO YOU WANT TO GIVE FULL ACCESS? ";
		cin >> Answer;
		if (toupper(Answer)=='Y')
		{
			return -1;
		}
		else
		{
			cout << "\nDO YOU WANT TO GIVE ACCESS TO : ";
			cout << "\n[1] SHOW CLIENT LEST ? ";
			cin >> Answer;
			if (toupper(Answer)=='Y')
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
		User.Permissions =_ReadPermissionToSet();
	}
public:
	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("ADD NEW USER ");
		cout << "\n ENTER USER NAME : ";
		string UserName = clsInputValidate::ReadString();
		while (clsUser::IsUserExist(UserName))
		{
			cout << "\n THIS USER NAME ALREADY USING ,ENTER ANOTHER ONE : ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::GetAddNewUserObject(UserName);
		_ReadUserInfo(User);
		clsUser::enSaveResults SaveResult = User.Save();
		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceeded:
			cout << "\nClient saved successfully\n";
			_PrintUserRecordLine(User);
			break;
		case clsBankClient::enSaveResults::svFaildEmptyObject:
			cout << "\n Client Don't saved because it is empty object ";
			break;
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
			cout << "\n Client Don't saved because AccountNumber already used  ";
			break;
		}

	}
};

