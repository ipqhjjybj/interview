#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

struct node{
	int left, right, val;

	node(){}
	node(int _left, int _right, int _val){
		left = _left;
		right = _right;
		val = _val;
	}

	bool operator <(const node &a) const{
		if(left == a.left){return right < a.right;}
		else{
			return left < a.left;
		}
	}
};

int n;
vector<node> vecs;
int result[200100];
int main(){
	cin >> n;
	vector<int> all_nums;
	map<int, int> mp;
	for(int i = 0;i < n;i++){
		int a,b,c;
		cin >> a >> b >> c;
		all_nums.push_back(a);
		all_nums.push_back(b);
		vecs.push_back(node(a,b,c));
	}
	sort(vecs.begin(), vecs.end());
	sort(all_nums.begin(), all_nums.end());
	for(int i = 0; i < all_nums.size();i++){
		mp[all_nums[i]] = i;
	}

	for(int i = 0;i < n;i++){
		int left_index = mp[vecs[i].left];
		int right_index = mp[vecs[i].right];
		for(int j = left_index; j <= right_index;j++){
			result[j] += vecs[i].val;
		}
	}	
	int now_server_num = 0;
	for(int i = 0;i <= all_nums.size();i++){
		now_server_num = max(now_server_num, result[i]);
	}
	cout << now_server_num << endl;
}