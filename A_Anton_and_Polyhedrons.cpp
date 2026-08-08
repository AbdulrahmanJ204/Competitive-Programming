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
    ll n;
    cin>>n;
    ll ans=0;
    for (int i = 0; i < n; i++)
    {
      string s;
      cin>>s;
      if(s=="Tetrahedron") ans+=4 ;
      if(s=="Cube") ans+= 6;
      if(s=="Octahedron") ans+=8 ;
      if(s=="Dodecahedron") ans+= 12;
      if(s=="Icosahedron") ans+=20 ;
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