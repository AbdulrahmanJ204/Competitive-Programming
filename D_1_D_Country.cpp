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
  #define rep(i , from , to) for(int i = from ; i < to ;i++)
  #define repR(i , from , to) for(int i = from ; i >= to ;i--)
  #define oo  LLONG_MAX;
  #define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

  void solve()
  {
      ll n;
      cin>>n;
      ll x[n],p[n];
      cin1(x,n);
      cin1(p,n);
      set<int> xs;
      map<int,int> mp;
      for (int i = 0; i < n; i++)
      {
        xs.insert(x[i]);
        mp[x[i]]=i+1;
      }
      ll pre[n+1];
      pre[0]=0;
      for (int i = 1; i < n+1; i++)
      {
        pre[i]=p[i-1]+pre[i-1];
      }
      
      int q;
      cin>>q;
      while(q--){
        int l ,r ;
        cin>>l>>r;
        if(n==1){
          if(x[0]<=r && x[0]>=l) cout<<p[0]<<endl;
          else cout<<0<<endl;
          continue;
        }
        l=*xs.lower_bound(l);
        auto it=(xs.upper_bound(r));
        it--;
        r=*it;
        if(l>r) {
          cout<<0<<endl;
          continue;
        }
        l=mp[l] , r=mp[r];
        cout<<pre[r]-pre[l-1]<<endl;
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