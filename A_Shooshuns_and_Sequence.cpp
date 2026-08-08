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
    ll n,k;
    cin>>n>>k;
    k--;
    ll a[n];
    for (int i = 0; i < n; i++)
      cin>>a[i];
    bool ok=true;
    for (int i = k; i < n-1; i++)
      if(a[i]!=a[i+1]) ok=false;
    if(!ok) {
      cout<<-1;
      return;
    }
    ll ans=0;
    for (int i = k - 1; i >= 0; i--)
    {
      if(a[i]!=a[k]) {
        ans=i+1;
        break;
      }
    }
    
    cout<<ans;    

  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    //cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}