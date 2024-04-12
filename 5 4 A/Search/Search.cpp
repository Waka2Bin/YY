#include <iostream>
#include <map>
#include <vector>

struct para{
	long left;
	long right;
};

int main()
{
	using namespace std;
	
	long n, val,k, l, r, k_l, k_r,idx,delt;
	map <long, long> data_num;
	map <long, long> data_num_sum;
	vector <para> inpt;

	long idx_sum = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		if (data_num.count(val)) data_num[val]++;
		else data_num[val] = 1;
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> l >> r;
		data_num[l] += 0;
		data_num[r] += 0;
		inpt.push_back({ l,r });
	}
	map <long, long>::iterator it;
	it = data_num.begin();
	for (it = data_num.begin(); it != data_num.end(); it++)
	{
		idx = it->first;
		idx_sum = idx_sum + it->second;
		data_num_sum[idx] = idx_sum;
	}
	for (auto &ld : inpt ) 
	{
		k_l = ld.left;
		k_r = ld.right;
		delt = data_num_sum[k_r] - data_num_sum[k_l]+data_num[k_l];
		cout << delt << " ";
	}
	return 0;
}