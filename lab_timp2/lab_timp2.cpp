// lab_timp2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Encode.h"
using namespace std;
int main()
{
	char* p;
	p = new char[20];
	unsigned int key;
	int i = 0;
	cin >> p;
	cin >> key;
	Encode x(p, key);
	p = x.EnCode();
	cout << i;
	while (i<3)
	{
		cout << p[i];
		i = i++;
	}
    return 0;
}

