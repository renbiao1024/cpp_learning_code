#pragma once
#include <vector>
//模板函数
template <typename T>
void func_1(T a)
{

}

//有默认值的模板函数
template<typename T = int>
void func_2(T a){}

//多类型模板函数
template <typename T, typename U>
void func_3(T a, U b){}
//偏特化
template<typename T> 
void func_3<T, int>(T a, int b){}
//全特化，可以用函数重载代替
template<> 
void func_3<int, int>(int a, int b){}

//含有非类型的参数
template <int x>
void func_4()
{
	std::vector<int>(x,0);
}


//模板类
template<class T>
class cmp{};
//类特化
template<class T>
class cmp<T*>{};

