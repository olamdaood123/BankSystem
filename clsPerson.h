#pragma once
#include<iostream>
#include"InterfaceCommunication.h"
using namespace std;

class clsPerson :public InterfaceCommunication
{
public:
	clsPerson(string FirstName, string LastName, string Email, string Phone)
	{
		_firstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}
	void setFirstName(string FirstName)
	{
		_firstName = FirstName;
	}
	string GetFirstName()
	{
		return _firstName;
	}
	__declspec(property(get = GetFirstName, put = setFirstName))string FirstName;
	void setLastName(string LastName)
	{
		_LastName = LastName;
	}
	string GetLastName()
	{
		return _LastName;
	}
	__declspec(property(get = GetLastName, put = setLastName))string LastName;
	void setEmail(string Email)
	{
		_Email = Email;
	}
	string GetEmail()
	{
		return _Email;
	}
	__declspec(property(get = GetEmail, put = setEmail))string Email;
	void setPhone(string Phone)
	{
		_Phone = Phone;
	}
	string GetPhone()
	{
		return _Phone;
	}
	__declspec(property(get = GetPhone, put = setPhone))string Phone;
	string FullName()
	{
		return _firstName + " " + _LastName;
	}
	virtual void SendEmail(string Title, string Body)
	{

	}
	virtual void SendFax(string Title, string Body)
	{

	}
	virtual void SendSMS(string Title, string Body)
	{

	}
private:
	string _firstName;
	string _LastName;
	string _Email;
	string _Phone;
};