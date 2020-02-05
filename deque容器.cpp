#include<iostream>
#include<string> 
#include<deque> 
#include<algorithm> 
using namespace std;
//void printDeque(const deque<int> &dec)
//{
//	//不加const_报错[Error] conversion from 'std::deque<int>::const_iterator {aka std::_Deque_iterator<int, const int&, const int*>}' to non-scalar type 'std::deque<int>::iterator {aka std::_Deque_iterator<int, int&, int*>}' requested 
//	//因为传入的是const deque<int>  const_iterator只读迭代器 
//	for(deque<int>::const_iterator it = dec.begin(); it != dec.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//}
void printDeque(const deque<int> &dec)
{
	for(int i = 0; i < dec.size(); i++)
		cout << dec[i] << " ";
	cout << endl;
}
//deque的构造函数
//	deque<T> deq 默认构造函数。
//	deque<T>(begin, end) 将v[begin, end)区间中的元素拷贝给本身，注意是前闭后开。
//	deque<T>(n, elem) 将n个elem拷贝给本身。
//	deque<T>(const deque &deq) 拷贝构造函数。
void test01()
{
	//默认构造函数
	deque<int> d1;
	for(int i = 0; i < 10; i++)
		d1.push_back(i);
	printDeque(d1);
	//将v[begin, end)区间中的元素拷贝给本身
	deque<int> d2(d1.begin(), d1.end()); 
	printDeque(d2);
	//将n个elem拷贝给本身
	deque<int> d3(10, 1);
	printDeque(d3);
	//拷贝构造函数
	deque<int> d4(d1);
	printDeque(d4);
} 
//deque赋值操作
//	deque& operator=(const deque &deq) 重载 = 运算符。
//	assign(beg, end) 将[beg, end)区间的数据拷贝赋值给本身。
//	assign(n, elem) 将n个elem拷贝赋值给本身。
void test02()
{
	deque<int> d1;  
	for(int i = 0; i < 10; i++) 
		d1.push_front(i);
	printDeque(d1);
	//重载 = 运算符。
	deque<int> d2;
	d2 = d1;
	printDeque(d2);
	//通过区间进行赋值
	deque<int> d3;
	d3.assign(d1.begin(), d1.end()); 
	printDeque(d3);
	//将n个elem拷贝赋值给本身。
	deque<int> d4;
	d4.assign(10, 1);
	printDeque(d4);
}
//对deque的大小进行操作。
//	empty() 判断容器是否为空。
//	size() 返回容器中元素的个数。
//	resize(int num) 重新指定容器的长度为num，若容器变长，则以默认值填充新位置；若容器变短，则末尾超出容器长度的元素被删除。
//	resize(int num, elem) 重新指定容器的长度为num，若容器变长，则以elem值填充新位置；若容器变短，则末尾超出容器长度的元素被删除。
void test03()
{
	deque<int> deq;
	cout << deq.empty() << "  ";
	cout << deq.size() << "  ";
	for(int i = 0; i < 10; i++) 
		deq.push_back(i);
	cout << deq.empty() << "  ";
	cout << deq.size() << "  ";
	deq.resize(5);
	cout << deq.size() << endl;
	printDeque(deq);
	deq.resize(15, 1);
	printDeque(deq);		
}
//deque插入和删除
//	两端插入删除操作:
//		push_back(elem) 在容器尾部添加一个数据。
//		push_front(elem) 在容器头部插入一个数据。
//		pop_back() 删除容器最后1个数据。
//		pop_front() 删除容器第1个数据。
//	指定位置操作：
//		insert(pos, elem) 在pos位置插入1个elem元素的拷贝，返回新数据的位置。
//		insert(pos, n, elem) 在pos位置插入n个elem数据，无返回值。
//		insert(pos, begin, end) 在pos位置插入[begin, end)区间中的数据，无返回值。
//		clear() 清空容器中所有的数据。
//		erase(begin, end) 删除[begin, end)区间中的数据，返回下一个数据的位置。
//		erase(pos) 删除pos位置的数据，返回下一个数据的位置。
void test04()
{
	deque<int> deq;
	for(int i = 0; i < 10; i++) 
		deq.push_front(i);
	printDeque(deq);
	deq.pop_back();
	printDeque(deq);
	deq.pop_front();
	printDeque(deq);
	deque<int>::iterator it;
	it = deq.insert(deq.begin() + 2, 7);
	cout << (it == deq.begin() + 2) << "  ";
	printDeque(deq);
	deq.insert(deq.begin() + 4, 2, 6);
	printDeque(deq);
	deque<int> d;
	d.insert(d.begin(), deq.begin() + 3, deq.end() - 2);
	printDeque(d);
	d.clear();
	cout << d.size() << "  ";
	it = deq.erase(deq.begin() + 2, deq.begin() + 5 );
	cout << (it == deq.begin() + 2) << "  ";
	cout << d.size() << "  ";
	printDeque(deq);
	deque<int>::iterator it1;
	deque<int>::iterator it2;
	it1 = deq.begin() + 1;
	cout << (deq.begin() == it1) << "  ";
	it = deq.erase(deq.begin() + 1);
	cout << (deq.begin() == it1) << "  ";
	*it1 = 0;
	*(deq.begin() + 1) = 100;
	it2 = deq.begin() + 1;
	cout << *it << "  ";
	cout << (it2 == it1 + 1) << "  ";
	cout << (it == deq.begin() + 1) << "  ";
	printDeque(deq);	 
} 
//deque数据存取
//	at(int idx) 返回索引idx所指的数据。
//	operator[](int idx) 运算符 [] 重载，返回索引idx所指的数据。
//	front() 返回容器中第1个数据元素。
//	back() 返回容器中最后1个数据元素。
void test05()
{
	deque<int> deq; 
	for(int i = 0; i < 10; i++) 
		deq.push_back(i);
	for(int i = 0; i < 10; i++) 
		cout << deq.at(i) << " "; 
	cout << endl;
	for(int i = 0; i < 10; i++) 
		cout << deq[i] << " "; 
	cout << endl;
	cout << deq.front() << " " << deq.back() << endl;
} 
//deque排序 
//	sort(iterator begin, iterator end) 对[begin, end)区间内元素排序。 
void test06()
{
	deque<int> deq; 
	for(int i = 0; i < 10; i++) 
		deq.push_front(i);
	printDeque(deq);
	sort(deq.begin(), deq.begin() + 5);
	printDeque(deq);
} 
int main()
{
//	test01();
//	test02();
//	test03();
//	test04();
//	test05();
	test06();
	system("pause");	
	return 0;
} 
