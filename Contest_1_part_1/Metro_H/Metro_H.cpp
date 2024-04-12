#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <map>

struct dat {
    int min = 0;
    int max = 0;
};

int main()
{
    using namespace std;
    int a1, a2, n1, n2;
    map <int, dat> data;
    cin >> a1 >> a2 >> n1 >> n2;
    data[0].min = a1 * (n1-1) + n1;
    data[0].max = a1 * (n1+1) + n1;
    data[1].min = a2 * (n2-1) + n2;
    data[1].max = a2 * (n2+1) + n2;
    int tmp_min = max(data[0].min, data[1].min);
    int tmp_max = min(data[0].max, data[1].max);
    if (tmp_max >= tmp_min) {
        cout << tmp_min << " " << tmp_max;
    }
    else cout << -1;
    return 0;
}