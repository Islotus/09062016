 ///
 /// @file    assignment_operator_overloading.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-10 18:59:09
 ///

//成员函数形式的运算符重载
//

#include <iostream>
using std :: cout;
using std :: endl;

class complex  //定义复数类complex
{
	public:
		complex(double r = 0.0, double i = 0.0)  //构造函数，带缺省参数值constructor，band default parameter
		:_real(r)
		,_imag(i)
		{
			cout << "band default parameter constructor" << endl;
		}
		complex operator += (const complex &);  //成员函数形式重载加+=

		complex operator + (const complex &);  //成员函数形式重载加+
		complex operator - (const complex &);  //成员函数形式重载减-
		complex operator - ();                 //成员函数形式重载一元-（取反）
		complex operator * (const complex &);  //成员函数形式重载乘*
		complex operator / (const complex &);  //成员函数形式重载除/

		complex & operator ++ ();                //成员函数形式重载前置++
		complex operator ++ (int);             //成员函数形式重载后置++

		void display() const                   //成员函数，输出复数
		{
			cout << _real << "+" << "i*" << _imag << endl;
		}

	private:
		double _real, _imag;
};

complex complex :: operator += (const complex & CC)  //加+=的实现
{
	_real += CC._real;
	_imag += CC._imag;
	return (*this);
}

complex complex :: operator + (const complex & CC)  //加+的实现
{
	return complex(_real + CC._real, _imag + CC._imag);
}

complex complex :: operator - (const complex & CC)  //减-的实现
{
	return complex(_real - CC._real, _imag - CC._imag);
}

complex complex :: operator * (const complex & CC)  //乘*的实现
{
	return complex(_real*CC._real -_imag*CC._imag, _real*CC._imag + _imag*CC._real);
}

complex complex :: operator / (const complex & CC)  //除/的实现
{
	return complex((_real*CC._real + _imag + CC._imag)/(CC._real*CC._real + CC._imag*CC._imag),
			(_imag*CC._real - _real*CC._imag)/(CC._real*CC._real + CC._imag*CC._imag));
}

complex complex :: operator - ()  //单目-，即取反的实现
{
	return complex(-_real, -_imag);
}

complex & complex :: operator ++()  //前置++的实现
{
	cout << "前置++" << endl;
	++ _real;
	++ _imag;
	return (*this);
}

complex complex :: operator ++ (int)  //后置++的实现，体会和前置++的区别
{
	cout << "后置++" << endl;
	complex cTemp = (*this);  //最终的返回的值是原来的值，因此需要先保存原来的值
	++(*this);                //返回后原来的值需要加1
	return cTemp;
}

int main()
{
	complex cx1(1.0, 2.0),cx2(3.0,4.0),cxRes;

	cxRes += cx2;    //相当于cxRes.operator+=(cx2)
	cxRes.display();

	cxRes = cx1 + cx2;    //相当于cx1.operator+(cx2)
	cxRes.display();

	cxRes = cx1 - cx2;    //相当于cx1.operator-(cx2)
	cxRes.display();

	cxRes = cx1 * cx2;    //相当于cx1.operator*(cx2)
	cxRes.display();


	cxRes = cx1/cx2;    //相当于cx1.operator/(cx2)
	cxRes.display();

	cxRes = -cx1;    //相当于cx1.operator-()
	cxRes.display();

	cout << endl;

	complex cx3(1.0, 1.0),cx4(5.0, 5.0);

	cxRes = ++cx3;    //相当于cx3.operator++()
	cxRes.display();
	cx3.display();

	cout << endl;

	cxRes = cx4++;    //相当于cx4.operator++(0)
	cxRes.display();
	cx4.display();

	cout << endl;

	//注意下述语句在友元函数形式和成员函数形式中的对比
	cxRes = cx1 + 5;    //相当于cx1.operator+(5)或cx1.operator+(complex(5))
	cxRes.display();

//	cxRes = 5 + cx1;    //错误。相当于5.operator+(cx1)
//	cxRes.diaplay();

	return 0;

}
