#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>

using namespace std;

int main()
{
	int a1, a2, b1, b2;
	cin >> a1 >> b1>> a2>> b2;
	pair < int,int > val;
	map <int, pair < int, int >> data;
	map <int,int> answ;
	
	data[0].first = max(a1, b1) + a2;
	data[0].second = max(min(a1, b1), b2);
	data[1].first = max(a1, b1) + b2;
	data[1].second = max(min(a1, b1), a2);
	data[2].first = min(a1, b1) + a2;
	data[2].second = max(max(a1, b1), b2);
	data[3].first = min(a1, b1) + b2;
	data[3].second = max(max(a1, b1), a2);

	for (int i = 0; i < data.size();i++) {
		int a = data[i].first;
		int b = data[i].second;
		int s_temp = a*b;
		answ[s_temp] = i;
	}

	for (auto i : answ) {
		cout << i.first << ":" << i.second << endl;
	}

	map <int, int> ::iterator it = answ.begin();
	int res = it->second;
	cout << data[res].first << " " << data[res].second;
	
	return 0;
}