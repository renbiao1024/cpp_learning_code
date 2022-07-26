#pragma once

//extern
extern "C" void c_func(){} //按照c的规则表达函数

extern int a = 0;//外部变量，只能在一个文件里定义

//explicit
class Explicit_Class
{
public:
	explicit Explicit_Class(Explicit_Class& a){}
};

//constexpr 验证变量/函数是不是一个常量，以便于优化
constexpr int func_int(){return 1;}

//volatatile 每次从内存中取用
volatile int vo_a;

//mutable 可修改的
class mutable_class
{
	mutable int mu_a;
	int com_a;
	int func_mutable()const
	{
		mu_a ++;
		//com_a ++;
	}
};
