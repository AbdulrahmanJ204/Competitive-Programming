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
const int z=0;


void solve()
{
  
    ll n ,m;
    cin>>n>>m;
    vector<vector<ll>> a(n,vector<ll>(m));
    cin2(a,n,m);
    ll ans=1e18;
    
    ll dist1[n][m], dist2[n][m];
    assign2(dist1,n,m,1e18);
    assign2(dist2,n,m,1e18);
    dist1[0][0]=0;
    priority_queue<pair<ll,pair< ll, ll>>,
                       vector<pair<ll,pair< ll, ll>>>,
                       greater<pair<ll,pair< ll, ll>>>> pq;
    int directionOffsets[5] = {-1, 0, 1, 0, -1};
    pq.emplace(make_pair(0,make_pair(0,0)));
    while(!pq.empty()){
      pair<ll,pair<ll,ll>> tp = pq.top();
      ll currentTime= tp.first, row=tp.second.first, col=tp.second.second;
      pq.pop();
      // if (row == n - 1 && col == m - 1) {
      //   dist1[n-1][m-1]=min(dist1[n-1][m-1], currentTime);
      // }
    for (int k = 0; k < 4; ++k) {
        int newX = row + directionOffsets[k], newY = col + directionOffsets[k + 1];
        if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
            int newTime = currentTime + (a[row][col]<2);
            if (newTime < dist1[newX][newY]) {
                dist1[newX][newY] = newTime;
                pq.emplace(make_pair(newTime,make_pair( newX, newY)));
            }
        }
    }
    }

  while(!pq.empty()) pq.pop();
    
    
    dist2[n-1][m-1]=0;
    pq.emplace(make_pair(0,make_pair(n-1,m-1)));
    
    while(!pq.empty()){
    
      pair<ll,pair<ll,ll>> tp = pq.top();
      ll currentTime= tp.first, row=tp.second.first, col=tp.second.second;
        pq.pop();
      if (row == 0 && col == 0) {
        dist2[0][0]=min(dist2[0][0], currentTime);
      }
    for (int k = 0; k < 4; ++k) {
        int newX = row + directionOffsets[k], newY = col + directionOffsets[k + 1];
        if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
            int newTime = currentTime + (a[row][col]==2||!a[row][col]);
            if (newTime < dist2[newX][newY]) {
                dist2[newX][newY] = newTime;
                pq.emplace(make_pair( newTime,make_pair( newX, newY)));
            }
        }
    }
    }

    // cout<<"\ndist 1 : \n";
    // cout2(dist1,n,m);
    // cout<<"\ndist 2 : \n";
    // cout2(dist2,n,m);
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        ans=min(ans, dist1[i][j]+ dist2[i][j]);
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