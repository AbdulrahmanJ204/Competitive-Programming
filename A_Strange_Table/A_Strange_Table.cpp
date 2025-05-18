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
    ll n,m,x;
    cin>>n>>m>>x;
    ll col=x/n;
    ll row=x%n;
    if(row>0) col++;
    if(row==0) row=n;
    ll ans=row*m-(m-col);
    // if(ans==0) ans=x;
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