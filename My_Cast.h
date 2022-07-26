#pragma once
#include <cstdlib>
#include <iostream>
class father
{
public:
	virtual void func_father(){}
};

class son : public father
{
public:
	void func_son(){}
};

void Cast_test()
{
	int a = 0;
	double b = 123.2;

	father f;
	son s;
	father* fa = new father;
	son* so = new son;

	void* v;
	double* d = &b;
	int* ap = &a;

	a = static_cast<int>(b); //static_cast支持基本类型转换
	f = static_cast<father>(s);	
	//s = static_cast<son>(f); //static_cast不支持父类向子类转换
	//支持父类向子类指针类型的显示转换
	fa = static_cast<father*>(so);
	so = static_cast<son*>(fa);

	//dynamic_cast 仅支持指针类型的转换，允许安全的向上转换
	fa = dynamic_cast<father*>(so);
	so = dynamic_cast<son*>(fa);

	//reinterprinter_cast 支持低级转换 ，不同指针的转换，int和指针的转换
	d = reinterpret_cast<double*>(v);
	ap = reinterpret_cast<int*>(d);
	a = reinterpret_cast<int>(d);
}