#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
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
#define oo  LLONG_MAX;
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n;
    cin>>n;
    set<pair<int,int>> st;
    vector<pair<int,int>> v;
    
    for (int i = 0; i < n; i++)
    {
      int x,y;
      cin>>x>>y;
      st.insert({x,y});
      v.push_back({x,y});
    }
    map<pair<int,int>, pair<int,int>> ans;
    
    
    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};
    queue<pair<int,int>> q;

    for (int i = 0; i < n; i++)
    { 
      int x = v[i].first , y =v[i].second;
      ans[{x,y}]={-1e8,-1e8};
      for (int j = 0; j < 4; j++)
      {
        int nx = x+dx[j] , ny = y+dy[j];
        if(!st.count({nx,ny})){
            ans[{x,y}]= {nx,ny};
            q.push({x,y});
            break;
        }
      }
    }
    
    while(q.size()){
      int x = q.front().first , y = q.front().second;
      q.pop();
       for (int j = 0; j < 4; j++)
      {
        int nx = x+dx[j] , ny = y+dy[j];

        if(st.count({nx,ny}) && ans[{nx,ny}].first==-1e8){
            ans[{nx,ny}]= ans[{x,y}];
            q.push({nx,ny});
        }
      }
    }
    
    
    for (int i = 0; i < n; i++)
    {
      int x = v[i].first , y =v[i].second;
      cout<<ans[{x,y}].first<<" "<<ans[{x,y}].second<<endl;
    }

  return;
}

int32_t main() {
    InTheNameOfAllah
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
    //cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}