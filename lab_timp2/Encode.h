#pragma once
#include <string>
using namespace std;
class Encode
{
public:
	Encode(const int key):Key(key){}
	string Encrypt(const string Text);
	string Decrypt(const string Text);
private:
	int max = 26;
	string text;
	int Key;
	void Encrypt_Error(const string Text);
	void Decrypt_Error(const string Text);
	void KeyError();
	string Deleted(string Text);
	string Up(string text);
};

