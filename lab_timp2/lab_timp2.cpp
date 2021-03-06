// lab_timp2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Encode.h"
#include <Windows.h>
#include <ctype.h>
#include <string>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	string k,input;
	unsigned int key;
	int i = 0, l = 0, max=26;
    char answer = '1';
	cout << "Input key." << endl;
	cin >> key;
	try
	{
	
		while (answer!='0')
		{
			cout << "Input text." << endl;
			cin.ignore();
			getline (cin, k) ;
			cout << "Do you want to encrypt or decrypt the text?" << endl;
			cout << "Encrypt - 1. Decrypt - 2. Exit - 0" << endl;
			cin >> answer;
			if (answer == '1')
			{
				Encode x(key);
				input = x.Encrypt(k);
			}
			else if (answer == '2')
			{
				Encode x(key);
				input = x.Decrypt(k);
			}
			else if (answer=='0')
			{ 
			}
			else
				throw 5;
			if(answer!='0')
			cout << input << endl;
		} 
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
					if (error == 4)
					{
						cerr << "Text input error." << endl;
						return 4;
					}
		{
			cerr << "The answer to the question is incorrect." << endl;
			return 5;
		}
	}
	return 0;
}

