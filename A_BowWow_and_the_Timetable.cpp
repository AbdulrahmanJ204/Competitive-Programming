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
    int first = -1, last = s.size()-1;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '1') {
            first=i;
            break;        
        }
      if(first==-1) cout<<0;
      else if(first==last) cout<<last/2+last%2;
      else cout<<last/2+1;
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