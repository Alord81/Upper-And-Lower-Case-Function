#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadText(string Message)
{
	string Text;
	cout << Message;
	getline(cin, Text);

	return Text;
}

short changeToNumber(char Char)
{
	return int(Char);
}

char ChangeToChar(short Number)
{
	return char(Number);
}

bool IsInRange(char Char, short From, short To)
{
	return changeToNumber(Char) >= From && changeToNumber(Char) <= To;
}

string AppendAllLettersInOneSting(vector <char> & vLetters)
{
	string TheText;
	for (char& Letter : vLetters)
		TheText += Letter;
	return TheText;
}

string Upper_Case(string text)
{
	string TheText = "";
	vector <char> vLetters;
	for (int i = 0; i < text.length(); i++)
	{
		if (IsInRange(text[i], 97, 122))
			vLetters.push_back(ChangeToChar(changeToNumber(text[i]) - 32));
		else
			vLetters.push_back(text[i]);
	}

	TheText = AppendAllLettersInOneSting(vLetters);
	return TheText;
}

string Lower_Case(string text)
{
	string TheText = "";
	vector <char> vLetters;
	for (int i = 0; i < text.length(); i++)
	{
		if (IsInRange(text[i], 65, 90))
			vLetters.push_back(ChangeToChar(changeToNumber(text[i]) + 32));
		else
			vLetters.push_back(text[i]);
	}

	for (char &Letter : vLetters)
		TheText += Letter;

	TheText = AppendAllLettersInOneSting(vLetters);
	return TheText;
}

int main()
{

	string Text = ReadText("Please enter a text : ");
	cout << "The Normal Text : " << Text << endl;
	cout << "In Upper Case   : " << Upper_Case(Text) << endl;
	cout << "In Lower Case   : " << Lower_Case(Text) << endl;

	return 0;
}