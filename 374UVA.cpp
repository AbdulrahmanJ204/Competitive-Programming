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
int mod;
ll mul(ll x, ll y){
  return (x%mod * y%mod)%mod;
}

ll fastPower(ll base, ll exponent)
{
    long long result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = mul(result, base) % mod;
        }
        base = mul(base, base) % mod;
        exponent /= 2;
    }
    return result % mod;
}
int main() {
    InTheNameOfAllah
    int b,p;
    while(cin>>b>>p>>mod){
      cout<<fastPower(b,p)<<endl;
    }
    return 0;
}