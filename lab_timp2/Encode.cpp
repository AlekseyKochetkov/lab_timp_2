#include "stdafx.h"
#include "Encode.h"

char* Encode::EnCode()
{
	int i = 0;
	while (Point[i] != '\0')
	{
		if (Point[i]+Key>90)
			Point[i] = Point[i] - (26 - Key);
		else
		Point[i] = Point[i] + Key;
		i++;
	}
	return Point;
}

void Encode::Error()
{
	int i = 0;
	if ((Key <= 26) && (Key>0))
		throw;
	while (Point[i] != '\0')
	{
		if ((Point[i]>=48) && (Point[i]<=57))
			throw 
		i++;
	}
}
