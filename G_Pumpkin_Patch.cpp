#include <bits/stdc++.h>
using namespace std;

#define ll int
// #define int short
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
const int Zz= 110;
ll n,m;
string s[Zz];
bool valid(int i , int j){
  if(i<0 || i>= n || j<0 || j>= m) return false;
  return s[i][j]!='P';
}

int visited[Zz][Zz][400][10];
void solve()
{
    cin>>n>>m;
    cin1(s,n);
    int cnt=0;
pair<int,int> start , end;
map<pair<int,int> ,int> mp;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
      if(s[i][j]=='S') start={i,j};
      if(s[i][j]=='E') end={i,j};
      if(s[i][j]=='C') mp[{i,j}]=cnt++;
      }
      
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        for (int k = 0; k < (1<<mp.size()+1); k++)
          for (int l = 0; l < mp.size()+1; l++)
            visited[i][j][k][l] =-1;
    
    queue<pair<pair<int,int> , pair<int,int>>>q;
    q.push(make_pair(start , make_pair(0,0)));
    int dx[4] = {0 , 0 , 1 , -1};
    int dy[4] = {1 , -1 , 0 , 0};
    visited[start.first][start.second][0][0]=0;

    while (q.size()) {
        pair<pair<int, int>, pair<int, int>> tp = q.front();
        q.pop();
        int x = tp.first.first, y = tp.first.second,
            msk = tp.second.first, coins = tp.second.second;

        if (x == end.first && y == end.second)
            continue;

        for (int i = 0; i < 4; i++) {

            int newX = x + dx[i], newY = y + dy[i];
            if (!valid(newX, newY)) continue;
            
            ll newCoins = coins;
            ll newMask = msk;
            if (s[newX][newY] == 'C') {
                int z = mp[{newX, newY}];
                if (msk & (1 << z));
                else {
                    newMask |= (1 << z);
                    newCoins++;
                }
            }
            if (s[newX][newY] == 'J') {
                if (!coins)
                    continue;
                newCoins--;
            }
            if (visited[newX][newY][newMask][newCoins] == -1) {
                q.push({{newX, newY}, {newMask, newCoins}});
                visited[newX][newY][newMask][newCoins] = visited[x][y][msk][coins] + 1;
            }
        }
    }
    ll ans=INT_MAX;
    for (int k = 0; k < (1<<mp.size()+1); k++)
          for (int l = 0; l < mp.size()+1; l++)
            if(visited[end.first][end.second][k][l]!=-1) ans=min(ans,visited[end.first][end.second][k][l]);

    if(ans!=INT_MAX) cout<<ans;
    else cout<<"SPOOKED!";         
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