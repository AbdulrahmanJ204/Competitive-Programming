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
#define rit 2*x +1, (lx+rx)/2+1 , rx
int segSize;
struct Node
{
  int pre , suf , mx , sum ;
};

 struct SEG
{
  vector<Node> tree;
  Node neutral;

  int size = 1;
  SEG(int n){

    size =1;
    neutral.mx = neutral.suf= neutral.sum = neutral.mx = 0;
    segSize = n;
    while(size<=n) size*=2;
    tree.assign(2*size , neutral);
    // cout<<tree.size()<<endl;
    // cout<<segSize<<endl;
    // for(auto x : tree) cout<<x.sum<<" ";cendl;
  }
  Node merge(Node a , Node b){
    Node node;
    node.sum = a.sum + b.sum;
    node.pre = max({a.pre , a.sum , a.sum + b.pre});
    node.suf = max({a.suf+ b.sum , b.sum , b.suf});
    node.mx = max({node.sum, node.pre, node.suf, a.suf + b.pre, a.mx, b.mx});
    return node;
  }
  Node build (vector<int> &a  , int x  = 1, int lx = 1 , int rx = segSize){
    
    if(lx==rx) {
      tree[x].pre = a[lx];
      tree[x].suf = a[lx];
      tree[x].sum = a[lx];
      tree[x].mx =a[lx];
      return tree[x];
    }
    return tree[x] =  merge(build(a , lft) , build(a , rit));
  }
  Node set(int i , int v , int x= 1 , int lx = 1, int rx = segSize){
    if(lx == rx){
      tree[x].pre = v;
      tree[x].suf = v;
      tree[x].sum = v;
      tree[x].mx =  v;
      return tree[x];
    }
    int mid = (lx+rx)/2;
    if(i<=mid) set(i , v , lft);
    else set(i ,v ,rit);
    return tree[x] = merge(tree[2*x] , tree[2*x +1]);
  }
  int query(){
    return max(tree[1].mx , 0ll);
  }
};




void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for (int i = 1; i < n+1; i++)
    {
      cin>>a[i];
    }
    a[0]=0;
    SEG seg(n);
    seg.build(a);
    cout<<seg.query()<<endl;
    while(m--)
    {
      int i , v ;
      cin>>i>>v;
      i++;
      seg.set(i ,v);
    cout<<seg.query()<<endl;

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