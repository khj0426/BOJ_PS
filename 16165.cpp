#include <iostream>
#include <map>
#include <string>

//백준 16165 걸그룹 마스터 준석이

using namespace std;

int main(void) {
    map<string, string> m;

    int n;
    int k;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        string group;
        cin >> group;
        int group_num;
        cin >> group_num;
        for (int j = 0; j < group_num; j++) {
            string member;
            cin >> member;
            m[member] = group;
        }

    }

    for (int i = 0; i < k; i++) {
        map<string, string>::iterator iter;

        string q;
        cin >> q;
        int Q;
        cin >> Q;
        if (Q == 1) {
            iter = m.find(q);
            if (iter != m.end()) {
                cout << iter->second << '\n';
            }
        }
        else if (Q == 0) {

            for (iter = m.begin(); iter != m.end(); iter++) {
                if (iter->second == q) {
                    cout << iter->first << '\n';
                }
            }
        }
    }




}