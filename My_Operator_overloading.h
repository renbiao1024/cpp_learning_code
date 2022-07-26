#pragma once

class Operator_overloading_class
{
private:
	int i;
public:
	int operator+(Operator_overloading_class& rhs){
		return i + rhs.i;
	}
	//成员函数操作符重载,常用于单目运算
	Operator_overloading_class& operator++(){return *this;}//前置++
	Operator_overloading_class operator++(int){return *this;}//后置++
	bool operator==(Operator_overloading_class& a){return *this == a;}

	//友元函数操作符重载,常用于双目运算
	friend Operator_overloading_class operator+(Operator_overloading_class&lhs, Operator_overloading_class& rhs) {return lhs;}
};