/**
 *
要求：开发一个高效率两方ID求交的算法prototype。
注意：首先，需要先确定整体思路，然后再进行代码实现。
输入：两个固定长度256字节的字符串数据组，分别来自两个参与方。
输出：交集部分。

输入例子:

a.in
abcde abcef

a.out
abce

a_dic, b_dic
*/
#include <cstdio>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

unordered_map<char, int> a_dic;
//set<char> a_dic;
string a, b;
int main(){
	cin >> a >> b;
	int u = a.size();
	for(int i = 0;i < u;i++){
		a_dic[a[i]] = 1;
		//a_dic.insert(a[i]);
	} //nlogn + nlogn
	string ans = "";
	int n = b.size();
	for(int i = 0;i < n;i++){
		if(a_dic.count(b[i])){
			ans += b[i];
		}
	}
	cout << ans << endl;

	return 0;
}