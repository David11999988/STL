#include<iostream>
#include<string> 
using namespace std;
//string�Ĺ��캯��
//	string() ����һ���յ��ַ���������string str��
//	string(const char *s) ʹ���ַ���s��ʼ����
//	string(const string &s) �������죬ʹ��һ��string�����ʼ����һ��string����
//	string(int n, char c) ʹ��n���ַ�c��ʼ����
void test01()
{
	string s1;  //Ĭ�Ϲ��� 
	const char *str = "hello world";
	string s2(str);  //ʹ���ַ�����ʼ�� 
	cout << "s2 = " << s2 << endl; 
	string s3(s2);  //ʹ�ÿ������� 
	cout << "s3 = " << s3 << endl; 
	string s4(10, 'a');  //ʹ��n���ַ���ʼ�� 
	cout << "s4 = " << s4 << endl; 
} 
//string��ֵ����
//	string& operator=(const char *s) char*���͵��ַ�����ֵ����ǰ�ַ�����
//	string& operator=(const string &s) ���ַ���s��ֵ����ǰ�ַ�����
//	string& operator=(char c) �ַ���ֵ����ǰ�ַ�����
//	string& assign(const char *s) ���ַ���s��ֵ����ǰ�ַ�����
//	string& assign(const char *s, int n) ���ַ���s��ǰn���ַ���ֵ����ǰ�ַ�����
//	string& assign(const string &s) ���ַ���s��ֵ����ǰ�ַ�����
//	string& assign(int n, char c) n���ַ�c��ֵ����ǰ�ַ�����
void test02() 
{
	string s1, s2, s3, s4, s5, s6, s7;
	s1 = "hello world";  //string& operator=(const char *s)
	cout << "s1 = " << s1 << endl;
	s2 = s1;  //string& operator=(const string &s)
	cout << "s2 = " << s2 << endl;
	s3 = 'a';  //string& operator=(char c)
	cout << "s3 = " << s3 << endl;
	s4.assign("hello C++");  //string& assign(const char *s)
	cout << "s4 = " << s4 << endl;
	s5.assign("hello world", 5);  //string& assign(const char *s, int n)
	cout << "s5 = " << s5 << endl;
	s6.assign(s5);  //string& assign(const string &s)
	cout << "s6 = " << s6 << endl;
	s7.assign(10, 'a');  //string& assign(int n, char c)
	cout << "s7 = " << s7 << endl;
} 
//string�ַ���ƴ��
//	string& operator+=(const char *str) ����+=�������
//	string& operator+=(const char c) ����+=�������
//	string& operator+=(const string &str) ����+=�������
//	string& append(const char *s) ���ַ���s���ӵ���ǰ�ַ�����β��
//	string& append(const char *s, int n) ���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β��
//	string& append(const string &s) ͬoperator+=(const string &str)��
//	string& append(const string &s, int pos, int n) �ַ���s�д�pos��ʼ��n���ַ����ӵ���ǰ�ַ�����β��
void test03()
{
	const char* s = "hello ";
	string s1(s), s2(s), s3(s), s4(s), s5(s), s6(s), s7(s);
	s1 += "s1";  //string& operator+=(const char *str)
	cout << "s1��" << s1 << endl;
	(s2 += 's') += '2';  //string& operator+=(const char c)
	cout << "s2��" << s2 << endl;
	string str3 = "s3";
	s3 += str3;  //string& operator+=(const string &str)
	cout << "s3��" << s3 << endl;
	s4.append("s4");  //string& append(const char *s)
	cout << "s4��" << s4 << endl;
	s5.append("s5s5s5", 2);  //string& append(const char *s, int n)
	cout << "s5��" << s5 << endl;
	string str6("s6"); 
	s6.append(str6);  //string& append(const string &s)
	cout << "s6��" << s6 << endl;
	string str7("hello s7!");  
	s7.append(str7, 6, 2);  //string& append(const string &s, int pos, int n)
	cout << "s7��" << s7 << endl;
}
//�ַ������� 
//	int find(const string& str, int pos = 0) const  //����str��һ�γ��ֵ�λ�ã���pos(�±꣬��0��ʼ)��ʼ����
//	int find(const char *s, int pos = 0) const  //����s��һ�γ��ֵ�λ�ã���pos��ʼ����		
//	int find(const char *s, int pos, int n) const  //��posλ�ò���s��ǰn���ַ���һ�γ��ֵ�λ��		
//	int find(const char c, int pos = 0) const  //�����ַ�c��һ�γ��ֵ�λ��		
//	int rfind(const string& str, int pos = npos) const  //����str���һ�γ��ֵ�λ�ã���pos��ʼ����
//	int rfind(const char *s, int pos = npos) const  //����s���һ�γ��ֵ�λ�ã���pos��ʼ����
//	int rfind(const char *s, int pos, int n) const  //��posλ�ò���s��ǰn���ַ����һ�γ��ֵ�λ��
//	int rfind(const char c, int pos = 0) const  //�����ַ�c���һ�γ��ֵ�λ��

void test04()
{
	string s = "hello world world!";
	//�޷����������ֵ���з�����-1�Ĳ�������ͬ��
	cout << (string::npos == -1) << "  "; 
	cout << (s.find("wood")  == string::npos) << endl;
	string s1 = "world";
	cout << s.find(s1, 0) << "  ";
	cout << ("world", 0) << "  ";
	cout << (s.find("world1", 0) == -1) << "  ";
	cout << s.find("wood", 0, 2) << "  ";
	cout << s.find('o', 0) << "  ";
	cout << s.rfind(s1, string::npos) << "  ";
	cout << s.rfind(s1, 11) << "  "; 
	cout << s.rfind(s1, 12) << "  ";
	cout << s.rfind("world", string::npos) << "  ";
	cout << s.rfind("wood", string::npos, 2) << "  ";
	cout << s.rfind('o', string::npos) << endl;
} 
//�ַ����滻 
//	string& replace(int pos, int n, const string &str)  //���ַ���str�滻��pos��ʼ��n���ַ�		
//	string& replace(int pos, int n, const char *s)  //���ַ���s�滻��pos��ʼ��n���ַ�
void test05()
{
	string s = "hello world";
	string str = "C++";
	cout << s.replace(6, 5, str) << "  ";
	cout << s.replace(6, 5, "David Wu") << endl; 
}
//�ַ����Ƚ�
//	int compare(const string &s) const
//	int compare(const char *s) const
void test06()
{
	string s = "hello world";
	string str = "hello C++";
	cout << s.compare(str) << "  ";
	cout << s.compare("hello world") << "  ";
	cout << s.compare("zero") << endl; 
}
//string�ַ���ȡ
//	char& operator[](int n) ͨ��[]��ʽ��ȡ�ַ�
//	char& at(int n) ͨ��at������ȡ�ַ�

void test07()
{
	string s = "hello world";
	//����ÿ���ַ� 
	for(int i = 0; i < s.size(); i++) 
		cout << s[i] << " ";
	cout << endl;
	for(int i = 0; i < s.size(); i++) 
		cout << s.at(i) << " ";
	cout << endl;
	//�޸ĵ����ַ�
	s[6] = 'x';
	s.at(7) = 'p';
	cout << s << endl;  
}
//string�����ɾ��
//	string& insert(int pos, const char *s) ��ָ��λ�ò����ַ���
//	string& insert(int pos, const string &s) ��ָ��λ�ò����ַ���
//	string& insert(int pos, int n, char c) ��ָ��λ�ò���n���ַ�c
//	string& erase(int pos, int n = npos) ɾ����pos��ʼ��n���ַ�
void test08()
{
	string s = "hello world";
	s.insert(6, "my ");
	cout << s << endl; 
	string str("great ");
	s.insert(9, str);
	cout << s << endl; 
	s.insert(6, 3, 'a');
	cout << s << endl;
	s.erase(6, 12);
	cout << s << endl;
}
//string�Ӵ�
//	string substr(int pos = 0, int n = npos) const  //������pos��ʼ��n���ַ���ɵ��ַ���
void test09()
{
	string s = "hello world";
	string str = s.substr(6, 5);
	cout << str << endl;
	//�������ַ�л�ȡ�û�����Ϣ 
	s = "wudawei1998@163.com";
	string username(s.substr(0, s.find('@')));
	cout << "username��" << username << endl; 
}
int main()
{
//	test01(); 
//	test02();
//	test03();
//	test04();
//	test05(); 
//	test06();
//	test07();
//	test08();
	test09(); 
	system("pause");	
	
	return 0;
} 
