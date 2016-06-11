 ///
 /// @file    assignment_operator_overloading2.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-10 22:46:20
 ///

//赋值运算符重载，如果没有，执行时会出错
//assignment operator overloading,if no, function execution error

#include <iostream>
#include <cstring>
using std :: cout;
using std :: endl;

class computer
{
	public:
		computer ()    //no band parameter constructor
		:_brand(NULL)
		,_price(0)
		{
			cout << "无参构造函数被调用" << endl;
		}
		computer (const char * brand, float price)  
		:_price(price)
		{
			_brand = new char [strlen(brand) + 1];
			strcpy(_brand,brand);
			cout << "2 参数构造函数被调用" << endl;
		}
		computer(const computer & cp)    //copy constructor 
		:_price(cp._price)
		{
			_brand = new char [strlen(cp._brand) + 1];
			strcpy(_brand,cp._brand);
			cout << "赋值构造函数被调用" << endl;
		}

#if 0
		//如果我们没有重载=，则系统会隐式的重载成如下形式：
		computer & operator = (const computer & cp)
		{
			_price = cp._price;
			_brand = cp._brand;
			cout << "系统默认赋值函数被调用" << endl;
			return (*this);
		}
#endif

#if 1

		//应该使用下述函数取代上述系统隐式的定义
		computer & operator = (const computer & cp)  //成员函数形式重载赋值运算符
		{
			if(this == &cp)            //首先判断是否是自赋值，是的话，反回当前对象
				return (*this);
			_price = cp._price;         //如果不是自赋值 ，先对_price赋值
										//防止内存泄露，先释放_brand指向的内容
			_brand = new char[strlen(cp._brand) + 1];    //为_brand重新开辟一块内存空间
			if(_brand != NULL)			//如果开辟成功
			{
				strcpy(_brand,cp._brand);    //复制字符串
			}else
			{
				cout << "_computer & operator error" << endl;
			}
			cout << "赋值运算符重载函数被调用" << endl;
			return (*this);               //返回当前对象的引用，为的是实现链式赋值
		}

#endif


		~computer()    //destructor
		{
			delete [] _brand;
			cout << "析构函数被调用" << endl;
		}
		void print() const
		{
			cout << "品牌：" << _brand << endl;
			cout << "价格：" << _price << endl;
		}

	private:
		char * _brand;
		float _price;
};

int main()
{
	computer com1("Dell",2000);  //brand parameter constructor
	com1.print();
	computer com2 = com1;  //copy constructor
	com2.print();

	if(true)
	{
		computer com3;  //no parameter constructor
		com3 = com1;    //assignment operator overloading function
		com3.print();
	}

	return 0;

}

