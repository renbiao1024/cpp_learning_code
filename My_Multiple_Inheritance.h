#pragma once
class Grandfather
{
public:
	void SameName() {}
};

class Father_1: virtual public Grandfather //虚继承防止菱形继承导致的多祖父问题
{
};

class Father_2: virtual public Grandfather
{

};

class Son :public Father_1, public Father_2
{
	
};

void Multiple_Inheritance_Test()
{
	Son* s = new Son;
	s->Father_1::SameName();//使用 :: 使调用的同名函数明确
}