﻿#include <iostream>
#include <map>


int main()
{
    using namespace std;

    int n;
    long x, y, x1, x2, y1, y2;
    long x1_cur, x2_cur, y1_cur, y2_cur;
    bool third = false;
    bool forth = false;
    int counts = 0;
    int counts_max = 0;


    map <long, map<long, long>> data_col;
    map <long, map<long, long>> data_str;
    map <int, int> sq;

    

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        data_col[x][y] = y;
        data_str[y][x] = x;
    }
    for (long i = 0; i < data_col.size(); i++)
    {
        int cnt = 0;
        for (long j = cnt+1; j < data_col[i].size(); j++)
        {
            sq[1] = 1;
            sq[2] = 1;
            y1_cur = data_col[i][cnt];
            y2_cur = data_col[i][j];
            long delt = abs(y2_cur - y1_cur);
            sq[6] = delt;
            sq[7] = y1_cur;
            map <long, map<long, long>> ::iterator it;
            advance(it,i);
            sq[8] = it->first;
            if (data_str[i + delt].count(y1_cur)) {
                sq[3] = 1;
                sq[5] = 1;
                if (data_str[i + delt].count(y2_cur)) {
                    sq[4] = 1;
                }
            } 

            if (data_str[i - delt].count(y1_cur)) {
                counts = 3;
                if (data_str[i - delt].count(y2_cur)) {
                    counts = 4;
                }
            } else counts = 2;
            if (data_str[i + delt].count(y2_cur)) {
                counts = 3;
                if (data_str[i + delt].count(y1_cur)) {
                    counts = 4;
                }
            } else counts = 2;
            if (data_str[i - delt].count(y2_cur)) {
                counts = 3;
                if (data_str[i - delt].count(y1_cur)) {
                    counts = 4;
                }
            }
            
            if (counts > counts_max) {
                y1 = i;
                y2 = i;
                x1 = i;
                x2 = i;
            }
            cnt++;
        }
    }

    return 0;
}
