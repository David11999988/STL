#include<iostream>
#include<string> 
#include<deque> 
#include<algorithm> 
using namespace std;
//void printDeque(const deque<int> &dec)
//{
//	//����const_����[Error] conversion from 'std::deque<int>::const_iterator {aka std::_Deque_iterator<int, const int&, const int*>}' to non-scalar type 'std::deque<int>::iterator {aka std::_Deque_iterator<int, int&, int*>}' requested 
//	//��Ϊ�������const deque<int>  const_iteratorֻ�������� 
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
//deque�Ĺ��캯��
//	deque<T> deq Ĭ�Ϲ��캯����
//	deque<T>(begin, end) ��v[begin, end)�����е�Ԫ�ؿ���������ע����ǰ�պ󿪡�
//	deque<T>(n, elem) ��n��elem����������
//	deque<T>(const deque &deq) �������캯����
void test01()
{
	//Ĭ�Ϲ��캯��
	deque<int> d1;
	for(int i = 0; i < 10; i++)
		d1.push_back(i);
	printDeque(d1);
	//��v[begin, end)�����е�Ԫ�ؿ���������
	deque<int> d2(d1.begin(), d1.end()); 
	printDeque(d2);
	//��n��elem����������
	deque<int> d3(10, 1);
	printDeque(d3);
	//�������캯��
	deque<int> d4(d1);
	printDeque(d4);
} 
//deque��ֵ����
//	deque& operator=(const deque &deq) ���� = �������
//	assign(beg, end) ��[beg, end)��������ݿ�����ֵ������
//	assign(n, elem) ��n��elem������ֵ������
void test02()
{
	deque<int> d1;  
	for(int i = 0; i < 10; i++) 
		d1.push_front(i);
	printDeque(d1);
	//���� = �������
	deque<int> d2;
	d2 = d1;
	printDeque(d2);
	//ͨ��������и�ֵ
	deque<int> d3;
	d3.assign(d1.begin(), d1.end()); 
	printDeque(d3);
	//��n��elem������ֵ������
	deque<int> d4;
	d4.assign(10, 1);
	printDeque(d4);
}
//��deque�Ĵ�С���в�����
//	empty() �ж������Ƿ�Ϊ�ա�
//	size() ����������Ԫ�صĸ�����
//	resize(int num) ����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�ã���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
//	resize(int num, elem) ����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�ã���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
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
//deque�����ɾ��
//	���˲���ɾ������:
//		push_back(elem) ������β�����һ�����ݡ�
//		push_front(elem) ������ͷ������һ�����ݡ�
//		pop_back() ɾ���������1�����ݡ�
//		pop_front() ɾ��������1�����ݡ�
//	ָ��λ�ò�����
//		insert(pos, elem) ��posλ�ò���1��elemԪ�صĿ��������������ݵ�λ�á�
//		insert(pos, n, elem) ��posλ�ò���n��elem���ݣ��޷���ֵ��
//		insert(pos, begin, end) ��posλ�ò���[begin, end)�����е����ݣ��޷���ֵ��
//		clear() ������������е����ݡ�
//		erase(begin, end) ɾ��[begin, end)�����е����ݣ�������һ�����ݵ�λ�á�
//		erase(pos) ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
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
//deque���ݴ�ȡ
//	at(int idx) ��������idx��ָ�����ݡ�
//	operator[](int idx) ����� [] ���أ���������idx��ָ�����ݡ�
//	front() ���������е�1������Ԫ�ء�
//	back() �������������1������Ԫ�ء�
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
//deque���� 
//	sort(iterator begin, iterator end) ��[begin, end)������Ԫ������ 
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
