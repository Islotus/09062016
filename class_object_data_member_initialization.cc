 ///
 /// @file    class_object_data_member_initialization.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-11 06:49:17
 ///

//类对象数据成员的初始化，要通过初始化列表进行

#include <iostream>
using std :: cin;
using std :: cout;
using std :: endl;

class point  //点类的定义 point class difinition
{
	public:
		point(int x = 0, int y = 0)  //带缺省调用的构造函数 default constructor
		{
			cout << "点的构造函数被执行" << endl;
			_xPos = x;
			_yPos = y;
		}
		point(const point & pt)  //复制构造函数  copy constructor
		{
			cout << "点的复制构造函数被执行" << endl;
			_xPos = pt._xPos;
			_yPos = pt._yPos;
		}
		void print() const
		{
			cout << "(" << _xPos << "," << _yPos << ")";
		}
	private:
		int _xPos;
		int _yPos;
};

class line  //line类的定义  line class definition
{
	public:
		line(int x1,int y1,int x2,int y2)  //line 对象的有参构造函数
		:pt1(x1,y1)
		,pt2(x2,y2)
		{
			cout << "线的构造函数被执行" << endl;
		}
		line(const line & ll)  //line类的复制构造函数
		:pt1(ll.pt1)
		,pt2(ll.pt2)
		{
			cout << "线的复制构造函数被执行" << endl;
		}
		void draw() const
		{
			pt1.print();
			cout << "to";
			pt2.print();
			cout << endl;
		}
	
	private:
		point pt1;  //point类对象作为line类成员，此处若写成point pt1(3,4),Error
		point pt2;
};
 
int main()
{
	line l1(1,2,3,4);  //call brand parameter constructor
	l1.draw();
	line l2(l1);  //call copy constructor
	l2.draw();
	return 0;
}



