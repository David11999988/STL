#include<iostream>
#include<string> 
#include<stack> 
using namespace std;
//stack的构造函数
//	stack<T> stk 默认构造函数。
//	stack<T>(const stack &stk) 拷贝构造函数。
//stack赋值操作
//	stack& operator=(const stack &stk) 重载 = 运算符。 
//对stack的大小进行操作。
//	empty() 判断容器是否为空。
//	size() 返回容器中元素的个数。
//stack数据存取
//	push(elem) 入栈。
//	pop() 栈顶元素出栈。
//	top() 返回栈顶元素。
void test01()
{
	//默认构造函数
	stack<int> stk;
	//元素入栈 
	for(int i = 0; i < 5; i++)
		stk.push(i);
	cout << "栈中元素个数：" << stk.size() << endl;
	cout << "栈中元素(从栈顶到栈底)：" << endl; 
	//只要栈不为空，查看栈顶，并且执行出栈操作
	while(!stk.empty())
	{
		//查看栈顶元素
		cout << stk.top() << " ";
		//栈顶元素出栈，为了访问下一个元素 
		stk.pop(); 
	} 
	cout << endl << "栈中元素个数：" << stk.size() << endl;
} 
int main()
{
	test01();
	system("pause");	
	return 0;
} 
