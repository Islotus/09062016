 ///
 /// @file    example_of_constructor_calling.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-10 08:22:25
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
			cout << "默认构造函数 " << this << " ";
		}

//		explicit   //加上explicit可防止CPoint pt1 =1;这种隐形转换
		CPoint(int ix)
		:_x(ix)
		,_y(0)
		{
			cout << "1参数构造函数 " << this << " ";
		}
		CPoint(int ix, int iy)
		:_x(ix)
		,_y(iy)
		{
			cout << "2参数构造函数 " << this << " ";
		}

//		explicit    //加上explicit 可防止CPoint pt2 = pt1;这种隐性转换
		CPoint(const CPoint & cp)
		:_x(cp._x)
		,_y(cp._y)
		{
			cout << "拷贝构造函数 " << this << " ";
		}

		CPoint & operator = (const CPoint & cp)
		{
			cout << "赋值运算符重载函数 " << this << " ";
			if(this != &cp)  //防止自己赋值自己
			{
				_x = cp._x;
				_y = cp._y;
			}
			return (*this);
		}

		~CPoint()
		{
			cout << "析构函数 " << this << " ";
		}
	
	private:
		int _x;
		int _y;
};

int main(int argc, char * argv[])
{
	CPoint p0();  //这是函数的声明，不是实例化类

	cout << endl << "CPoint pt1;\t\t";
	CPoint pt1;    //缺省构造函数

	cout << endl << "CPoint pt2(1);\t\t";
	CPoint pt2(1);  //一个参数的构造函数

	cout << endl << "CPoint pt3(1, 2);\t";
	CPoint pt3(1,2);  //两个参数的构造函数

	cout << endl << "CPoint pt4 = 1;\t\t";
	CPoint pt4 = 1;    //等价于CPoint t4(1)  //explicit

	cout << endl << "CPoint pt5 = t1;\t";
	CPoint pt5 = pt1;  //CPoint(t1)

	cout << endl << "CPoint pt6 = CPoint();\t";
	CPoint pt6 = CPoint();  //CPoint(1);CPoint(1,2);

	cout << endl << "pt6 = CPoint(1);\t";
	pt6 = CPoint(1);

	cout << endl << "pt6 = 1;\t\t";
	pt6 = 1;    //首先调用单个参数的构造函数，生成临时对象CPoint(1),然后调用赋值运算函数

	cout << endl << "pt6 = t1;\t\t";
	pt6 = pt1;

	cout << endl << endl;
	return 0;

}


