#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main()
{
    char x = 0;
    bool answ = false;
    map <char, long> firstString;
    map <char, long> secondString;
    
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    //ifstream cin("D:/TrAlRadioavionica/3_Рабочие файлы/УЧЕБА/C/jj/Annogram/9.txt");
    //ofstream cout("C:/Users/tretyakovaa/Downloads/09(1)_answer.txt");

    while (cin.get(x)) {
        if (x == '\n') break;
        if (firstString.count(x)) firstString[x] += 1;
        else firstString[x] = 1;
    }

    while (cin.get(x)) {
        if (x == '\n') break;
        if (secondString.count(x)) secondString[x] += 1;
        else secondString[x] = 1;
    }
    /*
    for (auto& a : firstString) {
        cout << a.first << "=" << a.second << ";";
    }
    cout << "__" << endl;
    for (auto& a : secondString) {
        cout << a.first << "=" << a.second << ";";
    }
    */

    if (firstString.size() == secondString.size()) {
        for (auto& l : firstString) {
            char a = l.first;
            //int val_a = l.second;
            //int val = secondString[a];
            //cout << a << val_a << val << endl;
            if (l.second == secondString[a]) answ = true;
            else {
                answ = false;
                goto hi;
            }
        }
    } else goto hi;
    hi:
    if (answ) cout << "YES";
    else cout << "NO";

    return 0;
}