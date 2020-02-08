#include<iostream>
#include<string> 
#include<queue> 
using namespace std;
class Person
{
public:
	string m_Name;
	int m_Age;
	Person(string name, int age) : m_Name(name), m_Age(age) {} 
	void showPerson()
	{ cout << "name:" << m_Name << "|age:" << m_Age << "  "; }
}; 
//queue构造函数：
//	queue<T> que 默认构造函数。
//	queue<T>(const queue &que) 拷贝构造函数。
//queue赋值操作：
//	queue& operator=(const queue &que) 重载 = 运算符。
//queue数据存取：
//	push(elem) 往队尾添加元素。
//	pop() 从队头移除第1个元素。
//	back() 返回最后1个元素。
//	front() 返回第1个元素。
//queue大小操作：
//	empty() 判断queue容器是否为空。
//	size() 返回容器中元素个数。
void test01()
{
	//默认构造函数
	queue<Person> que;
	//准备数据
	Person p1("唐僧", 30);
	Person p2("孙悟空", 999);
	Person p3("猪八戒", 888);
	Person p4("沙僧", 777);
	//元素入队 
	que.push(p1); 
	que.push(p2);
	que.push(p3);
	que.push(p4);
	cout << "队列中元素个数：" << que.size() << endl;
	cout << "队列中元素：" << endl; 
	//只要队列不为空，查看队头，并且执行出队操作
	while(!que.empty())
	{
		//查看队头元素
		cout << "队头："; 
		que.front().showPerson();
		//查看队尾元素
		cout << "队尾：";
		que.back().showPerson();
		cout << endl;
		//队头元素出队，为了访问下一个元素 
		que.pop(); 
	} 
	cout << "队列中元素个数：" << que.size() << endl;
} 
int main()
{
	test01();
	system("pause");	
	return 0;
} 
