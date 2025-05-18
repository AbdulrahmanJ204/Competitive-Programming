#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"
#define cno cout<<"NO"
#define cin(v) for(ll i=0;i<v.size();i++)cin>>v[i];
#define cin1(v,n) for(ll i=0;i<n;i++)cin>>v[i];
#define cin2(v,n,m) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) cin>>v[i][j];
#define tryAndCry(v) for(auto x : v){cout<<x<<" ";}cout<<"\n";
#define cout1(v,n) for(ll i=0;i<n;i++)cout<<v[i]<<' '; cendl;
#define cout2(v,n,m) for(ll i=0;i<n;i++,cendl) for (int j = 0; j < m; j++) cout<<v[i][j]<<' ';
#define assign1(v,n,value) for(ll i=0;i<n;i++)v[i]=value;
#define assign2(v,n,m,value) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) v[i][j]=value;
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n,q;
    cin>>n>>q;
    vector<vector<ll>>cnt(1e3+10,vector<ll>(1e3+10,0));
    vector<ll>p(1e3+10,1e4);
    // map<ll,pair<pair<ll,?ll>,ll>> LR;
    vector<pair<ll,ll>> v[n+1];
    while(q--){
      ll x,l,r;
      cin>>x>>l>>r;
      v[x].push_back(make_pair(l,r));
      cnt[x][l]++;
      cnt[x][r+1]--;
      
      p[l]=min(p[l],r);
    }
    
    for(int i=1;i<=1e3;i++)
    {
      for (int j = 1; j <= 1e3; j++)
      {
        cnt[i][j]+=cnt[i][j-1];
        if(cnt[i][j]>2)
        {
          cno;
          return;
        }
    
      }
      
    }
    bool flag=1;
    for (int i = 1; i <= 1e3; i++)
    {
      for (int j = 1; j <= 1e3; j++)
      {
        if(cnt[i][j]==2)
        {
          if(!flag)
          {
            cno;
            return;
          }
          int fr=j,sc=p[j];
          for (int k = 0; k < v[i].size(); k++)
          {
            if(v[i][k].first<=j && v[i][k].second>p[j])
            {
              fr=v[i][k].first;
              sc=v[i][k].second;
              break;
            }
          }
          
          for(int k=fr;k<=sc;k++)
          cnt[i][k]--;
          flag=0;
        }

      }
    }
    
    cyes;
    
    

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