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

void solve() {
  
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    ll n;
    cin >> n;
    int k;
    cin >> k;
    int a[n + 1];
    int pre[n + 1];
    a[0] = pre[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a, a + n+1);

    for (int i = 1; i <= n; i++)
        pre[i] = a[i] + pre[i - 1];

    int i = 1, j = 0, sum = 0,ans=0;
    while(j<n){
      j++;
      while(abs(a[j]-a[i])>k&&i<=j) i++; 
      sum=max(j-i+1,sum);
    }
    cout<<sum;
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