#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n,m;
    cin>>n>>m;
    ll i=0,j=0,ans=0;
    string a,b;
    cin>>a>>b;
    if(a==b){
      cout<<n;
      return;
    }
    while (i<n&&j<m)
    {
      if(a[i]==b[j])
      {
        ans++;
        i++;
      }
      j++;
    }
    cout<<ans;

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