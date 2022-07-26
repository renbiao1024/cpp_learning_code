#pragma once
#include <utility>
#include <iostream>
int func()
{
	return 2;
}

class rA
{
public:
//移动语义，转移内存的所有权

	//拷贝构造,复制，传入，销毁3步
	rA(rA& a) {}
	
	//移动构造
	rA(rA&& a)noexcept
	{
		std::cout << "move construct";
	}

	//拷贝赋值
	rA& operator=(rA& a){}

	//移动赋值
	rA& operator=(rA&& a)noexcept
	{
		std::cout << "move operator = ";
	}
};



void RValue_Test()
{
	int val = 1;

	//左值引用，别名
	int& l_val = val;

	//右值引用，延长生命周期， = move左值/无名变量/函数返回值
	int&& r_val = std::move(l_val);
	int&& r_num = 3;
	int&& r_returnVal = func();

	//常引用 + 左值。右值，不能修改引用的值
	const int& c_Lval_l = val;
	const int& c_Lval_r = r_val;

}

void func_perfect(int&& a)
{
	std::cout << a;//left val
	std::cout << std::forward<int>(a);//通过 通用引用 实现当前类型为传入的类型
	std::cout << std::move(a);//right val
}
