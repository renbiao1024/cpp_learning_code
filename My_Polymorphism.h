#pragma once

//静态多态
//宏多态
#define add(a,b) ((a)+(b))

//函数重载
int static_polymorphism(int a, int b)
{
	return a + b;
}

int static_polymorphism(int a)
{
	return a + a;
}

//动态多态
class dynamic_polymorphism
{
public:
	virtual int polymorphism_add(int a,int b){return a + b;}
};
class dynamic_polymorphism_son : public dynamic_polymorphism
{
public:
	//函数重写
	int polymorphism_add(int a, int b) {return a + a + b + b; }
};