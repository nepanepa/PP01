#include <iostream>
using namespace std;

class a
{
public:
	virtual void dynamic_printf()
	{
		cout << "���̳���ũ ����\n";
	}

	 void static_print()
	{
		cout << "����\n";
	}
};

class b : public a
{
public :
	void dynamic_printf()
	{
		cout << "���̳���ũ ���m\n";
	}
	void static_print() 
	{
		cout << "���m\n";
	}

	void static_print(int a)
	{
		cout << a << "���m\n";
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