#include <iostream>
#include <map>

using namespace std;

struct val_i {
    long long num = 0;
    bool num_prev = false;
    bool num_post = false;
};

int main()
{
    long long a;
    map <  long long, val_i > data;

    cin >> a;
    for (int i = 0; i < a; i++) {
        long long val;
        cin >> val;
        data[val].num += 1;
        data[val].num_prev = true;
        data[val + 1].num_prev = true;
        data[val].num_post = true;
        data[val - 1].num_post = true;
    }

    auto iter = data.cbegin();
    long long sum_max = 0;
    while (iter != data.cend())
    {
        long long sum_prev = iter->second.num;
        long long sum_post = iter->second.num;
        if (iter->second.num_prev) sum_prev += data[iter->first - 1].num;
        if (iter->second.num_post) sum_post += data[iter->first + 1].num;
        long long sum = max(sum_prev, sum_post);
        if (sum > sum_max) sum_max = sum;
        iter++;
    }
    cout << a - sum_max << endl;
    return 0;
}