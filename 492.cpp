#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isVowel(char c)
{
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' 
		|| c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

string pigLatin(string word)
{
	if (isVowel(word[0]))
		return word + "ay";
	else
		return word.substr(1, word.length() - 1) + word[0] + "ay";
}

int main()
{
	string line;
	while (getline(cin, line))
	{
		int index = 0;
		string word = "";
		while (index < line.length())
		{
			while (isalpha(line[index]))
			{
				word = word + line[index];
				index++;

				if (index >= line.length())
					break;
			}
			cout << pigLatin(word);
			word = "";
			while (!isalpha(line[index]))
			{
				cout << line[index];
				index++;

				if (index >= line.length())
					break;
			}
		}
		
		cout << endl;
	}
	return 0;
}