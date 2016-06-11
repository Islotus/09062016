 ///
 /// @file    static_data_parameter_initialization.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-11 07:14:50
 ///

//静态数据成员初始化
//static data member initialization

#include <iostream>
using std :: cin;
using std :: cout;
using std :: endl;

class computer
{
	public:
		computer(const float p)  //构造函数，模拟买电脑的操作，对total_price进行累加
		:_price(p)
		{
			_total_price += p;
			cout << "调用构造函数" << endl;
		}
		~computer()  //析构函数，模拟退还电脑的操作，从total_price中减去所退电脑的price
		{
			_total_price -= _price;
			cout << "调用析构函数" << endl;
		}
		void print() const  //输出函数
		{
			cout << "总价：" << _total_price << endl;
		}
		void print_unit_price()  //输出单价
		{
			cout << "单价：" << _price << endl;
		}
		void setPrice(int x)
		{
			_price = x;
			cout << "setPrice " << endl;
		}
	private:
	float _price;  //float 型数据成员price，表示价格
	static float _total_price;  //static成员，总价，不依附于某个对象

};

float computer :: _total_price = 0;  //初始化,static数据成员初始化要放在类的外面进行

int main()
{
	computer comp1(7000);  //买入电脑1
	cout << "购买电脑1后" << endl;
	comp1.print_unit_price(); 
	comp1.print();
	
	computer comp2(4999);  //买入电脑2
	cout << "购买电脑2后" << endl;
	comp2.print_unit_price();
	comp2.print();

	computer comp3(2500);  //买入电脑3
	cout << "购买电脑3后" << endl;
	comp3.print_unit_price();
	comp1.print();  //此处调用comp1.print(),comp2.print(),comp3.print()输出结果相同

	comp2.~computer();  //退掉电脑2
	cout << "退掉电脑2后" << endl;
	comp3.print();

	comp2.print();
	comp2.print_unit_price();

	comp2.setPrice(1000);
	comp2.print_unit_price();
	comp2.print();
	return 0;

}





