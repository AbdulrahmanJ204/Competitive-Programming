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
  int size= 1;
  int neut= 0;
  SEG(int n){
    size =1;
    while(size<= n) size*=2;
    segSize= n;
    tree.assign(size*2 , neut);
  }
  int merge(int a, int b){
    return max(a,b);
  }
  int build(vector<int> &a , int x =1 , int lx = 1, int rx = segSize){
    if(lx==rx) return tree[x] = a[lx];
    return tree[x] = merge(build(a , lft) , build (a , rit));
  }
  int set(int i , int v , int x = 1, int lx = 1 , int rx = segSize){
    if(lx==rx){
      return tree[x]= v;
    }
    int mid = lx+rx;
    mid/=2;
    if(i<=mid) set(i ,v , lft);
    else set(i , v , rit);
    return tree[x] = merge(tree[2*x] , tree[2*x+1]);
  }
  
  int query(int v , int l ,  int x= 1 , int lx= 1 , int rx = segSize){
   if(tree[x] < v) return -1;
    if(lx==rx) return lx-1;
    int mid = (lx+rx)/2 ;
    if(l<=mid){
    int first= query(v , l ,lft);
    if(~first) 
    return first;
    return query(v , l , rit);
    }
    else return query(v , l , rit);
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
    while(m--){
      int op;
      cin>>op;
      if(op==1){
        int i , v;
        cin>>i>>v;
        seg.set(i+1, v);
      }
      else{
        int x,l;
        cin>>x>>l;
        l++;
        cout<<seg.query(x,l)<<endl;
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