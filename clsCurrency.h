#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"clsString.h"
using namespace std;

class clsCurrency
{
private:

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float  _Rate;
	enum enMode
	{
		enEmptyMode=0,enUpdateMode=1
	};
	enMode _Mode;
	
	static clsCurrency  _ConvertCurrencyLineToObject(string Line,string Separator="#//#")
	{
		vector<string> vCurrency = clsString::Split(Line, Separator);
		return clsCurrency(enMode::enUpdateMode,vCurrency[0],vCurrency[1],vCurrency[2],stof(vCurrency[3]));
	}
	static clsCurrency GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::enEmptyMode, "", "", "", 0);
	}
	static vector<clsCurrency>  _LoadCurrencyDataFromFile()
	{
		vector<clsCurrency> _vCurrency;
		fstream MyFile;
		MyFile.open("Currency.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertCurrencyLineToObject(Line);
				_vCurrency.push_back(Currency);
			}
			MyFile.close();
		}
		return _vCurrency;
	}
	 static string _ConvertCurrencyObjectToLine(clsCurrency& Currency, string Separator = "#//#")
	{
		 string S1 = "";
		 S1 += Currency.Country() + Separator;
		 S1 += Currency.CurrencyCode() + Separator;
		 S1 += Currency.CurrencyName() + Separator;
		 S1 += to_string(Currency.Rate());
		 return S1;
	}
	static void _SaveCurrencyDataToFile(vector<clsCurrency>& vCurrency)
	{
		fstream MyFile;
		MyFile.open("Currency.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsCurrency& C : vCurrency)
			{
				string DataLine = _ConvertCurrencyObjectToLine(C);
				MyFile << DataLine << endl;
			}
			MyFile.close();
		}
		
	}

	
	
	void _Update()
	{
		vector<clsCurrency> _vCurrency = _LoadCurrencyDataFromFile();
		for (clsCurrency& C : _vCurrency)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(_vCurrency);
	}
public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	float Rate()
	{
		return _Rate;
	}
	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::enEmptyMode);
	}
	string Country()
	{
		return _Country;
	}
	string CurrencyCode()
	{
		return _CurrencyCode;
	}
	string CurrencyName()
		{
			return _CurrencyName;
		}
	

	static clsCurrency FindByCurrencyCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		fstream MyFile;
		MyFile.open("Currency.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency= _ConvertCurrencyLineToObject(Line);
				if (Currency.CurrencyCode()==clsString::UpperAllString (CurrencyCode))
				{
					MyFile.close();
					return Currency;
				}

			}
			MyFile.close();
		}
		return GetEmptyCurrencyObject();
	}
	static clsCurrency FindByCountry(string Country)
	{
		// 1.  ÕÊÌ· ‰’ «·»ÕÀ ≈·Ï √Õ—› ﬂ»Ì—…
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currency.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertCurrencyLineToObject(Line);

				// 2.  ÕÊÌ· «”„ «·œÊ·… „‰ «·„·› ·√Õ—› ﬂ»Ì—… +  ‰ŸÌ› «·„”«›«  ≈‰ ÊÃœ 
				// (»«› —«÷ ÊÃÊœ œ«·… Trim ›Ì ﬂ·«” clsString ⁄‰œﬂ)
				string CountryFromFile = clsString::UpperAllString(Currency.Country());

				if (CountryFromFile == Country)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);
		return (!Currency.IsEmpty());
	}
	static vector<clsCurrency> GetCurrencyList()
	{
		return _LoadCurrencyDataFromFile();
	}

	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / Rate());
	}
	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);
		if (Currency2.CurrencyCode()=="USD")
		{
			return AmountInUSD;
		}
		else
		{
			return (float)(AmountInUSD * Currency2.Rate());
		}
	}











};

