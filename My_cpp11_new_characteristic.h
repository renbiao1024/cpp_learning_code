#pragma once
#include <memory>
#include <assert.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <functional>
class A
{
public:
	//explicit阻止隐式转换
	explicit A(int a = 0, int b = 0):_A(a),_B(b) {}
	
	//类内成员初始化
	int _A = 0;
	int _B {2};
};

void display_A(A a)
{
	std::cout <<a._A << a._B; 
}

void explicit_test()
{
	display_A(A(1));//可以显示转换
	//display_A(1);
}

//类成员函数的控制
class control_class
{
public:
	control_class() = delete;
	~control_class() = default;
};
//final禁止类继承
class control_class_son final
{

};

void new_characteristic_test()
{
//智能指针：解决内存泄漏问题
	//shared_ptr 
	auto sp = std::make_shared<A>();
	std::cout << sp.use_count();//查看引用计数
	auto sp_1 = sp;
	std::cout << sp.use_count();

	//unique_ptr
	auto up = std::make_unique<A>();
	//auto up_1 = up; 
	auto up_2 = move(up);
	assert(up == nullptr);

	//weak_ptr
	//可认为是一个不增长引用计数的 shared_ptr，用于解决shared_ptr循环引用的问题
	std::weak_ptr<A> wp;
	wp = sp;

//右值 My_Rvalue.h;

//新类型
	long long a = 2.2;
	unsigned long long b = 3.21;
	char16_t c = 1u;
	char32_t d = 2U;
	std::string e = R"(sad)";//原始字符串

//{}初始化
	int dkh = {2};

//自动类型推导
	decltype (dkh) td = 13;

//auto
	auto d = td;

//using 类模板的别名
	using map_int_double = std::map<int, double>;

//空指针
	int* pa = nullptr;

//基于范围的for循环
	std::vector<int> arr (12,0);
	for (auto i : arr)
	{
		std::cout << i;
	}

//将变量声明到寄存器
	register int ra = 2;

}

//后置返回类型
template <typename T, typename U>
auto func(T a, U b)->decltype(a + b)
{
	return (a + b);
}

//noexcept 表示函数不会引发异常
void func_1() noexcept
{

}

//枚举类
enum class t_shirt{S, M , L};

//namespace
namespace na{
	int a = 2;

	namespace nb{
		int a = 2;
	}
}
int xc = na::a = 2l;
int xd = na::nb::a = 32;

//函数重写控制 override，final 见My_Virtual.h

//lambda 
auto f1 = [&](int n)->int {return n + xc;};

//function函数包装器
std::function<void(int)> fa = f1;

//可变参数模板
template <typename... Args>
std::ostream& errorMsg(ostream& os, const Args&... rest)
{
	return print(os, debug_rep(rest)...);
}