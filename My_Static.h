#pragma once

static int c = 4; //在当前文档可见

class static_test_class
{
public:

	const static int x {3};
	static int y;//在当前类/派生类可见

public:
	static_test_class(){}

	static void static_test_func()//在当前类/派生类可见
	{
		std::cout << ++y;//静态成员函数 只能访问静态成员对象
	}

	void func_1()
	{
		static int m = 3;//在当前函数可见
		std::cout << ++m;
	}
};

int static_test_class::y = 2;//静态非const成员函数在类外初始化

class static_son_class : public static_test_class
{

};

void static_test()
{
	static_test_class* stc = new static_test_class();
	static_test_class* ssc = new static_son_class();

	stc->func_1();
	ssc->func_1();
	stc->static_test_func();
	ssc->static_test_func();
	std::cout << static_son_class::y;
	std::cout << static_test_class::y;
	static_test_class::y = 3;
	std::cout << static_son_class::y;
	std::cout << static_test_class::y;
}