#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int v = 0, h = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            if (v == 0) {
                v = 1;
                cout << 1 << ' ' << 1 << endl;
            } else {
                v = 0;
                cout << 3 << ' ' << 1 << endl;
            }
        } else {
            if (h == 0) {
                h = 1;
                cout << 4 << ' ' << 3 << endl;
            } else {
                h = 0;
                cout << 4 << ' ' << 1 << endl;
            }
        }
    }


    return 0;
}
