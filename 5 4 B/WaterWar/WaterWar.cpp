#include <iostream>

long long res(long long k);

int main()
{
    using namespace std;

    long long n;
    cin >> n;
    long long l = 0;
    long long r = 21000000;
    long long mid;

    while (l < r) {
        mid = (l + r) / 2;
        if (res(mid) > n) r = mid;
        else l = mid + 1;
    }
    r--;
    cout << r;
    return 0;
}

long long res(long long k) {
    long long shp_lng = 0;
    long long i = 0;
    do {
        shp_lng += (k - i + 1) * (i + 1);
        i++;
    } while (i < k);
    shp_lng -= 1;
    return shp_lng;
}