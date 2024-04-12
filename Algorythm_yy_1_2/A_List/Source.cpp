#include <iostream>
#include <string>
#include <vector>

using namespace std;

int CheckLine(const vector<int>& val);

int main() {
	char s;
	vector<int> values;
	string s1;
	while (cin.get(s)) {
		if (isspace(s)) {
			int n = atoi(s1.c_str());
			values.push_back(int(n));
			s1.erase();
		} else s1 += s;
		if (s == '\n') break;
	}
	
	int i = CheckLine(values);
	if (i) cout << "YES";
	else cout << "NO";
}

int CheckLine(const vector<int>& val) {
	int check = 1;
	for (int i = 0; i< val.size()-1;i++) {
		int delt = val[i+1] - val[i];
		if (delt > 0);
		else {
			check = 0;
			break;
		}
	}
	return check;
}