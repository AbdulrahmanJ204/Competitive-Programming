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

ll n,m,k;
bool isValid(int i , int j){
  if( i <0 || i>=n || j < 0 || j>=m) return false;
  return true;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        string s[n];
        int vis[n][m], BFS[26][26];
        assign2(BFS, 26, 26, 1e7);
        cin1(s, n);
        string b;
        cin >> b;

        for (int src = 0; src < 26; src++) {

            assign2(vis, n, m, -1);

            queue<pair<int, int>> pq;
            BFS[src][src] = 0;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (s[i][j] - 'a' == src) {
                        pq.emplace(i, j);
                        vis[i][j] = 0;
                    }
            int dirs[5] = {-1, 0, 1, 0, -1};

            while (!pq.empty()) {
                pair<int, int> f = pq.front();
                int x = f.first, y = f.second;
                int curTime = vis[x][y];
                pq.pop();
                for (int k = 0; k < 4; k++) {
                    int newX = x + dirs[k], newY = y + dirs[k + 1];

                    if (isValid(newX, newY) && vis[newX][newY] == -1) {
                        int to = s[newX][newY] - 'a', newTime = curTime + 1;
                        BFS[to][src] = min(BFS[to][src], newTime);
                        BFS[src][to] = min(BFS[src][to], newTime);
                        vis[newX][newY] = newTime;
                        pq.emplace(newX, newY);
                    }
                }
            }
        }

        ll ans = 0;
        for (int i = 0; i < k - 1; i++) {
            int from = b[i] - 'a', to = b[i + 1] - 'a';
            ans += BFS[from][to];
        }
        cout << ans << endl;
    }
    return 0;
}