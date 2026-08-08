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
#define lft 2 * x, lx, (lx + rx) / 2
#define rt 2 * x + 1, (lx + rx) / 2 + 1, rx
int seg_size;
struct SEG
{
  int neut =0;
  vector<int> tree;
  int size =1;
  SEG(int n){
    seg_size = n;
    while (size<=n)
    {
      size*=2;
    }
    tree.assign(size*2 , neut);
  }
  int merge(int a , int b){
    return a|b;
  }
  void build(vector<int> &a , int x =1 , int lx =1  , int rx=seg_size)
  {
    if(lx==rx) {
      tree[x] = a[lx];
      return;
    }
    build(a , lft);
    build(a ,rt);
    tree[x] =merge(tree[2*x] ,tree[2*x+1]);
  }
  int query(int l , int r , int x = 1 , int lx = 1 , int rx = seg_size){
    if(lx > r || rx < l) return neut;
    if(l <= lx && rx <=r) return tree[x];
    return merge(query(l , r ,lft) , query(l ,r , rt));
  }
};

void solve()
{
    ll n;
    cin>>n;
    n++;
    int a[n] ; vector<int> b(n);
    int pre[n];pre[0]=0;
    for (int i = 1; i < n; i++)
    {
      cin>>a[i];
      pre[i]= pre[i-1]+ a[i]*a[i];
    }
    for (int i = 1; i < n; i++)
    {
      cin>>b[i];
    }
    SEG seg(n);
    seg.build(b);
    int l = 1 , r=1 , ans =0;
    while(r<n+1){
      int f = pre[r]-pre[l-1];
      int g = seg.query(l ,r);
      g*=g;
      if(f<g)
         r++;
      else  l++,ans+=r-l+1;
      
      if(l>r) r++;
    }
    cout<<ans;
    /*
    5
1 2  4  3  1

1 5 21 30 31
1 5 13 15 15

1 4  8  7  1
*/

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