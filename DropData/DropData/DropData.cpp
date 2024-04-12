/*
#include <iostream>
#include <map>

using namespace std;

int main()
{
    long long a, val;
    map <long long, long long> data;
    long long max_sum;
    long long max_sum_idx_i = 0;
    long long summ = 0;

    cin >> a;
    for (long long i = 0; i < a; i++)
    {
        cin >> val;
        if (data.count(val)) data[val] += 1;
        else data[val] = 1;
    }

    if (a < 2 || data.size() < 2 || data.empty()) {
        std::cout << "0";
    }
    else if (data.size() == 2) {
        auto it = data.begin();
        long long x, y, val_it_x, val_it_y, temp, delt;
        x = it->second;
        val_it_x = it->first;
        ++it;
        y = it->second;
        val_it_y = it->first;
        temp = x + y;
        delt = val_it_y - val_it_x;
        if (delt > 1) {
            std::cout << min(x, y);
        } else std::cout << "0";
    }
    else {
        for (auto it = data.begin(); it != data.end();++it) {
            long long x, y, val_it_x, val_it_y, temp, delt;
            x = it->second;
            val_it_x = it->first;
            ++it;
            if (it == data.end()) goto hi;
            y = it->second;
            val_it_y = it->first;
            temp = x + y;
            delt = val_it_y - val_it_x;
            if (max_sum < temp && delt == 1) {
                max_sum = temp;
                max_sum_idx_i = val_it_x;
            };
            --it;
        }
        hi:
        for (auto iter = data.begin(); iter != data.end(); ++iter) {
            long long x = iter->first;
            long long value = iter->second;
            if (x != max_sum_idx_i && x != (max_sum_idx_i + 1)) {
                summ += value;
            }
        }
        std::cout << summ;
    }
    return 0;
}
*/