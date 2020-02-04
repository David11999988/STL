#include<iostream>
#include<string> 
using namespace std;
//string的构造函数
//	string() 创建一个空的字符串，例如string str。
//	string(const char *s) 使用字符串s初始化。
//	string(const string &s) 拷贝构造，使用一个string对象初始化另一个string对象。
//	string(int n, char c) 使用n个字符c初始化。
void test01()
{
	string s1;  //默认构造 
	const char *str = "hello world";
	string s2(str);  //使用字符串初始化 
	cout << "s2 = " << s2 << endl; 
	string s3(s2);  //使用拷贝构造 
	cout << "s3 = " << s3 << endl; 
	string s4(10, 'a');  //使用n个字符初始化 
	cout << "s4 = " << s4 << endl; 
} 
//string赋值操作
//	string& operator=(const char *s) char*类型的字符串赋值给当前字符串。
//	string& operator=(const string &s) 把字符串s赋值给当前字符串。
//	string& operator=(char c) 字符赋值给当前字符串。
//	string& assign(const char *s) 把字符串s赋值给当前字符串。
//	string& assign(const char *s, int n) 把字符串s的前n个字符赋值给当前字符串。
//	string& assign(const string &s) 把字符串s赋值给当前字符串。
//	string& assign(int n, char c) n个字符c赋值给当前字符串。
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
//string字符串拼接
//	string& operator+=(const char *str) 重载+=运算符。
//	string& operator+=(const char c) 重载+=运算符。
//	string& operator+=(const string &str) 重载+=运算符。
//	string& append(const char *s) 把字符串s连接到当前字符串结尾。
//	string& append(const char *s, int n) 把字符串s的前n个字符连接到当前字符串结尾。
//	string& append(const string &s) 同operator+=(const string &str)。
//	string& append(const string &s, int pos, int n) 字符串s中从pos开始的n个字符连接到当前字符串结尾。
void test03()
{
	const char* s = "hello ";
	string s1(s), s2(s), s3(s), s4(s), s5(s), s6(s), s7(s);
	s1 += "s1";  //string& operator+=(const char *str)
	cout << "s1：" << s1 << endl;
	(s2 += 's') += '2';  //string& operator+=(const char c)
	cout << "s2：" << s2 << endl;
	string str3 = "s3";
	s3 += str3;  //string& operator+=(const string &str)
	cout << "s3：" << s3 << endl;
	s4.append("s4");  //string& append(const char *s)
	cout << "s4：" << s4 << endl;
	s5.append("s5s5s5", 2);  //string& append(const char *s, int n)
	cout << "s5：" << s5 << endl;
	string str6("s6"); 
	s6.append(str6);  //string& append(const string &s)
	cout << "s6：" << s6 << endl;
	string str7("hello s7!");  
	s7.append(str7, 6, 2);  //string& append(const string &s, int pos, int n)
	cout << "s7：" << s7 << endl;
}
//字符串查找 
//	int find(const string& str, int pos = 0) const  //查找str第一次出现的位置，从pos(下标，从0开始)开始查找
//	int find(const char *s, int pos = 0) const  //查找s第一次出现的位置，从pos开始查找		
//	int find(const char *s, int pos, int n) const  //从pos位置查找s的前n个字符第一次出现的位置		
//	int find(const char c, int pos = 0) const  //查找字符c第一次出现的位置		
//	int rfind(const string& str, int pos = npos) const  //查找str最后一次出现的位置，从pos开始查找
//	int rfind(const char *s, int pos = npos) const  //查找s最后一次出现的位置，从pos开始查找
//	int rfind(const char *s, int pos, int n) const  //从pos位置查找s的前n个字符最后一次出现的位置
//	int rfind(const char c, int pos = 0) const  //查找字符c最后一次出现的位置

void test04()
{
	string s = "hello world world!";
	//无符号数的最大值和有符号数-1的补码是相同的
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
//字符串替换 
//	string& replace(int pos, int n, const string &str)  //用字符串str替换从pos开始的n个字符		
//	string& replace(int pos, int n, const char *s)  //用字符串s替换从pos开始的n个字符
void test05()
{
	string s = "hello world";
	string str = "C++";
	cout << s.replace(6, 5, str) << "  ";
	cout << s.replace(6, 5, "David Wu") << endl; 
}
//字符串比较
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
//string字符存取
//	char& operator[](int n) 通过[]方式获取字符
//	char& at(int n) 通过at方法获取字符

void test07()
{
	string s = "hello world";
	//访问每个字符 
	for(int i = 0; i < s.size(); i++) 
		cout << s[i] << " ";
	cout << endl;
	for(int i = 0; i < s.size(); i++) 
		cout << s.at(i) << " ";
	cout << endl;
	//修改单个字符
	s[6] = 'x';
	s.at(7) = 'p';
	cout << s << endl;  
}
//string插入和删除
//	string& insert(int pos, const char *s) 在指定位置插入字符串
//	string& insert(int pos, const string &s) 在指定位置插入字符串
//	string& insert(int pos, int n, char c) 在指定位置插入n个字符c
//	string& erase(int pos, int n = npos) 删除从pos开始的n个字符
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
//string子串
//	string substr(int pos = 0, int n = npos) const  //返回由pos开始的n个字符组成的字符串
void test09()
{
	string s = "hello world";
	string str = s.substr(6, 5);
	cout << str << endl;
	//从邮箱地址中获取用户名信息 
	s = "wudawei1998@163.com";
	string username(s.substr(0, s.find('@')));
	cout << "username：" << username << endl; 
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
