#include <bits/stdc++.h>
using namespace std;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
const int N = 100;
ll n;
ll r1, c1, r2, c2;
bool visited[N][N];
string s[N];
vector<pair<int,int>> graph[2];
bool valid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= n)
        return false;
    return s[i][j] == '0' && !visited[i][j];
}
ll dif(pair<int,int> fi, pair<int,int> se) {
    return (fi.first-se.first) * (fi.first-se.first) + (fi.second-se.second) * (fi.second-se.second);
}
void dfs(int i , int j , int node){
  if(!valid(i,j)) return;
  visited[i][j]=true;
  graph[node].push_back({i,j});
  dfs(i+1,j,node);
  dfs(i,j+1,node);
  dfs(i-1,j,node);
  dfs(i,j-1,node);
  return;
}
void solve() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--;
    r2--;
    c1--;
    c2--;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < N; j++)
        visited[i][j]=false;
      
    dfs(r1,c1,0);
    dfs(r2,c2,1);
    ll ans=1e9;
    if(graph[1].size()){
      for (int i = 0; i < graph[0].size(); i++)
      for (int j = 0; j < graph[1].size(); j++)
            ans=min(dif(graph[0][i],graph[1][j]),ans);
      cout<<ans;
      
    } 
    else cout<<0; 
    
    
    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    // cin>>t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}