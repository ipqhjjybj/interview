#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ori="{\"time\":1701245639,\"time_ms\":1701245639014,\"channel\":\"futures.order_book_update\",\"event\":\"update\",";
string getStrValueFromKey(string s, string key);

//string ori2="\"a\":[{\"p\":\"38155.9\",\"s\":0},{\"p\":\"38154.5\",\"s\":0},{\"p\":\"38154.5\",\"s\":0}],";
string ori2="\"b\":[],\"s\":\"BTC_USDT\"";
vector<string> getArrayValueFromKey(string s, string key){
	vector<string> ans;
	int pos = s.find("\"" + key + "\"");
	s = s.substr(pos);
	int left_find = s.find("[");
	int right_find = s.find("]");
	string arrayinfo = s.substr(left_find, right_find - left_find + 1);
	vector<int> cc;
	for(int i = 0;i < arrayinfo.size();i++){
		// && i + 1 < arrayinfo.size() && arrayinfo[i-1] == '{'
		if(arrayinfo[i] == ',' && i > 0 && arrayinfo[i-1] == '}' ){
			cc.push_back(i);
		}
	}
	cc.push_back(arrayinfo.size() - 1);

	int left = 1;
	for(int i = 0; i < cc.size();i++){
		int ns = cc[i];
		//printf("i=%d ns=%d\n", i, ns);
		string line = arrayinfo.substr(left, ns - left );
		if(line.size() > 0){
			ans.push_back(line);
		}
		left = ns+1;
	}
	return ans;
}


struct priceVolume{
	string price;
	int volume;
	priceVolume(){volume=0;}

	void print(){
		cout << "price:" << price << endl;
		cout << "volume:" << volume << endl;
	}

};

string getStrIntgerValueFromKey(string s, string key);
string getStrValueFromKey(string s, string key);

int main(){
	// {"p":"38155.9","s":0}

	//string result = getStrValueFromKey(ori, "channel");
	cout << "debug 1" << endl;
	vector<string> lines = getArrayValueFromKey(ori2, "b");
	cout << "debug 2" << endl;
	vector<priceVolume> vecPriceVolume;
	for(int i = 0;i < lines.size();i++){
		cout << "line:" << lines[i] << " why!!" << endl;
		string ask_price = getStrValueFromKey(lines[i], "p");
		string ask_sell_number = getStrIntgerValueFromKey(lines[i], "s");

		cout << "ask_price:" << ask_price << endl;
		cout << "ask_sell_number:" << ask_sell_number << endl;
	}

	return 0;
}

string getStrIntgerValueFromKey(string s, string key){
	int pos = s.find(key + "\"");
	int n = key.size();
	string result = s.substr(pos + n + 2);
	int end_pos = result.find(",");
	result = result.substr(0, end_pos);
	//cout << "result size:" << result.size() << endl;
	if(result.size() > 0 && result[result.size()-1] == '}'){
		result = result.substr(0, result.size()-1);
	}
	//cout << result << endl;
	return result;
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