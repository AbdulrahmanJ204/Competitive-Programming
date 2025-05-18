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
    int cnt[5]={0};
    for (int i = 0; i < n; i++)
    {
      int x;
      cin>>x;
      cnt[x]++;
    }
    int ans=cnt[4];
    ans+=cnt[2]/2;
    cnt[2]%=2;
    int mn=min(cnt[1],cnt[3]);
    cnt[1]-=mn;
    cnt[3]-=mn;
    ans+=mn;
    ans+=cnt[3];
    int two= cnt[2] ? 2:0;
    ans+= (cnt[1]+two+3)/4;
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