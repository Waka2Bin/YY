#include <iostream>
#include <cmath>

using namespace std;

int main() {
	float a, b, c;
	cin >> a >> b >> c;
	if (c < 0) cout << "NO SOLUTION";
	else if (0 == a) {
		if (c*c==b) cout << "MANY SOLUTIONS";
		else cout << "NO SOLUTION";
	}
	else {
		float x = (c * c - b) / a;
		if (floor(x) == x) {
			int answ = int(x);
			cout << answ;
		}
		else cout << "NO SOLUTION";
	}
	return 0;
}