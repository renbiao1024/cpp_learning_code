#pragma once
#include <iostream>

#define m (2) //简单的字符替换，多份拷贝
const int n = 2; // 数据类型检测，一份拷贝

class const_class
{
public:
	const int x = 2;
	int y {1};
	mutable int s = 2;

	const void func1()
	{
		std::cout << x; 
	}

	void func2(const int c)
	{
		y = c;
	}

	void func3()const //不能修改 成员对象 除非 mutable修饰
	{
		std::cout << ++s; 
	}

	void func4()
	{
		int v = 0;
		//const 可以修饰左值/右值 表示常量
		const int p = 0;
		const int&& k = 9;

		//const引用 能引用一切
		const int& s = v;
		const int& f = p;
		const int& a = k;

		//常量指针 不能修改指向的内容，能指向一切
		int const * pc = &v;
		int const * po = &p;
		int const * ph = &k;

		//指针常量 不能修改指向，能修改内容
		int *const pd = &v;

		int* f = const_cast<int*>(pc);
	}
};