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
#define log2(x) __builtin_popcountll(x)
#define pi pair<int,int>
#define lft 2*x , lx , (lx+rx)/2
#define rit 2*x +1 , (lx+rx)/2+1 , rx
#define mn second.first
#define mx second.second

int seg_size;
int toSet = 0;
map<int,pi> mp;
template <typename T> struct SEG{
  int size = 1;
  T neutral = {0 , {1e18 , -1e18}};
  vector<T> tree;
  SEG(int n){
    seg_size = n;
    while(size<=n) size*=2;
    tree.assign(size *2 , neutral);
  }
  T merge(T a , T b){
    int mnn = min(a.mn , b.mn) , mxx = max(a.mx , b.mx);
    int cnt = a.first + b.first;
    return {cnt ,{mnn , mxx}};
  }
  void set(int i ,int v , int x = 1 , int lx = 1 , int rx =seg_size){
    if(lx==rx){
      tree[x] = {1 ,{v , v}};
      return;
    }
    if(tree[x]==neutral) 
    tree[2*x] = tree[2*x+1] = neutral;
    int mid = (lx+rx)/2;
    if(i<=mid) set(i , v, lft);
    else set(i , v , rit);
    tree[x] = merge(tree[2*x] , tree[2*x+1]);
  }
  T query(int l , int r , int p , int x =1, int lx = 1 , int rx = seg_size ){
    if(lx > r || rx < l || tree[x].mn > p) {
      return neutral;}
    if(l<= lx && rx <=r && tree[x].mx <= p){
      T ans = tree[x];
      tree[x] = neutral;
      return ans ;
    }
    if(l==lx && r==rx) return tree[x] =  neutral;
    T ans =  merge(query(l ,r , p , lft) , query(l , r, p , rit));
    tree[x] = merge(tree[2*x] , tree[2*x+1]);
    return ans;
  }
  
  
};
void solve()
{
  int n, m;
  cin>>n>>m;
  SEG<pair<int,pi>> seg(n+1);
  for (int i = 0; i < m; i++)
  {
    int op ; 
    cin>>op;
    if(op==1)
    {
      int i , h;
      cin>>i>>h;
      seg.set(i + 1, h);
    }
    else {
      int l , r  , p;  
      cin>>l>>r>>p;
      cout<<seg.query(l+1,r,p).first<<endl;
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