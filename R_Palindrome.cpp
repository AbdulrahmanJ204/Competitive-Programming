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
    int n;
    cin >> s;
    cin >> n;
    map<int, int> m;
    int pre[s.size()];
    for (int i = 0; i < s.size(); i++)
    {
      pre[i]=0;
    }    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        m[x]++;
    }
    int i=0,last=0;
    for (auto x : m) {
    pre[x.first]=x.second;
    }
    n=s.size();
    for (int i = 0; i < n-1; i++)
    {
      pre[i+1]+=pre[i];
    }
    
    
    for (int i = 0; i < s.size()/2; i++)
    {
      if(pre[i]%2==1){
        char c=s[i];
        s[i]=s[n-i-1];
        s[n-i-1]=c;
        
      }
    
    }

    


    cout << s;

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