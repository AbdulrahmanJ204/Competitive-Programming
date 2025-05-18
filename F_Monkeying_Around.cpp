#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
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
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> q;
    for (int i = 0; i < m; i++)
    {
      ll x , joke , k;
      cin>>x>>joke>>k;
      ll start=max(x-k , 1ll) , end = min(n, x+k);
      q.push_back({joke,{start,end}});
    }
    reverse(all(q));
    set<int> onSeats;
    for (int i = 0; i < n; i++)
      onSeats.insert(i+1);
    map<int,set<int>> mp;
    ll backOnSeats=0;
    for (int i = 0; i < m; i++)
    {
       int joke = q[i].first, start = q[i].second.first, end = q[i].second.second;
       set<int> monkeys;
       auto first = onSeats.lower_bound(start);
       auto last = onSeats.upper_bound(end);
       while(first!=last){
        monkeys.insert(*first);
        auto removeMonkey=first;
        first++;
        onSeats.erase(removeMonkey);
       } 
       auto first_Heard = mp[joke].lower_bound(start);
       auto last_Heard = mp[joke].upper_bound(end);
       while(first_Heard!=last_Heard){
        backOnSeats++;
        auto removeMonkey=first_Heard;
        first_Heard++;
        mp[joke].erase(removeMonkey);
       }
       // add all monkeys that heard the joke to the map
       for(int x : monkeys) mp[joke].insert(x);
    }
    cout<<onSeats.size()+backOnSeats;
    

  return;
}

int32_t main() {
    InTheNameOfAllah
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}