#include <iostream>
#include <map>

int main()
{
    using namespace std;
    long long n, k, val;
    map <long long, long long> data;

    bool status = false;

    cin >> n;
    cin >> k;

    for (long long i = 1; i <= n; i++) {
        cin >> val;
        long long i_prev;
        if (data.count(val)) {
            i_prev = data[val];
            if (i - i_prev <= k) {
                status = true;
                goto hi;
            }
            else data[val] = i;
        }
        else data[val] = i;
    }
    hi:
    if (status) cout << "YES";
    else cout << "NO";
    return 0;
}