#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>


int main()
{
    using namespace std;

    string sl, sl_voc, sl_sub, sl_part, sl_2;
    map<int, vector <string>> voc;
    vector <string> answ;
    bool check = false;
    bool check_2 = false;

    getline(cin, sl);
    istringstream iss(sl);
    while (iss >> sl_voc) {
        int leng = sl_voc.size();
        voc[leng].push_back(sl_voc);
    }

    getline(cin, sl_2);
    istringstream iss_out(sl_2);
    while (iss_out >> sl_sub) {
        int leng = sl_sub.size();
        int af, bf;
        for (int i = 1; i <= leng; i++) {
            sl_part = sl_sub.substr(0,i);
            for (int j = 0; j < voc[i].size(); j++)
            {
                if (voc[i][j] == sl_part) {
                    check_2 = true;
                    check = true;
                    af = i;
                    bf = j;
                    break;
                }
            }
            if (check_2) break;
        }
        if (check) {
            answ.push_back(voc[af][bf]);
            check = false;
        }
        else answ.push_back(sl_sub);
        check_2 = false;
    }
    for (auto &l : answ) cout << l << " ";
    return 0;
}