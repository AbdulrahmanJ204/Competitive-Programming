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
    string s;
    cin >> s;
    string temp=s;
    temp.resize(unique(temp.begin(),temp.end())-temp.begin());
    if(n%2==1||temp.size()==1)
    {
      cout<<-1;
      return;
    } 
    vector<int> v;
    for (int i = 0; i < n/2; i++)
    {
      if(s[i]==s[n-i-1]) v.push_back(i);
    }
    
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