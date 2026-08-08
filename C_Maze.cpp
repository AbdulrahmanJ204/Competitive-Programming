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
const int N=510;
char s[N][N];
bool visited[N][N];
int n, m, k,nOfConnected,hs=0,cnt=0;
bool valid(int i , int j){
  if(i>=n||j>=m||i<0||j<0) return false;
  return !visited[i][j]&&s[i][j]=='.';
}

bool dfs(int i , int j) {
  if(!valid(i,j)) return false;
  visited[i][j]=true;
  cnt++;
  if(cnt==nOfConnected) return true;
  if(dfs(i,j+1)) return true;
  if(dfs(i+1,j)) return true;
  if(dfs(i-1,j)) return true;
  if(dfs(i,j-1)) return true;
  
 return false; 
}

void solve() {
    
    
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      visited[i][j]=false;
    
    
    for (int i = 0; i < n; i++)
      cin>>s[i];

    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
     if(s[i][j]=='#') hs++;
     nOfConnected=n*m-hs-k;
      //  cout<<n<<' '<<m<<' '<<hs<<' '<<k<<endl;
       bool ok=false;
       for (int i = 0; i < n; i++) {
           for (int j = 0; j < m; j++)
           {
               if (dfs(i, j)) {
                   ok = true;
                   break;
               }
           }
           if (ok)
               break;
       }

    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if(!visited[i][j]&&s[i][j]=='.') s[i][j]='X';
    for (int i = 0; i < n; i++)
    cout<<s[i]<<endl;
    
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