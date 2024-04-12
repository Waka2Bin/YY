#include <iostream>

int main() {
	using namespace std;

	int a, b, c,s_1,s_2,s_3;
	cin >> a; cin >> b; cin >> c;
	s_1 = min(a, b);
	s_2 = min(max(a, b), c);
	s_3 = max(max(a, b), c);
	if ((s_1 + s_2) <= s_3) cout << "NO";
	else cout << "YES";
	return 0;
}