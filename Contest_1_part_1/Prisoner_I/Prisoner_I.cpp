#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

int main()
{
    using namespace std;
    
    int a, b, c, d, e, min_h, max_h;
    cin >> a >> b >> c >> d >> e;
    min_h = min(d, e);
    max_h = max(d, e);

    vector<int>dat = { a,b,c };
    sort(dat.begin(),dat.end());
    
    if (dat[1] <= max_h && dat[0]<= min_h) cout << "YES";
    else cout << "NO";
    return 0;
}