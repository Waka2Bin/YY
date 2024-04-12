#include <iostream>

int main()
{
    using namespace std;

    int n, k, m, det, delt_n;
    cin >> n >> k >> m;
    det = (n / k)*(k/m);
    delt_n = n % k + ((n / k) * (k % m));
    while (delt_n >= k) {
        int det_i = (delt_n / k) *(k / m);
        det += det_i;
        if (det_i > 0) delt_n = delt_n % k + ((delt_n / k) * (k % m));
        else break;
    }
    cout << det;
}