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
    string s[n];
    int fi=0,la=0;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
      int cnt=0;
      for (int j = 0; j < n; j++)
      {
        if(s[i][j]=='1') cnt++;
      }
      if(cnt>0)
      v.push_back(cnt);  
    }
    if(v[0]!=v[v.size()-1]) cout<<"TRIANGLE";
    else cout<<"SQUARE";

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