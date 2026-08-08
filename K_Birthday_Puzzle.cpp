#include <bits/stdc++.h>
using namespace std;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define cin(v)                        \
    for (ll i = 0; i < v.size(); i++) \
        cin >> v[i];
#define unq(v) v.resize(distance(v.begin(), unique(all(v))));
#define tryAndCry(v)      \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << "\n";
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int n;
ll a[30];
vector<vector<int>> v;
vector<int> temp;
void fun(int index){
  for (int i = index; i < n; i++)
  {
    temp.push_back(a[i]);
    fun(i+1);
  }
    v.push_back(temp);
    temp.pop_back();
}

void solve() {
    cin >> n;
    ll sum = 0;
   
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans =0;
    fun(0);
    for (int i = 0; i < v.size(); i++)
    {
      ll temp=0;
      for (int j = 0; j < v[i].size(); j++)
      {
        temp|=v[i][j];
      }
      ans+=temp;
    }
    
    cout << ans ;

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