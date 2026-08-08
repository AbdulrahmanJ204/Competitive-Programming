/*
            .------.____
         .-'       \ ___)
      .-'         \\\
   .-'        ___  \\)
.-'          /  (\  |)
         __  \  ( | |
        /  \  \__'| |
       /    \____).-'
     .'       /   |
    /     .  /    |
  .'     / \/     |
 /      /   \     |
       /    /    _|_
       \   /    /\ /\
        \ /    /__v__\
         '    |       |
              |     .#|
              |#.  .##|
              |#######|
              |#######|
                      (
                        )     (
                 ___...(-------)-....___
             .-""       )    (          ""-.
       .-'``'|-._             )         _.-|
      /  .--.|   `""---...........---""`   |
     /  /    |                             |
     |  |    |                             |
      \  \   |                             |
       `\ `\ |                             |
         `\ `|                             |
         _/ /\                             /
        (__/  \                           /
     _..---""` \                         /`""---.._
  .-'           \                       /          '-.
 :               `-.__             __.-'              :
 :                  ) ""---...---"" (                 :
  '._               `"--...___...--"`              _.'
    \""--..__                              __..--""/
     '._     """----.....______.....----"""     _.'
        `""--..,,_____            _____,,..--""`
                      `"""----"""`
 * */
#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
const int N=2001;
vector<ll> graph[N];
bool visited[N];
ll ans=1;
void dfs(ll i,ll len) {
    visited[i] = true;
    for (auto x:graph[i]) {
        if (!visited[x]) {
            ans = max(ans, len + 1);
            dfs(x, len + 1);
        }
    }
}
int main() {
    InTheNameOfAllah
    for (int j = 0; j < N; ++j) {
        visited[j]=false;
    }
    int n;
    cin >> n;
    vector<ll> v;
    for (int i = 1; i <= n; ++i) {
        ll x;
        cin>>x;
        if(x!=-1) graph[x].push_back(i);
        else v.push_back(i);
    }
    for(ll x:v) {
        dfs(x, 1);
    }
    cout<<ans<<endl;
    // SECOND SOLUTION
//    int p[2001];
//    int c[2001];
//    bool a1 = true;
//    for (int l = 0; l < 2001; ++l) {
//        p[l] = 0;
//        c[l] = -1;
//    }
//    for (int i = 1; i <= n; ++i) {
//        cin >> p[i];
//        if (p[i] != -1) a1 = false;
//        else c[i] = 1;
//    }
//    if (a1) {
//        cout << 1 << endl;
//        return 0;
//    }
//    int x = 1, temp = n;
//    while (temp--) {
//        for (int j = 1; j <= n; ++j)
//            if (p[j] == -1) continue;
//            else if (c[p[j]] == x)
//                c[j] = x+1;
//        x++;
//    }
//    int ans = 0;
//    for (int k = 0; k < n + 1; ++k) {
//        ans = max(c[k], ans);
//    }
//
//    cout << ans  << endl;

    return 0;
}