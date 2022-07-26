
class My_class
{
//默认为private
	int a;
};
union My_union
{
	int a;
	int b;
	int c;
};

struct My_struct
{
//默认为public
	int a;
	union My_union u;//多变量共享最大变量空间

	union//匿名共用体的变量被认为是地址相同的多个变量
	{
		int s;
		int b;
	};
};

