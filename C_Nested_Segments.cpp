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
#define oo  LLONG_MAX
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
#define lft 2*x , lx , (lx+rx)/2
#define rit 2*x +1, (lx+rx)/2+1,rx
int seg_size;
struct SEG
{
  vector<int> tree;
  int neut = 0;
  
  int size;
  SEG(int n){
    size= 1;
    seg_size = n;
    while(size<=n) size*=2;
    tree.assign(2*size , neut);
  }
  void build(vector<int>&a , int x= 1, int lx = 1 , int rx= seg_size){
      tree[x] = 0;
    if(lx==rx)
    return ;
    build(a , lft);
    build(a , rit);
  }

  int merge(int a , int b){
    return a+b;
  }
  int set(int i , int x = 1, int lx = 1 ,int rx= seg_size){
    if(lx==rx){
      return tree[x] = !tree[x];
    }
    int mid= (lx+rx)/2;
    if(i<=mid) set(i , lft);
    else set(i , rit);
    return tree[x] = merge(tree[2*x] , tree[2*x +1]);
  }
  int query(int l , int r , int x = 1 , int lx = 1, int rx = seg_size){
    if(l>=r) return 0;
    if(lx > r || rx < l) return neut;
    if(l<= lx && rx <=r) return tree[x];
    return merge(query(l , r , lft) , query(l , r ,rit));
  }
};

void solve()
{
    ll n;
    cin>>n;
    vector<int> a(2*n+1);
    for (int i = 1; i < 2*n+1; i++)
    {
      cin>>a[i];
    }
    SEG seg(2*n);
    seg.build(a);
    map<int,int> mp;
    ll ans[n+1];
    for (int i = 1; i < 2*n+1; i++){
      if (mp[a[i]]) {
          ans[a[i]] = seg.query(mp[a[i]] , i);
          seg.set(mp[a[i]]);
      }
      else mp[a[i]] = i;
    }
    for (int i = 1; i < n+1; i++)
    {
      cout<<ans[i]<<" ";
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