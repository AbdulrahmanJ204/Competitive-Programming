#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define gcd(a ,b) __gcd(a,b)
#define lcm(a,b) a*b/gcd(a,b)
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"
#define cno cout<<"NO"
#define cin(v) for(ll i=0;i<v.size();i++)cin>>v[i];
#define cin1(v,n) for(ll i=0;i<n;i++)cin>>v[i];
#define cin2(v,n,m) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) cin>>v[i][j];
#define tryAndCry(v) for(auto x : v){cout<<x<<" ";}cout<<"\n";
#define cout1(v,n) for(ll i=0;i<n;i++)cout<<v[i]<<' '; cendl;
#define cout2(v,n,m) for(ll i=0;i<n;i++,cendl) for (int j = 0; j < m; j++) cout<<v[i][j]<<' ';
#define assign1(v,n,value) for(ll i=0;i<n;i++)v[i]=value;
#define assign2(v,n,m,value) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) v[i][j]=value;
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define oo  LLONG_MAX
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n;
    cin>>n;
    int a[n];
    cin1(a,n);
    map<int,vector<int>> mp;
    map<int,int> updateVal;
    for (int i = 0; i < n; i++)
    {
      int c;
      cin>>c;
      if(!mp.count(c)) mp[c].push_back(0);
      mp[c].push_back(a[i]);
    }
    for(auto &x : mp){
      for(int i = 1 ; i<x.second.size(); i++) x.second[i]+=x.second[i-1];
    }
    int q;
    cin>>q;
    int allIncreased = 0;
    while(q--){
      int op , col , val;
      cin>>op>>col>>val;
      if(op==1){
        allIncreased+=val;
        updateVal[col]-=val;
      }
      else {
        if(!mp.count(col)){
          cout<<0<<endl;
          continue;
        }
        //do binary search where prefix of mp[col] , where index * (all-up[col]) + pre <=x
        int l = 0 , r = mp[col].size()-1, ans = 0;
        while(l<=r){
          int mid = (l+r)/2;
          int curTaken = allIncreased + updateVal[col];
          curTaken*=mid;
          curTaken+=mp[col][mid];
          // cout<<"Query : "<<col<< " "<<val<<endl;
          // cout<<"idx = "<<mid<<" "<<curTaken<<" "<<allIncreased<<" "<<updateVal[col]<<endl;
          // for(auto  x : mp[col]){
          //   cout<<x + allIncreased - updateVal[col]<<" ";
          // }cendl;
          if(curTaken <=val){
            ans = max(ans , mid);
            l = mid+1;
          }
          else r=mid-1;
        }
        // if(ans==mp[col].size()) ans--;
        cout<<ans<<endl;
      }

    }
        

  return;
}

int32_t main() {
    InTheNameOfAllah
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
    //cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}