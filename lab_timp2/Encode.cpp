#include "stdafx.h"
#include <ctype.h>
#include <string>
#include "Encode.h"
using namespace std;


string Encode::Code(string Text)
{
	Error(Text);
	int i = 0;
	Text=Deleted(Text);
	Text=Up(Text);
	while (Text[i] != '\0')
	{
		if (Text[i]+Key>'Z')
			Text[i] = Text[i] - (26 - Key);
		else
			Text[i] = Text[i] + Key;
		i++;
	}
	return string(Text);
}

string Encode::UnCode(string Text)
{
	Error(Text);
	int i = 0;
	Text=Deleted(Text);
	Text=Up(Text);
	while (Text[i] != '\0')
	{
		if (Text[i] - Key<'A')
			Text[i] = Text[i] + (26 - Key);
		else
			Text[i] = Text[i] - Key;
		i++;
	}
	return string(Text);
}

void Encode::Error(string Text)
{
	int i = 0;
	if ((Key >= 26) | (Key<0))
		throw 1;
	while (Text[i] != '\0')
	{
		if ((Text[i] >= '0') && (Text[i] <= '9'))
			throw 2;
		i++;
	}
	i = 0;
	while (Text[i] != '\0')
	{
		if ( ( (Text[i] >= 'À' ) && (Text[i] <= 'ÿ') ) | (Text[i] <= '¨') | (Text[i] <= '¸'))
			throw 3;
		i++;
	}
}

string Encode::Deleted(string Text)
{
	int i = 0;
	while (Text[i] != '\0')
	{
		if (((Text[i] >= 'A') && (Text[i] <= 'Z')) | ((Text[i] >= 'a') && (Text[i] <= 'z')))
		{
		}
		else
		{
        Text.erase(i, 1);
		i = i - 1;
	    }
		i++;
	}
	return string(Text);
}

string Encode::Up(string Text)
{
	int i = 0;
	while (Text[i] != '\0')
	{
		Text[i] = toupper(Text[i]);
		i++;
	}
	return string(Text);
}


