#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
ll const N = 2e5+10; // max number of vertices
bool visited[N];
ll dp[N];
vector<ll> graph[N];
ll dfs(ll u)
{   visited[u]=true;
    if(graph[u].size()==1)
        return 1;
    ll ans=0;
    if(dp[u]>0)return dp[u];
    for (ll v : graph[u])
    {
        if (!visited[v])
        {   dp[v]=dfs(v);
            ans+=dp[v];
        }
    }
return dp[u]=ans;

}



int main() {
    InTheNameOfAllah
    test {
    int n;cin>>n;
        for (ll j = 0; j <= n; ++j) {

            graph[j].clear();
        }
        for (ll i = 0; i <= n; ++i) {
            visited[i]=false;
            dp[i]=-1;
        }
        graph[1].push_back(0);
        for (ll i = 0; i < n-1; i++)
        {
            ll u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
//        for (int i = 0; i <=n; ++i) {
//            cout<<graph[i].size()<<' ';
//        }cendl;
        ll q;
        cin>>q;
        for (int i = 0; i < n; ++i) {
            dfs(i+1);
        }
        while(q--) {
            ll x, y;
            cin >> x >> y;

            ll ans = dp[x]*dp[y];

            cout << ans << endl;

        }

    }
    return 0;
}