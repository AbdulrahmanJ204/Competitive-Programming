#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    string ans;
    bool exist = false;
    int seven = 0, four = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == '4') {
            exist = true;
            four++;
        }
        if (s[i] == '7') {
            exist = true;
            seven++;
        }
    }

    if (exist)
        if (four >= seven)
            cout << 4 << endl;
        else
            cout << 7 << endl;
    else
        cout << -1 << endl;


    return 0;
}
