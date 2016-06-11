 ///
 /// @file    const_data_member_initialization.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-11 05:36:58
 ///

//const 数据成员变量的初始化不能在构造函数体内进行，只能在成员初始化表中进行

#include <iostream>
using std :: cin;
using std :: cout;
using std :: endl;

class point
{
	public:
#if 0      //const data member 只能在初始化列表中初始化
		point(int x,int y)  //2 parameter cnostructor
		{
			_xPos = x;  //Error,无法直接赋值
			_yPos = y;
		}
		point(const point & pt)  //copy constructor
		{
			_xPos = pt._xPos;
			_yPos = pt._yPos;
		}
#endif

		point(int x, int y)
		:_xPos(x)
		,_yPos(y)
		{
			cout << "call 2 parameter constructor" << endl;
		}
		point(const point & pt)
		:_xPos(pt._xPos)
		,_yPos(pt._yPos)
		{
			cout << "copy constructor" << endl;
		}

		void print() const
		{
			cout << "xPos:" << _xPos << ",_yPos:" << _yPos << endl;
		}

	private:
		const int _xPos;
		const int _yPos;
};
 
int main()
{
	point pt1(3, 4);
	pt1.print();

	point pt2(pt1);
	pt2.print();

	return 0;
}

