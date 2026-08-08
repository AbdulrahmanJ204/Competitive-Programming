#include <bits/stdc++.h>
using namespace std;
#define test  ll t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    test {
        int n, m;
        cin >> n >> m;
        map<int, int> ma;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            ma[u]++;
            ma[v]++;
        }
        multiset<int> s;
        for (auto x:ma) {
            if (x.second > 1)
                s.insert(x.second);
        }
        int x, y, cx = 0, cy = 0;
        int first = *s.begin(), last = *s.rbegin();

        auto second = s.begin();
        auto blast = s.rbegin();
        second++, blast++;
        if (first == last)
            cout << first << ' ' << last - 1 << endl;
        else if (*blast == last)
            cout << first << ' ' << last - 1 << endl;
        else if (*second == first)
            cout << last << ' ' << first - 1 << endl;


    }
    return 0;
}