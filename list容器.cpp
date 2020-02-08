#include<iostream>
#include<string>
#include<list> 
#include<algorithm>
using namespace std;
void printList(const list<int> &l)
{
	//����const_������Ϊ�������const deque<int>  const_iteratorֻ��������
	for(list<int>::const_iterator it = l.begin(); it != l.end(); it++)
		cout << *it << " ";
	cout << endl;
}
//list��������
//	list<T> v Ĭ�Ϲ��캯����
//	list<T>(v.begin(), v.end()) ��v��[begin(), end())�����е�Ԫ�ؿ���������ע����ǰ�պ󿪡�
//	list<T>(n, elem) ��n��elem����������
//	list<T>(const list &lst) �������캯����
void test01()
{
	//Ĭ�Ϲ��캯�� 
	list<int> l1;  
	for(int i = 0; i < 5; i++) 
		l1.push_back(i);
	for(int i = 5; i < 10; i++) 
		l1.push_front(i);
	printList(l1);
	//ͨ�����䷽ʽ���й��� 
	list<int> l2(l1.begin(), l1.end());  
	printList(l2);
	//ͨ��n��elem���й���
	list<int> l3(10, 1);
	printList(l3);
	//�������캯�� 
	list<int> l4(l3);
	printList(l4);
}
//list��ֵ����
//	list& operator=(const list &vec) ���� = �������
//	assign(beg, end) ��[beg, end)��������ݿ�����ֵ������
//	assign(n, elem) ��n��elem������ֵ������
//	swap(lst) ��lst�뱾���Ԫ�ػ�����
void test02()
{
	list<int> l1;  
	for(int i = 0; i < 5; i++) 
		l1.push_back(i);
	for(int i = 5; i < 10; i++) 
		l1.push_front(i);
	printList(l1);
	//���� = �������
	list<int> l2;
	l2 = l1;
	printList(l2);
	//ͨ��������и�ֵ
	list<int> l3;
	l3.assign(l1.begin(), l1.end()); 
	printList(l3);
	//��n��elem������ֵ������
	list<int> l4;
	l4.assign(5, 1);
	printList(l4);
	//����Ԫ��
	l3.swap(l4);
	printList(l3);
	printList(l4);
}
//��list�����Ĵ�С���в�����
//	empty() �ж������Ƿ�Ϊ�ա�
//	size() ����������Ԫ�صĸ�����
//	resize(int num) ����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�ã���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
//	resize(int num, elem) ����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�ã���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
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
//list�����ɾ��
//	���˲�����
//		push_back(elem) ������β�����һ�����ݡ�
//		pop_back() ɾ���������1�����ݡ�
//		push_front(elem) ������ͷ������һ�����ݡ�
//		pop_front() ɾ��������1�����ݡ�
//	ָ��λ�ò�����
//		insert(pos, elem) ��posλ�ò���1��elemԪ�صĿ��������������ݵ�λ�á�
//		insert(pos, n, elem) ��posλ�ò���n��elem���ݣ��޷���ֵ��
//		insert(pos, begin, end) ��posλ�ò���[begin, end)�����е����ݣ��޷���ֵ��
//		clear() ɾ������������Ԫ�ء�
//		erase(begin, end) ɾ��[begin, end)�����е����ݣ�������һ�����ݵ�λ�á�
//		erase(pos) ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
//		remove(elem) ɾ��������������elemֵƥ������ݡ�
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
//list���ݴ�ȡ
//	front() ���������е�1������Ԫ�ء�
//	back() �������������1������Ԫ�ء�
void test05()
{
	list<int> lst;   
	for(int i = 0; i < 5; i++) 
		lst.push_back(i);
	for(int i = 5; i < 10; i++) 
		lst.push_front(i);
	printList(lst);
	cout << "��1��Ԫ�أ�" << lst.front() << "  ";
	cout << "���1��Ԫ�أ�" << lst.back() << endl; 
	list<int>::iterator it;
	it = lst.begin(); 
	it++;  //��ȷ��list�����ĵ�����֧��ǰ�ƺͺ��� 
	it--;  //��ȷ 
//	it = it + 1;  //����list�����ĵ�������֧��������ʼ� +n�Ĳ��� 
} 
//list��ת������ 
//	reverse() ��ת������vector������reserve(int len)�������ֿ���
//	sort() �������򣬳�Ա������Ĭ�������������
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
	//���в�֧��������ʵ��������������������ñ�׼�㷨 
	//sort(lst.begin(), lst.end());
	//��֧��������ʵ��������������ڲ����ṩһЩ��Ӧ���㷨 
	lst.sort();  //Ĭ������������� 
	printList(lst);
	lst.sort(myCompare);  //�������� 
	printList(lst);
} 
//list������
//	����������
//		��Person�Զ����������ͽ�������Person�����������������䡢��ߡ�
//	�������
//		������������������������ͬ������߽��н���
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
		cout << "name��" << name << "  ";
		cout << "age��" << age << "  ";
		cout << "height��" << height << endl;
	}
}; 
bool myCompare1(const Person &p1,const Person &p2)
{
	if(p1.age == p2.age)  //������ͬ����߽��� 
		return p1.height > p2.height;
	else  //�������� 
		return p1.age < p2.age;
}
/* printList����������Ĳ�����const list<Person> &���ͣ������в��ܸı�lst�д洢��Person�����ĳ�Ա������ֵ���ָú���
���õ��˳�Ա����showPerson()������showPerson()���뱣֤���ܸı�Person������г�Ա������ֵ������Ҫ��const����showPerson()
������Ļ��ᱨ�� 
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
	//׼������ 
	Person p1("����", 35, 175);
	Person p2("�ܲ�", 45, 180);
	Person p3("��Ȩ", 40, 170);
	Person p4("����", 25, 190);
	Person p5("�ŷ�", 35, 160);
	Person p6("����", 35, 200);
	//list�����в������� 
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
