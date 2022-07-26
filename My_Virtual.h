#pragma once

class Virtual_Class //含有虚函数的类 成为抽象类 不能实例化
{
public:
	Virtual_Class(){}//构造函数不可override

	virtual void func1(){}//子类可以override

	virtual void func2() = 0;//子类必须override

	virtual ~Virtual_Class(){}//析构函数应该virtual

};

class Virtual_Son_1 : public Virtual_Class
{
public:
	virtual void func1() override{}

	virtual void func2() override{}
};

class Virtual_Son_2 : public Virtual_Class
{
public:
	virtual void func1() final {}//他的子类不能再重写该函数

	virtual void func2() override final {}//他的子类不用再实现这个纯虚函数
};

class My_Interface//只含有纯虚函数的类成为接口
{
	virtual void func1() = 0;//纯虚函数默认为public，即使在private下
	virtual void func2() = 0;
	virtual void func3() = 0;
};

class Interface_Son : public My_Interface
{
public:
	void func1()override{}
};

