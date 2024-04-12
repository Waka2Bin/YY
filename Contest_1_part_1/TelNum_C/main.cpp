#include <iostream>
#include <vector>
#include <string>

using namespace std;

string tel_format(vector<string>& val1, string& val2);

int main() {
	
	int num = 4;
	string tel;
	vector<string>data;
	vector<string>tels;

	data.push_back("(");
	data.push_back(")");
	data.push_back("-");
	data.push_back("+");

	for (int i = 0; i < num; i++) {
		cin >> tel;
		tels.push_back(tel_format(data, tel));
	}
	
	for (size_t i = 1; i < tels.size(); i++)
	{
		if (tels[0] == tels[i]) cout << "YES"<<"\n";
		else cout << "NO" << "\n";
	}
	return 0;
}

string tel_format(vector<string>& val1, string& val2) {
	for (auto j : val1) {
		string new_str{ "" };
		size_t start{ val2.find(j) };
		while (start != std::string::npos)
		{
			val2.replace(start, j.length(), "");
			start = val2.find(j, start + new_str.length());
		}
	}
	if (val2.length() < 10)			val2.insert(0,"495");
	else if (val2.length() == 11)	val2.erase(0, 1);
	return val2;
}