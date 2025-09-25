#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

class clsString
{
private:
	string _Value;

public:
	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static short Length(string Str)
	{
		return Str.length();
	}

	short Length()
	{
		return _Value.length();
	}

	static string UpperFirstLetterOfEachWord(string Str)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < Str.length(); i++)
		{
			if (Str[i] != ' ' && isFirstLetter)
			{
				Str[i] = toupper(Str[i]);
			}

			isFirstLetter = (Str[i] == ' ') ? true : false;
		}

		return Str;
	}

	void UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string Str)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < Str.length(); i++)
		{
			if (Str[i] != ' ' && isFirstLetter)
			{
				Str[i] = tolower(Str[i]);
			}

			isFirstLetter = (Str[i] == ' ') ? true : false;
		}

		return Str;
	}

	void LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

	static string UpperAllString(string Str)
	{
		for (short i = 0; i < Str.length(); i++)
		{
			Str[i] = toupper(Str[i]);
		}

		return Str;
	}

	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

	static string LowerAllString(string Str)
	{
		for (short i = 0; i < Str.length(); i++)
		{
			Str[i] = tolower(Str[i]);
		}

		return Str;
	}

	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}

	static char InvertLetterCase(char Letter)
	{
		return isupper(Letter) ? tolower(Letter) : toupper(Letter);
	}

	static string InvertAllLettersCase(string Str)
	{
		for (short i = 0; i < Str.length(); i++)
		{
			Str[i] = InvertLetterCase(Str[i]);
		}

		return Str;
	}

	void InvertAllLettersCase()
	{
		_Value = InvertAllLettersCase(_Value);
	}

	static short CountCapitalLetters(string Str)
	{
		short Count = 0;

		for (short i = 0; i < Str.length(); i++)
		{
			if (isupper(Str[i]))
			{
				Count++;
			}
		}

		return Count;
	}

	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static short CountSmallLetters(string Str)
	{
		short Count = 0;

		for (short i = 0; i < Str.length(); i++)
		{
			if (islower(Str[i]))
			{
				Count++;
			}
		}

		return Count;
	}

	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	enum enWhatToCount {
		SmallLetters = 0, CapitalLetters = 1, Digits = 2,
		Punctuations = 3, All = 4
	};

	static short CountCharacters(string Str, enWhatToCount WhatToCount = enWhatToCount::All)
	{
		if (WhatToCount == enWhatToCount::All)
			return Str.length();

		short Count = 0;

		for (short i = 0; i < Str.length(); i++)
		{
			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(Str[i]))
				Count++;

			else if (WhatToCount == enWhatToCount::SmallLetters && islower(Str[i]))
				Count++;

			else if (WhatToCount == enWhatToCount::Digits && isdigit(Str[i]))
				Count++;

			else if (WhatToCount == enWhatToCount::Punctuations && ispunct(Str[i]))
				Count++;
		}

		return Count;
	}

	short CountCharacters(enWhatToCount WhatToCount = enWhatToCount::All)
	{
		return CountCharacters(_Value, WhatToCount);
	}

	static short CountSpecificLetter(string Str, char Letter, bool CaseSensitive = true)
	{
		short Count = 0;

		for (short i = 0; i < Str.length(); i++)
		{
			if (CaseSensitive)
			{
				if (Str[i] == Letter)
				{
					Count++;
				}
			}
			else
			{
				if (tolower(Str[i]) == tolower(Letter))
				{
					Count++;
				}
			}
		}

		return Count;
	}

	short CountSpecificLetter(char Letter, bool CaseSensitive = true)
	{
		return CountSpecificLetter(_Value, Letter, CaseSensitive);
	}

	static bool IsVowel(char Letter)
	{
		Letter = tolower(Letter);

		return (Letter == 'a' || Letter == 'e' || Letter == 'i' || Letter == 'o' || Letter == 'u');
	}

	static short CountVowels(string Str)
	{
		short Count = 0;

		for (short i = 0; i < Str.length(); i++)
		{
			if (IsVowel(Str[i]))
			{
				Count++;
			}
		}

		return Count;
	}

	short CountVowels()
	{
		return CountVowels(_Value);
	}

	static short CountWords(string Str)
	{
		string delim = " ";
		short pos = 0;
		string Word;
		short Count = 0;

		while ((pos = Str.find(delim)) != string::npos)
		{
			Word = Str.substr(0, pos);

			if (Word != "")
				Count++;

			Str.erase(0, pos + delim.length());
		}

		if (Str != "")
			Count++;

		return Count;
	}

	short CountWords()
	{
		return CountWords(_Value);
	}

	static vector<string> Split(string Str, string Delim)
	{
		vector<string> vString;

		short pos = 0;
		string Word;

		while ((pos = Str.find(Delim)) != string::npos)
		{
			Word = Str.substr(0, pos);

			//if (Word != "")               Note: Doctor did this in OOP Bank System
			vString.push_back(Word);

			Str.erase(0, pos + Delim.length());
		}

		if (Str != "")
			vString.push_back(Str);

		return vString;
	}

	vector<string> Split(string Delim)
	{
		return Split(_Value, Delim);
	}

	static string TrimLeft(string Str)
	{
		for (short i = 0; i < Str.length(); i++)
		{
			if (Str[i] != ' ')
			{
				return Str.substr(i, Str.length() - i);
			}
		}

		return "";
	}

	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string Str)
	{
		for (short i = Str.length() - 1; i >= 0; i--)
		{
			if (Str[i] != ' ')
			{
				return Str.substr(0, i + 1);
			}
		}

		return "";
	}

	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string Str)
	{
		return TrimLeft(TrimRight(Str));
	}

	void Trim()
	{
		_Value = Trim(_Value);
	}

	static string JoinString(vector<string> vString, string Delim)
	{
		string Str = "";

		for (const string& Element : vString)
		{
			Str += Element + Delim;
		}

		return Str.substr(0, Str.length() - Delim.length());
	}

	static string JoinString(string arr[], short arrLength, string Delim)
	{
		string Str = "";

		for (short i = 0; i < arrLength; i++)
		{
			Str += arr[i] + Delim;
		}

		return Str.substr(0, Str.length() - Delim.length());
	}

	// Mine: using index
	static string ReverseWords(string Str)
	{
		vector<string> vString = Split(Str, " ");
		string NewStr = "";

		for (short i = vString.size() - 1; i >= 0; i--)
		{
			NewStr += vString[i] + " ";
		}

		return NewStr.substr(0, NewStr.length() - 1);
	}

	// Mine: using index
	void ReverseWords()
	{
		_Value = ReverseWords(_Value);
	}

	// Doctor: using iterator
	static string ReverseWordsInString(string Str)
	{
		vector<string> vString;
		vString = Split(Str, " ");

		vector<string>::iterator iter = vString.end();

		string NewStr = "";
		while (iter != vString.begin())
		{
			iter--;

			NewStr += *iter + " ";
		}

		NewStr = NewStr.substr(0, NewStr.length() - 1);

		return NewStr;
	}

	// Doctor: using iterator
	void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}

	// Using Built-In
	static string ReplaceSubStrings(string Str, string StrToReplace, string ReplaceTo)
	{
		short pos = 0;

		while ((pos = Str.find(StrToReplace, pos)) != string::npos)
		{
			Str.replace(pos, StrToReplace.length(), ReplaceTo);
			pos += ReplaceTo.length();
		}

		return Str;
	}

	// Using Built-In
	string ReplaceSubStrings(string StrToReplace, string ReplaceTo)
	{
		return ReplaceSubStrings(_Value, StrToReplace, ReplaceTo);
	}

	// Custom
	static string ReplaceWord(string Str, string StrToReplace, string ReplaceTo, bool CaseSensitive = true)
	{
		vector<string> vString = Split(Str, " ");

		for (string& Element : vString)
		{
			if (CaseSensitive)
			{
				if (Element == StrToReplace)
				{
					Element = ReplaceTo;
				}
			}
			else
			{
				if (LowerAllString(Element) == LowerAllString(StrToReplace))
				{
					Element = ReplaceTo;
				}
			}
		}

		return JoinString(vString, " ");
	}

	// Custom
	string ReplaceWord(string StrToReplace, string ReplaceTo, bool CaseSensitive = true)
	{
		return ReplaceWord(_Value, StrToReplace, ReplaceTo, CaseSensitive);
	}

	static string RemovePunctuations(string Str)
	{
		string NewStr = "";

		for (short i = 0; i < Str.length(); i++)
		{
			if (!ispunct(Str[i]))
			{
				NewStr += Str[i];
			}
		}

		return NewStr;
	}

	void RemovePunctuations()
	{
		_Value = RemovePunctuations(_Value);
	}

};
