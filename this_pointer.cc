 ///
 /// @file    this_pointer.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-12 00:16:51
 ///

//this指针是隐含在成员函数体内的一种指针，称为指向本对象的指针
//this作用域是在类内部，当在类的非静态成员函数中访问类的非静态成员的时候，编译器会自动将对象本身
//的地址作为一个隐含参数传递给函数

#include <iostream>
//不完整代码

class Ex
{
	private:
		int _x;
		int _y;
	public:
		void Set()
		{
			this -> _x = 1;
			this -> _y = 2;
		}
};

//example2:
class CNullPointCall
{
	public:
		static void Test1();
		void Test2();
		void Test3(int iTest);
		void Test4();

	private:
		static int _m_iStatic;
		int _m_iTest;
};


int CNullPointCall :: _m_iStatic = 0;  //静态成员数据要在类外初始化

void CNullPointCall :: Test1()
{
	cout << _m_iStatic << endl;
}

void CNullPointCall :: Test2()
{
	cout << "Very Cool!" << endl;
}

void CNullPointCall :: Test3(int iTest)
{
	cout << iTest << endl;
}

void CNullPointCall :: Test4()
{
	cout << _m_iTest << endl;
}

