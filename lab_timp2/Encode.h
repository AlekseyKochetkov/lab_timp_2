#pragma once
#include <string>
using namespace std;
class Encode
{
public:
	Encode(const int key):Key(key){}
	string Code(string Text);
	string UnCode(string Text);
private:
	int Key;
	void Error(const string Text);
	string Deleted(string Text);
	string Up(string Text);
};

