#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

double sq(ll a,ll b){
  return (a-b)*(a-b);
}
void solve()
{
    ll n,k,x1,x2,y1,y2;
    cin>>n>>k;
    n--;
    double len=0;
    cin>>x1>>y1;
    while (n--)
    {
      cin>>x2>>y2;
      len+=sqrt(sq(x2,x1)+sq(y2,y1));
      x1=x2; y1=y2;
    }
    double ans=len/50*k;
    cout<<fixed<<setprecision(9)<<ans;
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