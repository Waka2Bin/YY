#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	int n,num,counter;
	string trekName;
	map <string,int> audioList;
	
	counter = 0;

	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> trekName;
			if (audioList.count(trekName)) {
				audioList[trekName] += 1;
			}
			else audioList[trekName] = 1;
		}
	}

	for (auto &l : audioList) {
		if (l.second == n) 
			counter++;
	}
	cout << counter<< endl;
	for (auto &l : audioList) {
		if (l.second == n) 
			cout << l.first << " ";
	}
	return 0;
}