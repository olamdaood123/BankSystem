#pragma once
#include<iostream>
#include "clsScreens.h"
using namespace std;
class clsShowDeleteUserScreen:protected clsScreens
{
private:
	static void _PrintUser(clsUser&User)
    {
        cout << "\nClient Card:";
        cout << "\n_______";
        cout << "\nFirstName   : " << User.FirstName; 
        cout << "\nLastName    : " << User.LastName; 
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\Permission   : " << User.Permissions;
        cout << "\n_______\n";
    }
	
public:
	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("DELETE USER ");
        cout << "\n ENTER USER NAME : ";
        string UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\n THIS USER NAME ALREADY USING ,ENTER ANOTHER ONE : ";
            UserName = clsInputValidate::ReadString();
        }
        clsUser User = clsUser::Find(UserName);
		_PrintUser(User);
		cout << "\nARE YOU SURE YOU WANT TO DELETE THIS USER? ";
		char Answer = 'n';
		cin >> Answer;
		if (toupper(Answer)=='Y')
		{
            if (User.Delete())
            {
                cout << "\nUSER DELETED SUCCESSFULY ";
                _PrintUser(User);
            }
		}
		else
		{
            cout << "\nDELETE CANCELED!!!";
		}

	}
};

