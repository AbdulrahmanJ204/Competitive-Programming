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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int cnt=0;
    for (int i = min(a,b)+1; i < max(a,b); i++)
    {
      if(i==c||i==d) cnt++;
    }
    cnt==1? cout<<"YES": cout<<"NO";

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