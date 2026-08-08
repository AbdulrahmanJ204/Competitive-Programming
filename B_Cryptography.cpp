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
ll mod;
const int z =4;
struct Node
{
  int a0 , a1 , a2 , a3;
  Node(){
    a0 = a3 = 1;
    a1 = a2 = 0;
  }
};

int seg_size;
int mul(int a, int b) {
  return ((a%mod) * (b%mod) )%mod;
}
struct SEG
{
  vector<Node> tree;
  Node neut ;
  int size;
  SEG(int n){
    size = 1;
    seg_size = n;
    while(size <= n) size*=2;
    tree.assign(2*size , neut);
  }
  Node merge(Node a , Node b){
  
  Node res;
  res.a0 = (mul(a.a0 , b.a0) + mul(a.a1 , b.a2) )%mod; 
  res.a1 = (mul(a.a0 , b.a1) + mul(a.a1 , b.a3) )%mod; 
  res.a2 = (mul(a.a2 , b.a0) + mul(a.a3 , b.a2) )%mod; 
  res.a3 = (mul(a.a2 , b.a1) + mul(a.a3 , b.a3) )%mod; 
  
  return res;
}
  Node build(vector<Node> &a , int x =1 , int lx =1  , int rx = seg_size){
    if(lx==rx) return tree[x] = a[lx];
    return tree[x] = merge(build(a , lft) , build(a , rit));
  }  
  
  Node query(int l ,int r , int x = 1, int lx = 1 ,int rx = seg_size){
    if(lx > r || rx < l) return neut;
    if(l <= lx && rx <=r) return tree[x];
    return merge(query(l ,r , lft) , query(l ,r , rit));
  }

};

void print(Node res){
  cout<<res.a0<<' '<<res.a1<<endl;
  cout<<res.a2<<' '<<res.a3<<endl;
}

void solve()
{
    ll n ,m;
    cin>>mod>>n>>m;
    vector<Node> a(n+1);
    for (int i = 1; i <= n; i++)
    {
      cin>>a[i].a0;
      cin>>a[i].a1;
      cin>>a[i].a2;
      cin>>a[i].a3;
    }

    SEG seg(n);
    seg.build(a);
    while(m--){
      int l ,r;
      cin>>l>>r;
      Node res = seg.query(l ,r);
      print(res);
      cendl;
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