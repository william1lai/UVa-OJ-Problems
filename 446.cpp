#include <iostream>
#include <string>

using namespace std;

string hexTobin(string hex)
{
	string bin = "";
	bool neg = false;
	for (int i = 0; i < hex.length(); i++)
	{
		char c = hex[i];
		switch (c)
		{
		case '-': neg = true; break;
		case '0': bin = bin + "0000"; break;
		case '1': bin = bin + "0001"; break;
		case '2': bin = bin + "0010"; break;
		case '3': bin = bin + "0011"; break;
		case '4': bin = bin + "0100"; break;
		case '5': bin = bin + "0101"; break;
		case '6': bin = bin + "0110"; break;
		case '7': bin = bin + "0111"; break;
		case '8': bin = bin + "1000"; break;
		case '9': bin = bin + "1001"; break;
		case 'A': bin = bin + "1010"; break;
		case 'B': bin = bin + "1011"; break;
		case 'C': bin = bin + "1100"; break;
		case 'D': bin = bin + "1101"; break;
		case 'E': bin = bin + "1110"; break;
		case 'F': bin = bin + "1111"; break;
		}
	}
	for (int i = 0; i < 3 - hex.length() + neg; i++)
		bin = "0000" + bin;
	bin = "0" + bin;

	if (neg)
	{
		for (int i = 0; i < bin.length(); i++)
		{
			if (bin[i] == '0')
				bin[i] = '1';
			else bin[i] = '0';
		}

		for (int i = bin.length() - 1; i >= 0; i--)
		{
			if (bin[i] == '0')
			{
				bin[i] = '1';
				break;
			}
			else
			{
				bin[i] = '0';
			}
		}
	}

	return bin;
}

int hexTodec(string hex)
{
	int dec = 0;
	bool neg = false;
	for (int i = 0; i < hex.length(); i++)
	{
		dec = dec*16;
		char c = hex[i];
		switch (c)
		{
		case '-': neg = true; break;
		case '0': break;
		case '1': dec = dec + 1; break;
		case '2': dec = dec + 2; break;
		case '3': dec = dec + 3; break;
		case '4': dec = dec + 4; break;
		case '5': dec = dec + 5; break;
		case '6': dec = dec + 6; break;
		case '7': dec = dec + 7; break;
		case '8': dec = dec + 8; break;
		case '9': dec = dec + 9; break;
		case 'A': dec = dec + 10; break;
		case 'B': dec = dec + 11; break;
		case 'C': dec = dec + 12; break;
		case 'D': dec = dec + 13; break;
		case 'E': dec = dec + 14; break;
		case 'F': dec = dec + 15; break;
		}
	}
	if (neg)
		return -dec;
	return dec;
}

int main()
{
	int ncases;
	cin >> ncases;
	cin.ignore(1000, '\n');

	for (int i = 0; i < ncases; i++)
	{
		string f;
		string s;
		string op;

		cin >> f >> op >> s;
		cin.ignore(1000, '\n');

		string b1 = hexTobin(f);
		string b2 = hexTobin(s);
		int d1 = hexTodec(f);
		int d2 = hexTodec(s);
		
		cout << b1 << " " + op << " " << b2 << " = ";

		if (op == "+")
			cout << (d1 + d2) << "\n";
		else
			cout << (d1 - d2) << "\n";
	}
	return 0;
}