// lab_timp2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Encode.h"
#include <stdexcept>
#include <Windows.h>
#include <ctype.h>
#include <string>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	string k;
	unsigned int key;
	int i = 0, l = 0, answer;
	cout << "Input text." << endl;
	cout << "Input key." << endl;
	getline(cin, k);
	cin >> key;
	cout << "Do you want to encrypt or decrypt the text?" << endl;
	cout << "Encrypt - 1. Decrypt - 2." << endl;
	cin >> answer;

	try
	{
		if (answer == 1)
		{
			Encode x (key);
			k = x.Code(k);
		}
		else if (answer == 2)
		{
				Encode x(key);
				k = x.UnCode(k);
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

		cout << k << endl;
    return 0;
}

