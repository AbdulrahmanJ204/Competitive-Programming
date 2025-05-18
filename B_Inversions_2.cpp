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
struct SEG
{
  vector<int> tree;
  int size , neutral = 0;
  SEG(int n){
    size= 1;
    segSize= n;
    while(size <=n) size*=2;
    tree.assign(2*size, neutral);
  }


   int merge(int a ,int b) {
    return a+b;
   }

   int build(int x= 1, int lx = 1, int rx = segSize)
   {
      if(lx==rx) return  tree[x] = 1;
      
        build(lft);
        build(rit);
      return tree[x] =merge(tree[2*x] , tree[2*x+1]);
      
   }
   
   int set(int i , int x=1 , int lx = 1 , int rx = segSize){
    if(lx==rx){

      tree[x]=0;
      return tree[x];
    }
    int mid= (lx+rx) /2;
    if(i<=mid) set(i , lft);
    else set(i  , rit);
    return tree[x] = merge(tree[2*x] , tree[2*x+1]);
   }

  int query(int suf , int x= 1 , int lx = 1 , int rx = segSize){
    if(lx==rx) return lx;
    if(tree[2*x+1] < suf) return query(suf - tree[2*x+1] , lft);
    return query(suf , rit);
  }
  void print(){
    tryAndCry(tree);
  }
};

void solve()
{
    ll n;
    cin>>n;
    vector<int> a(n+1);
    for (int i = 1; i < n+1; i++)
      cin>>a[i];
    SEG seg(n);
    seg.build();
    vector<int>v;
    for (int i = n ; i >= 1; i--)
    {
      ll ans= seg.query(a[i]+1);
      seg.set(ans);
      v.push_back(ans); 
      
    } 
    reverse(all(v));
    tryAndCry(v);

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