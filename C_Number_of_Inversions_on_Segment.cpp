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
// int seg_size;
struct Node
{
  int sum , a;
  vector<int> cnt;
  Node(){
    sum =a=0;
    cnt.assign(41 , 0);
  }
  
};


int sz;

  vector<Node> tree;
  vector<int> a;
  Node merge(Node a , Node b ,int l1 ,int r1 , int l2 , int r2 ){
    int gl = 0 , sr  = 0;
    int res = a.sum+b.sum;
    int lastSum= 0;
    int i= 2 , j= 1;
    while(i<=40){
      gl = a.cnt[i];
      if(!gl){ i++;continue;}
      while(j<i){
        lastSum+=b.cnt[j];
        j++;
      }
      res+=gl * lastSum;
      i++;
    }
    Node c;
    c.sum = res;
    for (int i = 0; i < 41; i++)
      c.cnt[i] = a.cnt[i] + b.cnt[i];
    return c;
  }
  
  Node build(int x= 1 , int lx = 1 , int rx = sz){
    if(lx==rx) 
    { 
      tree[x].sum = 0;
      tree[x].a = a[lx];
      tree[x].cnt[a[lx]]++;
      return tree[x];
    }
    return tree[x] =  merge(build(lft) ,build(rit),lx , (lx+rx)/2 , (lx+rx)/2 +1 , rx);
  }
  
  Node neut;
  void init1(int n){
    int size1 =1;
    sz = n;
    while(size1<=n) size1*=2;
    tree.assign(2*size1 , neut);
    build();
  }
  


  void set2(int i ,int v, int x = 1, int lx = 1 , int rx = sz){
    if(lx==rx) {
      tree[x].sum = 0;
      tree[x].cnt[tree[x].a]--;
      tree[x].a = v;
      tree[x].cnt[tree[x].a]++;
      return ;
      }
    int mid = (lx+rx)/2;
    if(i<=mid) set2(i ,v ,lft);
    else set2(i ,v, rit);
    tree[x] = merge(tree[2*x] , tree[2*x+1] , lx , (lx+rx)/2 , (lx+rx)/2 +1 , rx);
  }

  Node query(int l , int r ,int x= 1, int lx = 1 , int rx = sz)
  {
    if(lx> r || rx < l) return neut;
    if(l<= lx && rx <= r) return tree[x];
    return merge(query(l , r , lft) , query(l , r, rit) , max(l , lx) , (lx+rx)/2 , (lx+rx)/2 +1 , min(r , rx));
  }




void solve()
{
    ll n,q;
    cin>>n>>q;
    a.assign(n+1 , 0);
    for (int i = 1; i < n+1; i++)
    {
      cin>>a[i];
    }
    a[0]=0;
    init1(n);
    
    while(q--){
      int op ;
      cin>>op;
      if(op==1){
        int l , r;
        cin>>l>>r;
        cout<<query(l,r).sum<<endl;
      }
      else{
        int i ,v ;
        cin>>i>>v;
        set2(i,v);
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