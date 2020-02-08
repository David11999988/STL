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
//queue���캯����
//	queue<T> que Ĭ�Ϲ��캯����
//	queue<T>(const queue &que) �������캯����
//queue��ֵ������
//	queue& operator=(const queue &que) ���� = �������
//queue���ݴ�ȡ��
//	push(elem) ����β���Ԫ�ء�
//	pop() �Ӷ�ͷ�Ƴ���1��Ԫ�ء�
//	back() �������1��Ԫ�ء�
//	front() ���ص�1��Ԫ�ء�
//queue��С������
//	empty() �ж�queue�����Ƿ�Ϊ�ա�
//	size() ����������Ԫ�ظ�����
void test01()
{
	//Ĭ�Ϲ��캯��
	queue<Person> que;
	//׼������
	Person p1("��ɮ", 30);
	Person p2("�����", 999);
	Person p3("��˽�", 888);
	Person p4("ɳɮ", 777);
	//Ԫ����� 
	que.push(p1); 
	que.push(p2);
	que.push(p3);
	que.push(p4);
	cout << "������Ԫ�ظ�����" << que.size() << endl;
	cout << "������Ԫ�أ�" << endl; 
	//ֻҪ���в�Ϊ�գ��鿴��ͷ������ִ�г��Ӳ���
	while(!que.empty())
	{
		//�鿴��ͷԪ��
		cout << "��ͷ��"; 
		que.front().showPerson();
		//�鿴��βԪ��
		cout << "��β��";
		que.back().showPerson();
		cout << endl;
		//��ͷԪ�س��ӣ�Ϊ�˷�����һ��Ԫ�� 
		que.pop(); 
	} 
	cout << "������Ԫ�ظ�����" << que.size() << endl;
} 
int main()
{
	test01();
	system("pause");	
	return 0;
} 
