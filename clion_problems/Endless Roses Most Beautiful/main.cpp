#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int b[n];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    string s;
    cin >> s;
    if (k == 1) {
        cout << -1;
        return 0;
    }
    priority_queue<int> w, r, o, oo;
    for (int j = 0; j < n; ++j) {
        if (s[j] == 'O') {
            o.push(b[j]);
            oo.push(b[j]);
        } else if (s[j] == 'W')
            w.push(b[j]);
        else if (s[j] == 'R')
            r.push(b[j]);
    }
    int cnt = 0;
    if (o.empty() || k == 1) {
        cout << -1;
        return 0;
    }
    if (w.empty())
        cnt++;
    if (r.empty())
        cnt++;
    if (cnt > 1) {
        cout << -1;
        return 0;
    }
    if (r.size() + o.size() < k && w.size() + o.size() < k) {
        cout << -1;
        return 0;
    }
    ll s1 = 0, s2 = 0;
    int temp = k;
    if (w.size() + o.size() >= k && !w.empty()) {
        s1 += o.top() + w.top();
        o.pop();
        w.pop();
        k -= 2;
        while (k > 0) {
            while (!o.empty() && !w.empty() && k > 0)
                if (o.top() > w.top()) {
                    s1 += o.top();
                    o.pop();
                    k--;
                } else {
                    s1 += w.top();
                    w.pop();
                    k--;
                }

            if (o.empty())
                while (!w.empty() && k > 0) {
                    k--;
                    s1 += w.top();
                    w.pop();
                }

            if (w.empty())
                while (!o.empty() && k > 0) {
                    k--;
                    s1 += o.top();
                    o.pop();
                }

        }
    }

    k = temp;
    if (r.size() + oo.size() >= k && !r.empty()) {
        s2 += oo.top() + r.top();
        oo.pop();
        r.pop();
        k -= 2;
        while (k > 0) {
            while (!oo.empty() && !r.empty() && k > 0)
                if (oo.top() > r.top()) {
                    s2 += oo.top();
                    oo.pop();
                    k--;
                } else {
                    s2 += r.top();
                    r.pop();
                    k--;
                }

            if (oo.empty())
                while (!r.empty() && k > 0) {
                    k--;
                    s2 += r.top();
                    r.pop();
                }

            if (r.empty())
                while (!oo.empty() && k > 0) {
                    k--;
                    s2 += oo.top();
                    oo.pop();
                }
        }
    }
    cout << max(s1, s2) << endl;
    return 0;
}