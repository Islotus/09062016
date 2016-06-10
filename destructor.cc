 ///
 /// @file    destructor.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-09 23:08:38
 ///
 
#include <iostream>
#include <cstring>
using std :: cin;
using std :: cout;
using std :: endl;

class computer
{
	public:
		computer (const char * sz, float price)
		{
			_brand = new char [strlen (sz) +1];
			strcpy (_brand, sz);
			_price = price;
		}
		~computer ()
		{
			delete [] _brand;  //对象撤销时，释放内存，避免泄露
			_brand = NULL;
			cout << "site clearing" << endl;
		}
		void print () //cout massage
		{
			cout << "brand: " << _brand << endl;
			cout << "price: " << _price << endl;
		}
	private:
		char * _brand;  //指针成员
		float _price;
};
int main()
{
	computer comp ("Dell", 7000);
	comp.print ();  //massage output
	return 0;
}
