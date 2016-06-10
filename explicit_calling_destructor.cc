 ///
 /// @file    explicit_calling_destructor.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-10 04:10:24
 ///

//explicit calling destructor
//显式调用析构函数

#include <iostream>
#include <cstring>
using std :: cout;
using std :: endl;
class computer
{
	public:
		computer (const char * brand, float price)
		:_price (price)
		{
			_brand = new char [strlen (brand) + 1];
			strcpy (_brand, brand);
		}
		~computer()
		{
			if(_brand != NULL)  //对象撤销时，释放内存，避免重复释放内存而错误
			{
				delete [] _brand;
				_brand = NULL;
			}
		}
		void print() const  //output massage
		{
			cout << "brand: " << _brand << endl;
			cout << "price: " << _price <<endl;
		}

	private:
		char * _brand;
		float _price;
};

int main()
{
	computer comp("dell", 7000);
	comp.print();
	comp.~computer();  //explicit calling destructor 显式调用析构函数
	return 0;
}
 
