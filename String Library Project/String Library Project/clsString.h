#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class clsString
{

private:

	string _Value;
	enum enWhatToCount { CapitalLetters = 0, SmallLetters = 1, AllLetters = 2 };

public:

	clsString() {
		_Value = "";
	}

	clsString(string Value) {
		_Value = Value;
	}

	void SetValue(string Value) {
		_Value = Value;
	}

	string GetValue() {
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static short Length(string S1) {
		return S1.length();
	}

	short Length() {
		return Length(_Value);
	}

	static void FirstLetterOfString(string S1) {
		cout << "\nFirst Letter of this string : \n";
		bool isFirstLetter = true;

		for (int i = 0; i < S1.length();i++) {
			if (S1[i] != ' ' && isFirstLetter)
			{
				cout << S1[i] << endl;
			}
			isFirstLetter = S1[i] == ' ' ? true : false;
		}
	}

	void FirstLetterOfString() {
		FirstLetterOfString(_Value);
	}

	static string UpperFirstLetterOfEachWord(string S1) {
		bool isFirstLetter = true;
		for (int i = 0; i < S1.length();i++) {
			if (S1[i] != ' ' && isFirstLetter) {
				S1[i] = toupper(S1[i]);
			}
			isFirstLetter = S1[i] == ' ' ? true : false;
		}
		return S1;
	}

	void UpperFirstLetterOfEachWord() {
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string S1) {
		bool isFirstLetter = true;
		for (int i = 0; i < S1.length();i++) {
			if (S1[i] != ' ' && isFirstLetter) {
				S1[i] = tolower(S1[i]);
			}
			isFirstLetter = S1[i] == ' ' ? true : false;
		}
		return S1;
	}

	void LowerFirstLetterOfEachWord() {
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

	static string UpperAllString(string S1) {
		for (short i = 0; i < S1.length();i++) {
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}

	void UpperAllString() {
		_Value = UpperAllString(_Value);
	}

	static string LowerAllString(string S1) {
		for (short i = 0; i < S1.length();i++) {
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}

	void LowerAllString() {
		_Value = LowerAllString(_Value);
	}

	static char InvertLetterCase(char Letter) {
		return isupper(Letter) ? tolower(Letter) : toupper(Letter);
	}

	static string InvertAllLettersCase(string S1) {
		for (short i = 0; i < S1.length(); i++) {
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;
	}

	void InvertAllLettersCase() {
		_Value = InvertAllLettersCase(_Value);
	}

	static short CountAllLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::AllLetters) {

		short Counter = 0;

		if (WhatToCount == enWhatToCount::AllLetters)
			return S1.length();

		for (short i = 0;i < S1.length();i++) {

			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
				Counter++;

			if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
				Counter++;

		}

		return Counter;
	}

	short CountAllLetters() {
		return CountAllLetters(_Value);
	}

	static short CountSmallLetters(string S1) {
		short Counter = 0;
		for (short i = 0; i < S1.length();i++) {
			if (islower(S1[i]))
				Counter++;
		}
		return Counter;
	}

	short CountSmallLetters() {
		return CountSmallLetters(_Value);
	}

	static short CountCapitalLetters(string S1) {
		short Counter = 0;
		for (short i = 0; i < S1.length();i++) {
			if (isupper(S1[i]))
				Counter++;
		}
		return Counter;
	}

	short CountCapitalLetters() {
		return CountCapitalLetters(_Value);
	}

	static short CountSpecificLetter(string S1, char Letter, bool MatchCase = true) {

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (MatchCase) {
				if (S1[i] == Letter)
					Counter++;
			}
			else
				if (tolower(S1[i]) == tolower(Letter))
					Counter++;
		}

		return Counter;
	}

	short CountSpecificLetter(char Letter, bool MatchCase = true) {
		return CountSpecificLetter(_Value, Letter, MatchCase);
	}

	static bool IsVowel(char Letter) {

		Letter = tolower(Letter);
		return (Letter == 'a' || Letter == 'e' || Letter == 'i' || Letter == 'o' || Letter == 'u');
	}

	static short CountVowels(string S1) {
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++) {
			if (IsVowel(S1[i]))
				Counter++;
		}

		return Counter;

	}

	short CountVowels() {
		return CountVowels(_Value);
	}

	static void PrintVowels(string S1) {

		cout << "\nVowels in string are : ";

		for (short i = 0; i < S1.length(); i++) {
			if (IsVowel(S1[i]))
				cout << S1[i] << "  ";
		}

	}

	void PrintVowels() {
		PrintVowels(_Value);
	}

	static void PrintEachWord(string S1)
	{
		string delim = " ";
		short pos = 0;
		string sWord;

		while ((pos = S1.find(delim)) != string::npos) {

			sWord = S1.substr(0, pos);

			if (sWord != "")
				cout << sWord << endl;

			S1.erase(0, pos + delim.length());

		}

		if (S1 != "")
			cout << S1 << endl;
	}

	void PrintEachWord() {
		PrintEachWord(_Value);
	}

	static short CountWords(string S1) {
		short pos = 0;
		string Word;
		string delim = " ";
		short Counter = 0;

		while ((pos = S1.find(delim)) != std::string::npos) {

			Word = S1.substr(0, pos);

			if (Word != "")
				Counter++;

			S1.erase(0, pos + delim.length());
		}
		if (S1 != "")
			Counter++;

		return Counter;
	}

	short CountWords() {
		return CountWords(_Value);
	}

	static vector <string> Split(string S1, string delimiter) {

		vector <string> Split;
		string sWord;
		short pos = 0;

		while ((pos = S1.find(delimiter)) != string::npos) {
			sWord = S1.substr(0, pos);

			if (sWord != "") {
				Split.push_back(sWord);
			}

			S1.erase(0, pos + delimiter.length());

		}

		if (S1 != "")
		{
			Split.push_back(S1);
		}

		return Split;
	}

	vector <string> Split(string delimiter) {
		return Split(_Value, delimiter);
	}

	static string TrimLeft(string S1) {
		for (short i = 0; i < S1.length();i++) {
			if (S1[i] != ' ') {
				return S1.substr(i, S1.length() - 1);
			}
		}
		return "";
	}

	void TrimLeft() {
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string S1) {
		for (short i = S1.length() - 1; i >= 0;i--) {
			if (S1[i] != ' ') {
				return S1.substr(0, i + 1);
			}
		}
		return "";
	}

	void TrimRight() {
		_Value =  TrimRight(_Value);
	}

	static string Trim(string S1) {

		return TrimLeft(TrimRight(S1));
	}

	void Trim() {
		_Value = Trim(_Value);
	}

	static string JoinString(vector <string> Join, string delim) {
		string S1 = "";

		for (string& s : Join) {
			S1 += s + delim;
		}
		return S1.substr(0, S1.length() - delim.length());

	}

	static string JoinString(string arr[100], short arrLength, string delim) {
		string S1 = "";
		for (short i = 0; i < arrLength; i++) {
			S1 = S1 + arr[i] + delim;
		}

		return S1.substr(0, S1.length() - delim.length());
	}

	static string ReverseWords(string S1) {

		vector <string> vString;

		vString = Split(S1, " ");
		string S2 = "";

		vector <string>::iterator iter = vString.end();

		while (iter != vString.begin()) {

			iter--;

			S2 = S2 + *iter + " ";


		}

		return S2.substr(0, S2.length() - 1);
	}

	void ReverseWords() {
		_Value = ReverseWords(_Value);
	}

	static string ReplaceWord(string S1, string StringToReplace, string ReplaceTo) {

		short pos = S1.find(StringToReplace);

		while (pos != std::string::npos) {

			S1 = S1.replace(pos, StringToReplace.length(), ReplaceTo);
			pos = S1.find(StringToReplace);

		}

		return S1;
	}

	void ReplaceWord(string StringToReplace, string ReplaceTo) {
		_Value = ReplaceWord(_Value, StringToReplace,ReplaceTo);
	}

	// Punctuations are: . , ; : ? ! " '
	static string RemovePunctuations(string S1) {

		string S2 = "";

		for (short i = 0; i < S1.length();i++) {

			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			}
		}

		return S2;
	}

	void RemovePunctuations() {
		_Value = RemovePunctuations(_Value);
	}

	
};

