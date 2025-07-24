#include <iostream>
#include "clsString.h"

using namespace std;

int main()
{
	clsString Test("Abdullah Muhammed Hassan Sayed");
	
	// Some Examples
	

	// Print number of vowels in the string
	cout << "Number Of Vowels : " << Test.CountVowels() << endl;


	// Print total number of letters in the string
	cout << "Number Of All Letters : " << Test.CountAllLetters() << endl;


	// Print number of words in the string
	cout << "Number Of Words : " << Test.CountWords() << endl;

	// Make the first letter of each word lowercase
	Test.LowerFirstLetterOfEachWord();
	cout << "Lower First Letter Of Each Word : " << Test.Value << endl;
	
	// Make the first letter of each word uppercase
	Test.UpperFirstLetterOfEachWord();
	cout << "Upper First Letter Of Each Word : " << Test.Value << endl;

	// Reverse the order of words
	Test.ReverseWords();
	cout << "Reversed : " << Test.Value << endl;



	system("pause>0");
	return 0;
}