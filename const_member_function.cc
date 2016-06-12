 ///
 /// @file    const_member_function.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-11 18:53:32
 ///

//void print();==> void print(point *const this)
//1.只能读取类数据成员，而不能修改之
//2.只能调用const成员函数，不能调用非const成员函数
//在函数体和函数头之间加const


#include <iostream>
using std :: cin;
using std :: cout;
using std :: endl;

class point
{

	public:
		point(int xp = 0, int yp = 0) //default constructor
		:_x(xp)
		,_y(yp)
		{
			cout << "defualt constructor called " << endl;
		}

		void print() const  //const 成员函数内无法修改数据成员，否则编译器报错
		{
//			_x = 5;  //1.试图修改_x将发生编译器报错
			set();  //2.试图调用非const函数将引发编译器报错
			cout << "_x: " << _x << ",_y; " << _y << endl;
		}

		void set()     const  //将set()定义成const函数就能解决问题  
			//多两个空格没关系，但从美观等方面考虑还是留一个空格
		{
			cout << "set() called" << endl;
		}

	private:
		int _x;  //默认为private的数据成员_x和_y
		int _y;
};
int main()
{
	point pt;  //声明类对象，以缺省参数形式调用的构造函数
	pt.print();  //调用const成员数据

	return 0;

}


