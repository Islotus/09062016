 ///
 /// @file    si_of_object.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-11 20:19:22
 ///

//对象的大小只包含非静态成员，
//类中的引用成员当成“指针”indicator来维护，占4个字节
//类中有虚函数时，对象大小还包含一个指针（4个字节），指向虚函数表

#include <iostream>
using std :: cin;
using std :: cout;
using std :: endl;

class cex
{
	private:
		int a;  //int型，在一般系统上占据4个内存字节    4
		char b;  //char型，占1个内存字节    1+3（3浪费）
		float c;  //单精度浮点型，占4个内存字节    4+4（4浪费）
		double d;  //double型，占8个内存字节    8
		short e[5];  //short型数组，每个元素占2个内存字节    8+2
		char & f;  //引用，当成指针维护    2+4（2浪费）
		double & g;  //引用，当成指针维护    4+4（后4浪费）
		static int h;  //static成员，公共内存，不影响单个对象的大小0

	public:
			cex():f(b),g(d)  //和构造函数，引用数据成员必须在初始化表中初始化
			{
			}
			void print() const  //成员函数的定义，普通成员函数不影响对象大小
			{
				cout << "Hello" << endl;
			}
};

int cex :: h = 0;    //static成员的初始化

int main()
{
	cex c;
	cout << "sizeof(cex):" << sizeof(cex) << endl;  //输出类对象的大小sizeof（cex) = 48;
	return 0;
}


