#include <iostream>
using namespace std;

class a
{
public:
	virtual void dynamic_printf()
	{
		cout << "다이나미크 데헷\n";
	}

	 void static_print()
	{
		cout << "데헤\n";
	}
};

class b : public a
{
public :
	void dynamic_printf()
	{
		cout << "다이나미크 헤헿\n";
	}
	void static_print() 
	{
		cout << "헤헿\n";
	}

	void static_print(int a)
	{
		cout << a << "헤헿\n";
	}
};

void main()
{
	a* tempa;
	b* tempb = new b();
	tempa = tempb;
	tempa->static_print();
	tempb->static_print();

	tempa->dynamic_printf();
	tempb->dynamic_printf();
} 