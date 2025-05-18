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
ll mod=1e9+7;
ll mul(ll x, ll y)
{
    return (x % mod * y % mod) % mod;
}
ll perm(ll n, vector<int> s){
  // calculates n! / (S1! * S2! * ..... Sn!)
  vector<int> num(n-1);
  queue<int> q;// de_num
  for (int i = 2; i <= n; i++)
  {
    num[i-2]=i;
  }
  for(auto x: s){
    while(x>1){
      q.push(x);
      x--;
    }
  }
  while(!q.empty()){
    int x=q.front();
    q.pop();
    for (int i = 0; i < num.size(); i++)
    {
      int g=__gcd(x,num[i]);
      num[i]/=g;
      x/=g;
      if(x==1) break;
    }
    if(x!=1) q.push(x);
  }
  int lower=1;
  while(!q.empty()) {lower*=q.front();q.pop();}
  ll upper=1;
  for(auto x: num) upper= mul(upper, x);
  return upper/lower;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    //cin>>t;
    while(t--){
      vector<int> s{2 , 3 , 2};
      int n=20;
      cout<<perm(n,s);
    }
    return 0;
}