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

void solve()
{
    ll n;
    string s;
    cin>>n;
    cin>>s;
    if(n<=2){
      cout<<s;
      return;
    }
    char op[n];
    for (int i = 1; i < n-1; i++)
    { 
      if(s[i]-'0'==0&& n>3) {
        cout<<0;
        return;
      }
      if((s[i-1]-'0')*(s[i]-0)<(s[i-1]-'0')+(s[i]-0)) op[i]='*';
      else op[i]='+';
    }
    ll ans=1e18;
    
    
  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}