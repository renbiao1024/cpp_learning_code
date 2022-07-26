#pragma once
void pointer_func()
{
	int m = 10;
	int* a; 
	a = &m;
	*a = 1;//修改指针指向的值
	int n = 2;
	a = &n;//可修改指针对象
	a++;//指向指针的下一地址
}

void reference_func()
{
	//int& b;//error 
	
	int a = 10;
	int& b = a;//& 必须初始化,且不能修改引用对象
	b++;// a = 11;
}