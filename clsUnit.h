#pragma once // áÖãÇä ÊÖãíä Çáãáİ ãÑÉ æÇÍÏÉ İŞØ ÃËäÇÁ ÚãáíÉ ÇáÊÌãíÚ
#include <iostream> // ãßÊÈÉ ÇáÅÏÎÇá æÇáÅÎÑÇÌ ÇáÃÓÇÓíÉ (ãËá cout)
#include <string> // ãßÊÈÉ ÇáÊÚÇãá ãÚ ÇáÓáÇÓá ÇáäÕíÉ
#include "clsDate.h" // ÊÖãíä ßáÇÓ ÇáÊÇÑíÎ ÇáÎÇÕ

using namespace std; // ÇÓÊÎÏÇã İÖÇÁ ÇáÃÓãÇÁ ÇáŞíÇÓí áÊÓåíá ßÊÇÈÉ ÇáÃæÇãÑ

class clsUnit // ÊÚÑíİ ßáÇÓ ÇáÃÏæÇÊ ÇáãÓÇÚÏÉ (Utility Class)
{

public: // ÃÚÖÇÁ ÚÇãÉ íãßä ÇáæÕæá ÅáíåÇ ãä ÎÇÑÌ ÇáßáÇÓ
    enum enCharType {
        SamallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5
    }; // ÊÚÑíİ ãÑŞã áÃäæÇÚ ÇáÍÑæİ

    static void  Srand() // ÏÇáÉ áÊåíÆÉ ãæáÏ ÇáÃÑŞÇã ÇáÚÔæÇÆíÉ
    {
        // ÊÚÊãÏ ÇáÊåíÆÉ Úáì æŞÊ ÇáÌåÇÒ ÇáÍÇáí áÖãÇä ÚÔæÇÆíÉ ãÎÊáİÉ İí ßá ÊÔÛíá
        srand((unsigned)time(NULL));
    }

    static  int RandomNumber(int From, int To) // ÏÇáÉ áÊæáíÏ ÑŞã ÚÔæÇÆí Öãä äØÇŞ ãÍÏÏ
    {
        // ãÚÇÏáÉ ÍÓÇÈ ÑŞã ÚÔæÇÆí Èíä ÑŞãíä (ÈÏÇíÉ æäåÇíÉ)
        int randNum = rand() % (To - From + 1) + From;
        return randNum; // ÅÑÌÇÚ ÇáÑŞã ÇáÚÔæÇÆí ÇáäÇÊÌ
    }

    static char GetRandomCharacter(enCharType CharType) // ÏÇáÉ áÌáÈ ÍÑİ ÚÔæÇÆí ÈäÇÁğ Úáì ÇáäæÚ
    {

        // ÅĞÇ ßÇä ÇáäæÚ ÇáãØáæÈ "ãÒíÌ"¡ íÊã ÇÎÊíÇÑ äæÚ ÚÔæÇÆí Èíä (ÕÛíÑ¡ ßÈíÑ¡ ÃÑŞÇã)
        if (CharType == MixChars)
        {
            // ÊÍæíá ÇáÑŞã ÇáÚÔæÇÆí ÇáäÇÊÌ áíÊäÇÓÈ ãÚ Şíã enum
            CharType = (enCharType)RandomNumber(1, 3);

        }

        switch (CharType) // İÍÕ äæÚ ÇáÍÑİ ÇáãØáæÈ
        {

        case enCharType::SamallLetter: // İí ÍÇá ØáÈ ÍÑİ ÕÛíÑ
        {
            return char(RandomNumber(97, 122)); // ÅÑÌÇÚ ÍÑİ Èíä 'a' æ 'z' ÈÇÓÊÎÏÇã Şíã ASCII
            break;
        }
        case enCharType::CapitalLetter: // İí ÍÇá ØáÈ ÍÑİ ßÈíÑ
        {
            return char(RandomNumber(65, 90)); // ÅÑÌÇÚ ÍÑİ Èíä 'A' æ 'Z' ÈÇÓÊÎÏÇã Şíã ASCII
            break;
        }
        case enCharType::SpecialCharacter: // İí ÍÇá ØáÈ ÑãÒ ÎÇÕ
        {
            return char(RandomNumber(33, 47)); // ÅÑÌÇÚ ÑãÒ ÎÇÕ ÈÇÓÊÎÏÇã Şíã ASCII
            break;
        }
        case enCharType::Digit: // İí ÍÇá ØáÈ ÑŞã
        {
            return char(RandomNumber(48, 57)); // ÅÑÌÇÚ ÑŞã Èíä '0' æ '9' ÈÇÓÊÎÏÇã Şíã ASCII
            break;
        }
    defualt: // ÇáÍÇáÉ ÇáÇİÊÑÇÖíÉ (İí ÍÇá ÍÏæË ÎØÃ Ãæ ãÏÎá ÛíÑ ãÚÑæİ)
        {
            return char(RandomNumber(65, 90)); // ÅÑÌÇÚ ÍÑİ ßÈíÑ ßÇİÊÑÇÖí
            break;
        }
        }
    }

    static  string GenerateWord(enCharType CharType, short Length) // ÏÇáÉ áÊæáíÏ ßáãÉ ÚÔæÇÆíÉ ÈØæá ãÍÏÏ

    {
        string Word; // ãÊÛíÑ áÊÎÒíä ÇáßáãÉ ÇáãÊßæäÉ

        for (int i = 1; i <= Length; i++) // ÍáŞÉ ÊßÑÇÑ ÈÚÏÏ Øæá ÇáßáãÉ ÇáãØáæÈÉ

        {

            Word = Word + GetRandomCharacter(CharType); // ÅÖÇİÉ ÍÑİ ÚÔæÇÆí İí ßá ÏæÑÉ

        }
        return Word; // ÅÑÌÇÚ ÇáßáãÉ ÇáäåÇÆíÉ
    }

    static string  GenerateKey(enCharType CharType = CapitalLetter) // ÏÇáÉ áÊæáíÏ ãİÊÇÍ (Key) ÈÊäÓíŞ ãÚíä
    {

        string Key = ""; // ãÊÛíÑ áÊÎÒíä ÇáãİÊÇÍ


        Key = GenerateWord(CharType, 4) + "-"; // ÊæáíÏ ÇáÌÒÁ ÇáÃæá æÅÖÇİÉ İÇÕáÉ
        Key = Key + GenerateWord(CharType, 4) + "-"; // ÊæáíÏ ÇáÌÒÁ ÇáËÇäí æÅÖÇİÉ İÇÕáÉ
        Key = Key + GenerateWord(CharType, 4) + "-"; // ÊæáíÏ ÇáÌÒÁ ÇáËÇáË æÅÖÇİÉ İÇÕáÉ
        Key = Key + GenerateWord(CharType, 4); // ÊæáíÏ ÇáÌÒÁ ÇáÑÇÈÚ æÇáÃÎíÑ


        return Key; // ÅÑÌÇÚ ÇáãİÊÇÍ (ãËÇá: ABCD-EFGH-IJKL-MNOP)
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType) // ÏÇáÉ áØÈÇÚÉ ÚÏÏ ãÚíä ãä ÇáãİÇÊíÍ
    {

        for (int i = 1; i <= NumberOfKeys; i++) // ÍáŞÉ ÊßÑÇÑ ÈÚÏÏ ÇáãİÇÊíÍ ÇáãØáæÈÉ

        {
            cout << "Key [" << i << "] : "; // ØÈÇÚÉ ÑŞã ÇáãİÊÇÍ ÇáÍÇáí
            cout << GenerateKey(CharType) << endl; // ÊæáíÏ æØÈÇÚÉ ÇáãİÊÇÍ
        }

    }

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To) // ÊÚÈÆÉ ãÕİæİÉ ÃÑŞÇã ÚÔæÇÆíÉ
    {
        for (int i = 0; i < arrLength; i++) // ÍáŞÉ ÊßÑÇÑ ÊãÑ Úáì ÚäÇÕÑ ÇáãÕİæİÉ
            arr[i] = RandomNumber(From, To); // æÖÚ ÑŞã ÚÔæÇÆí İí ßá ÚäÕÑ
    }


    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength) // ÊÚÈÆÉ ãÕİæİÉ ßáãÇÊ ÚÔæÇÆíÉ
    {
        for (int i = 0; i < arrLength; i++) // ÍáŞÉ ÊßÑÇÑ ÊãÑ Úáì ÚäÇÕÑ ÇáãÕİæİÉ
            arr[i] = GenerateWord(CharType, Wordlength); // æÖÚ ßáãÉ ÚÔæÇÆíÉ İí ßá ÚäÕÑ

    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType) // ÊÚÈÆÉ ãÕİæİÉ ãİÇÊíÍ ÚÔæÇÆíÉ
    {
        for (int i = 0; i < arrLength; i++) // ÍáŞÉ ÊßÑÇÑ ÊãÑ Úáì ÚäÇÕÑ ÇáãÕİæİÉ
            arr[i] = GenerateKey(CharType); // æÖÚ ãİÊÇÍ ÚÔæÇÆí İí ßá ÚäÕÑ
    }

    static  void Swap(int& A, int& B) // ÏÇáÉ ÊÈÏíá Èíä ÑŞãíä ÕÍíÍíä (ÈÇáÅÓäÇÏ)
    {
        int Temp; // ãÊÛíÑ ãÄŞÊ

        Temp = A; // ÊÎÒíä ŞíãÉ ÇáÃæá İí ÇáãÄŞÊ
        A = B; // æÖÚ ŞíãÉ ÇáËÇäí İí ÇáÃæá
        B = Temp; // æÖÚ ÇáŞíãÉ ÇáãÄŞÊÉ İí ÇáËÇäí
    }

    static  void Swap(double& A, double& B) // ÏÇáÉ ÊÈÏíá Èíä ÑŞãíä ÚÔÑííä
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(bool& A, bool& B) // ÏÇáÉ ÊÈÏíá Èíä ŞíãÊíä ãäØŞíÊíä
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(char& A, char& B) // ÏÇáÉ ÊÈÏíá Èíä ÍÑİíä
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(string& A, string& B) // ÏÇáÉ ÊÈÏíá Èíä äÕíä
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(clsDate& A, clsDate& B) // ÏÇáÉ ÊÈÏíá Èíä ÊÇÑíÎíä ÈÇÓÊÎÏÇã ßáÇÓ ÇáÊÇÑíÎ
    {
        clsDate::SwapDates(A, B); // ÇÓÊÏÚÇÁ ÏÇáÉ ÇáÊÈÏíá ãä ßáÇÓ ÇáÊÇÑíÎ

    }

    static  void ShuffleArray(int arr[100], int arrLength) // ÏÇáÉ áÎáØ ÚäÇÕÑ ãÕİæİÉ ÇáÃÑŞÇã
    {

        for (int i = 0; i < arrLength; i++) // ÍáŞÉ ÊãÑ Úáì ÌãíÚ ÇáÚäÇÕÑ
        {
            // ÊÈÏíá ÇáÚäÕÑ ÇáÍÇáí ãÚ ÚäÕÑ ÂÎÑ íÊã ÇÎÊíÇÑå ÚÔæÇÆíÇğ
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static  void ShuffleArray(string arr[100], int arrLength) // ÏÇáÉ áÎáØ ÚäÇÕÑ ãÕİæİÉ ÇáäÕæÕ
    {

        for (int i = 0; i < arrLength; i++) // ÍáŞÉ ÊãÑ Úáì ÌãíÚ ÇáÚäÇÕÑ
        {
            // ÊÈÏíá ÇáÚäÕÑ ÇáÍÇáí ãÚ ÚäÕÑ ÂÎÑ ÚÔæÇÆí
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static string  Tabs(short NumberOfTabs) // ÏÇáÉ áÊæáíÏ æØÈÇÚÉ ãÓÇİÇÊ ÇáÌÏæáÉ (Tabs)
    {
        string t = ""; // ãÊÛíÑ áÊÎÒíä ÇáãÓÇİÇÊ

        for (int i = 1; i < NumberOfTabs; i++) // ÍáŞÉ ÊßÑÇÑ ÈÚÏÏ ÇáãÓÇİÇÊ ÇáãØáæÈÉ
        {
            t = t + "\t"; // ÅÖÇİÉ ÚáÇãÉ ÇáÌÏæáÉ (tab)
            cout << t; // ØÈÇÚÉ ÇáãÓÇİÉ ÇáÍÇáíÉ
        }
        return t; // ÅÑÌÇÚ ÇáäÕ ÇáĞí íÍÊæí Úáì ÇáãÓÇİÇÊ

    }


    static string NumberToText(int Number) // ÏÇáÉ áÊÍæíá ÇáÃÑŞÇã Åáì äÕæÕ ßáãÇÊ (ÈÇááÛÉ ÇáÅäÌáíÒíÉ)
    {

        if (Number == 0) // ÍÇáÉ ÇáÕİÑ
        {
            return "";
        }

        if (Number >= 1 && Number <= 19) // ÇáÊÚÇãá ãÚ ÇáÃÑŞÇã ãä 1 Åáì 19
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " "; // ÌáÈ ÇáßáãÉ ãä ÇáãÕİæİÉ ÈäÇÁğ Úáì ŞíãÉ ÇáÑŞã

        }

        if (Number >= 20 && Number <= 99) // ÇáÊÚÇãá ãÚ ÇáÃÑŞÇã ãä 20 Åáì 99
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10); // ÊÍæíá ÎÇäÉ ÇáÚÔÑÇÊ Ëã ÇÓÊÏÚÇÁ ÇáÏÇáÉ ááÈÇŞí
        }

        if (Number >= 100 && Number <= 199) // ÇáÊÚÇãá ãÚ ÇáãÆÇÊ (ãä 100 Åáì 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999) // ÇáÊÚÇãá ãÚ ãÆÇÊ (ãä 200 Åáì 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }


        if (Number >= 1000 && Number <= 1999) // ÇáÊÚÇãá ãÚ ÇáÂáÇİ (1000 Åáì 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999) // ÇáÊÚÇãá ãÚ ÂáÇİ (ÃßÈÑ ãä 2000)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999) // ÇáÊÚÇãá ãÚ ÇáãáÇííä (ãä ãáíæä Åáì ãáíæäíä)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999) // ÇáÊÚÇãá ãÚ ãáÇííä (ÃßÈÑ ãä 2 ãáíæä)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999) // ÇáÊÚÇãá ãÚ ÇáãáíÇÑÇÊ (Èáíæä)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else // ááÃÑŞÇã ÇáÊí ÊÒíÏ Úä ÇáãáíÇÑ
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }


    }
    static string EncryptionText(string Text, short EncryptionKey=2)
    {
        for (int i = 0; i <=Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }
        return Text;
    }
    static string DecryptText(string Text, short EncryptionKey=2)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text;
    }
};