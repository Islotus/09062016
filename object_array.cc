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
#if 1
		point(int ix = 0, int iy = 0)
#endif
#if 0
		point(int ix, int iy)
#endif
#if 1
		:_x(ix)
		,_y(iy)
		{
			static int iCount = 0;
			iCount ++;
			cout << iCount << ".构造函数被调用" << endl;

		}
#endif
	private:
		int _x;
		int _y;
};
 

int main()
{
	point pt1[2];  //错误，没有合适的构造函数

//	point pt2[2] = {point(1,2), point(3,4)};  //正确

//	point pt3[] = {point(1,2), point(3,4)};  //正确，自动确定数组的元素个数

	//Error，后3个元素会自动调用无参的构造函数，但这样的构造函数不存在
	point pt4[5] = {point(1,2), point(3,4)};

	//解决办法：给上述构造函数的2个参数定义缺省值
	return 0;

}
