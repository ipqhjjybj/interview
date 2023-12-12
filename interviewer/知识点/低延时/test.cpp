#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include<chrono>
using namespace std;
using namespace chrono;

typedef std::chrono::high_resolution_clock Clock;

struct priceVolume{
	string price;
	int volume;
	priceVolume(){volume=0;}
	priceVolume(string _price, int _volume){
		price = _price;
		volume = _volume;
	}

	void print(){
		cout << "price:" << price << endl;
		cout << "volume:" << volume << endl;
	}
};

struct depthResult{
	string U;
	vector<priceVolume> bids, asks;
	void print(){
		cout << "bids:" << endl;
		for(int i = 0;i < bids.size(); i++){
			cout << "priceVolume:" << i << ": " ;
			bids[i].print();	
		}
		cout << "asks:" << endl;
		for(int i = 0;i < asks.size(); i++){
			cout << "priceVolume:" << i << ": " ;
			asks[i].print();	
		}
	}
};

struct depthUpdate{
	int time;
	string time_ms;
	string channel;
	string event;
	depthResult result;
	string symbol;
	int t;
	int u;

	void print(){
		cout << "time:" << time << endl;
		cout << "time_ms:" << time_ms << endl;
		cout << "channel:" << channel << endl;
		cout << "event:" << event << endl;
		cout << "result:" << endl;
		result.print(); 
		cout << "symbol:" << symbol << endl;
		cout << "t:" << t << endl;
		cout << "u:" << u << endl;
	}
};

struct depthUpdate parseDepthUpdate(string line);


int main(){
	string line;
	
	//while(cin >> line){
		//cout << line << endl;
	cin >> line;

		auto t1 = Clock::now();//计时开始
		depthUpdate ans = parseDepthUpdate(line);
		auto t2 = Clock::now();//计时结束

		cout << "compute time:" << endl;
		std::cout <<std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 1e+3 << '\n';

		//ans.print();
	//}
	
	// while(cin >> line){
	// 	cout << line << endl;
	// }

	return 0;
}

string getStrValueFromKey(string s, string key){
	int pos = s.find(key + "\"");
	int n = key.size();
	string result = s.substr(pos + n + 3);
	int end_pos = result.find("\"");
	result = result.substr(0, end_pos);
	//cout << result << endl;
	return result;
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
		// printf("i=%d ns=%d\n", i, ns);
		string line = arrayinfo.substr(left, ns - left );
		// cout << "line:" << line << endl;
		if(line.size() > 0){
			ans.push_back(line);
		}
		left = ns+1;
	}
	return ans;
}

struct depthUpdate parseDepthUpdate(string line){
	depthUpdate data;
	int pos = line.find("\"result\"");
	// printf("pos=%d\n", pos);
	string left_line = line.substr(0, pos);
	string right_line = line.substr(pos);
	
	//cout << "left_line:" << left_line << endl;

	data.time = atoi(left_line.substr(8, 10).c_str());
	data.time_ms = left_line.substr(29, 13);
	data.channel = getStrValueFromKey(left_line, "channel");
	data.event = getStrValueFromKey(left_line, "event");

	// cout << "time:" << data.time << endl;
	// cout << "time_ms:" << data.time_ms << endl;
	// cout << "channel:" << data.channel << endl;
	// cout << "event:" << data.event << endl;

	// cout << "right_line:" << right_line << endl;

	int mid_s = right_line.find("\"s\":\"");
	string mid_line = right_line.substr(0, mid_s);
	string end_line = right_line.substr(mid_s);

	data.result.U = getStrIntgerValueFromKey(mid_line, "U");
	// cout << "data.result.U: " << data.result.U << endl;
	// cout << "mid_line:" << mid_line << endl;
	// cout << "end_line:" << end_line << endl;

	vector<string> a_vector = getArrayValueFromKey(mid_line, "a");
	for(int i = 0;i < a_vector.size();i++){
		string ask_price = getStrValueFromKey(a_vector[i], "p");
		int ask_sell_number = atoi(getStrIntgerValueFromKey(a_vector[i], "s").c_str());

		data.result.bids.push_back(priceVolume(ask_price, ask_sell_number));
	}

	vector<string> b_vector = getArrayValueFromKey(mid_line, "b");
	for(int i = 0;i < b_vector.size();i++){
		string bid_price = getStrValueFromKey(b_vector[i], "p");
		int bid_buy_number = atoi(getStrIntgerValueFromKey(b_vector[i], "s").c_str());
		data.result.asks.push_back(priceVolume(bid_price, bid_buy_number));
	}

	string real_symbol = end_line.substr(5);
	int tpos = real_symbol.find("\",\"t");
	data.symbol = real_symbol.substr(0, tpos);
	
	//cout << "real_symbol:" << real_symbol << endl;
	// char symbol[20];
	// sscanf("\"s\":\"BTC_USDT\",\"t\":1701245639006,\"u\":53095233724}}", "\"s\":\"%s\",\"t\":%d,\"u\":%d}}", symbol, &data.t, &data.u);

	return data;
} 