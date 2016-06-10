 ///
 /// @file    default_copy_constructor.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-10 06:57:25
 ///
 
#include <iostream>
#include <cstring>
using std :: cout;
using std :: endl;

class computer
{
	public:
		computer(const char * brand, float price)
		:_price(price)
		{
			_brand = new char [strlen(brand) + 1];
			strcpy(_brand, brand);
			cout << "2 parameter constructor " << this << " " << endl;
		}

		computer (const computer & cp)  //默认的复制构造函数的实现如下：
		:_price(cp._price)
		{
			_brand = cp._brand;  //对指针变量不能这样直接赋值，这是引起错误的根源
		}

		~computer()
		{
			delete [] _brand;
			cout << "site clearing" << endl;
		}
		void print() const
		{
			cout << "brand: " << _brand << endl;
			cout << "price: " << _price << endl;
		}
	private:
		char * _brand;
		float _price;
};

int main()
{
	computer comp1("dell",7000);
	comp1.print();
	computer comp2(comp1);
	comp2.print();
	return 0;
}
