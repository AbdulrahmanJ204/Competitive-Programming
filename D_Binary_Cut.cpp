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
    string s;
    cin >> s;
    int index=-1;
    int n=s.size();
    int cnt=1;
    bool can=false;
    for (int i = 0; i < n-1; i++)
    {
      if(s[i]!=s[i+1]) cnt++;
      if(s[i]=='0'&&s[i+1]=='1') can=true;
    }
       if(can) cnt--;
       cout<<cnt;


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