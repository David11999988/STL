#include<iostream>
#include<string> 
#include<stack> 
using namespace std;
//stack�Ĺ��캯��
//	stack<T> stk Ĭ�Ϲ��캯����
//	stack<T>(const stack &stk) �������캯����
//stack��ֵ����
//	stack& operator=(const stack &stk) ���� = ������� 
//��stack�Ĵ�С���в�����
//	empty() �ж������Ƿ�Ϊ�ա�
//	size() ����������Ԫ�صĸ�����
//stack���ݴ�ȡ
//	push(elem) ��ջ��
//	pop() ջ��Ԫ�س�ջ��
//	top() ����ջ��Ԫ�ء�
void test01()
{
	//Ĭ�Ϲ��캯��
	stack<int> stk;
	//Ԫ����ջ 
	for(int i = 0; i < 5; i++)
		stk.push(i);
	cout << "ջ��Ԫ�ظ�����" << stk.size() << endl;
	cout << "ջ��Ԫ��(��ջ����ջ��)��" << endl; 
	//ֻҪջ��Ϊ�գ��鿴ջ��������ִ�г�ջ����
	while(!stk.empty())
	{
		//�鿴ջ��Ԫ��
		cout << stk.top() << " ";
		//ջ��Ԫ�س�ջ��Ϊ�˷�����һ��Ԫ�� 
		stk.pop(); 
	} 
	cout << endl << "ջ��Ԫ�ظ�����" << stk.size() << endl;
} 
int main()
{
	test01();
	system("pause");	
	return 0;
} 
