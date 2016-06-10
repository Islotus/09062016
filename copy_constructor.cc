 ///
 /// @file    copy_constructor.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-10 04:24:57
 ///

//copy constructor 
//复制构造函数

#include <iostream>
using std :: cout;
using std :: endl;
class point
{
	public:
		point(int x = 0, int y = 0)
		:_xPos(x)
		,_yPos(y)
		{
			cout << "calling constructor" << endl;  //调用构造函数
		}
		point(const point & p)
		:_xPos(p._xPos)
		,_yPos(p._yPos)
		{
			cout << "calling copy constructor" << endl;  //调用复制构造函数
			cout << "member initialization list" << endl;  //成员初始化列表
		}
		void print() const
		{
			cout << "xpos: " << _xPos << ", ypos: " << _yPos << endl;
		}
	private:
		int _xPos;
		int _yPos;
};

int main()
{
	cout << "pt1: " << endl;
	point pt1(3, 4);
	pt1.print();
	
	cout << "pt2 = pt1" << endl;
	point pt2 = pt1;  //equall point pt2(pt1),calling copy constructor
	pt2.print();
	
	cout << "pt3(pt1)" << endl;
	point pt3(pt1);
	pt3.print();
	
	cout << "pt4" << endl;	
	point pt4;
	pt4.print();

	cout << "pt2 = pt4" << endl;  
	//the default assignment operator overloading function
	pt2 = pt4;
	pt2.print();
	return 0;
}


