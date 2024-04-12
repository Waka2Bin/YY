#include <iostream>

int main()
{
    using namespace std;
    double a, b, c, d, e, f, x, y;
    cin >> a >> b >> c >> d >> e >> f;

    if ((a * d == b * c && (a * f != c * e || b * f != d * e)) || (a == 0 && b == 0 && c == 0 && d == 0 && (e != 0 || f != 0)))   cout << 0; //0
    else if (a * d == c * b && a * f == c * e && b * f == d * e && a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) cout << 5;//5
    else if (b == 0 && d == 0 && c*e==f*a) {
        if (a==0) x = f / c;
        else x = e / a;
        cout << 3 << " " << x; //3
    }
    else if (a == 0 && c == 0 && b*f ==d*e) {
        if (b==0) y = f / d;
        else  y = e / b;
        cout << 4 << " " << y; //4
    }
    else if (((a == 0 && b == 0 && e == 0) && (c != 0 && d != 0)) || (e * d == f * b && a * d == b * c && (c != 0 && d != 0))) {
        double k_answ = -c / d;
        double b_answ = f / d;
        cout << 1 << " " << k_answ << " " << b_answ; //1
    }
    else if ((c == 0 && d == 0 && f == 0 && (a != 0 && b != 0)) || (e * d == f * b && a * d == b * c && (a != 0 && b != 0))) {

        double k_answ = -a / b;
        double b_answ = e / b;
        cout << 1 << " " << k_answ << " " << b_answ;//1
    }
    else {
        y = (e * c - a * f) / (b * c - a * d);
        x = (d * e - f * b) / (d * a - b * c);
        cout << 2 << " " << x << " " << y;         //2
    }
    return 0;
}