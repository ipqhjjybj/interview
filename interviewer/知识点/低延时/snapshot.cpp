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

bool comp_ask(pair<double,int> a1, pair<double,int >a2){
	return a1.first < a2.first;
}
bool comp_bid(pair<double,int> b1, pair<double,int >b2){
	return b1.first > b2.first;
}
struct snapshot{
	map<double, int> asks;
	map<double, int> bids;
	snapshot(){
		asks.clear();
		bids.clear();
	}

	void updateBid(priceVolume info){
		double price = stod(info.price);
		if(info.volume == 0 && bids.count(price) > 0){
			bids.erase(price);
		}else if(info.volume > 0){
			bids[price] = info.volume
		}
	}
	void updateAsk(priceVolume info){
		double price = stod(info.price);
		if(info.volume == 0 && asks.count(price) > 0){
			asks.erase(price);
		}else if(info.volume > 0){
			asks[price] = info.volume;
		}
	}

	void print_latest_20(){
		vector<pair<double,int> > pair_asks(asks.begin(), asks.end());

		sort(pair_asks.begin(), pair_asks.end(), comp_ask);
	}
};

void testbids(){

}

void testasks(){

}

int main(){
	testbids();
	testasks();
	return 0;
}