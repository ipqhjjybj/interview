#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>


using namespace std;

bool cmp(char it1, char it2)
{
	char a = it1, b = it2;
	/*if (it1 >= 'A' && it1 <= 'Z')
	{
		a = it1 - 'A' + 'a';
	}
	if (it2 >= 'A' && it2 <= 'Z')
	{
		b = it2 - 'A' + 'a';
	}*/

	return a < b;
}
bool cmpstr(string str1, string str2)
{
	for (int i = 0; i < str1.size(); ++i)
	{
		char a = str1[i];
		char b = str2[i];
		/*if (str1[i] >= 'A' && str1[i] <= 'Z')
		{
			a = str1[i] - 'A' + 'a';
		}
		if (str2[i] >= 'A' && str2[i] <= 'Z')
		{
			b = str2[i] - 'A' + 'a';
		}*/

		if (a != b)
		{
			return a < b;
		}
	}
	return true;
}
bool cmp2(pair<string, int> it1, pair<string, int> it2)
{
	if ((it1).second == (it2).second)
	{
		if ((it1).first.length() == (it2).first.length())
		{
			return cmpstr((it1).first, (it2).first);
		}
		else
		{
			return (it1).first.length() < (it2).first.length();
		}
	}
	else
	{
		return (it1).second > (it2).second;
	}
}

int main()
{
	string word;
	
	map<string, int> mp;

	while (cin >> word)
	{
		sort(word.begin(), word.end(), cmp);
		//vec.push_back(word);
		mp[word]++;
		word.clear();
	}
	
	vector<pair<string, int> > vec(mp.begin(), mp.end());
	sort(vec.begin(), vec.end(), cmp2);
	bool first = true;
	for (vector<pair<string, int> >::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		for (int i = 0; i < (*it).second; i++)
		{
			if (first == false)
			{
				cout << " ";
			}
			cout << (*it).first;
			first = false;
		}
	}

	return 0;
}