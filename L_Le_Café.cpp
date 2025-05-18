#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define cin(v) for(ll i=0;i<v.size();i++)cin>>v[i];
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define tryAndCry(v) for(auto x : v){cout<<x<<" ";}cout<<"\n";
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
// const int MX = 505;
// int n, k; 
// bool dp[MX][MX];
// vector<int> x(MX);
// set<int> values;
// void fun(int i, int sum, int subSum) {
//     if (i == n or sum >= k) {
//         if (sum == k)
//             values.insert(subSum);
//         return;
//     }
//     if (dp[i][sum][subSum])
//         return;
//     fun(i + 1, sum, subSum);
//     fun(i + 1, sum + x[i], subSum + x[i]);
//     fun(i + 1, sum + x[i], subSum);
//     dp[i][sum][subSum] = 1;
// }
void solve()
{
    ll n;
    cin>>n;
    int a[n];
     map<int,int> m;
     bool can=false;
    for (int i = 0; i < n; i++)
    {
      cin>>a[i];
      m[a[i]]++;
      if(m[a[i]]>1) can=true;
    }
    if(can) {
      cout<<"S";
      return;
    }

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