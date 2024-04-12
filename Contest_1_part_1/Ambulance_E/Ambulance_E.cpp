#include <iostream>
#include <math.h>
#include <map>

using namespace std;

int main()
{
    double k1, k2, p2, n2;
    int p1, m, n1;
    cin >> k1>> m>> k2>> p2>>n2;

    map<int, int> temp_fl, temp_par;

    double r_f = k2 / (n2 + m * (p2 - 1));
    double floor1 = ceil(k1 / ceil(r_f));
    p1 = ceil(floor1 / m);
    n1 = floor1 - m*(p1-1);

    for (int i = int(r_f); i <= k2; i++)
    {
        int n_temp = int(ceil(k2 / i)) - m * (p2-1);
        int p_temp = ceil(int(ceil(k2 / i)) / m) ;
        if (ceil(ceil(k2 / i) / m) == p2 && n_temp == n2) temp_par[p_temp] = 1;
        if (n_temp == n2 ) temp_fl[i] = 1;
    }
    if ((m * (p2 - 1) + n2) > k2 )                      { n1 = -1;p1 = -1; }
    else if (k2/) {}
    else if (k1 == k2)                                  { n1 = n2; p1 = p2; }
    else if (1 == p2) {
        if (1 == n2) {
            if (temp_fl.size() > 1)                     { p1 = 0; n1;}
            else if (1 == m)                            { p1 = 0; n1 = 1; }
            else if (temp_par.size() > 1 || n1 > n2)    n1 = 0;
            else if (k1 > k2 && k1 < m * k2)            { n1 = 0; p1 = 1; }
            else if (k1 > k2 && k1 > m * k2)            { n1 = 0; p1 = 0; }
            else if (k1 < k2)                           { n1 = 1; p1 = 1; }
            else                                        { n1 = 1; p1 = 0; }
        }
        else {
            if (1 == m || temp_fl.size() > 1)           p1 = 0;
            else {}
        }
    }

    cout << "temp_par.size():" << temp_par.size() << endl;
    cout << "temp_fl.size():" << temp_fl.size() << endl;
    cout << "apart on floor:" << r_f << endl;
    cout << "floors for k1:" << floor1 << endl;
    cout << "paradn for k1:" << p1 << endl;
    cout << "etagh for k1:" << n1 << endl;

    cout << p1 << " " << n1;
    return 0;
}