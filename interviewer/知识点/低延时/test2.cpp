#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string ori="{\"time\":1701245639,\"time_ms\":1701245639014,\"channel\":\"futures.order_book_update\",\"event\":\"update\",";
string getStrValueFromKey(string s, string key);

int main(){
	string result = getStrValueFromKey(ori, "channel");

	return 0;
}

string getStrValueFromKey(string s, string key){
	int pos = s.find(key + "\"");
	int n = key.size();
	string result = s.substr(pos + n + 3);
	int end_pos = result.find("\"");
	result = result.substr(0, end_pos);

	cout << result << endl;
	return result;
}