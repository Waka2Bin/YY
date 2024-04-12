#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long long n;
	long long a, b, k, val;
	long long answ = 0;
	vector <long long> data;
	vector <long long> data1;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> val;
		data.push_back(val);
	}
	cin >> a >> b >> k;
	val = data[0];
	data.push_back(val);

	if (b <= k) { cout << data[0]; }
	else if ((b - a) == n) {
		long long answ = 0;
		for (int i = 0; i < data.size(); i++) {
			long long value = data[i];
			if (answ < value) {
				answ = value;
			}
		};
		cout << answ;
	}
	else if ((b / k) > n && (a / k) <= n) {
		long long steps_top_left = b % k;
		long long steps_low_left = a % k;

		long long steps_top = b / k;
		long long steps_low = a / k;

		if (steps_top_left != 0) {
			if (steps_top == n) { steps_top = n; }
			else if (steps_top > n) { steps_top = steps_top % n; }
		}
		else {
			if (steps_top == n) { steps_top = n - 2; }
			else if (steps_top != n) { steps_top = steps_top % n - 1; }
			else { steps_top = (b - 1) / k; }
		};

		if (steps_low_left != 0) {
			if (steps_low == n) { steps_low = n; }
			else if (steps_low > n) { steps_low = steps_low % n; }
		}
		else {
			if (steps_low == n) { steps_low = n - 2; }
			else if (steps_low > n) { steps_low = steps_low % n - 1; }
			else { steps_low = (a - 1) / k; }
		};

		for (int i = steps_top; i < data.size(); i++) {
			long long value = data[i];
			if (answ < value) {
				answ = value;
			}
		}
		for (int i = 0; i <= steps_low; i++) {
			long long value = data[i];
			if (answ < value) {
				answ = value;
			}
		}
		cout << answ;
	}
	else {
		long long steps_top_left = b % k;
		long long steps_low_left = a % k;
		
		long long steps_top = b / k;
		long long steps_low = a / k;
		
		if (steps_top_left != 0) {
			if (steps_top == n) { steps_top = n; }
			else if (steps_top > n) { steps_top = steps_top % n; }
		}
		else { 
			if (steps_top == n) { steps_top = n-2; }
			else if (steps_top != n) { steps_top = steps_top % n - 1; }
			else { steps_top = (b - 1) / k; }
		};

		if (steps_low_left != 0) {
			if (steps_low == n) { steps_low = n; }
			else if (steps_low > n) { steps_low = steps_low % n; }
		}
		else { 
			if (steps_low == n) { steps_low = n - 2; }
			else if (steps_low > n) { steps_low = steps_low % n - 1; }
			else { steps_low = (a-1) / k; }
		};

		for (int i = steps_low; i <= steps_top; i++) {
			long long value = data[i];
			if (answ < value) {
				answ = value;
			}
		};

		int hight = data.size() - 1 - steps_low;
		int low = data.size() - 1 - steps_top;
		
		if (low == (data.size() - 1)) {
			low -= (data.size() - 1);
		}

		/*cout << endl;
		cout << steps_low << " " << steps_top <<" "<< data.size() << endl;
		cout << hight << " " << low << endl;
		cout << endl;*/

		for (int i = hight; i >= low; i--) {
			long long value = data[i];
			if (answ < value) {
				answ = value;
			}
		}
		cout << answ;
	}
	return 0;
}