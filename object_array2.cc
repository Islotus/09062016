 ///
 /// @file    object_array.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-12 01:06:56
 ///

//1.队象数组的声明 类名 数组名【对象个数】，这种格式会
//调用无参或所有参数都缺省的构造函数，类定义要符合要求
//2.一定要注意要写无参或所有参数都缺省的构造函数

#include <iostream>
using std :: cin;
using std :: cout;
using std :: endl;

class point
{
	public:
		point(int ix = 0, int iy = 0)
		:_x(ix)
		,_y(iy)
		{
			static int iCount = 0;
			iCount ++;
			cout << iCount << ".构造函数被调用" << endl;
		}
	private:
		int _x;
		int _y;
};
 
int main()
{
	point pt4[5] = {point(1,2), point(3,4)};

	return 0;
}
