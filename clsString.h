
//Ola Mohammed Daood

#pragma once

#include <iostream>
#include <vector>

using namespace std;

class clsString
{

private:
    string _Value; // «·„ €Ì— «·Œ«’ «·–Ì ÌÕ„· ﬁÌ„… «·‰’ ›Ì «·ﬂ«∆‰

public:

    // «·„‘Ìœ «·«› —«÷Ì: Ì⁄ÿÌ ﬁÌ„… ›«—€… ··‰’
    clsString()
    {
        _Value = "";
    }

    // „‘Ìœ Ì” ﬁ»· ‰’« ⁄‰œ ≈‰‘«¡ «·ﬂ«∆‰
    clsString(string Value)
    {
        _Value = Value;
    }

    //  ⁄ÌÌ‰ ﬁÌ„… ÃœÌœ… ··‰’ «·Œ«’ »«·ﬂ«∆‰
    void SetValue(string Value) {
        _Value = Value;
    }

    // «·Õ’Ê· ⁄·Ï ﬁÌ„… «·‰’ «·Œ«’ »«·ﬂ«∆‰
    string GetValue() {
        return _Value;
    }

    // Œ«’Ì… (Property) ··Ê’Ê· ··ﬁÌ„… »”ÂÊ·… (·€… C++)
    __declspec(property(get = GetValue, put = SetValue)) string Value;


    // œ«·… ” « Ìﬂ:  —Ã⁄ ÿÊ· «·‰’ «·„—”· ·Â«
    static short Length(string S1)
    {
        return (short)S1.length();
    };

    //  —Ã⁄ ÿÊ· ‰’ «·ﬂ«∆‰ «·Õ«·Ì
    short Length()
    {
        return (short)_Value.length();
    };

    // œ«·… ” « Ìﬂ:  ﬁÊ„ »⁄œ «·ﬂ·„«  ›Ì ‰’ „⁄Ì‰ »‰«¡ ⁄·Ï «·›—«€« 
    static short CountWords(string S1)
    {

        string delim = " "; // «·›«’· ÂÊ «·„”«›…
        short Counter = 0;
        rsize_t pos = 0;
        string sWord;

        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // «” Œ—«Ã «·ﬂ·„…
            if (sWord != "")
            {
                Counter++;
            }
            S1.erase(0, pos + delim.length()); // „”Õ «·ﬂ·„… «· Ì  „ ⁄œÂ«
        }

        if (S1 != "")
        {
            Counter++; // ⁄œ «·ﬂ·„… «·√ŒÌ—…
        }

        return Counter;

    }

    // ⁄œ «·ﬂ·„«  ›Ì ‰’ «·ﬂ«∆‰ «·Õ«·Ì
    short CountWords()
    {
        return CountWords(_Value);
    };

    // œ«·… ” « Ìﬂ:  Ã⁄· «·Õ—› «·√Ê· „‰ ﬂ· ﬂ·„… "ﬂ»Ì—«" (Upper Case)
    static string UpperFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = (char)toupper(S1[i]);
            }
            isFirstLetter = (S1[i] == ' ' ? true : false);
        }
        return S1;
    }

    //  ÿ»Ìﬁ  ﬂ»Ì— «·Õ—› «·√Ê· ⁄·Ï ‰’ «·ﬂ«∆‰ «·Õ«·Ì „»«‘—…
    void UpperFirstLetterOfEachWord()
    {
        _Value = UpperFirstLetterOfEachWord(_Value);
    }

    // œ«·… ” « Ìﬂ:  Ã⁄· «·Õ—› «·√Ê· „‰ ﬂ· ﬂ·„… "’€Ì—«" (Lower Case)
    static string LowerFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = (char)tolower(S1[i]);
            }
            isFirstLetter = (S1[i] == ' ' ? true : false);
        }
        return S1;
    }

    //  ÿ»Ìﬁ  ’€Ì— «·Õ—› «·√Ê· ⁄·Ï ‰’ «·ﬂ«∆‰ «·Õ«·Ì
    void LowerFirstLetterOfEachWord()
    {
        _Value = LowerFirstLetterOfEachWord(_Value);
    }

    // œ«·… ” « Ìﬂ:  ÕÊÌ· «·‰’ »«·ﬂ«„· ≈·Ï √Õ—› ﬂ»Ì—…
    static string UpperAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = (char)toupper(S1[i]);
        }
        return S1;
    }

    //  ÕÊÌ· ‰’ «·ﬂ«∆‰ «·Õ«·Ì »«·ﬂ«„· ·√Õ—› ﬂ»Ì—…
    void UpperAllString()
    {
        _Value = UpperAllString(_Value);
    }

    // œ«·… ” « Ìﬂ:  ÕÊÌ· «·‰’ »«·ﬂ«„· ≈·Ï √Õ—› ’€Ì—…
    static string LowerAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = (char)tolower(S1[i]);
        }
        return S1;
    }

    //  ÕÊÌ· ‰’ «·ﬂ«∆‰ «·Õ«·Ì »«·ﬂ«„· ·√Õ—› ’€Ì—…
    void LowerAllString()
    {
        _Value = LowerAllString(_Value);
    }

    // œ«·… ” « Ìﬂ: ⁄ﬂ” Õ«·… «·Õ—› (≈–« ﬂ»Ì— Ì’»Õ ’€Ì—« Ê«·⁄ﬂ”)
    static char InvertLetterCase(char char1)
    {
        return isupper(char1) ? (char)tolower(char1) : (char)toupper(char1);
    }

    // œ«·… ” « Ìﬂ: ⁄ﬂ” Õ«·… Ã„Ì⁄ √Õ—› «·‰’ «·„—”·
    static string InvertAllLettersCase(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = InvertLetterCase(S1[i]);
        }
        return S1;
    }


    // ⁄ﬂ” Õ«·… Ã„Ì⁄ √Õ—› ‰’ «·ﬂ«∆‰ «·Õ«·Ì
    void InvertAllLettersCase()
    {
        _Value = InvertAllLettersCase(_Value);
    }

    //  ÕœÌœ ‰Ê⁄ «·√Õ—› «·„—«œ ⁄œ¯Â« (’€Ì—…° ﬂ»Ì—…° √Ê «·ﬂ·)
    enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

    // ⁄œ «·√Õ—› »‰«¡ ⁄·Ï «·›· — «·„Œ «— (ﬂ»Ì—/’€Ì—/«·ﬂ·)
    static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
    {
        if (WhatToCount == enWhatToCount::All)
        {
            return (short)S1.length();
        }

        short Counter = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
                Counter++;

            if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
                Counter++;
        }
        return Counter;
    }
    short CountLetters(enWhatToCount WhatToCount = enWhatToCount::All)
    {
        return CountLetters(_Value, WhatToCount);
    }

    // œ«·… ” « Ìﬂ: ⁄œ «·√Õ—› «·ﬂ»Ì—… ›ﬁÿ
    static short CountCapitalLetters(string S1)
    {
        short Counter = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (isupper(S1[i]))
                Counter++;
        }
        return Counter;
    }

    // ⁄œ «·√Õ—› «·ﬂ»Ì—… ›Ì ‰’ «·ﬂ«∆‰ «·Õ«·Ì
    short CountCapitalLetters()
    {
        return CountCapitalLetters(_Value);
    }

    // œ«·… ” « Ìﬂ: ⁄œ «·√Õ—› «·’€Ì—… ›ﬁÿ
    static short CountSmallLetters(string S1)
    {
        short Counter = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (islower(S1[i]))
                Counter++;
        }
        return Counter;
    }

    // ⁄œ «·√Õ—› «·’€Ì—… ›Ì ‰’ «·ﬂ«∆‰ «·Õ«·Ì
    short CountSmallLetters()
    {
        return CountSmallLetters(_Value);
    }

    // œ«·… ” « Ìﬂ: ⁄œ  ﬂ—«— Õ—› „⁄Ì‰ („⁄ ≈„ﬂ«‰Ì…  ÕœÌœ „ÿ«»ﬁ… «·Õ«·… √Ê  Ã«Â·Â«)
    static short CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
    {
        short Counter = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (MatchCase)
            {
                if (S1[i] == Letter)
                    Counter++;
            }
            else
            {
                if (tolower(S1[i]) == tolower(Letter))
                    Counter++;
            }
        }
        return Counter;
    }

    // ⁄œ Õ—› „⁄Ì‰ ›Ì ‰’ «·ﬂ«∆‰ «·Õ«·Ì
    short CountSpecificLetter(char Letter, bool MatchCase = true)
    {
        return CountSpecificLetter(_Value, Letter, MatchCase);
    }

    // œ«·… ” « Ìﬂ: «· √ﬂœ ≈–« ﬂ«‰ «·Õ—› ÂÊ Õ—› ⁄·… (Vowel)
    static bool IsVowel(char Ch1)
    {
        Ch1 =(char) tolower(Ch1);
        return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
    }

    // œ«·… ” « Ìﬂ: ⁄œ Õ—Ê› «·⁄·… ›Ì «·‰’
    static short CountVowels(string S1)
    {
        short Counter = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (IsVowel(S1[i]))
                Counter++;
        }
        return Counter;
    }

    // ⁄œ Õ—Ê› «·⁄·… ›Ì ‰’ «·ﬂ«∆‰ «·Õ«·Ì
    short CountVowels()
    {
        return CountVowels(_Value);
    }

    // œ«·… ” « Ìﬂ:  ﬁ”Ì„ «·‰’ ≈·Ï "›Ìﬂ Ê—" „‰ «·ﬂ·„«  »‰«¡ ⁄·Ï ›«’· „⁄Ì‰
    static vector<string> Split(string S1, string Delim)
    {
        vector<string> vString;
        rsize_t pos = 0;
        string sWord;

        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos);
            if (sWord != "")
            {
                vString.push_back(sWord);
            }
            S1.erase(0, pos + Delim.length());
        }

        if (S1 != "")
        {
            vString.push_back(S1);
        }
        return vString;
    }

    //  ﬁ”Ì„ ‰’ «·ﬂ«∆‰ «·Õ«·Ì ≈·Ï ﬂ·„« 
    vector<string> Split(string Delim)
    {
        return Split(_Value, Delim);
    }

    // œ«·… ” « Ìﬂ: „”Õ «·›—«€«  „‰ ÃÂ… «·Ì”«—
    static string TrimLeft(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(i, S1.length() - i);
            }
        }
        return "";
    }

    // „”Õ «·›—«€«  «·Ì”—Ï ·‰’ «·ﬂ«∆‰ «·Õ«·Ì
    void TrimLeft()
    {
        _Value = TrimLeft(_Value);
    }


    // œ«·… ” « Ìﬂ: „”Õ «·›—«€«  „‰ ÃÂ… «·Ì„Ì‰
    static string TrimRight(string S1)
    {
        for (short i = S1.length() - 1; i >= 0; i--)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(0, i + 1);
            }
        }
        return "";
    }

    // „”Õ «·›—«€«  «·Ì„‰Ï ·‰’ «·ﬂ«∆‰ «·Õ«·Ì
    void TrimRight()
    {
        _Value = TrimRight(_Value);
    }

    // œ«·… ” « Ìﬂ: „”Õ «·›—«€«  „‰ «·Ã«‰»Ì‰
    static string Trim(string S1)
    {
        return (TrimLeft(TrimRight(S1)));
    }

    // „”Õ ›—«€«  «·Ã«‰»Ì‰ ·‰’ «·ﬂ«∆‰ «·Õ«·Ì
    void Trim()
    {
        _Value = Trim(_Value);
    }

    // œ«·… ” « Ìﬂ:  Ã„Ì⁄ ﬂ·„«  «·›Ìﬂ Ê— ›Ì ‰’ Ê«Õœ „⁄ ›«’·
    static string JoinString(vector<string> vString, string Delim)
    {
        string S1 = "";
        for (string& s : vString)
        {
            S1 = S1 + s + Delim;
        }
        return S1.substr(0, S1.length() - Delim.length());
    }

    // œ«·… ” « Ìﬂ:  Ã„Ì⁄ ﬂ·„«  „’›Ê›… (Array) ›Ì ‰’ Ê«Õœ „⁄ ›«’·
    static string JoinString(string arrString[], short Length, string Delim)
    {
        string S1 = "";
        for (short i = 0; i < Length; i++)
        {
            S1 = S1 + arrString[i] + Delim;
        }
        return S1.substr(0, S1.length() - Delim.length());
    }

    // œ«·… ” « Ìﬂ: ⁄ﬂ”  — Ì» «·ﬂ·„«  ›Ì «·‰’ („À«·: "Hello World"  ’»Õ "World Hello")
    static string ReverseWordsInString(string S1)
    {
        vector<string> vString;
        string S2 = "";
        vString = Split(S1, " ");

        vector<string>::iterator iter = vString.end();
        while (iter != vString.begin())
        {
            --iter;
            S2 += *iter + " ";
        }
        S2 = S2.substr(0, S2.length() - 1);
        return S2;
    }

    // ⁄ﬂ”  — Ì» ﬂ·„«  ‰’ «·ﬂ«∆‰ «·Õ«·Ì
    void ReverseWordsInString()
    {
        _Value = ReverseWordsInString(_Value);
    }

    // œ«·… ” « Ìﬂ: «” »œ«· ﬂ·„… »ﬂ·„… √Œ—Ï œ«Œ· «·‰’
    static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
    {
        vector<string> vString = Split(S1, " ");
        for (string& s : vString)
        {
            if (MatchCase)
            {
                if (s == StringToReplace) { s = sRepalceTo; }
            }
            else
            {
                if (LowerAllString(s) == LowerAllString(StringToReplace)) { s = sRepalceTo; }
            }
        }
        return JoinString(vString, " ");
    }

    // «” »œ«· ﬂ·„… ›Ì ‰’ «·ﬂ«∆‰ «·Õ«·Ì
    string ReplaceWord(string StringToReplace, string sRepalceTo)
    {
        return ReplaceWord(_Value, StringToReplace, sRepalceTo);
    }

    // œ«·… ” « Ìﬂ: Õ–› Ã„Ì⁄ ⁄·«„«  «· —ﬁÌ„ „‰ «·‰’
    static string RemovePunctuations(string S1)
    {
        string S2 = "";
        for (short i = 0; i < S1.length(); i++)
        {
            if (!ispunct(S1[i]))
            {
                S2 += S1[i];
            }
        }
        return S2;
    }

    // Õ–› ⁄·«„«  «· —ﬁÌ„ „‰ ‰’ «·ﬂ«∆‰ «·Õ«·Ì
    void RemovePunctuations()
    {
        _Value = RemovePunctuations(_Value);
    }

};


