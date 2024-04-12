/*
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

struct para {
	long long otr;
	long long num;
	long long answ = 0;
};

long b_search(std::vector<long long>& vec, long long& orc_val, long long& orc_otr);
long binary(std::vector<long long>& vec, long long& orc_val);

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	using namespace std;

	int n, m;
	long long val, i_sum, val_3, val_4, answer;
	map <long long, para> answers;
	vector <para> inpt;
	vector <long long> data;
	vector <long long> data_2;
	vector <long long> res;

	i_sum = 0;
	val = 0;
	answer = 0;

	cin >> n >> m;
	data.reserve(n + 1);
	data_2.reserve(n + 1);
	inpt.reserve(m + 1);
	res.reserve(m + 1);
	for (int i = 0; i < n; i++) {
		cin >> val;
		i_sum += val;
		data_2.push_back(i_sum);
		data.push_back(val);
	}
	for (int j = 0; j < m; j++)
	{
		cin >> val_3 >> val_4;
		inpt.push_back({ val_3,val_4 });
	}
	for (int i = 0; i < inpt.size(); i++) {
		long long strt = 0;
		long long end = data_2.size() - 1;
		if (inpt[i].otr == 1) answer = binary(data, inpt[i].num);
		else if (end == inpt[i].otr ) {
			if (inpt[i].num == data_2[end]) answer = 1;
		}
		else if (answers.count(inpt[i].otr + inpt[i].num)) answer = answers[inpt[i].otr + inpt[i].num].answ;
		else {
			answer = b_search(data_2, inpt[i].num, inpt[i].otr);
			answers[inpt[i].otr + inpt[i].num].num = inpt[i].num;
			answers[inpt[i].otr + inpt[i].num].answ = answer;
		}
		res.push_back(answer);
	}
	for (auto& x : res) { cout << x << endl; }
	return 0;
}

long binary(std::vector<long long>& vec, long long& orc_val) {
	long long l = 0;
	long long r = vec.size() - 1;
	long long result = 0;
	bool result_flag = false;
	while (r > l && result_flag == false) {
		long long mid = (l + r) / 2;
		if (vec[r] == orc_val)			{ result = r+1; result_flag = true; }
		else if (vec[l] == orc_val)		{ result = l+1; result_flag = true;}
		else if (vec[mid] == orc_val)	{ result = mid+1; result_flag = true;}
		else if (vec[mid] > orc_val)	r = mid-1;
		else if (vec[mid] < orc_val)	l = mid+1;
		else return -1;
	}
	return result;
}

long b_search(std::vector<long long>& vec, long long& orc_val, long long& orc_otr) {
	long long start = 0;
	long long l = 0;
	long long r = vec.size() - 1;
	bool result_flag = false;
	long long result = -1;
	while (r>l && result_flag == false) {
		long long mid = (l + r) / 2;
		int a = orc_otr % 2;
		long long mid_l, mid_r;
		
		if (a ==0) mid_l = mid - orc_otr / 2;
		else mid_l = mid - orc_otr / 2 + 1;
		mid_r = mid + orc_otr / 2;
		if (mid_l < start) mid_l = start;
		if (mid_r > r ) mid_r = r;
		if (vec[mid_r] - vec[mid_l] == orc_val) {
			result = mid_l; result_flag = true;
		}
		else if (vec[r] == orc_val && r + 1 == orc_otr) { result = 1; result_flag = true; }
		else if (vec[l] == orc_val && l + 1 == orc_otr) { result = 1; result_flag = true; }
		else if (vec[mid] == orc_val && mid + 1 == orc_otr) { result = 1; result_flag = true; }
		else if (vec[r] > orc_val && orc_otr == r - l) {
			if (orc_val == vec[r] - vec[l]) {
				result = l + 2; result_flag = true;
			}
			else {
				result = -1;
			}
		}
		else if (vec[mid] > orc_val)						r = mid - 1;
		else if (vec[mid] < orc_val)						l = mid + 1;
		else if ((r - l) < orc_otr)							{ result = 1; result_flag = true; }
		else return -1;
	}
	return result;
}
*/