 ///
 /// @file    const_object.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-11 19:31:49
 ///
 
#include <iostream>
using std :: cin;
using std :: cout;
using std :: endl;

class point  //class definition
{
	public:
		point(int xp = 0, int yp = 0)  //constructor
		:_x(xp)
		,_y(yp)
		{
			cout << "constructor called " << endl;
		}
		~point()
		{
			_x = -1;
			cout << "destructor called ,_x = " << _x << endl;
		}
		void setX(int xp)  //非const成员函数setX，设置x
		{
			_x = xp;
			cout << "setX() called " << endl;
		}
		void setY(int yp)  //非const成员函数setY，设置y
		{
			_y = yp;
			cout << "setY() called " << endl;
		}
		void print() const  //const成员函数print，不能修改x和y
		{
			cout << "print() const called " << endl;
			cout << "_x: " << _x << ",_y: " << _y <<endl;
		}


	private:
	int _x;  //默认private型成员变量_x和_y
	int _y;
};


int main()
{
	point pt(3, 4);  //声明一个普通类变量pt
	pt.print();
	pt.setX(5);  //使用pt可调用非const成员函数
	pt.setY(6);
	pt.print();  //pt也可以调用const成员函数

	const point ptc(1,2);  //声明一个const对象（类变量）
	ptc.print();
//	ptc.setX(8);    //Error，ptc是const对象，只能调用const成员函数
	//ptc.setY(9);    //Error, pte是const对象，只能调用const成员函数
	ptc.~point();     //right, const对象也能调用非const类型的析构函数（不能为const类型）
	ptc.print();    //right, const对象只能调用const类型成员函数

	return 0;
	
}
