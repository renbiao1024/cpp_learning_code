#pragma once
#include <iostream>
template<typename T>
class My_Shared_ptr
{
private:
	int* count {new int(0)};
	T* ptr {nullptr};
public:
	My_Shared_ptr(T* t):ptr(t),count(new int(1)) {
		std::cout << *count;
	}

	My_Shared_ptr(My_Shared_ptr<T>& p): ptr(p.ptr) {
		++* p.count;
		count = p.count;
		std::cout << *count;
	}

	My_Shared_ptr<T>& operator=(My_Shared_ptr<T>& sp)
	{
		if (sp != *this)
		{
			++* sp.count;
			count = sp.count;
			ptr = sp.ptr;
		}
		std::cout << *count;
		return *this;
	}
	
	T* operator->()
	{
		return ptr;
	}

	T& operator*()
	{
		return *ptr;
	}

	~My_Shared_ptr()
	{
		-- *count;
		if (*count == 0)
		{
			delete count;
			delete ptr;
		}
		std::cout << "~";
	}
};

class A{};


void shared_ptr_test()
{
	A* a = new A;

	My_Shared_ptr<A>* msp = new My_Shared_ptr<A>(a);
	
	My_Shared_ptr<A> sd(*msp);
	My_Shared_ptr<A> sdq(*msp);
	My_Shared_ptr<A> sda = *msp;
}