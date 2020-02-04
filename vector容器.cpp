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
	{ cout << "��ͨ���캯��" << endl; }
	Person(const Person &p)
	{
			cout << "�������캯��" << endl; 
			m_Name = p. m_Name;
			m_Age = p. m_Age; 
	} 
 	void showPerson()
	{ cout << "name��" << m_Name << " age��" << m_Age << endl; }
};
//void printVector(const vector<int> &v)
//{
//	for(int i = 0; i < v.size(); i++)
//		cout << v[i] << " ";
//	cout << endl;
//}
void printVector(const vector<int> &v)
{
	//����const_������Ϊ�������const deque<int>  const_iteratorֻ��������
	for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
	cout << endl;
}
//vector��������
//	vector<T> v Ĭ�Ϲ��캯����
//	vector(v.begin(), v.end()) ��v[begin(), end())�����е�Ԫ�ؿ���������ע����ǰ�պ󿪡�
//	vector(n, elem) ��n��elem����������
//	vector(const vector &vec) �������캯����
void test01()
{
	//Ĭ�Ϲ��캯�� 
	vector<int> v1;  
	for(int i = 0; i < 10; i++) 
		v1.push_back(i);
	printVector(v1);
	//ͨ�����䷽ʽ���й��� 
	vector<int> v2(v1.begin(), v1.end());  
	printVector(v2);
	//ͨ��n��elem���й���
	vector<int> v3(10, 1);
	printVector(v3);
	//�������캯�� 
	vector<int> v4(v3);
	printVector(v4);
}
//vector��ֵ����
//	vector& operator=(const vector &vec) ���� = �������
//	assign(beg, end) ��[beg, end)��������ݿ�����ֵ������
//	assign(n, elem) ��n��elem������ֵ������
void test02()
{
	vector<int> v1;  
	for(int i = 0; i < 10; i++) 
		v1.push_back(i);
	printVector(v1);
	//���� = �������
	vector<int> v2;
	v2 = v1;
	printVector(v2);
	//ͨ��������и�ֵ
	vector<int> v3;
	v3.assign(v1.begin(), v1.end()); 
	printVector(v3);
	//��n��elem������ֵ������
	vector<int> v4;
	v4.assign(10, 1);
	printVector(v4);
}
//��vector�����������ʹ�С���в�����
//	empty() �ж������Ƿ�Ϊ�ա�
//	capacity() ������������
//	size() ����������Ԫ�صĸ�����
//	resize(int num) ����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�ã���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
//	resize(int num, elem) ����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�ã���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
void test03()
{
	vector<int> v1; 
	//�ж������Ƿ�Ϊ��
	cout << v1.empty() << " "; 
	//����������
	cout << v1.capacity() << " ";
	for(int i = 0; i < 10; i++) 
		v1.push_back(i);
	//�ж������Ƿ�Ϊ��
	cout << v1.empty() << " "; 
	//���������� ��̬��չ 
	cout << v1.capacity() << " ";
	//������Ԫ�صĸ���
	cout << v1.size() << endl;
	v1.resize(5);
	printVector(v1);
	//����������
	cout << v1.capacity() << endl;
	v1.resize(10);
	printVector(v1);
	v1.resize(5, 0);
	printVector(v1);
	v1.resize(21, 10);
	printVector(v1);
	//���������� ��̬��չ 
	cout << v1.capacity() << endl;
		
}
//vector�����ɾ��
//	push_back(elem) β������Ԫ��elem��
//	pop_back() ɾ�����1��Ԫ�ء�
//	insert(const_iterator pos, elem) ������ָ��λ��pos����Ԫ��elem��
//	insert(const_iterator pos, int n, elem) ������ָ��λ��pos����n��Ԫ��elem��
//	erase(const_iterator pos) ɾ��������ָ���Ԫ�ء�
//	erase(const_iterator start, const_iterator end) ɾ����������start��end֮���Ԫ�ء�
//	clear() ɾ������������Ԫ�ء�
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
//vector���ݴ�ȡ
//	at(int idx) ��������idx��ָ�����ݡ�
//	operator[](int idx) ����� [] ���أ���������idx��ָ�����ݡ�
//	front() ���������е�1������Ԫ�ء�
//	back() �������������1������Ԫ�ء�
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
//vector��������
//	swap(vec) ��vec�뱾���Ԫ�ؽ��л����� 
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
//swapʵ����; ����swap���������ڴ�ռ� 
void test07() 
{
	vector<int> v; 
	for(int i = 0; i < 100000; i++) 
		v.push_back(i);
	cout << "v��������" << v.capacity() << endl;
	cout << "v�Ĵ�С��" << v.size() << endl;
	v.resize(3);
	cout << "v��������" << v.capacity() << endl;
	cout << "v�Ĵ�С��" << v.size() << endl;
	vector<int> vec(20,8);
	vec = v;
	cout << "vec��������" << vec.capacity() << endl;
	cout << "vec�Ĵ�С��" << vec.size() << endl;  
	//����swap�����ڴ�
	vector<int>(v).swap(v);  //����������ÿ������캯�� 
	//��������ǰ�н�����ͻ��գ����˷��ڴ�ռ� 
	cout << "v��������" << v.capacity() << endl;
	cout << "v�Ĵ�С��" << v.size() << endl; 
} 
//vectorԤ���ռ�
//	reserve(int len) ����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ� 
void test08() 
{
	vector<int> v1; 
	vector<int> v2; 
	int *p1 = NULL;
	int *p2 = NULL;
	int num1 = 0;  //ͳ��v1�ڴ濪�ٴ���
	int num2 = 0;  //ͳ��v2�ڴ濪�ٴ���
	v2.reserve(100000);  //����reserveԤ���ռ� 
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
	cout << "v1�ڴ濪�ٴ�����" << num1 << endl;
	cout << "v1��������" << v1.capacity() << endl;
	cout << "v1�Ĵ�С��" << v1.size() << endl;
	cout << "v2�ڴ濪�ٴ�����" << num2 << endl;
	cout << "v2��������" << v2.capacity() << endl;
	cout << "v2�Ĵ�С��" << v2.size() << endl;
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
