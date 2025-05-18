#include <bits/stdc++.h>
using namespace std;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

bool isSmall(char a) {
    return a <= 'z' && a >= 'a';
}

bool isCapital(char a) {
    return a <= 'Z' && a >= 'A';
}
bool isNumber(char a) {
    return a >= '0' && a <= '9';
}
void solve() {
    string s;
    cin >> s;
    int sm = 0, cp = 0, nm = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isSmall(s[i]))
            sm++;
        else if (isCapital(s[i]))
            cp++;
        else
            nm++;
    }

    if (cp == 0) {
        if (sm == 0) {
            s[0] = 'A';
            s[1] = 'a';
        } else if (nm == 0) {
            s[0] = 'A';
            s[1] = '1';
        } else if (sm == 1) {
            if (!isSmall(s[0])) {
                s[0] = 'A';
                cout << s;
                return;
            } else if (!isSmall(s[1])) {
                s[1] = 'A';
                cout << s;
                return;
            }
        } else if (nm == 1) {
            if (!isNumber(s[0])) {
                s[0] = 'A';
                cout << s;
                return;
            } else if (!isNumber(s[1])) {
                s[1] = 'A';
                cout << s;
                return;
            }
        } else {
            s[0] = 'A';
        }
        cout << s;
        return;
    }
    if (nm == 0) {
        if (sm == 0) {
            s[0] = '1';
            s[1] = 'a';
            cout << s;
            return;
        }
        if (cp == 1) {
            if (!isCapital(s[0])) {
                s[0] = '1';
                cout << s;
                return;
            } else if (!isCapital(s[1])) {
                s[1] = '1';
                cout << s;
                return;
            }
        } else if (sm == 1) {
            if (!isSmall(s[0])) {
                s[0] = '1';
                cout << s;
                return;
            } else if (!isSmall(s[1])) {
                s[1] = '1';
                cout << s;
                return;
            }
        } else {
            s[0] = '1';
            cout << s;
            return;
        }
    }
    if (sm == 0) {
        if (cp == 1) {
            if (!isCapital(s[0])) {
                s[0] = 'a';
                cout << s;
                return;
            } else if (!isCapital(s[1])) {
                s[1] = 'a';
                cout << s;
                return;
            }
        } else if (nm == 1) {
            if (!isNumber(s[0])) {
                s[0] = 'a';
                cout << s;
                return;
            } else if (!isNumber(s[1])) {
                s[1] = 'a';
                cout << s;
                return;
            }
        } else {
            s[0] = 'a';
            cout << s;
            return;
        }
    }

    cout << s;

    return;
}
int main() {
    InTheNameOfAllah
        ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}