#pragma once
// Ì„‰⁄  ﬂ—«—  ÷„Ì‰ «·„·› √ﬂÀ— „‰ „—…

#include <iostream>
#include <string>

#include "clsString.h"
// ﬂ·«” Œ«’ »«· ⁄«„· „⁄ «·‰’Ê’ (€Ì— „” Œœ„ „»«‘—… Â‰«)

#include "clsDate.h"
// ﬂ·«” ·· ⁄«„· „⁄ «· Ê«—ÌŒ

using namespace std;

class clsInputValidate
{
public:

    // «· Õﬁﬁ Â· «·—ﬁ„ (short) »Ì‰ ﬁÌ„ Ì‰
    static bool IsNumberBetween(short Number, short From, short To)
    {
        if (Number >= From && Number <= To)
            return true;
        else
            return false;
    }

    // «· Õﬁﬁ Â· «·—ﬁ„ (int) »Ì‰ ﬁÌ„ Ì‰
    static bool IsNumberBetween(int Number, int From, int To)
    {
        if (Number >= From && Number <= To)
            return true;
        else
            return false;
    }

    // «· Õﬁﬁ Â· «·—ﬁ„ (double) »Ì‰ ﬁÌ„ Ì‰
    static bool IsNumberBetween(double Number, double From, double To)
    {
        if (Number >= From && Number <= To)
            return true;
        else
            return false;
    }

    // «· Õﬁﬁ Â·  «—ÌŒ „⁄Ì‰ »Ì‰  «—ÌŒÌ‰ (»€÷ «·‰Ÿ— ⁄‰ «· — Ì»)
    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
    {
        // «·Õ«·… «·√Ê·Ï: Date >= From && Date <= To
        if ((clsDate::IsDate1AfterDate2(Date, From) ||
            clsDate::IsDate1EqualDate2(Date, From))
            &&
            (clsDate::IsDate1BeforeDate2(Date, To) ||
                clsDate::IsDate1EqualDate2(Date, To)))
        {
            return true;
        }

        // «·Õ«·… «·À«‰Ì…: Date >= To && Date <= From
        if ((clsDate::IsDate1AfterDate2(Date, To) ||
            clsDate::IsDate1EqualDate2(Date, To))
            &&
            (clsDate::IsDate1BeforeDate2(Date, From) ||
                clsDate::IsDate1EqualDate2(Date, From)))
        {
            return true;
        }

        return false;
    }

    // ﬁ—«¡… —ﬁ„ ’ÕÌÕ „⁄ «· Õﬁﬁ „‰ ’Õ… «·≈œŒ«·
    static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        int Number;

        // ≈⁄«œ… «·ÿ·» ÿ«·„« «·≈œŒ«· €Ì— —ﬁ„Ì
        while (!(cin >> Number))
        {
            cin.clear(); // „”Õ Õ«·… «·Œÿ√
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //  Ã«Â· «·≈œŒ«· «·Œ«ÿ∆
            cout << ErrorMessage;
        }

        return Number;
    }

    // ﬁ—«¡… —ﬁ„ ’ÕÌÕ ÷„‰ „Ã«· „Õœœ
    static int ReadIntNumberBetween(int From, int To,
        string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        int Number = ReadIntNumber();

        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadIntNumber();
        }

        return Number;
    }

    // ﬁ—«¡… —ﬁ„ ⁄‘—Ì (float) „⁄ «· Õﬁﬁ
    static double ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        float Number;

        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }

        return Number;
    }

    // ﬁ—«¡… —ﬁ„ ⁄‘—Ì ÷„‰ „Ã«· „Õœœ
    static double ReadFloatNumberBetween(double From, double To,
        string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        float Number = ReadFloatNumber();

        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadDblNumber();
        }

        return Number;
    }

    // ﬁ—«¡… —ﬁ„ double „⁄ «· Õﬁﬁ
    static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        double Number;

        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }

        return Number;
    }

    // ﬁ—«¡… —ﬁ„ double ÷„‰ „Ã«· „Õœœ
    static double ReadDblNumberBetween(double From, double To,
        string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        double Number = ReadDblNumber();


        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadDblNumber();
        }

        return Number;
    }

    // «· Õﬁﬁ „‰ ’Õ… «· «—ÌŒ
    static bool IsValideDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }

    // ﬁ—«¡… ‰’ ﬂ«„· (string) „⁄  Ã«Â· «·›—«€«  «·”«»ﬁ…
    static string ReadString()
    {
        string S1 = "";

        // ws   Ã«Â· √Ì ›—«€«  √Ê √”ÿ— ÃœÌœ… ﬁ»· «·ﬁ—«¡…
        getline(cin >> ws, S1);

        return S1;
    }
};