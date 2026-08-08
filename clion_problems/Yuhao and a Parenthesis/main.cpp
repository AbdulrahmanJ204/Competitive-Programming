#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<string> v;
    int n;
    cin >> n;
    bool a[n];
    vector<pair<stack<char>, stack<char>>> lr(n);
    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        v.push_back(x);
        a[i] = true;
    }
    for (int i = 0; i < n; ++i) {
        string s = v[i];
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == '(')
                lr[i].first.push(s[j]);
            else if (!lr[i].first.empty() && s[j] == ')')
                lr[i].first.pop();
            else if (lr[i].first.empty() && s[j] == ')') {
                lr[i].second.push(s[j]);
            }
        }
    }
    int ans = 0, temp = 0;
    map<int, int> l, r;
    for (int i = 0; i < n; ++i) {
        int stl = lr[i].first.size(), str = lr[i].second.size();
        if (stl == 0 && str == 0) {
            temp++;
            if (temp == 2) {
                temp = 0;
                ans++;
            }
        } else if (stl == 0 && str > 0)
            r[str]++;
        else if (str == 0 && stl > 0)
            l[stl]++;
    }
    for (auto i = l.begin(); i != l.end(); ++i) {
        if (r[(*i).first] != 0) {
            ans += min((*i).second, r[(*i).first]);
        }
    }
    cout << ans << endl;
    return 0;

}