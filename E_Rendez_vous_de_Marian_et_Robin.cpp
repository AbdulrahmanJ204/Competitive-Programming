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
    ll n, m, h;
    cin >> n >> m >> h;

    vector<pair<int, int>> graph[n];
    bool horses[n];
    assign1(horses, n, false);
    for (int i = 0; i < h; i++) {
        int x;
        cin >> x;
        x--;
        horses[x] = 1;
    }

    for (int i = 0; i < m; i++) {
        int from, to, w;
        cin >> from >> to >> w;
        from--, to--;
        graph[from].push_back({to, w});
        graph[to].push_back({from, w});
    }

    ll dist1[n][2], dist2[n][2];
    priority_queue<pair<pair<int, int>, int>> pq;

    assign2(dist1, n, 2, 1e18);
    pq.push({{0, !horses[0]}, 0});

    while (!pq.empty()) {
        pair<pair<int, int>, int> curPair = pq.top();
        pq.pop();
        int curDist = -curPair.first.first,
            horse = !curPair.first.second,
            curNode = curPair.second;

        if (dist1[curNode][horse] <= curDist)
            continue;

        dist1[curNode][horse] = curDist;

        for (auto chlid : graph[curNode]) {
            int curChild = chlid.first,
                curEdge = horse ? chlid.second / 2 : chlid.second,
                newDist = curDist + curEdge;
            if (newDist < dist1[curChild][horse]) {
                pq.push({{-newDist, !(horse | horses[curChild])}, curChild});
            }
        }
    }

    assign2(dist2, n, 2, 1e18);
    pq.push({{0, !horses[n - 1]}, n - 1});

    while (!pq.empty()) {
        pair<pair<int, int>, int> curPair = pq.top();
        pq.pop();
        int curDist = -curPair.first.first,
            horse = !curPair.first.second,
            curNode = curPair.second;
        if (dist2[curNode][horse] <= curDist)
            continue;

        dist2[curNode][horse] = curDist;

        for (auto chlid : graph[curNode]) {

            int curChild = chlid.first,
                curEdge = horse ? chlid.second / 2 : chlid.second,
                newDist = curDist + curEdge;

            if (newDist < dist2[curChild][horse]) {
                pq.push({{-newDist, !(horse | horses[curChild])}, curChild});
            }
        }
    }

    ll ans=1e18;
    for (int i = 0; i < n; i++)
    ans=min(ans,max(min(dist1[i][0],dist1[i][1]),min(dist2[i][0],dist2[i][1])));
    
    if(ans==1e18) ans=-1;
    cout<<ans;
    return;
}

int32_t main() {
    InTheNameOfAllah
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}