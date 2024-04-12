#include <iostream>

int main()
{
    using namespace std;

    long long n, sum = 1;
    cin >> n;
    long long cur=0,prev=0,iter=1;
    for (; sum < n;) {
        iter++;
        prev = sum;
        sum += iter;
        if (sum == n)       cur = sum;    
        else if (sum > n)   cur = n; 
    }
    bool szb = (iter + 1) % 2;
    if (1 == n) std::cout << "1\/1"; 
    else if (false==szb) { //nechotny ryad
        long long last_v = cur - prev;
        long long col = iter +1 - last_v;
        long long row = last_v;
        std::cout << row << "/" << col;
    }
    else {//chotny ryad
        long long last_v = cur - prev;
        long long col = last_v;//rost
        long long row = iter +1 - last_v;
        std::cout << row << "/" << col;
    }
    return 0;
}