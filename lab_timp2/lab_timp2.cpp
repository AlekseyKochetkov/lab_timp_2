// lab_timp2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Encode.h"
using namespace std;
int main()
{
	char* p;
	char c[200];
	unsigned int key;
	int i = -1,l=0;
	cin >> c;
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

	Encode x(p, key);
	p = x.EnCode();

	i = 0;
	while (i!=l)
	{
		cout << p[i];
		i = i++;
	}
	delete[] p;
    return 0;
}

