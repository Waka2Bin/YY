#include <iostream>
#include <vector>
#include <fstream>

int binary(std::vector < long long >& val, long long& val_2);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    using namespace std;

    //ofstream out("output7.txt");
    //ifstream in("07.txt");

    ofstream out("output.txt");
    ifstream in("input.txt");

    size_t n, m;
    in >> n >> m;

    vector < long long > data;
    data.reserve(n + 1);
    long long sum = 0;
    vector < long long > data_sum;
    data_sum.reserve(n + 1);
    for (size_t i = 0; i < n; i++) {
        long long value;
        in >> value;
        data.push_back(value);
        data_sum.push_back(sum);
        sum += value;
    }
    data.push_back(0);
    data_sum.push_back(sum);

    vector < pair <long long, long long> > otr; 
    otr.reserve(m);
    vector < long long > answs(m);
    for (size_t i = 0; i < m; i++) {
        pair <long long, long long> temp;
        in >> temp.first >> temp.second;
        otr.push_back(temp);
        answs[i] = -1;
    }

    long long sum_orc_prev = 0; 
    long long sum_orc_post = 0;
    long long mid, mid_prev, mid_post;

    for (size_t i = 0; i < otr.size(); i++) {
        long long start = 0;
        long long end = data.size() - 1;
        if (1 == otr[i].first) {
            long long  val = binary(data, otr[i].second);
            if (val != -1) answs[i] = val + 1;
        }
        else if (otr[i].first + 1 == data.size()) {
            if (data_sum[end] == otr[i].second)
                answs[i] = 1;
        }
        else {
            while (end - start > otr[i].first) {
                mid = (start + end) / 2;
                mid_prev = mid - otr[i].first;
                mid_post = mid + otr[i].first;
                if (mid_prev < start) mid_prev = start; //chek beg elem
                sum_orc_prev = data_sum[mid_prev + otr[i].first] - data_sum[mid_prev];   //val orc
                if (sum_orc_prev == otr[i].second) { answs[i] = mid_prev + 1; break; }   //low border
                if (mid_post > end) mid_post = end; //chek last elem
                sum_orc_post = data_sum[mid_post] - data_sum[mid_post - otr[i].first]; //hi border
                if (sum_orc_post == otr[i].second) { answs[i] = mid_post - otr[i].first + 1; break; }
                if (sum_orc_prev < otr[i].second && sum_orc_post < otr[i].second) start = mid;  //bin
                else if (sum_orc_prev > otr[i].second && sum_orc_post > otr[i].second) end = mid;
                else {
                    long long tmp = mid_prev + otr[i].first + 1;
                    for (long long j = mid_prev + 1; tmp <= mid_post; j++) {
                        sum_orc_prev = data_sum[tmp] - data_sum[j];
                        if (sum_orc_prev == otr[i].second) { answs[i] = j + 1; break; }
                        tmp++;
                    }
                    break;
                }
            }
        }
    }
    for (auto& i : answs) out << i << '\n';
    //out << "___" << "\n";
    //for (auto& i : otr) out << i.first << " - "<< i.second << '\n';

    return 0;
}

int binary(std::vector < long long >& val, long long& val_2)
{
    long long start = 0;
    long long end = val.size()-1;
    
    while (start<end)
    {
        long long mid = (start + end) / 2;
        if (val_2 == val[mid] ) return mid;
        else if (val_2 == val[start]) return start;
        else if (val_2 == val[end]) return end;
        else if (val_2 > val[mid]) start = mid+1;
        else if (val_2 < val[mid]) end = mid - 1;
    }
    return -1;
}