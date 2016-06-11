 ///
 /// @file    stat_member_function.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-11 08:11:59
 ///

//静态成员函数 static member function
//成员函数也可以定义成静态的，系统为每个类只建立一个函数实体，该实体为该类的所有对象共享
//静态成员函数体内，只能调用静态成员数据和函数
//静态成员函数的参数列表中不含有this指针

#include <iostream>
#include <cstring>
using std :: cin;
using std :: cout;
using std :: endl;

class computer
{
	public:
		computer(const char *chr, const float p)  //构造函数，模拟买电脑操作
		:_price(p)
		{
			_name = new char[strlen(chr) + 1];
			strcpy(_name, chr);
			_total_price += p;
			cout << "constructor called" << endl;
		}
		~computer() //destructor，模拟退掉电脑的操作
		{
			if(_name)
			{
				delete [] _name;
				_name = NULL;

			}
			_total_price -= _price;
			cout << "destructor called" << endl;
		}
		static void print_total()   //静态成员变量，原则上只能访问静态数据成员
		{
			cout << "总价：" << _total_price << endl;

		}
#if 1    //类内实现
		static void print(computer & com)  //静态成员函数print()原型，如果要访问某具体对象，必须传递参数
		{
			cout << "名称：" << com._name << endl;
			cout << "价格：" << com._price << endl;
		}
#endif

#if 0
		static void print(computer & com);
#endif

	private:
	char * _name;
	float _price;
	static float _total_price;  //静态数据成员
};

#if 0
void computer :: print(computer & com)  //静态成员函数print()实现
{
	cout << "名称：" << com._name << endl;
	cout << "价格：" << com._price << endl;
}
#endif

float computer :: _total_price = 0;  //初始化

int main()
{
	computer comp1("IBM",7000);  //声明类对象comp1，初始化，买入 statement class object
	computer :: print(comp1);  //类名加作用域限定符访问static成员函数，传递参数comp1
	computer :: print_total();  //类名加作用域限定符访问static成员函数

	computer comp2("ASUS", 4999);  //声明类对象comp2,初始化，买入
	computer :: print(comp2);  //类名加作用域限定符访问static成员函数，传递参数comp2
	computer :: print_total();

	comp2.~computer();  //析构函数调用，退还电脑
	computer :: print_total();

	return 0;
}

