#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

struct priceVolume{
	string price;
	int volume;
	priceVolume(){volume=0;}

	void print(){
		cout << "price:" << price << endl;
		cout << "volume:" << volume << endl;
	}
};

struct depthResult{
	string U;
	priceVolume bids, asks;
	void print(){
		cout << "bids:" << endl;
		bids.print();
		cout << "asks:" << endl;
		asks.print();
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
	
	cin >> line;
	cout << line << endl;

	depthUpdate ans = parseDepthUpdate(line);
	//ans.print();
	
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
	//cout << result << endl;
	return result;
}

struct depthUpdate parseDepthUpdate(string line){
	depthUpdate data;
	int pos = line.find("\"result\"");
	printf("pos=%d\n", pos);
	string left_line = line.substr(0, pos);
	string right_line = line.substr(pos);
	cout << "left_line:" << left_line << endl;

	data.time = atoi(left_line.substr(8, 10).c_str());
	data.time_ms = left_line.substr(29, 13);
	data.channel = getStrValueFromKey(left_line, "channel");
	data.event = getStrValueFromKey(left_line, "event");

	cout << "time:" << data.time << endl;
	cout << "time_ms:" << data.time_ms << endl;
	cout << "channel:" << data.channel << endl;
	cout << "event:" << data.event << endl;

	//cout << "right_line:" << right_line << endl;

	int mid_s = right_line.find("\"s\":\"");
	string mid_line = right_line.substr(0, mid_s);
	string end_line = right_line.substr(mid_s);

	data.result.U = getStrIntgerValueFromKey(mid_line, "U");
	cout << "data.result.U: " << data.result.U << endl;
	cout << "mid_line:" << mid_line << endl;
	cout << "end_line:" << end_line << endl;

	string real_symbol = end_line.substr(5);
	int tpos = real_symbol.find("\",\"t");
	data.symbol = real_symbol.substr(0, tpos);
	

	//cout << "real_symbol:" << real_symbol << endl;
	// char symbol[20];
	// sscanf("\"s\":\"BTC_USDT\",\"t\":1701245639006,\"u\":53095233724}}", "\"s\":\"%s\",\"t\":%d,\"u\":%d}}", symbol, &data.t, &data.u);

	return data;
} 