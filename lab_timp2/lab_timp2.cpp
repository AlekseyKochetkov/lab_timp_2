// lab_timp2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Encode.h"
#include <stdexcept>
#include <Windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	char* p;
	char c[200];
	unsigned int key;
	int i = -1,l=0;
	cin.getline(c ,200);
	cin >> key;

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

	try{
		Encode x(p, key);
		p = x.EnCode();
	}

	catch (int error)
	{
		if (error == 1)
		{
			cerr << "Key input error."<< endl;
			return 1;
		}
		else 
			if (error == 2)
			{
				cerr << "Text input error. Cannot enter numbers."<<endl;
				return 2;
			}
			
		else
		{
			cerr << "Text input error. You cannot enter non - English characters."<<endl;
			return 3;
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

