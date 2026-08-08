#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

const int N = 1e5 + 10;
ll n;
vector<int> graph[N] ,v;
int a[N], b[N];
bool visited[N];
void dfs(int i , bool flip1, bool flip2){
    visited[i]=true;
    if(flip1) a[i]=1-a[i];
    if(a[i]!=b[i]){
        v.push_back(i);
        a[i]=1-a[i];
        flip1=!flip1;
    }
    for(auto child: graph[i]){
        if(!visited[child]) dfs(child,flip2, flip1);
    }
}
void solve()
{
    
    cin>>n;
    
    for (int i = 0; i <= n; i++) {
        visited[i]=false;
    }

    for (int i = 0; i < n - 1; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        cin >> b[i];
    dfs(1,0,0);
    cout<<v.size()<<endl;
    for(auto x: v) cout<<x<<endl;

  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    //cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// #define test  \
//     int t;    \
//     cin >> t; \
//     while (t--)
// #define ll long long
// #define endl '\n'
// #define cendl cout << endl
// #define cyes cout << "YES" << endl
// #define cno cout << "NO" << endl
// #define InTheNameOfAllah          \
//     ios_base::sync_with_stdio(0); \
//     cin.tie(0);

// const int N = 1e5 + 10;
// ll n;
// vector<int> graph[N], newGraph[N], v;
// int a[N], b[N], dp[N][2];

// void buildNew(int node, int parent) {
//     for (auto child : graph[node]) {
//         if (child != parent) {
//             for (auto x : graph[child]) {
//                 if (x != node)
//                     newGraph[node].push_back(x);
//             }
//             buildNew(child, node);
//         }
//     }
// }

// ll fun(int node, int flip, int parent) {

//     if (!newGraph[node].size()) {
//         if ((a[node] == b[node] && flip) || (a[node] != b[node] && !flip)) // case is root and need to flip it
//             return dp[node][flip] = 1;
//         return dp[node][flip] = 0; // ai==bi , no flip
//     }
//     if (dp[node][flip] != -1) // calculated
//         return dp[node][flip];
//     ll c = 0;
//     // for each child , check if need to flip it
//     for (auto child : newGraph[node]) {
//         if (child != parent) {
//             if ((a[child] != b[child] && !flip) || (a[child] == b[child] && flip)) {
//                 c += 1 + fun(child, !flip, node);
//                 v.push_back(child);
//             } else
//                 c += fun(child, flip, node);
//         }
//     }

//     return dp[node][flip] = c;
// }

// void solve() {

//     cin >> n;

//     for (int i = 0; i <= n; i++) {
//         dp[i][0] = -1;
//         dp[i][1] = -1;
//     }

//     for (int i = 0; i < n - 1; i++) {
//         int from, to;
//         cin >> from >> to;
//         graph[from].push_back(to);
//         graph[to].push_back(from);
//     }
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];

//     for (int i = 1; i <= n; i++)
//         cin >> b[i];

//     buildNew(1, -1);

//     ll x = 0;
//     vector<int> ans;
//     if (a[1] == b[1])
//         fun(1, 0, -1);
//     else {
//         fun(1, 1, -1);
//         v.push_back(1);
//     }
//     for (auto child : graph[1]) {
//         if (a[child] == b[child])
//             fun(child, 0, 1);
//         else {
//             fun(child, 1, 1);
//             v.push_back(child);
//         }
//     }

//     cout << v.size() << endl;
//     reverse(v.begin(), v.end());
//     for (auto x : v)
//         cout << x << endl;

//     return;
// }

// int main() {
//     InTheNameOfAllah
//         ll t = 1;
//     // cin>>t;
//     while (t--) {
//         solve();
//         cendl;
//     }
//     return 0;
// }