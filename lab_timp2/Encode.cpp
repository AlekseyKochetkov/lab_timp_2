#include "stdafx.h"
#include <ctype.h>
#include <string>
#include "Encode.h"
#include <iostream>
using namespace std;


string Encode::Encrypt(const string Text)
{
	Encrypt_Error(Text);
	int i = 0;
	text=Deleted(Text);
	text=Up(text);
	while (text[i] != '\0')
	{
		if (text[i]+Key>'Z')
			text[i] = text[i] - (max - Key);
		else
			text[i] = text[i] + Key;
		i++;
	}
	return string(text);
}

string Encode::Decrypt(const string Text)
{
	Decrypt_Error(Text);
	int i = 0;
	text = Text;
	while (text[i] != '\0')
	{
		if ((text[i] - Key)<'A')
			text[i] = text[i] + (max - Key);
		else
			text[i] = text[i] - Key;
		i++;
	}
	return string(text);
}

void Encode::Encrypt_Error(string Text)
{
	KeyError();
	int i = 0;
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

void Encode::Decrypt_Error(const string Text)
{
	KeyError();
	int i = 0;
	while (Text[i] != '\0')
	{
		if ((Text[i] >= 'A') && (Text[i] <= 'Z'))
		{ 
		}
		else
			throw 4;
		i++;
	}
}

void Encode::KeyError()
{
	if ((Key >= max) | (Key <= 0))
		throw 1;
}

string Encode::Deleted(string Text)
{
	int i = 0;
	text = Text;
	while (text[i] != '\0')
	{
		if (((text[i] >= 'A') && (text[i] <= 'Z')) | ((text[i] >= 'a') && (text[i] <= 'z')))
		{
			i++;
		}
		else
		{
		text.erase(i, 1);
	    }
	}
	return string(text);
}

string Encode::Up(string text)
{
	int i = 0;
	while (text[i] != '\0')
	{
		text[i] = toupper(text[i]);
		i++;
	}
	return string(text);
}


