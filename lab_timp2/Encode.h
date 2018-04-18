#pragma once
class Encode
{
public:
	char* Point;
	Encode(char* p , const int key): Point(p), Key(key){}
	char* Code();
	char* UnCode();
private:
	int Key;
	void Error();
	void Deleted();
	void Up();
};

