#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
vector<ll> twos;
ll fastPower(ll base, ll exponent)
{
    long long result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result *=base;
        }
        base *=base;
        exponent /= 2;
    }
    return result ;
}
void solve()
{
    ll n;
    cin>>n;
    for (int i = twos.size() - 1; i >= 0; i--)
    {
      if(twos[i]<=n) {
        cout<<twos[i];
        return;
      }
    }
    

  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    for (int i = 0; i < 31; i++)
    {
      twos.push_back(fastPower(2,i));
    }
    
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}