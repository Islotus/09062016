 ///
 /// @file    reference_data_member_initialization.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-11 06:16:39
 ///

//reference data member ininialization 引用数据成员初始化
//只能通过初始化表达式进行

#include <iostream>
using std :: cin;
using std :: cout;
using std :: endl;

class point
{
	public:
#if 0
		point(int x, int y, double & z)  //引用成员的初始化同样要放在初始化表中
		{
			_xPos = x;
			_yPos = y;
			_ref1 = _xPos;
			_ref2 = z;
		}
		//复制构造函数与此一致：）引用成员的初始化同样要放在初始化表中
		point(const point & pt)
		{
			_xPos = pt._xPos;
			_yPos = pt._yPos;
			_ref1 = pt._ref1;
			_ref2 = pt._ref2;
		}
#endif	
		point(int x, int y, double & z)  //引用成员的初始化同样要放在初始化表中
		:_ref1(_xPos)
		,_ref2(z)
		{
			_xPos = x;
			_yPos = y;
			cout << "调用构造函数" << endl;
		}
		//复制构造函数与此一致：）引用成员的初始化同样要放在初始化表中
		point(const point & pt)
		:_ref1(pt._ref1)
		,_ref2(pt._ref2)
		{
			_xPos = pt._xPos;
			_yPos = pt._yPos;
			cout << "调用拷贝构造函数" << endl;
		}
		
		void print() const
		{
			cout << "xPos: " << _xPos << ",yPos: " << _yPos;
			cout << ",ref1: " << _ref1 << ",ref2: " << _ref2 << endl;
		}
		void SetX(int x)
		{
			_xPos = x;
		}


	private:
		int _xPos;
		int _yPos;
		int & _ref1;
		double & _ref2;
};

int main()
{
	double outint = 5.0;
	point pt1(3, 4, outint);
	pt1.print();

	point pt2(pt1);
	pt2.print();

	cout << "改变pt1中的x后" << endl;
	pt1.SetX(7);
	pt1.print();
	pt2.print();

	outint = 6;
	cout << "outint变化后：" << endl;
	pt1.print();
	pt2.print();

	return 0;
}
