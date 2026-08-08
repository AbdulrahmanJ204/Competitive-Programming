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
    int n,q;
    cin>>n>>q;
    int a[n+1];
    int pre[n+1][11];
    for (int i = 1; i <= n; i++)
    {
      cin>>a[i];
      for (int j = 0; j < 11; j++)
      {
        pre[i][j]=0;
      }
      
    }
      for (int j = 0; j < 11; j++)
      {
        pre[0][j]=0;
      }
      
    for (int i = 1; i < n+1; i++)
    {
      pre[i][a[i]]++;
      for (int j = 0; j < 11; j++)
      {
        pre[i][j]+=pre[i-1][j];
      }
      
    }
    


    while (q--)
    {
      int l,r;
      cin>>l>>r;
      int cnt=0;
      for (int i = 0; i < 11; i++)
      {
        if(pre[r][i]-pre[l-1][i]>0) cnt++;
      }
      cnt>=3? cout<<"NO": cout<<"YES";
      cendl;
    }
    

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