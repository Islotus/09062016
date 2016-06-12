 ///
 /// @file    singleton.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-12 03:36:17
 ///

//单例设计模式：类在内存中只能有1个实例
//实现步骤：
//1.将构造函数私有化
//2.在类中定义一个静态的指针对象（可私，公有），并在类外初始化为空
//3.定义一个返回值为类指针的静态成员函数。如果2中的指针对象为空，则初始化对象。以后再有对象调用该静态
//该静态成员函数的时候，不再初始化对象，而是直接返回对象，保证内存中只有一个实例。

#include <iostream>
using std :: cin;
using std :: cout;
using std :: endl;

class CA
{
	private:
		static CA * pA;
		int _x;
		int _y;
		CA(int x = 0, int y = 0)
		{
#if 0
			this -> _x = x;
			this -> _y = y;
			cout << "构造函数被调用" << this << endl;
#endif
			_x = x;
			_y = y;
			cout << "构造函数被调用" << this << endl;
		}
	public:
		static CA * GetInstance(int x = 0, int y = 0)
		{
			if(pA == NULL)
			{
				pA = new CA(x,y);
			}
			return pA;
		}
		void disp() const
		{
			cout <<"("<<this->_x<<","<<this->_y<<")"<<endl;
		}
};

CA * CA::pA = NULL;  //静态成员要在外面初始化

int main()
{
	CA * p1 = CA::GetInstance(3, 4);
	CA * p2 = CA::GetInstance(2, 1);
	CA* p3 = CA::GetInstance(6, 2);

	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;
	
	p1 -> disp();
	p2 -> disp();
	p3 -> disp();

	return 0;
}
//此时p1 p2 p3是同一个，输出来的值相等，所以调用disp都输出同样的内容 

