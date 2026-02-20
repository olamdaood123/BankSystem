#pragma warning(disable : 4996) // ÊÚØíá ÊÍĞíÑÇÊ ÇáÏæÇá ÇáŞÏíãÉ ãËá localtime
#pragma once // áÖãÇä ÊÖãíä Çáãáİ ãÑÉ æÇÍÏÉ İŞØ ÃËäÇÁ ÇáÊÌãíÚ

#include<iostream>
#include<string>
#include<ctime>
#include "clsString.h" // ÊÖãíä ßáÇÓ ÇáÊÚÇãá ãÚ ÇáäÕæÕ

using namespace std;

class clsDate
{

private:
    // ãÊÛíÑÇÊ ÎÇÕÉ áÊÎÒíä Çáíæã¡ ÇáÔåÑ¡ æÇáÓäÉ
    short _Day = 1;
    short _Month = 1;
    short _Year = 1900;

public:

    // ÇáãäÔÆ ÇáÇİÊÑÇÖí: íŞæã ÈÌáÈ ÊÇÑíÎ ÇáäÙÇã ÇáÍÇáí
    clsDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        _Day = now->tm_mday;
        _Month = now->tm_mon + 1;
        _Year = now->tm_year + 1900;
    }

    // ãäÔÆ íÓÊŞÈá ÇáÊÇÑíÎ ßäÕ ÈÊäÓíŞ "DD/MM/YYYY" æíŞæã ÈÊÍæíáå
    clsDate(string sDate)
    {

        vector <string> vDate;
        vDate = clsString::Split(sDate, "/");

        _Day = stoi(vDate[0]);
        _Month = stoi(vDate[1]);
        _Year = stoi(vDate[2]);

    }

    // ãäÔÆ íÓÊŞÈá Çáíæã æÇáÔåÑ æÇáÓäÉ ßÃÑŞÇã
    clsDate(short Day, short Month, short Year)
    {

        _Day = Day;
        _Month = Month;
        _Year = Year;

    }

    // ãäÔÆ íÓÊŞÈá ÊÑÊíÈ Çáíæã ÎáÇá ÇáÓäÉ (ãËáÇğ Çáíæã ÑŞã 50 İí ÓäÉ 2023)
    clsDate(short DateOrderInYear, short Year)
    {
        // íÚÊãÏ Úáì ÏÇáÉ GetDateFromDayOrderInYear áÊÍæíá ÇáÑŞã Åáì ÊÇÑíÎ
        clsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);
        _Day = Date1.Day;
        _Month = Date1.Month;
        _Year = Date1.Year;
    }

    // ÏæÇá Set æ Get ááæÕæá ááãÊÛíÑÇÊ ÇáÎÇÕÉ
    void SetDay(short Day) {
        _Day = Day;
    }

    short GetDay() {
        return _Day;
    }
    // ÊÚÑíİ ÎÇÕíÉ (Property) ááíæã áÓåæáÉ ÇáÇÓÊÎÏÇã
    __declspec(property(get = GetDay, put = SetDay)) short Day;

    void SetMonth(short Month) {
        _Month = Month;
    }

    short GetMonth() {
        return _Month;
    }
    // ÊÚÑíİ ÎÇÕíÉ ááÔåÑ
    __declspec(property(get = GetMonth, put = SetMonth)) short Month;


    void SetYear(short Year) {
        _Year = Year;
    }

    short GetYear() {
        return _Year;
    }
    // ÊÚÑíİ ÎÇÕíÉ ááÓäÉ
    __declspec(property(get = GetYear, put = SetYear)) short Year;

    // ØÈÇÚÉ ÇáÊÇÑíÎ Úáì ÇáÔÇÔÉ
    void Print()
    {
        cout << DateToString() << endl;
    }

    // ÏÇáÉ ÓÊÇÊíß áÌáÈ ÊÇÑíÎ ÇáäÙÇã ÇáÍÇáí ßßÇÆä ãä ÇáßáÇÓ
    static clsDate GetSystemDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);

        short Day, Month, Year;

        Year = now->tm_year + 1900;
        Month = now->tm_mon + 1;
        Day = now->tm_mday;

        return clsDate(Day, Month, Year);
    }

    // ÏÇáÉ ÓÊÇÊíß ááÊÍŞŞ ãä ÕÍÉ ÇáÊÇÑíÎ ÇáãÏÎá
    static bool IsValidDate(clsDate Date)
    {

        if (Date.Day < 1 || Date.Day>31)
            return false;

        if (Date.Month < 1 || Date.Month>12)
            return false;

        if (Date.Month == 2) // ÇáÊÍŞŞ ãä ÔåÑ İÈÑÇíÑ (ÓäÉ ßÈíÓÉ Ãã áÇ)
        {
            if (isLeapYear(Date.Year))
            {
                if (Date.Day > 29)
                    return false;
            }
            else
            {
                if (Date.Day > 28)
                    return false;
            }
        }

        short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

        if (Date.Day > DaysInMonth)
            return false;

        return true;

    }

    // ÇáÊÍŞŞ ãä ÕÍÉ ÇáßÇÆä ÇáÍÇáí
    bool IsValid()
    {
        return IsValidDate(*this);
    }

    // ÏÇáÉ ÓÊÇÊíß áÊÍæíá ßÇÆä ÇáÊÇÑíÎ Åáì äÕ
    static string DateToString(clsDate Date)
    {
        return  to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
    }

    // ÊÍæíá ÇáßÇÆä ÇáÍÇáí Åáì äÕ
    string DateToString()
    {
        return  DateToString(*this);
    }

    // ÏÇáÉ ÓÊÇÊíß ááÊÍŞŞ åá ÇáÓäÉ ßÈíÓÉ Ãã áÇ
    static bool isLeapYear(short Year)
    {
        return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }

    // ÊÍŞŞ ãä ÇáÓäÉ ÇáÍÇáíÉ ááßÇÆä
    bool isLeapYear()
    {
        return isLeapYear(_Year);
    }

    // ÍÓÇÈ ÚÏÏ ÃíÇã ÇáÓäÉ
    static short NumberOfDaysInAYear(short Year)
    {
        return  isLeapYear(Year) ? 365 : 364; // ãáÇÍÙÉ: ÇáÓäÉ ÇáßÈíÓÉ 366 æÇáÚÇÏíÉ 365
    }

    short NumberOfDaysInAYear()
    {
        return  NumberOfDaysInAYear(_Year);
    }

    // ÍÓÇÈ ÚÏÏ ÓÇÚÇÊ ÇáÓäÉ
    static short NumberOfHoursInAYear(short Year)
    {
        return  NumberOfDaysInAYear(Year) * 24;
    }

    short NumberOfHoursInAYear()
    {
        return  NumberOfHoursInAYear(_Year);
    }

    // ÍÓÇÈ ÚÏÏ ÏŞÇÆŞ ÇáÓäÉ
    static int NumberOfMinutesInAYear(short Year)
    {
        return  NumberOfHoursInAYear(Year) * 60;
    }


    int NumberOfMinutesInAYear()
    {
        return  NumberOfMinutesInAYear(_Year);
    }

    // ÍÓÇÈ ÚÏÏ ËæÇäí ÇáÓäÉ
    static int NumberOfSecondsInAYear(short Year)
    {
        return  NumberOfMinutesInAYear(Year) * 60;
    }

    int NumberOfSecondsInAYear()
    {
        return  NumberOfSecondsInAYear();
    }

    // ÏÇáÉ ÓÊÇÊíß ÊÌáÈ ÚÏÏ ÃíÇã ÔåÑ ãÚíä İí ÓäÉ ãÚíäÉ
    static short NumberOfDaysInAMonth(short Month, short Year)
    {

        if (Month < 1 || Month>12)
            return  0;

        int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];

    }

    short NumberOfDaysInAMonth()
    {
        return NumberOfDaysInAMonth(_Month, _Year);
    }

    // ÍÓÇÈ ÚÏÏ ÇáÓÇÚÇÊ İí ÔåÑ ãÚíä
    static short NumberOfHoursInAMonth(short Month, short Year)
    {
        return  NumberOfDaysInAMonth(Month, Year) * 24;
    }

    short NumberOfHoursInAMonth()
    {
        return  NumberOfDaysInAMonth(_Month, _Year) * 24;
    }

    // ÍÓÇÈ ÚÏÏ ÇáÏŞÇÆŞ İí ÔåÑ ãÚíä
    static int NumberOfMinutesInAMonth(short Month, short Year)
    {
        return  NumberOfHoursInAMonth(Month, Year) * 60;
    }


    // ÍÓÇÈ ÚÏÏ ÇáÏŞÇÆŞ ááÔåÑ ÇáÍÇáí İí ÇáßÇÆä
    int NumberOfMinutesInAMonth()
    {
        return  NumberOfHoursInAMonth(_Month, _Year) * 60;
    }

    // ÏÇáÉ ÓÊÇÊíß áÍÓÇÈ ÚÏÏ ÇáËæÇäí İí ÔåÑ ãÚíä æÓäÉ ãÚíäÉ
    static int NumberOfSecondsInAMonth(short Month, short Year)
    {
        return  NumberOfMinutesInAMonth(Month, Year) * 60;
    }

    // ÍÓÇÈ ÚÏÏ ÇáËæÇäí ááÔåÑ ÇáÍÇáí İí ÇáßÇÆä
    int NumberOfSecondsInAMonth()
    {
        return  NumberOfMinutesInAMonth(_Month, _Year) * 60;
    }

    // ÏÇáÉ ÓÊÇÊíß áÊÍÏíÏ ÊÑÊíÈ íæã ÇáÃÓÈæÚ (0 ááÃÍÏ¡ 1 ááÇËäíä¡ ÅáÎ...) ÈÇÓÊÎÏÇã ÕíÛÉ "Zeller's congruence" ÇáãÈÓØÉ
    static short DayOfWeekOrder(short Day, short Month, short Year)
    {
        short a, y, m;
        a = (14 - Month) / 12;
        y = Year - a;
        m = Month + (12 * a) - 2;
        // ÇáÊŞæíã ÇáÛÑíÛæÑí:
        // 0:ÇáÃÍÏ¡ 1:ÇáÇËäíä¡ 2:ÇáËáÇËÇÁ... ÅáÎ
        return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    // ÌáÈ ÊÑÊíÈ íæã ÇáÃÓÈæÚ ááÊÇÑíÎ ÇáÍÇáí İí ÇáßÇÆä
    short DayOfWeekOrder()
    {
        return DayOfWeekOrder(_Day, _Month, _Year);
    }

    // ÏÇáÉ ÓÊÇÊíß ÊÚíÏ ÇÓã Çáíæã ÈÔßá ãÎÊÕÑ ÈäÇÁğ Úáì ÊÑÊíÈå
    static string DayShortName(short DayOfWeekOrder)
    {
        string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

        return arrDayNames[DayOfWeekOrder];

    }

    // ÏÇáÉ ÓÊÇÊíß ÊÚíÏ ÇÓã Çáíæã ÈÔßá ãÎÊÕÑ ÈäÇÁğ Úáì ÇáÊÇÑíÎ ÇáãÏÎá
    static string DayShortName(short Day, short Month, short Year)
    {

        string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

        return arrDayNames[DayOfWeekOrder(Day, Month, Year)];

    }

    // ÊÚíÏ ÇÓã Çáíæã ÈÔßá ãÎÊÕÑ ááÊÇÑíÎ ÇáÍÇáí İí ÇáßÇÆä
    string DayShortName()
    {

        string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

        return arrDayNames[DayOfWeekOrder(_Day, _Month, _Year)];

    }

    // ÏÇáÉ ÓÊÇÊíß ÊÚíÏ ÇÓã ÇáÔåÑ ÈÔßá ãÎÊÕÑ ÈäÇÁğ Úáì ÑŞãå
    static string MonthShortName(short MonthNumber)
    {
        string Months[12] = { "Jan", "Feb", "Mar",
               "Apr", "May", "Jun",
               "Jul", "Aug", "Sep",
               "Oct", "Nov", "Dec"
        };

        return (Months[MonthNumber - 1]);
    }

    // ÊÚíÏ ÇÓã ÇáÔåÑ ÇáÍÇáí ÈÔßá ãÎÊÕÑ ááßÇÆä
    string MonthShortName()
    {

        return MonthShortName(_Month);
    }

    // ÏÇáÉ ÓÊÇÊíß áØÈÇÚÉ ÊŞæíã ÔåÑ ãÍÏÏ ÈÔßá ãäÓŞ
    static void PrintMonthCalendar(short Month, short Year)
    {
        int NumberOfDays;

        // ÊÍÏíÏ Çáíæã ÇáĞí íÈÏÃ Èå ÇáÔåÑ (ÊÑÊíÈå ãä 0 Åáì 6)
        int current = DayOfWeekOrder(1, Month, Year);

        NumberOfDays = NumberOfDaysInAMonth(Month, Year);

        // ØÈÇÚÉ ÇÓã ÇáÔåÑ
        printf("\n  _%s_\n\n",
            MonthShortName(Month).c_str());

        // ØÈÇÚÉ ÃÓãÇÁ ÃíÇã ÇáÃÓÈæÚ
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // ØÈÇÚÉ ÇáãÓÇİÇÊ ÇáÈÇÏÆÉ ŞÈá ÈÏÇíÉ Ãæá íæã İí ÇáÔåÑ
        int i;
        for (i = 0; i < current; i++)
            printf("     ");

        // ØÈÇÚÉ ÃíÇã ÇáÔåÑ æÊäÓíŞ ÇáÕİæİ
        for (int j = 1; j <= NumberOfDays; j++)
        {
            printf("%5d", j);


            if (++i == 7) // ÇáÇäÊŞÇá áÓØÑ ÌÏíÏ ÈÚÏ íæã ÇáÓÈÊ
            {
                i = 0;
                printf("\n");
            }
        }

        printf("\n  _____\n");

    }

    // ØÈÇÚÉ ÊŞæíã ÇáÔåÑ ÇáÍÇáí ááßÇÆä
    void PrintMonthCalendar()
    {
        PrintMonthCalendar(_Month, _Year);
    }

    // ÏÇáÉ ÓÊÇÊíß áØÈÇÚÉ ÊŞæíã ÓäÉ ßÇãáÉ (12 ÔåÑ)
    static void PrintYearCalendar(int Year)
    {
        printf("\n  _____\n\n");
        printf("           Calendar - %d\n", Year);
        printf("  _____\n");


        for (int i = 1; i <= 12; i++)
        {
            PrintMonthCalendar(i, Year);
        }

        return;
    }

    // ØÈÇÚÉ ÊŞæíã ÇáÓäÉ ÇáÍÇáíÉ ááßÇÆä
    void PrintYearCalendar()
    {
        printf("\n  _____\n\n");
        printf("           Calendar - %d\n", _Year);
        printf("  _____\n");


        for (int i = 1; i <= 12; i++)
        {
            PrintMonthCalendar(i, _Year);
        }

        return;
    }

    // ÏÇáÉ ÓÊÇÊíß áÍÓÇÈ ÚÏÏ ÇáÃíÇã ÇáãäŞÖíÉ ãä ÈÏÇíÉ ÇáÓäÉ ÍÊì ÊÇÑíÎ ãÚíä
    static short DaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
    {


        short TotalDays = 0;

        for (int i = 1; i <= Month - 1; i++)
        {
            TotalDays += NumberOfDaysInAMonth(i, Year);
        }

        TotalDays += Day;

        return TotalDays;
    }

    // ÍÓÇÈ ÚÏÏ ÇáÃíÇã ÇáãäŞÖíÉ ãä ÈÏÇíÉ ÇáÓäÉ áÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí
    short DaysFromTheBeginingOfTheYear()
    {


        short TotalDays = 0;


        for (int i = 1; i <= _Month - 1; i++)
        {
            TotalDays += NumberOfDaysInAMonth(i, _Year);
        }

        TotalDays += _Day;

        return TotalDays;
    }

    // ÏÇáÉ ÓÊÇÊíß áÊÍæíá ÑŞã ÊÑÊíÈ Çáíæã İí ÇáÓäÉ Åáì ÊÇÑíÎ (íæã æÔåÑ)
    static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
    {

        clsDate Date;
        short RemainingDays = DateOrderInYear;
        short MonthDays = 0;

        Date.Year = Year;
        Date.Month = 1;

        while (true)
        {
            MonthDays = NumberOfDaysInAMonth(Date.Month, Year);

            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                Date.Month++;
            }
            else
            {
                Date.Day = RemainingDays;
                break;
            }

        }

        return Date;
    }

    // ÏÇáÉ áÅÖÇİÉ ÚÏÏ ãÚíä ãä ÇáÃíÇã Åáì ÇáÊÇÑíÎ ÇáÍÇáí æÊÍÏíË Şíã ÇáßÇÆä
    void AddDays(short Days)
    {


        short RemainingDays = Days + DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
        short MonthDays = 0;

        _Month = 1;

        while (true)
        {
            MonthDays = NumberOfDaysInAMonth(_Month, _Year);

            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                _Month++;


                // ÅĞÇ ÊÌÇæÒ ÚÏÏ ÇáÔåæÑ 12¡ äÚæÏ ááÔåÑ ÇáÃæá æäÒíÏ ÇáÓäÉ
                if (_Month > 12)
                {
                    _Month = 1;
                    _Year++;

                }
            }
            else
            {
                // ÅĞÇ ßÇäÊ ÇáÃíÇã ÇáãÊÈŞíÉ ÃŞá ãä ÃíÇã ÇáÔåÑ¡ äÍÏÏ Çáíæã æäÎÑÌ ãä ÇáÍáŞÉ
                _Day = RemainingDays;
                break;
            }

        }


    }

    // ÏÇáÉ ÓÊÇÊíß ááÊÍŞŞ ãÇ ÅĞÇ ßÇä ÇáÊÇÑíÎ ÇáÃæá íÓÈŞ ÇáÊÇÑíÎ ÇáËÇäí
    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
    {
        return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
    }

    // ÊÍŞŞ ãÇ ÅĞÇ ßÇä ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí íÓÈŞ ÇáÊÇÑíÎ ÇáããÑÑ
    bool IsDateBeforeDate2(clsDate Date2)
    {
        // ãáÇÍÙÉ: *this ÊÑÓá ÇáßÇÆä ÇáÍÇáí ááÏÇáÉ
        return  IsDate1BeforeDate2(*this, Date2);

    }

    // ÏÇáÉ ÓÊÇÊíß ááÊÍŞŞ ãä ÊØÇÈŞ ÊÇÑíÎíä ÊãÇãÇğ
    static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
    {
        return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
    }

    // ÊÍŞŞ ãÇ ÅĞÇ ßÇä ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí íÓÇæí ÇáÊÇÑíÎ ÇáããÑÑ
    bool IsDateEqualDate2(clsDate Date2)
    {
        return  IsDate1EqualDate2(*this, Date2);
    }

    // ÏÇáÉ ÓÊÇÊíß ááÊÍŞŞ ãÇ ÅĞÇ ßÇä Çáíæã åæ ÂÎÑ íæã İí ÔåÑå
    static bool IsLastDayInMonth(clsDate Date)
    {

        return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));

    }

    // ÊÍŞŞ ãÇ ÅĞÇ ßÇä Çáíæã ÇáÍÇáí ááßÇÆä åæ ÂÎÑ íæã İí ÔåÑå
    bool IsLastDayInMonth()
    {

        return IsLastDayInMonth(*this);

    }

    // ÏÇáÉ ÓÊÇÊíß ááÊÍŞŞ ãÇ ÅĞÇ ßÇä ÇáÔåÑ åæ ÔåÑ 12 (ÂÎÑ ÔåÑ İí ÇáÓäÉ)
    static bool IsLastMonthInYear(short Month)
    {
        return (Month == 12);
    }

    // ÏÇáÉ ÓÊÇÊíß áÅÖÇİÉ íæã æÇÍÏ İŞØ áÊÇÑíÎ ãÚíä æÇáÊÚÇãá ãÚ äåÇíÉ ÇáÔåÑ æÇáÓäÉ
    static clsDate AddOneDay(clsDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date.Month))
            {
                Date.Month = 1;
                Date.Day = 1;
                Date.Year++;
            }
            else
            {
                Date.Day = 1;
                Date.Month++;
            }
        }
        else
        {
            Date.Day++;
        }

        return Date;
    }

    // ÅÖÇİÉ íæã æÇÍÏ áÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí
    void AddOneDay()

    {
        *this = AddOneDay(*this);
    }

    // ÏÇáÉ ÓÊÇÊíß áÊÈÏíá ÇáŞíã Èíä ÊÇÑíÎíä (ÈÇáÅÔÇÑÉ)
    static void  SwapDates(clsDate& Date1, clsDate& Date2)
    {

        clsDate TempDate;
        TempDate = Date1;
        Date1 = Date2;
        Date2 = TempDate;

    }

    // ÏÇáÉ ÓÊÇÊíß áÍÓÇÈ İÑŞ ÇáÃíÇã Èíä ÊÇÑíÎíä ãÚ ÅãßÇäíÉ ÊÖãíä Çáíæã ÇáÃÎíÑ
    static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
    {
        int Days = 0;
        short SawpFlagValue = 1;

        // ÅĞÇ ßÇä ÇáÊÇÑíÎ ÇáÃæá ÈÚÏ ÇáËÇäí¡ äŞæã ÈÇáÊÈÏíá æäÖÑÈ ÇáäÊíÌÉ ÈÜ -1
        if (!IsDate1BeforeDate2(Date1, Date2))
        {
            SwapDates(Date1, Date2);
            SawpFlagValue = -1;

        }

        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Days++;
            Date1 = AddOneDay(Date1);
        }

        return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
    }

    // ÍÓÇÈ İÑŞ ÇáÃíÇã Èíä ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí æÊÇÑíÎ ÂÎÑ
    int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
    {
        return GetDifferenceInDays(*this, Date2, IncludeEndDay);
    }

    // ÏÇáÉ ÓÊÇÊíß áÍÓÇÈ ÇáÚãÑ ÈÇáÃíÇã ÈäÇÁğ Úáì ÊÇÑíÎ ÇáãíáÇÏ æÊÇÑíÎ ÇáäÙÇã ÇáÍÇáí
    static short CalculateMyAgeInDays(clsDate DateOfBirth)
    {
        return GetDifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), true);
    }

    // ÏÇáÉ ÓÊÇÊíß áÒíÇÏÉ ÇáÊÇÑíÎ ÈãŞÏÇÑ ÃÓÈæÚ (7 ÃíÇã)
    static clsDate IncreaseDateByOneWeek(clsDate& Date)
    {

        for (int i = 1; i <= 7; i++)
        {
            Date = AddOneDay(Date);
        }

        return Date;
    }

    // ÒíÇÏÉ ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí ÈãŞÏÇÑ ÃÓÈæÚ
    void IncreaseDateByOneWeek()
    {
        IncreaseDateByOneWeek(*this);
    }

    // ÒíÇÏÉ ÇáÊÇÑíÎ ÈãŞÏÇÑ ÚÏÏ ãÚíä ãä ÇáÃÓÇÈíÚ
    clsDate IncreaseDateByXWeeks(short Weeks, clsDate& Date)
    {

        for (short i = 1; i <= Weeks; i++)
        {
            Date = IncreaseDateByOneWeek(Date);
        }
        return Date;
    }

    // ÒíÇÏÉ ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí ÈãŞÏÇÑ X ãä ÇáÃÓÇÈíÚ
    void IncreaseDateByXWeeks(short Weeks)
    {
        IncreaseDateByXWeeks(Weeks, *this);
    }

    // ÒíÇÏÉ ÇáÊÇÑíÎ ÈãŞÏÇÑ ÔåÑ æÇÍÏ ãÚ ãÚÇáÌÉ ÇáÃíÇã ÇáÒÇÆÏÉ (ãËá ÇáÇäÊŞÇá ãä 31 Jan Åáì 28 Feb)
    clsDate IncreaseDateByOneMonth(clsDate& Date)
    {


        if (Date.Month == 12)
        {
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Month++;
        }

        // ÇáÊÍŞŞ ãä Ãä Çáíæã áÇ íÊÌÇæÒ ÚÏÏ ÃíÇã ÇáÔåÑ ÇáÌÏíÏ
        // ãËÇá: ÅĞÇ ßÇä ÇáÊÇÑíÎ 31/1/2022¡ ÇáÒíÇÏÉ ÈÔåÑ íÌÈ Ãä ÊÕÈÍ 28/2/2022 æáíÓ 31/2
        short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
        if (Date.Day > NumberOfDaysInCurrentMonth)
        {
            Date.Day = NumberOfDaysInCurrentMonth;
        }

        return Date;
    }

    // ÒíÇÏÉ ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí ÈÔåÑ æÇÍÏ
    void IncreaseDateByOneMonth()
    {

        IncreaseDateByOneMonth(*this);

    }

    // ÒíÇÏÉ ÇáÊÇÑíÎ ÈãŞÏÇÑ ÚÏÏ ãÚíä ãä ÇáÃíÇã
    clsDate IncreaseDateByXDays(short Days, clsDate& Date)
    {

        for (short i = 1; i <= Days; i++)
        {
            Date = AddOneDay(Date);
        }
        return Date;
    }

    // ÒíÇÏÉ ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí ÈãŞÏÇÑ X ãä ÇáÃíÇã
    void IncreaseDateByXDays(short Days)
    {

        IncreaseDateByXDays(Days, *this);
    }

    // ÒíÇÏÉ ÇáÊÇÑíÎ ÈãŞÏÇÑ ÚÏÏ ãÚíä ãä ÇáÔåæÑ
    clsDate IncreaseDateByXMonths(short Months, clsDate& Date)
    {

        for (short i = 1; i <= Months; i++)
        {
            Date = IncreaseDateByOneMonth(Date);
        }
        return Date;
    }

    // ÒíÇÏÉ ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí ÈãŞÏÇÑ X ãä ÇáÔåæÑ
    void IncreaseDateByXMonths(short Months)
    {
        IncreaseDateByXMonths(Months, *this);
    }

    // ÏÇáÉ ÓÊÇÊíß áÒíÇÏÉ ÇáÊÇÑíÎ ÈãŞÏÇÑ ÓäÉ æÇÍÏÉ
    static clsDate IncreaseDateByOneYear(clsDate& Date)
    {
        Date.Year++;
        return Date;
    }


    // ÒíÇÏÉ ÓäÉ æÇÍÏÉ ááÊÇÑíÎ ÇáÍÇáí ááßÇÆä
    void IncreaseDateByOneYear()
    {
        IncreaseDateByOneYear(*this);
    }

    // ÒíÇÏÉ ÚÏÏ ãÚíä ãä ÇáÓäæÇÊ áÊÇÑíÎ ããÑÑ
    clsDate IncreaseDateByXYears(short Years, clsDate& Date)
    {
        Date.Year += Years;
        return Date;
    }

    // ÒíÇÏÉ ÚÏÏ ãÚíä ãä ÇáÓäæÇÊ áÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí
    void IncreaseDateByXYears(short Years)
    {
        IncreaseDateByXYears(Years, *this);
    }

    // ÒíÇÏÉ ÇáÊÇÑíÎ ÈãŞÏÇÑ ÚŞÏ æÇÍÏ (10 ÓäæÇÊ)
    clsDate IncreaseDateByOneDecade(clsDate& Date)
    {
        Date.Year += 10;
        return Date;
    }

    // ÒíÇÏÉ ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí ÈãŞÏÇÑ ÚŞÏ æÇÍÏ
    void IncreaseDateByOneDecade()
    {
        IncreaseDateByOneDecade(*this);
    }

    // ÒíÇÏÉ ÇáÊÇÑíÎ ÈãŞÏÇÑ ÚÏÏ ãÚíä ãä ÇáÚŞæÏ (ßá ÚŞÏ 10 ÓäæÇÊ)
    clsDate IncreaseDateByXDecades(short Decade, clsDate& Date)
    {
        Date.Year += Decade * 10;
        return Date;
    }

    // ÒíÇÏÉ ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí ÈãŞÏÇÑ ÚÏÏ ãÚíä ãä ÇáÚŞæÏ
    void IncreaseDateByXDecades(short Decade)
    {
        IncreaseDateByXDecades(Decade, *this);
    }

    // ÒíÇÏÉ ÇáÊÇÑíÎ ÈãŞÏÇÑ ŞÑä æÇÍÏ (100 ÓäÉ)
    clsDate IncreaseDateByOneCentury(clsDate& Date)
    {
        Date.Year += 100;
        return Date;
    }

    // ÒíÇÏÉ ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí ÈãŞÏÇÑ ŞÑä æÇÍÏ
    void IncreaseDateByOneCentury()
    {
        IncreaseDateByOneCentury(*this);
    }

    // ÒíÇÏÉ ÇáÊÇÑíÎ ÈãŞÏÇÑ ÃáİíÉ æÇÍÏÉ (1000 ÓäÉ)
    clsDate IncreaseDateByOneMillennium(clsDate& Date)
    {
        Date.Year += 1000;
        return Date;
    }

    // ÒíÇÏÉ ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí ÈãŞÏÇÑ ÃáİíÉ æÇÍÏÉ
    void IncreaseDateByOneMillennium()
    {
        IncreaseDateByOneMillennium(*this);
    }

    // ÏÇáÉ ÓÊÇÊíß áÅäŞÇÕ íæã æÇÍÏ ãä ÇáÊÇÑíÎ ãÚ ãÚÇáÌÉ ÇáÇäÊŞÇá ááÔåÑ Ãæ ÇáÓäÉ ÇáÓÇÈŞÉ
    static clsDate DecreaseDateByOneDay(clsDate Date)
    {
        if (Date.Day == 1)
        {
            if (Date.Month == 1)
            {
                Date.Month = 12;
                Date.Day = 31;
                Date.Year--;
            }
            else
            {
                Date.Month--;
                Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
            }
        }
        else
        {
            Date.Day--;
        }

        return Date;
    }

    // ÅäŞÇÕ íæã æÇÍÏ ãä ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí
    void DecreaseDateByOneDay()
    {
        *this = DecreaseDateByOneDay(*this);
    }

    // ÏÇáÉ ÓÊÇÊíß áÅäŞÇÕ ÃÓÈæÚ (7 ÃíÇã) ãä ÇáÊÇÑíÎ
    static clsDate DecreaseDateByOneWeek(clsDate& Date)
    {

        for (int i = 1; i <= 7; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }

        return Date;
    }

    // ÅäŞÇÕ ÃÓÈæÚ ãä ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí
    void DecreaseDateByOneWeek()
    {
        DecreaseDateByOneWeek(*this);
    }

    // ÅäŞÇÕ ÚÏÏ ãÚíä ãä ÇáÃÓÇÈíÚ ãä ÇáÊÇÑíÎ
    static clsDate DecreaseDateByXWeeks(short Weeks, clsDate& Date)
    {

        for (short i = 1; i <= Weeks; i++)
        {
            Date = DecreaseDateByOneWeek(Date);
        }
        return Date;
    }

    // ÅäŞÇÕ ÚÏÏ ãÚíä ãä ÇáÃÓÇÈíÚ ãä ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí
    void DecreaseDateByXWeeks(short Weeks)
    {
        DecreaseDateByXWeeks(Weeks, *this);
    }

    // ÅäŞÇÕ ÔåÑ æÇÍÏ ãä ÇáÊÇÑíÎ ãÚ ãÚÇáÌÉ ÚÏÏ ÇáÃíÇã İí ÇáÔåÑ ÇáÓÇÈŞ
    static clsDate DecreaseDateByOneMonth(clsDate& Date)
    {

        if (Date.Month == 1)
        {
            Date.Month = 12;
            Date.Year--;
        }
        else
            Date.Month--;

        // ÇáÊÃßÏ ãä Ãä Çáíæã áÇ íÊÌÇæÒ ÃŞÕì ÚÏÏ ÃíÇã İí ÇáÔåÑ ÇáÌÏíÏ
        // ãËÇá: ÅĞÇ ßÇä ÇáÊÇÑíÎ 31/3/2022¡ ÅäŞÇÕ ÔåÑ íÌÚáå 28/2/2022
        short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
        if (Date.Day > NumberOfDaysInCurrentMonth)
        {
            Date.Day = NumberOfDaysInCurrentMonth;
        }


        return Date;
    }

    // ÅäŞÇÕ ÔåÑ æÇÍÏ ãä ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí
    void DecreaseDateByOneMonth()
    {
        DecreaseDateByOneMonth(*this);
    }

    // ÅäŞÇÕ ÚÏÏ ãÚíä ãä ÇáÃíÇã ãä ÇáÊÇÑíÎ
    static clsDate DecreaseDateByXDays(short Days, clsDate& Date)
    {

        for (short i = 1; i <= Days; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }
        return Date;
    }

    // ÅäŞÇÕ ÚÏÏ ãÚíä ãä ÇáÃíÇã ãä ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí
    void DecreaseDateByXDays(short Days)
    {
        DecreaseDateByXDays(Days, *this);
    }

    // ÅäŞÇÕ ÚÏÏ ãÚíä ãä ÇáÔåæÑ ãä ÇáÊÇÑíÎ
    static clsDate DecreaseDateByXMonths(short Months, clsDate& Date)
    {

        for (short i = 1; i <= Months; i++)
        {
            Date = DecreaseDateByOneMonth(Date);
        }
        return Date;
    }

    // ÅäŞÇÕ ÚÏÏ ãÚíä ãä ÇáÔåæÑ ãä ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí
    void DecreaseDateByXMonths(short Months)
    {
        DecreaseDateByXMonths(Months, *this);
    }


    // ÅäŞÇÕ ÓäÉ æÇÍÏÉ ãä ÇáÊÇÑíÎ
    static clsDate DecreaseDateByOneYear(clsDate& Date)
    {

        Date.Year--;
        return Date;
    }

    // ÅäŞÇÕ ÓäÉ æÇÍÏÉ ãä ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí
    void DecreaseDateByOneYear()
    {
        DecreaseDateByOneYear(*this);
    }

    // ÅäŞÇÕ ÚÏÏ ãÚíä ãä ÇáÓäæÇÊ ãä ÇáÊÇÑíÎ
    static clsDate DecreaseDateByXYears(short Years, clsDate& Date)
    {

        Date.Year -= Years;
        return Date;
    }

    // ÅäŞÇÕ ÚÏÏ ãÚíä ãä ÇáÓäæÇÊ ãä ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí
    void DecreaseDateByXYears(short Years)
    {
        DecreaseDateByXYears(Years, *this);
    }

    // ÅäŞÇÕ ÚŞÏ æÇÍÏ (10 ÓäæÇÊ) ãä ÇáÊÇÑíÎ
    static clsDate DecreaseDateByOneDecade(clsDate& Date)
    {
        Date.Year -= 10;
        return Date;
    }

    // ÅäŞÇÕ ÚŞÏ æÇÍÏ ãä ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí
    void DecreaseDateByOneDecade()
    {
        DecreaseDateByOneDecade(*this);
    }

    // ÅäŞÇÕ ÚÏÏ ãÚíä ãä ÇáÚŞæÏ ãä ÇáÊÇÑíÎ
    static clsDate DecreaseDateByXDecades(short Decades, clsDate& Date)
    {

        Date.Year -= Decades * 10;
        return Date;
    }

    // ÅäŞÇÕ ÚÏÏ ãÚíä ãä ÇáÚŞæÏ ãä ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí
    void DecreaseDateByXDecades(short Decades)
    {
        DecreaseDateByXDecades(Decades, *this);
    }

    // ÅäŞÇÕ ŞÑä æÇÍÏ (100 ÓäÉ) ãä ÇáÊÇÑíÎ
    static clsDate DecreaseDateByOneCentury(clsDate& Date)
    {
        Date.Year -= 100;
        return Date;
    }

    // ÅäŞÇÕ ŞÑä æÇÍÏ ãä ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí
    void DecreaseDateByOneCentury()
    {
        DecreaseDateByOneCentury(*this);
    }


    // ÏÇáÉ ÓÊÇÊíß áÅäŞÇÕ ÃáİíÉ æÇÍÏÉ (1000 ÓäÉ) ãä ÇáÊÇÑíÎ ÇáããÑÑ
    static clsDate DecreaseDateByOneMillennium(clsDate& Date)
    {
        Date.Year -= 1000;
        return Date;
    }

    // ÅäŞÇÕ ÃáİíÉ æÇÍÏÉ ãä ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí
    void DecreaseDateByOneMillennium()
    {
        DecreaseDateByOneMillennium(*this);
    }

    // ÏÇáÉ ÓÊÇÊíß ááÊÍŞŞ ããÇ ÅĞÇ ßÇä ÇáÊÇÑíÎ íŞÚ İí äåÇíÉ ÇáÃÓÈæÚ (íæã ÇáÓÈÊ ÊÍÏíÏÇğ ÈäÇÁğ Úáì ÇáÑŞã 6)
    static short IsEndOfWeek(clsDate Date)
    {
        return  DayOfWeekOrder(Date.Day, Date.Month, Date.Year) == 6;
    }

    // ÇáÊÍŞŞ ááßÇÆä ÇáÍÇáí ÅĞÇ ßÇä İí äåÇíÉ ÇáÃÓÈæÚ
    short IsEndOfWeek()
    {
        return IsEndOfWeek(*this);
    }

    // ÏÇáÉ ÓÊÇÊíß ááÊÍŞŞ ããÇ ÅĞÇ ßÇä Çáíæã åæ ÚØáÉ äåÇíÉ ÃÓÈæÚ (ÇáÌãÚÉ æÇáÓÈÊ)
    static bool IsWeekEnd(clsDate Date)
    {
        // ÃíÇã ÇáÚØáÉ åí ÇáÌãÚÉ (5) æÇáÓÈÊ (6)
        short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
        return  (DayIndex == 5 || DayIndex == 6);
    }

    // ÇáÊÍŞŞ ááßÇÆä ÇáÍÇáí ÅĞÇ ßÇä íæã ÚØáÉ
    bool IsWeekEnd()
    {
        return  IsWeekEnd(*this);
    }

    // ÏÇáÉ ÓÊÇÊíß ááÊÍŞŞ ããÇ ÅĞÇ ßÇä Çáíæã åæ íæã Úãá (ÇáÃÍÏ Åáì ÇáÎãíÓ)
    static bool IsBusinessDay(clsDate Date)
    {
        // ÇáØÑíŞÉ ÇáÃİÖá åí ÚßÓ äÊíÌÉ ÏÇáÉ IsWeekEnd áÖãÇä ÊäÇÓŞ ÇáßæÏ
        return !IsWeekEnd(Date);
    }

    // ÇáÊÍŞŞ ááßÇÆä ÇáÍÇáí ÅĞÇ ßÇä íæã Úãá
    bool IsBusinessDay()
    {
        return  IsBusinessDay(*this);
    }

    // ÍÓÇÈ ÚÏÏ ÇáÃíÇã ÇáãÊÈŞíÉ ÍÊì äåÇíÉ ÇáÃÓÈæÚ ÇáÍÇáí (ÇáÓÈÊ)
    static short DaysUntilTheEndOfWeek(clsDate Date)
    {
        return 6 - DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
    }

    short DaysUntilTheEndOfWeek()
    {
        return  DaysUntilTheEndOfWeek(*this);
    }

    // ÍÓÇÈ ÚÏÏ ÇáÃíÇã ÇáãÊÈŞíÉ ÍÊì äåÇíÉ ÇáÔåÑ ÇáÍÇáí
    static short DaysUntilTheEndOfMonth(clsDate Date1)
    {

        clsDate EndOfMontDate;
        EndOfMontDate.Day = NumberOfDaysInAMonth(Date1.Month, Date1.Year);
        EndOfMontDate.Month = Date1.Month;
        EndOfMontDate.Year = Date1.Year;

        return GetDifferenceInDays(Date1, EndOfMontDate, true);
    }

    short DaysUntilTheEndOfMonth()
    {
        return DaysUntilTheEndOfMonth(*this);
    }

    // ÍÓÇÈ ÚÏÏ ÇáÃíÇã ÇáãÊÈŞíÉ ÍÊì äåÇíÉ ÇáÓäÉ ÇáÍÇáíÉ
    static short DaysUntilTheEndOfYear(clsDate Date1)
    {

        clsDate EndOfYearDate;
        EndOfYearDate.Day = 31;
        EndOfYearDate.Month = 12;
        EndOfYearDate.Year = Date1.Year;

        return GetDifferenceInDays(Date1, EndOfYearDate, true);
    }

    short DaysUntilTheEndOfYear()
    {
        return  DaysUntilTheEndOfYear(*this);
    }

    // ÏÇáÉ áÍÓÇÈ ÚÏÏ ÃíÇã ÇáÚãá ÇáİÚáíÉ Èíä ÊÇÑíÎíä (ÈÇÓÊËäÇÁ ÇáÚØáÇÊ)
    static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
    {
        short Days = 0;
        while (IsDate1BeforeDate2(DateFrom, DateTo))
        {
            if (IsBusinessDay(DateFrom))
                Days++;

            DateFrom = AddOneDay(DateFrom);
        }
        return Days;
    }

    // ÍÓÇÈ ÃíÇã ÇáÅÌÇÒÉ (æåí äİÓåÇ ÃíÇã ÇáÚãá Èíä ÊÇÑíÎíä)
    static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
    {
        return CalculateBusinessDays(DateFrom, DateTo);
    }

    // ÏÇáÉ áÍÓÇÈ ÊÇÑíÎ ÇáÚæÏÉ ãä ÇáÅÌÇÒÉ ÈäÇÁğ Úáì ÊÇÑíÎ ÇáÈÏÁ æÚÏÏ ÃíÇã ÇáÅÌÇÒÉ ÇáãØáæÈÉ
    static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
    {
        short WeekEndCounter = 0;

        // ÃæáÇğ: ÅÖÇİÉ ÃíÇã ÇáÅÌÇÒÉ æÚÏø ÃíÇã ÇáÚØá ÇáÊí ÊÎááÊåÇ
        for (short i = 1; i <= VacationDays; i++)
        {
            if (IsWeekEnd(DateFrom))
                WeekEndCounter++;

            DateFrom = AddOneDay(DateFrom);
        }

        // ËÇäíÇğ: ÅÖÇİÉ ÃíÇã ÅÖÇİíÉ ÊÚæíÖÇğ Úä ÃíÇã ÇáÚØá ÇáÊí ÕÇÏİÊ æŞÊ ÇáÅÌÇÒÉ
        for (short i = 1; i <= WeekEndCounter; i++)
            DateFrom = AddOneDay(DateFrom);

        return DateFrom;
    }

    // ÏÇáÉ ÓÊÇÊíß ááÊÍŞŞ ããÇ ÅĞÇ ßÇä ÇáÊÇÑíÎ ÇáÃæá íŞÚ ÈÚÏ ÇáÊÇÑíÎ ÇáËÇäí
    static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
    {
        return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
    }

    // ÊÍŞŞ ãÇ ÅĞÇ ßÇä ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí íŞÚ ÈÚÏ ÇáÊÇÑíÎ ÇáããÑÑ
    bool IsDateAfterDate2(clsDate Date2)
    {
        return IsDate1AfterDate2(*this, Date2);
    }

    // ÊÚÑíİ "Enum" ááãŞÇÑäÉ Èíä ÇáÊæÇÑíÎ áÓåæáÉ ŞÑÇÁÉ ÇáäÊÇÆÌ
    enum enDateCompare { Before = -1, Equal = 0, After = 1 };


    // ÏÇáÉ ÓÊÇÊíß ÔÇãáÉ ááãŞÇÑäÉ ÊÚíÏ (ŞÈá¡ íÓÇæí¡ Ãæ ÈÚÏ)
    static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
    {
        if (IsDate1BeforeDate2(Date1, Date2))
            return enDateCompare::Before;

        if (IsDate1EqualDate2(Date1, Date2))
            return enDateCompare::Equal;

        return enDateCompare::After;
    }

    // ãŞÇÑäÉ ÊÇÑíÎ ÇáßÇÆä ÇáÍÇáí ãÚ ÊÇÑíÎ ÂÎÑ
    enDateCompare CompareDates(clsDate Date2)
    {
        return CompareDates(*this, Date2);
    }
    static string GetSystemDateTimeString()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        short Day, Month, year, Hour, Minute, Second;
        year = now->tm_year + 1900;
        Month = now->tm_mon + 1;
        Day = now->tm_mday;
        Hour = now->tm_hour;
        Minute = now->tm_min;
        Second = now->tm_sec;

        return (to_string(Day) + "/" + to_string(Month) + "/" + to_string(year) + "  _   " + to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second));
    }
};
