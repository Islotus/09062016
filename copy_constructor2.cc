 ///
 /// @file    copy_constructor2.c
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-10 05:48:14
 ///
 
#include <iostream>
using std :: cout;
using std :: endl;

class CPoint
{
	public:
		CPoint()
		:_x(0)
		,_y(0)
		{
			cout << "default constructor " << this << " " << endl;  //默认构造函数
		}
		CPoint(int ix)
		:_x(ix)
		,_y(0)
		{
			cout << "1 parameter constructor " << this << " " << endl;  //1参数构造函数
		}
		CPoint(int ix, int iy)
		:_x(ix)
		,_y(iy)
		{
			cout << "2 parameter constructor " << this << " " << endl;
		}

		CPoint(const CPoint & cp)
		:_x(cp._x)
		,_y(cp._y)
		{
			cout << "copy constructor " << this << " " << endl;
		}
		
		CPoint & operator = (const CPoint & cp)
		{
			cout << "assignment operator overloading " << this << " " << endl;  //赋值运算符重载
			if(this != &cp)  //防止自己赋值自己
			{
				_x = cp._x;
				_y = cp._y;
			}
			return (*this);
		}
#if 1
		~CPoint()
		{
			cout << "destructor " << this << " " << endl;  //析构函数
		}
	
#endif
	private:
		int _x;
		int _y;
};

void fun1(CPoint pt)
{
}
CPoint fun2()
{
	CPoint a;
	return a;
}
CPoint fun(CPoint a)
{
	return a;
}

int main(int argc, char * argv[])
{
	//第1类：
//	CPoint pt1 = CPoint();

//	CPoint pt2 = CPoint(1);

//	CPoint pt3 = 1;


	//第2类

//	CPoint pt4;
//	CPoint pt5 = pt4;

//	fun1(pt4);
//	fun2();

	CPoint pt6 = fun2();


//	CPoint pt7 = fun(pt4);

	return 0;
}


