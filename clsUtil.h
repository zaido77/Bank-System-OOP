#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include "clsDate.h"
using namespace std;

class clsUtil
{
public:
    enum enCharType {
        SmallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5
    };

    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    static int RandomNumber(int From, int To)
    {
        return rand() % (To - From + 1) + From;
    }

    static char GetRandomCharacter(enCharType CharType)
    {
        if (CharType == enCharType::MixChars)
            CharType = (enCharType)RandomNumber(1, 3);

        switch (CharType)
        {
        case enCharType::SmallLetter:
            return char(RandomNumber(97, 122));
        case enCharType::CapitalLetter:
            return char(RandomNumber(65, 90));
        case enCharType::SpecialCharacter:
            return char(RandomNumber(33, 47));
        case enCharType::Digit:
            return char(RandomNumber(48, 57));
        default:
            return char(RandomNumber(65, 90));
        }
    }

    static string GenerateWord(enCharType CharType, short Length)
    {
        string Word = "";

        for (short i = 1; i <= Length; i++)
        {
            Word += GetRandomCharacter(CharType);
        }

        return Word;
    }

    static string GenerateKey(enCharType CharType = enCharType::CapitalLetter)
    {
        string Key = "";

        Key = GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4);

        return Key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType = enCharType::CapitalLetter)
    {
        for (short i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key[" << i << "] : " << GenerateKey(CharType) << "\n";
        }
    }

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {
        for (short i = 0; i < arrLength; i++)
        {
            arr[i] = RandomNumber(From, To);
        }
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short WordLength)
    {
        for (short i = 0; i < arrLength; i++)
        {
            arr[i] = GenerateWord(CharType, WordLength);
        }
    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (short i = 0; i < arrLength; i++)
        {
            arr[i] = GenerateKey(CharType);
        }
    }

    static void Swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(double& A, double& B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(string& A, string& B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(clsDate& A, clsDate& B)
    {
        clsDate::SwapDates(A, B);
    }

    static void ShuffleArray(int arr[100], int arrLength)
    {
        for (short i = 0; i < arrLength; i++)
            Swap(arr[RandomNumber(0, arrLength - 1)],
                arr[RandomNumber(0, arrLength - 1)]); // Random(1, arrLength) - 1
    }

    static void ShuffleArray(string arr[100], int arrLength)
    {
        for (short i = 0; i < arrLength; i++)
            Swap(arr[RandomNumber(0, arrLength - 1)],
                arr[RandomNumber(0, arrLength - 1)]); // Random(1, arrLength) - 1
    }

    static string Tabs(short NumberOfTabs)
    {
        string t = "";

        for (short i = 0; i < NumberOfTabs; i++)
            t += "\t";

        return t;
    }

    static string EncryptText(string Text, short EncryptionKey = 2)
    {
        for (short i = 0; i <= Text.length() - 1; i++)
        {
            Text[i] = char(int(Text[i]) + EncryptionKey);
        }

        return Text;
    }

    static string DecryptText(string Text, short EncryptionKey = 2)
    {
        for (short i = 0; i <= Text.length() - 1; i++)
        {
            Text[i] = char(int(Text[i]) - EncryptionKey);
        }

        return Text;
    }

    enum enColors
    {
        Black = 0, Gray = 8,
        Blue = 1, LightBlue = 9,
        Green = 2, LightGreen = 10,
        Aqua = 3, LightAqua = 11,
        Red = 4, LightRed = 12,
        Purple = 5, LightPurple = 13,
        Yellow = 6, LightYellow = 14,
        White = 7, BrightWhite = 15
    };

    static void ResetScreen()
    {
        system("color 0F");
        system("cls");
    }

    static void ColorScreen(enColors Text = White, enColors Background = Black)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        WORD color = (Background << 4) | Text;
        SetConsoleTextAttribute(hConsole, color);
    }

    static string ColorToString(enColors Color)
    {
        switch (Color)
        {
        case enColors::Black: return "Black";
        case enColors::Gray: return "Gray";
        case enColors::Blue: return "Blue";
        case enColors::LightBlue: return "Light Blue";
        case enColors::Green: return "Green";
        case enColors::LightGreen: return "Light Green";
        case enColors::Aqua: return "Aqua";
        case enColors::LightAqua: return "Light Aqua";
        case enColors::Red: return "Red";
        case enColors::LightRed: return "Light Red";
        case enColors::Purple: return "Purple";
        case enColors::LightPurple: return "Light Purple";
        case enColors::Yellow: return "Yellow";
        case enColors::LightYellow: return "Light Yellow";
        case enColors::White: return "White";
        case enColors::BrightWhite: return "Bright White";
        }

    }

    static enColors StringToColor(string ColorName)
    {
        ColorName = clsString::LowerAllString(ColorName);

        if      (ColorName == "black")         return enColors::Black;
        else if (ColorName == "gray")          return enColors::Gray;
        else if (ColorName == "blue")          return enColors::Blue;
        else if (ColorName == "light blue")    return enColors::LightBlue;
        else if (ColorName == "green")         return enColors::Green;
        else if (ColorName == "light green")   return enColors::LightGreen;
        else if (ColorName == "aqua")          return enColors::Aqua;
        else if (ColorName == "light aqua")    return enColors::LightAqua;
        else if (ColorName == "red")           return enColors::Red;
        else if (ColorName == "light red")     return enColors::LightRed;
        else if (ColorName == "purple")        return enColors::Purple;
        else if (ColorName == "light purple")  return enColors::LightPurple;
        else if (ColorName == "yellow")        return enColors::Yellow;
        else if (ColorName == "light yellow")  return enColors::LightYellow;
        else if (ColorName == "white")         return enColors::White;
        else if (ColorName == "bright white")  return enColors::BrightWhite;
    }

    static string NumberToText(int Number)
    {
        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One", "Two", "Three", "Four", "Five", "Six",
            "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
            "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Ninteen" };

            return arr[Number] + " ";
        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "", "", "Twenty", "Thirty", "Fourty", "Fifty",
                            "Sixty", "Seventy", "Eighty", "Ninty" };

            return arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 999)
        {
            return NumberToText(Number / 100) + "Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 999999)
        {
            return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 999999999)
        {
            return NumberToText(Number / 1000000) + "Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 999999999999)
        {
            return NumberToText(Number / 1000000000) + "Billion " + NumberToText(Number % 1000000000);
        }

    }

    static string GetSystemTime()
    {
        time_t t = time(0);
        tm* now = localtime(&t);

        string Hour = to_string(now->tm_hour);
        string Minute = to_string(now->tm_min);
        string Second = to_string(now->tm_sec);

        return Hour + ":" + Minute + ":" + Second;
    }

};
