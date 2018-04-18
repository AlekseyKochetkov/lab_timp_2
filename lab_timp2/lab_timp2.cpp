// lab_timp2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Encode.h"
#include <stdexcept>
#include <Windows.h>
#include <ctype.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	char* p;
	char c[200];
	unsigned int key;
	int i = -1, l = 0, answer;
	cout << "Input text." << endl;
	cout << "Input key." << endl;
	cin.getline(c, 200);
	cin >> key;
	cout << "Do you want to encrypt or decrypt the text?." << endl;
	cout << "Encrypt - 1. Decrypt - 2." << endl;
	cin >> answer;

	do
	{
		i = i++;
		l = l++;
	} while (c[i] != '\0');

	p = new char[l];
	i = -1;
	do
	{
		i = i++;
		p[i] = c[i];
	} while (c[i] != '\0');

	try
	{
		if (answer == 1)
		{
			Encode x(p, key);
			p = x.Code();
		}
		else if (answer == 2)
		{
				Encode x(p, key);
				p = x.UnCode();
		}
		else
			throw 4;
	}
	catch (int error)
	{
		if (error == 1)
		{
			cerr << "Key input error." << endl;
			return 1;
		}
		else
			if (error == 2)
			{
				cerr << "Text input error. Cannot enter numbers." << endl;
				return 2;
			}

			else
				if (error == 3)
			{
				cerr << "Text input error. You cannot enter non - English characters." << endl;
				return 3;
			}
				else
				{
					cerr << "The answer to the question is incorrect." << endl;
					return 4;
				}


	}
	i = 0;
	while (i!=l)
	{
		cout << p[i];
		i = i++;
	}
	delete[] p;
	
    return 0;
}

