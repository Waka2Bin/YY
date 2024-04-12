#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, idx_max_str, idx_max_col, idx_prev_str, idx_prev_col;
    long  val, temp_val;
    idx_max_str = 0;
    idx_max_col = 0;
    idx_prev_str = 0;
    idx_prev_col = 0;
    
    cin >> n >> m;

    vector <vector <long long>> values;
    vector <long long> line;
    long  answ[2]{};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> val;
            line.push_back(val);
            if (answ[1] < val) {
                answ[0] = answ[1];
                idx_prev_str = idx_max_str;
                idx_prev_col = idx_max_col;
                answ[1] = val;
                idx_max_str = i;
                idx_max_col = j;
            }
            else if (answ[0] <= val) {
                answ[0] = val;
                idx_prev_str = i;
                idx_prev_col = j;
            }
        };
        values.push_back(line);
        auto begin = line.cbegin();
        auto end = line.cend();
        line.erase(begin,end);
    };
    if (idx_max_str != idx_prev_str && idx_max_col != idx_prev_col) {
        long long max_val_1 = 0;
        long long max_val_2 = 0;
        temp_val = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ( (i != idx_max_str) && (j != idx_prev_col) ) {
                    temp_val = values[i][j];
                    if (max_val_1 < temp_val) {
                        max_val_1 = temp_val;
                    }
                }
            };
        };
        temp_val = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((j != idx_max_col) && (i != idx_prev_str)) {
                    temp_val = values[i][j];
                    if (max_val_2 < temp_val) {
                        max_val_2 = temp_val;
                    }
                }
            };
        };
        if (max_val_1 >= max_val_2) { cout << idx_prev_str+1 << " " << idx_max_col+1; }
        else { cout << idx_max_str+1 << " " << idx_prev_col+1; }
    } 
    else if (idx_max_str == idx_prev_str) {
        long long max_val = 0;
        int temp_idx_col = 0;
        temp_val = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i != idx_max_str) {
                    temp_val = values[i][j];
                    if (max_val < temp_val) {
                        max_val = temp_val;
                        temp_idx_col = j;
                    }
                }
            };
        };
        cout << idx_max_str + 1 << " " << temp_idx_col + 1;
    }
    else if (idx_max_col == idx_prev_col) {
        long long max_val = 0;
        int temp_idx_str = 0;
        temp_val = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j != idx_max_col) {
                    temp_val = values[i][j];
                    if (max_val < temp_val) {
                        max_val = temp_val;
                        temp_idx_str = i;
                    }
                }
            };
        };
        cout << temp_idx_str + 1 << " " << idx_max_col + 1;
    }
    return 0;
};