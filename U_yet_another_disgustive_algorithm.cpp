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

void solve() {
    ll n;
    cin >> n;
    int n2 = 2 * n;
    int cnt = 1;
    int ans = 0;
    bool needToSort = false;
    int canIgnore=0;
        
    deque<int> q;
    string s;
    while (n2--) {
        cin >> s;
        if (s == "add") {
            int x;
            cin >> x;
            q.push_back(x);
        } else {
            if(!q.empty()){
                
                if(q.back()!=cnt){ ans++;
                while(!q.empty()) q.pop_front();
                }
                else q.pop_back();
            }
            cnt++;
        }
    }
    cout << ans;
    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    // cin>>t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}