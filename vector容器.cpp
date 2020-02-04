#include<iostream>
#include<string>
#include<vector> 
using namespace std;
class Person
{
public:
	string m_Name;
	int m_Age;
	Person(string name = "0", int age = 0) : m_Name(name), m_Age(m_Age) 
	{ cout << "普通构造函数" << endl; }
	Person(const Person &p)
	{
			cout << "拷贝构造函数" << endl; 
			m_Name = p. m_Name;
			m_Age = p. m_Age; 
	} 
 	void showPerson()
	{ cout << "name：" << m_Name << " age：" << m_Age << endl; }
};
//void printVector(const vector<int> &v)
//{
//	for(int i = 0; i < v.size(); i++)
//		cout << v[i] << " ";
//	cout << endl;
//}
void printVector(const vector<int> &v)
{
	//不加const_报错，因为传入的是const deque<int>  const_iterator只读迭代器
	for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
	cout << endl;
}
//vector容器构造
//	vector<T> v 默认构造函数。
//	vector(v.begin(), v.end()) 将v[begin(), end())区间中的元素拷贝给本身，注意是前闭后开。
//	vector(n, elem) 将n个elem拷贝给本身。
//	vector(const vector &vec) 拷贝构造函数。
void test01()
{
	//默认构造函数 
	vector<int> v1;  
	for(int i = 0; i < 10; i++) 
		v1.push_back(i);
	printVector(v1);
	//通过区间方式进行构造 
	vector<int> v2(v1.begin(), v1.end());  
	printVector(v2);
	//通过n个elem进行构造
	vector<int> v3(10, 1);
	printVector(v3);
	//拷贝构造函数 
	vector<int> v4(v3);
	printVector(v4);
}
//vector赋值操作
//	vector& operator=(const vector &vec) 重载 = 运算符。
//	assign(beg, end) 将[beg, end)区间的数据拷贝赋值给本身。
//	assign(n, elem) 将n个elem拷贝赋值给本身。
void test02()
{
	vector<int> v1;  
	for(int i = 0; i < 10; i++) 
		v1.push_back(i);
	printVector(v1);
	//重载 = 运算符。
	vector<int> v2;
	v2 = v1;
	printVector(v2);
	//通过区间进行赋值
	vector<int> v3;
	v3.assign(v1.begin(), v1.end()); 
	printVector(v3);
	//将n个elem拷贝赋值给本身。
	vector<int> v4;
	v4.assign(10, 1);
	printVector(v4);
}
//对vector容器的容量和大小进行操作。
//	empty() 判断容器是否为空。
//	capacity() 容器的容量。
//	size() 返回容器中元素的个数。
//	resize(int num) 重新指定容器的长度为num，若容器变长，则以默认值填充新位置；若容器变短，则末尾超出容器长度的元素被删除。
//	resize(int num, elem) 重新指定容器的长度为num，若容器变长，则以elem值填充新位置；若容器变短，则末尾超出容器长度的元素被删除。
void test03()
{
	vector<int> v1; 
	//判断容器是否为空
	cout << v1.empty() << " "; 
	//容器的容量
	cout << v1.capacity() << " ";
	for(int i = 0; i < 10; i++) 
		v1.push_back(i);
	//判断容器是否为空
	cout << v1.empty() << " "; 
	//容器的容量 动态扩展 
	cout << v1.capacity() << " ";
	//容器中元素的个数
	cout << v1.size() << endl;
	v1.resize(5);
	printVector(v1);
	//容器的容量
	cout << v1.capacity() << endl;
	v1.resize(10);
	printVector(v1);
	v1.resize(5, 0);
	printVector(v1);
	v1.resize(21, 10);
	printVector(v1);
	//容器的容量 动态扩展 
	cout << v1.capacity() << endl;
		
}
//vector插入和删除
//	push_back(elem) 尾部插入元素elem。
//	pop_back() 删除最后1个元素。
//	insert(const_iterator pos, elem) 迭代器指向位置pos插入元素elem。
//	insert(const_iterator pos, int n, elem) 迭代器指向位置pos插入n个元素elem。
//	erase(const_iterator pos) 删除迭代器指向的元素。
//	erase(const_iterator start, const_iterator end) 删除迭代器从start到end之间的元素。
//	clear() 删除容器中所有元素。
void test04()
{
	vector<int> v; 
	for(int i = 0; i < 10; i++) 
		v.push_back(i);
	printVector(v);
	v.pop_back();
	printVector(v);
	v.insert(v.begin() + 3, 10);
	printVector(v);
	v.insert(v.begin() + 2, 3, 2);
	printVector(v);
	v.erase(v.begin() + 6);
	printVector(v);
	v.erase(v.begin() + 2, v.begin() + 5);
	printVector(v);
	v.erase(v.begin() + 1, v.begin() + 3);
	printVector(v);
	v.clear();
	cout << v.empty() << endl; 
} 
//vector数据存取
//	at(int idx) 返回索引idx所指的数据。
//	operator[](int idx) 运算符 [] 重载，返回索引idx所指的数据。
//	front() 返回容器中第1个数据元素。
//	back() 返回容器中最后1个数据元素。
void test05()
{
	vector<int> v; 
	for(int i = 0; i < 10; i++) 
		v.push_back(i);
	for(int i = 0; i < 10; i++) 
		cout << v.at(i) << " "; 
	cout << endl;
	for(int i = 0; i < 10; i++) 
		cout << v[i] << " "; 
	cout << endl;
	cout << v.front() << " " << v.back() << endl;
} 
//vector互换容器
//	swap(vec) 将vec与本身的元素进行互换。 
void test06()
{
	vector<int> v1; 
	for(int i = 0; i < 10; i++) 
		v1.push_back(i);
	printVector(v1);
	vector<int> v2; 
	for(int i = 9; i >= 0; i--) 
		v2.push_back(i);
	printVector(v2);
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
} 
//swap实际用途 巧用swap可以收缩内存空间 
void test07() 
{
	vector<int> v; 
	for(int i = 0; i < 100000; i++) 
		v.push_back(i);
	cout << "v的容量：" << v.capacity() << endl;
	cout << "v的大小：" << v.size() << endl;
	v.resize(3);
	cout << "v的容量：" << v.capacity() << endl;
	cout << "v的大小：" << v.size() << endl;
	vector<int> vec(20,8);
	vec = v;
	cout << "vec的容量：" << vec.capacity() << endl;
	cout << "vec的大小：" << vec.size() << endl;  
	//巧用swap收缩内存
	vector<int>(v).swap(v);  //匿名对象调用拷贝构造函数 
	//匿名对象当前行结束后就回收，不浪费内存空间 
	cout << "v的容量：" << v.capacity() << endl;
	cout << "v的大小：" << v.size() << endl; 
} 
//vector预留空间
//	reserve(int len) 容器预留len个元素长度，预留位置不初始化，元素不可访问。 
void test08() 
{
	vector<int> v1; 
	vector<int> v2; 
	int *p1 = NULL;
	int *p2 = NULL;
	int num1 = 0;  //统计v1内存开辟次数
	int num2 = 0;  //统计v2内存开辟次数
	v2.reserve(100000);  //利用reserve预留空间 
	for(int i = 0; i < 100000; i++) 
	{
		v1.push_back(i);
		v2.push_back(i);
		if(p1 != &(v1[0])) 
		{
			num1++;
			p1 = &(v1[0]);
		}
		if(p2 != &(v2[0])) 
		{
			num2++;
			p2 = &(v2[0]);
		}
	} 
	cout << "v1内存开辟次数：" << num1 << endl;
	cout << "v1的容量：" << v1.capacity() << endl;
	cout << "v1的大小：" << v1.size() << endl;
	cout << "v2内存开辟次数：" << num2 << endl;
	cout << "v2的容量：" << v2.capacity() << endl;
	cout << "v2的大小：" << v2.size() << endl;
} 
int main()
{
	test01();
//	test02();
//	test03();
//	test04();
//	test05();
//	test06();
//	test07();
//	test08();
	system("pause");	
	return 0;
} 
