#pragma once
#include <iostream>
inline void func_inline()
{
	std::cout << "inline";
}

class MyClass
{
public:
//类内函数自动inline
	MyClass(){}
	~MyClass(){}

private:

};
