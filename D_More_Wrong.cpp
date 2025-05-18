#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"
#define cno cout<<"NO"
#define cin(v) for(ll i=0;i<v.size();i++)cin>>v[i];
#define cin1(v,n) for(ll i=0;i<n;i++)cin>>v[i];
#define cin2(v,n,m) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) cin>>v[i][j];
#define cout1(v,n) for(ll i=0;i<n;i++)cout<<v[i]<<' '; cendl;
#define cout2(v,n,m) for(ll i=0;i<n;i++,cendl) for (int j = 0; j < m; j++) cout<<v[i][j]<<' '; 
#define assign1(v,n,value) for(ll i=0;i<n;i++)v[i]=value;
#define assign2(v,n,m,value) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) v[i][j]=value;
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define tryAndCry(v) for(auto x : v){cout<<x<<" ";}cout<<"\n";
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
int ask(int l, int r){
    if(l==r) return 0;
    cout<<"? "<<l<<" "<<r<<endl;
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;

    int lastLevel=ceil(log2(n));
    int a[lastLevel+1][n];
    
    assign2(a,lastLevel+1,n,0);
    
    for (int i = 0; i < n; i++) a[0][i]=i+1;
    
    for (int cnt, level= 0; level < lastLevel; level++,cnt=0)
      for (int i = 0; i < n; i+=2)
      {
       if(i+1>=n||a[level][i]==0||a[level][i+1]==0) {
        a[level+1][cnt]=a[level][i];
        cnt++;
        continue;
       }
       int x= ask(a[level][i],a[level][i+1]);
       int last=ask(a[level][i],a[level][i+1]-1);
       a[level+1][cnt]= x==last? a[level][i+1] : a[level][i];
       cnt++;
      }
      
    
    cout<<"! " <<a[lastLevel][0]<<endl;
    
    return;
}

int main() {
    // InTheNameOfAllah
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}
