#pragma once
class Encode
{
public:
	char* Point;
	int Key;
	Encode(char* p , const int key): Point(p), Key(key){}
	char* EnCode();
};

