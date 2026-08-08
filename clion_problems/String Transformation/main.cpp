#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int c = 1;
    char x = 'a';
    for (int j = 0; j < s.size(); ++j)
        if (s[j] == 'a')
            for (int i = j; i < s.size(); ++i) {
                if (s[i] <= x) {
                    s[i] = x;
                    x++;
                    c++;
                }
                if (c == 27) {
                    cout << s;
                    return 0;
                }
            }
    cout << -1;
    return 0;

}
