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
    cin>>n;
    int a[n];
    map<int,int> m;
    bool z=false;
    for (int i = 0; i < n; i++)
    {
      cin>>a[i];
      m[a[i]]++;
      if(m[a[i]]>=2) z=true;
    }
    if(a[0]==a[n-1]) cout<<"NO";
    else {
      cout<<"YES"<<endl;
      bool b=true;
      if(m.size()==2){
        for(auto x:m) if(x.second>1&&b){
          b=false;
          cout<<"R";
          int cnt=x.second-1;
          while(cnt--) cout<<"B";
        }
        else {
          while(x.second--){
            cout<<"B";
          }
        };
      }
      else {
        cout<<"B";
        for (int i = 0; i < n-1; i++)
        {
          cout<<"R";
        }
        
      }
      
    }

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