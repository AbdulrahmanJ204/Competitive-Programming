#include <bits/stdc++.h>
using namespace std;

#define ll long long
// #define int ll
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
#define oo  LLONG_MAX
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n;
    cin>>n;
    int k1 , k2;
    cin>>k1;
    queue<int> q1 , q2;
    int m1 = 0 , m2 = 0;
    for (int i = 0; i < k1; i++)
    {
      int x;
      cin>>x;
      q1.push(x);
    }
    cin>>k2;
    for (int i = 0; i < k2; i++)
    {
      int x;
      cin>>x;
      q2.push(x);
    }
    set<pair<queue<int> , queue<int>>> st;
    st.insert(make_pair(q1 , q2));
    int cnt = 0;
    while(q2.size()&& q1.size()){
      cnt++;
      int c1 = q1.front() , c2 = q2.front();
      q1.pop();
      q2.pop();
      if(c1 > c2) {
        q1.push(c2);
        q1.push(c1);  
      } 
      else {
        q2.push(c1);
        q2.push(c2);
      }
      
      if(st.find(make_pair(q1 , q2)) != st.end()){
        cout<<-1;
        return;
      }
      st.insert(make_pair(q1 , q2));
    }

    cout<<cnt<<" "<<(q1.size() ? 1 : 2);
    
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