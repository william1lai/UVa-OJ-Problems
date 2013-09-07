#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isPrime[1041];

int main()
{
	//generate primes first
	for (int i = 0; i < 1041; i++)
		isPrime[i] = true;

        //note that in this problem, 1 is considered prime and that 0 doesn't matter
	for (int i = 2; i < 33; i++)
	{
		if (isPrime[i])
		{
			for (int j = i*i; j < 1041; j = j + i)
				isPrime[j] = false;
		}
	}


	string word;
	while (getline(cin, word))
	{
		int sum = 0;
		for (int i = 0; i < word.length(); i++)
		{
			if (islower(word[i]))
				sum = sum + word[i] - 'a' + 1;
			else
				sum = sum + word[i] - 'A' + 27;
		}

		if (isPrime[sum])
			cout << "It is a prime word.\n";
		else
			cout << "It is not a prime word.\n";
	}
	return 0;
}