#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <chrono>

using namespace std;
using namespace chrono;

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

struct snapshot{
	map<double, int> asks;
	map<double, int> bids;
	snapshot(){
		asks.clear();
		bids.clear();
	}

	void update(priceVolume info, int direction){
		
	}
};



int main(){

	return 0;
}