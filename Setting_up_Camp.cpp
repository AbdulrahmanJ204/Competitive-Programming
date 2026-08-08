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
    int a,b,c;
    cin>>a>>b>>c;
    int ans=a;
    int bs=b/3;
    int mod=b%3;
    if(mod>0&&3-mod>c) {
      cout<<-1;
      return;
    }
    else if(mod>0) {
      c-=3-mod;
      bs++;
    }
    mod=c%3;
    c/=3;
    ans+=c;
    ans+=bs;
    mod? ans++:ans;
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