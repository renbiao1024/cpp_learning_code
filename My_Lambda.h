#include <functional>
void func_lambda()
{
	int a = 2;

	auto f = [&](int b) ->int{return a+b;};
	std::function<int(int)> func_f = f;
}

