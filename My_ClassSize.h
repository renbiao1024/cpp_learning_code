#pragma once
#include <iostream>
//#pragma pack (2)
class Empty_Class{};

class MemoryAlignment_Class
{
private:
	int a;//2+2
	float b;//4
	char c;//1+1
	bool d;//1+1

	//default
	// (a   )  .   .
	// (b          )
	// (c ) . (d ) .

	//#pragma pack (2)
	//(a   )
	//(b       )
	//(c)(d)

};

class class_in_class_Class
{
	class MemoryAlignment_Class mc;//12+2

	int x;//2
};

class inherit_class : public MemoryAlignment_Class
{
	int x;
	static int s;//静态成员不算在类内
};

class function_Class
{
	void common_func(){}//0

	static void static_func(){}//0

	virtual void virtual_func_1(){}//8 虚表指针大小
	virtual void virtual_func_2(){}

	friend void friend_func(){}//0

	inline void inline_func(){}//0
};


void class_size_func()
{
	std::cout << sizeof(Empty_Class)<< std::endl; //空类 1 byte 
	std::cout << sizeof(MemoryAlignment_Class) << std::endl; //内存对齐 12
	std::cout << sizeof(class_in_class_Class) << std::endl;//内嵌类大小+自己的成员大小
	std::cout << sizeof(inherit_class) << std::endl;//继承父类的大小+自己的成员大小
	std::cout << sizeof(function_Class) << std::endl;//虚函数 + 虚表指针的大小，其余没有影响
}