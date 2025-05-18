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
      ll x,y,z,v;
      cin>>x>>y>>z>>v;
      ll V=x*y*z;
      if(v>V)
      {
        cout<<0;
        return;
      }
      ll ans=0;
      for (ll i = 1; i <= x; i++)
      { ll sum=0;  
        if(v%i==0)
        for (ll j = 1; j <= y; j++)
        {   ll v1=v/i;

            if(v1%j==0) 
          { ll v2= v1/j;
            if(v2<=z) {
              ll ss=(x-i+1)*(y-j+1)*(z-v2+1);
              ans=max(ss,ans);
            }

          }  
          
          
        }
        
      }
      cout<<ans;

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