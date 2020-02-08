#include<iostream>
#include<string>
#include<list> 
#include<algorithm>
using namespace std;
void printList(const list<int> &l)
{
	//不加const_报错，因为传入的是const deque<int>  const_iterator只读迭代器
	for(list<int>::const_iterator it = l.begin(); it != l.end(); it++)
		cout << *it << " ";
	cout << endl;
}
//list容器构造
//	list<T> v 默认构造函数。
//	list<T>(v.begin(), v.end()) 将v中[begin(), end())区间中的元素拷贝给本身，注意是前闭后开。
//	list<T>(n, elem) 将n个elem拷贝给本身。
//	list<T>(const list &lst) 拷贝构造函数。
void test01()
{
	//默认构造函数 
	list<int> l1;  
	for(int i = 0; i < 5; i++) 
		l1.push_back(i);
	for(int i = 5; i < 10; i++) 
		l1.push_front(i);
	printList(l1);
	//通过区间方式进行构造 
	list<int> l2(l1.begin(), l1.end());  
	printList(l2);
	//通过n个elem进行构造
	list<int> l3(10, 1);
	printList(l3);
	//拷贝构造函数 
	list<int> l4(l3);
	printList(l4);
}
//list赋值操作
//	list& operator=(const list &vec) 重载 = 运算符。
//	assign(beg, end) 将[beg, end)区间的数据拷贝赋值给本身。
//	assign(n, elem) 将n个elem拷贝赋值给本身。
//	swap(lst) 将lst与本身的元素互换。
void test02()
{
	list<int> l1;  
	for(int i = 0; i < 5; i++) 
		l1.push_back(i);
	for(int i = 5; i < 10; i++) 
		l1.push_front(i);
	printList(l1);
	//重载 = 运算符。
	list<int> l2;
	l2 = l1;
	printList(l2);
	//通过区间进行赋值
	list<int> l3;
	l3.assign(l1.begin(), l1.end()); 
	printList(l3);
	//将n个elem拷贝赋值给本身。
	list<int> l4;
	l4.assign(5, 1);
	printList(l4);
	//互换元素
	l3.swap(l4);
	printList(l3);
	printList(l4);
}
//对list容器的大小进行操作。
//	empty() 判断容器是否为空。
//	size() 返回容器中元素的个数。
//	resize(int num) 重新指定容器的长度为num，若容器变长，则以默认值填充新位置；若容器变短，则末尾超出容器长度的元素被删除。
//	resize(int num, elem) 重新指定容器的长度为num，若容器变长，则以elem值填充新位置；若容器变短，则末尾超出容器长度的元素被删除。
void test03()
{
	list<int> lst;  
	cout << lst.size() << "  ";
	cout << lst.empty() << "  "; 
	for(int i = 0; i < 5; i++) 
		lst.push_back(i);
	for(int i = 5; i < 10; i++) 
		lst.push_front(i);
	cout << lst.size() << "  ";
	cout << lst.empty() << "  "; 
	printList(lst);
	lst.resize(5);
	cout << lst.size() << "  ";
	printList(lst);
	lst.resize(12);
	cout << lst.size() << "  ";
	printList(lst);
	lst.resize(15, 10);
	cout << lst.size() << "  ";
	printList(lst);
}
//list插入和删除
//	两端操作：
//		push_back(elem) 在容器尾部添加一个数据。
//		pop_back() 删除容器最后1个数据。
//		push_front(elem) 在容器头部插入一个数据。
//		pop_front() 删除容器第1个数据。
//	指定位置操作：
//		insert(pos, elem) 在pos位置插入1个elem元素的拷贝，返回新数据的位置。
//		insert(pos, n, elem) 在pos位置插入n个elem数据，无返回值。
//		insert(pos, begin, end) 在pos位置插入[begin, end)区间中的数据，无返回值。
//		clear() 删除容器中所有元素。
//		erase(begin, end) 删除[begin, end)区间中的数据，返回下一个数据的位置。
//		erase(pos) 删除pos位置的数据，返回下一个数据的位置。
//		remove(elem) 删除容器中所有与elem值匹配的数据。
void test04()
{
	list<int> lst;   
	for(int i = 0; i < 5; i++) 
		lst.push_back(i);
	for(int i = 5; i < 10; i++) 
		lst.push_front(i);
	printList(lst);
	lst.pop_back();
	lst.pop_front();
	printList(lst);
	lst.insert(lst.begin(), 9);
	printList(lst);
	lst.insert(lst.end(), 3, 4);
	printList(lst);
	lst.insert(lst.end(), lst.begin(), lst.end());
	printList(lst);
	lst.remove(4);
	printList(lst);
	lst.clear();
	cout << lst.empty() << "  ";
	for(int i = 0; i < 5; i++) 
		lst.push_back(i);
	for(int i = 5; i < 10; i++) 
		lst.push_front(i);
	printList(lst);
	list<int>::iterator it;
	it = lst.begin();
	lst.erase(++it);
	printList(lst);
	lst.erase(lst.begin(), lst.end());
	cout << lst.empty() << endl;
} 
//list数据存取
//	front() 返回容器中第1个数据元素。
//	back() 返回容器中最后1个数据元素。
void test05()
{
	list<int> lst;   
	for(int i = 0; i < 5; i++) 
		lst.push_back(i);
	for(int i = 5; i < 10; i++) 
		lst.push_front(i);
	printList(lst);
	cout << "第1个元素：" << lst.front() << "  ";
	cout << "最后1个元素：" << lst.back() << endl; 
	list<int>::iterator it;
	it = lst.begin(); 
	it++;  //正确，list容器的迭代器支持前移和后移 
	it--;  //正确 
//	it = it + 1;  //错误，list容器的迭代器不支持随机访问即 +n的操作 
} 
//list反转和排序 
//	reverse() 反转链表。与vector容器的reserve(int len)方法区分开。
//	sort() 链表排序，成员函数。默认排序规则升序。
bool myCompare(int a, int b){ return a > b; }
void test06()
{
	list<int> lst;   
	for(int i = 0; i < 5; i++) 
		lst.push_back(i);
	for(int i = 5; i < 10; i++) 
		lst.push_front(i);
	printList(lst);
	lst.reverse();
	printList(lst);
	//所有不支持随机访问迭代器的容器，不可以用标准算法 
	//sort(lst.begin(), lst.end());
	//不支持随机访问迭代器的容器，内部会提供一些对应的算法 
	lst.sort();  //默认排序规则升序 
	printList(lst);
	lst.sort(myCompare);  //降序排序 
	printList(lst);
} 
//list排序案例
//	案例描述：
//		将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高。
//	排序规则：
//		按照年龄进行升序，如果年龄相同按照身高进行降序。
class Person
{
public:
	string name;
	int age;
	int height;
	Person(string name, int age, int height) 
	{
		this->name = name;
		this->age = age;
		this->height = height;
	}
	void showPerson() const 
	{
		cout << "name：" << name << "  ";
		cout << "age：" << age << "  ";
		cout << "height：" << height << endl;
	}
}; 
bool myCompare1(const Person &p1,const Person &p2)
{
	if(p1.age == p2.age)  //年龄相同按身高降序 
		return p1.height > p2.height;
	else  //年龄升序 
		return p1.age < p2.age;
}
/* printList函数，传入的参数是const list<Person> &类型，函数中不能改变lst中存储的Person类对象的成员变量的值，又该函数
中用到了成员函数showPerson()，所以showPerson()必须保证不能改变Person类对象中成员变量的值，所以要用const修饰showPerson()
，否则的话会报错： 
[Error] passing 'const Person' as 'this' argument of 'void Person::showPerson()' discards qualifiers [-fpermissive] */
void printList(const list<Person> &lst)  
{
	for(list<Person>::const_iterator it = lst.begin(); it != lst.end(); it++)
		it->showPerson();
	cout << endl;
}
void test07() 
{
	list<Person> lst;
	//准备数据 
	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 190);
	Person p5("张飞", 35, 160);
	Person p6("关羽", 35, 200);
	//list容器中插入数据 
	lst.push_back(p1);
	lst.push_back(p2);
	lst.push_back(p3);
	lst.push_back(p4);
	lst.push_back(p5);
	lst.push_back(p6);
	printList(lst);
	lst.sort(myCompare1);
	printList(lst);
} 
int main()
{
//	test01();
//	test02();
//	test03();
//	test04();
//	test05();
//	test06();
	test07();
	system("pause");	
	return 0;
} 
