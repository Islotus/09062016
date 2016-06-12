 ///
 /// @file    class_pointer_memory.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-12 01:43:28
 ///

//使用new/delete为类指针分配/释放内存
//如果写了析构函数，并且是用new动态分配数组的内存空间的话，
//那么还会多开辟4个字节的内存空间，用来存放分配数组的大小

#include <iostream>
using std :: cin;
using std :: cout;
using std :: endl;

class point
{
	public:        //private数据成员列表
		point(int xp = 0, int yp = 0)        //构造函数，带缺省参数值
		:_x(xp)
		,_y(yp)
		{
			cout << "constructor called" << endl;
		}
		~point()        //析构函数
		{
			cout << "destructor called" << endl;
		}
		void print() const        //成员函数，类内部实现
		{
			cout << "_x: " << _x << ",y: " << _y << endl;
		}
	private:
		int _x;
		int _y;
};

int main()
{
	//动态申请一块内存，存储point类对象，并将地址赋值给point型指针p
	point * p = new point(4, 5);  
	p -> print();  //使用指针加->调用成员函数
	delete p;  //释放动态申请的内存，防止内存泄露
	p = NULL;  //养成良好习惯，防止野指针

	point * pp = new point[3]; 
	//此时你会发现分配了28个字节的内存空间，多出的最开始的4个字节的内存空间，存放3
	cout << "sizeof(pp): " << sizeof(*pp) << endl;
//	cout << "pp->sizeof(): "<< pp -> sizeof() << endl;
	delete [] pp;
	pp = NULL;
	return 0;
}
