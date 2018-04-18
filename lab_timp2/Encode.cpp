#include "stdafx.h"
#include "Encode.h"
#include <ctype.h>


char* Encode::Code()
{
	Error();
	int i = 0;
	Deleted();
	Up();
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

char * Encode::UnCode()
{
	Error();
	int i = 0;
	Deleted();
	Up();
	while (Point[i] != '\0')
	{
		if (Point[i] - Key<65)
			Point[i] = Point[i] + (26 - Key);
		else
			Point[i] = Point[i] - Key;
		i++;
	}
	return Point;
}

void Encode::Error()
{
	int i = 0;
	if ((Key >= 26) | (Key<0))
		throw 1;
	while (Point[i] != '\0')
	{
		if ((Point[i] >= 48) && (Point[i] <= 57))
			throw 2;
		i++;
	}
	i = 0;
	while (Point[i] != '\0')
	{
		if ( ( (Point[i] >= 'À' ) && (Point[i] <= 'ÿ') ) | (Point[i] <= '¨') | (Point[i] <= '¸'))
			throw 3;
		i++;
	}
}

void Encode::Deleted()
{
	int i = 0;
	int j = 0;
	while (Point[i] != '\0')
	{
		if (((Point[i] >= 65) && (Point[i] <= 90)) | ((Point[i] >= 97) && (Point[i] <= 122)))
		{
		}
		else
		{
	      j = i - 1;
		     while (Point[i] != '\0')
		    {
				 Point[i] = Point[i + 1];
			   i++;
		    }
		  i = j;
	    }
		i++;
	}
}

void Encode::Up()
{
	int i = 0;
	while (Point[i] != '\0')
	{
		Point[i] = toupper( Point[i]);
		i++;
	}
}

