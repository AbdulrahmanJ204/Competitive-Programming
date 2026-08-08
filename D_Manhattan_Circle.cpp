#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define cin(v) for(ll i=0;i<v.size();i++)cin>>v[i];
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define tryAndCry(v) for(auto x : v){cout<<x<<" ";}cout<<"\n";
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    int n,m;
    cin>>n>>m;
    string s[n];
    for (int i = 0; i < n; i++)
    {
      cin>>s[i];
    }
    int mnl=1e9, mxr=-1, mnu=1e9, mxd=-1;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if(s[i][j]=='#'){
          mnl=min(j,mnl);
          mxr=max(j,mxr);
          mnu=min(i,mnu);
          mxd=max(i,mxd);
        }
      }
      
    }

    cout<<(mnu+mxd+2)/2 <<' '<<(mnl+mxr+2)/2;

  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}