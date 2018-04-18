#include "stdafx.h"
#include "Encode.h"

char* Encode::EnCode()
{
	int i = 0;
	while (Point[i] != '\0')
	{
		Point[i] = Point[i] + Key;
		i++;
	}
	return Point;
}
