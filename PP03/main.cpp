#include <iostream>
using namespace std;

class a
{
public:
	virtual void dynamic_printf()
	{
		cout << "´ÙÀÌ³ª¹ÌÅ© µ¥Çò\n";
	}

	 void static_print()
	{
		cout << "µ¥Çì\n";
	}
};

class b : public a
{
public :
	void dynamic_printf()
	{
		cout << "´ÙÀÌ³ª¹ÌÅ© ÇìÂm\n";
	}
	void static_print() 
	{
		cout << "ÇìÂm\n";
	}

	void static_print(int a)
	{
		cout << a << "ÇìÂm\n";
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