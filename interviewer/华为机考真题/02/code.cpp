#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

bool cmp(pair<string, int> it1, pair<string, int> it2){
	if(it1.second == it2.second){
		if(it1.first.length() == it2.first.length()){
			return it1.first < it2.first;
		}else{
			return it1.first.length() < it2.first.length();
		}
	}else{
		return it1.second > it2.second;
	}
}

int main(){
	string word;
	map<string, int> all_cnt;

	while(cin >> word){
		sort(word.begin(), word.end());
		all_cnt[word]+= 1;
		word.clear();
	}
	
	vector<pair<string, int> > vecWords(all_cnt.begin(), all_cnt.end());
	sort(vecWords.begin(), vecWords.end(), cmp);

	bool first = true;
	int n = vecWords.size();
	for(int i = 0; i < n;i++){
		pair<string, int> use_pair = vecWords[i];
		for(int j = 0; j < use_pair.second;j++){
			if(first){
				first = false;
				cout << use_pair.first;
			}else{
				cout << " " << use_pair.first;
			}
		}
	}
	cout << endl;
}

