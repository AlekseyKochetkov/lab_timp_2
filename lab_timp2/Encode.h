#pragma once
class Encode
{
public:
	char* Point;
	Encode(char* p , const int key): Point(p), Key(key){}
	char* EnCode();
private:
	int Key;
	void Error();
};

