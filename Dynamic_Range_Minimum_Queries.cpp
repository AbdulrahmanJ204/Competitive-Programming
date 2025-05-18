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
#define rit 2*x+1  , (lx+rx)/2+1 , rx
int seg_size;
template <typename T> struct SEG{

  vector<T> tree;
  T neut = 1e18;
  int size = 1;
  SEG(int n){
    seg_size = n;
    while(size <=n) size*=2;
    tree.assign(2*size , neut);
  }
  T merge (T a , T b){
    return min(a,b) ;
  }
  T build(vector<int> &a ,int x = 1 , int lx = 1 , int rx = seg_size){
    if(lx==rx){
      return tree[x]=a[lx];
    }
    return tree[x] = merge(build(a , lft) , build(a , rit));
  }
  void update(int i , int v , int x = 1 , int lx = 1 , int rx = seg_size){
    if(lx==rx){
      tree[x] = v;
      return;
    }
    int mid = (lx+rx)/2;
    if(i<=mid) update(i ,v , lft);
    else update(i , v , rit);

    tree[x] = merge(tree[2*x] , tree[2*x+1]);
    return;
  }
  T query(int l , int r , int x = 1 , int lx = 1 , int rx = seg_size){
    if(rx < l || r < lx) return neut;
    if(l <= lx && rx <=r) return tree[x];
    return merge(query(l ,r , lft) , query(l , r, rit));
  }

};
void solve()
{
    ll n;
    cin>>n;
    int q;
    cin>>q;
    vector<int> a(n+1);
    a[0]= 1e18;
    
    for (int i = 0; i < n; i++)
      cin>>a[i+1];
    SEG<int> seg(n);
    seg.build(a);
    while(q--){
      int op , l , r;
      cin>>op>>l>>r;
      if(op==1){
        seg.update(l , r);
      }
      else {
        cout<<seg.query(l , r)<<endl;
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