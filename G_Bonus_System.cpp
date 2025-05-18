#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
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
#define oo  LLONG_MAX;
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n;
    cin>>n;
    string pass;
    cin>>pass;
    string st[n+1];
    map<int , int> mp;
    for (int i = 1; i <= n; i++)
    {
      cin>>st[i];
      
      mp[i];
    }
    int q;
    cin>>q;
    while(q--){
      string s;
      cin>>s;
      if(s=="bonus" ){
        int x, y;
        string pp;
        cin>>x>>y>>pp;
        if(pp!=pass){
          cout<<"Wrong password please try again\n";
          cout<<"---\n";
          continue;
        }
        mp[x]+=y;
        cout<<"Updated successfully\n";
        cout<<"---\n";
        
        }
        else{
          vector<pair<int,int>> v;
          for(auto x : mp) v.push_back(x);
          sort(all(v) , [&](pair<int,int> a, pair<int,int> b){
            if(a.second!=b.second) return  a.second>b.second;
            return a.first<b.first;
          });
          int order = 0 , last = -1;
          for(auto x : v) {
            if(!x.second) continue;
            if(x.second!=last)order++;   
             cout<<order<<" "<<x.first<<" "<<st[x.first]<<" "<<x.second<<endl; 
             last=x.second;
          }
        cout<<"---\n";
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