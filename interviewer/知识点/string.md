#include<bits/stdc++.h>     // 包含通用C++头文件
using namespace std;
str = str.substr(start, k);     // 截取字符串的代码（从start开始截取k个），注意要赋值。不加k为截取到最后
return {tail, head};  tie(head, tail) = myReverse(head, tail);  // 返回两个值时，用tie去接收。

isupper()判断一个字符是否是大写字母
isalpha()判断一个字符是否是字母
isalnum()判断一个字符是否是字母或者数字
isblank()判断一个字符是否是空白符
isdigit()判断一个字符是否是十进制数字
islower()判断一个字符是否是小写字母
isspace()判断一个字符是否是空白符
tolower()将大写字母转换为小写字母
toupper()将小写字母转换为大写字母


while(cin >> str)   // 每次读一个string
cin >> a >> b >> c;     // 依次读入 20 3 5
while (getline(cin, s))    // 每次取一行的字符串，输入到s
while(cin >> hex >> res)  //hex表示读入十六进制数
cout << dec << res << endl; //dec表示输出十进制数


// 常用方法
int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
int rfind(const string& str, int pos = npos) const; //查找str最后一次位置,从pos开始查找
string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
string& insert(int pos, const char* s); //插入字符串
string substr(int pos = 0, int n = npos) const; //返回由pos开始的n个字符组成的字符串
string.push_back()
string.pop_back()

// 遍历string
for (auto & str : balloon) {
    map[str] = 0;
}

atoi(string.c_str() // string转char转int。atoi字符串转换成整形
c_str()：生成一个const char*指针，指向以空字符终止的数组。或者，转成c语言字符串；
