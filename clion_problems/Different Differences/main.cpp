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
    test {
        int n, k;
        cin >> k >> n;
        set<int> s;
        if (k == n) {
            for (int i = 0; i < n; ++i) {
                cout << i + 1 << ' ';
            }
            cendl;
            continue;
        }
        int temp = k;
        for (int i = 0; i < k; ++i) {

            if (n - i > 0) {
                s.insert(n - i);
                n -= i;
                temp--;
            } else break;
        }
        int cnt = 1;
        while (temp > 0) {
            if (s.find(cnt) == s.end()) {
                s.insert(cnt);
                temp--;
                cnt++;
            } else cnt++;
        }
        for (auto x: s) {
            cout << x << ' ';
        }
        cendl;
    }
    return 0;
}