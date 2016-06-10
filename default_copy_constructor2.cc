 ///
 /// @file    default_copy_constructor2.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-10 07:17:49
 ///
 
#include <iostream>
#include <cstring>
using std :: cout;
using std :: cin;
using std :: endl;

class computer
{
	public:
		computer(const char * brand, float price)
		:_price(price)
		{
			_brand = new char [strlen(brand) + 1];
			strcpy(_brand, brand);
			cout << "constructor " << this << " " << endl;
		}
		computer(const computer & cp) //自定义copy constructor
		{
			_brand = new char [strlen(cp._brand) + 1];
			strcpy(_brand, cp._brand);
			_price = cp._price;
			cout << "copy constructor " << this << " " << endl;
		}
		~computer()
		{
			delete [] _brand;
			cout << "site clearing " << this << " " << endl;
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
	computer comp1("Dell",7000);
	comp1.print();
	computer comp2(comp1);
	comp2.print();
	return 0;
}


