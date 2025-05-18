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
#define tryAndCry(v) for(auto x : v){cout<<x<<" ";}cout<<"\n";
#define cout1(v,n) for(ll i=0;i<n;i++)cout<<v[i]<<' '; cendl;
#define cout2(v,n,m) for(ll i=0;i<n;i++,cendl) for (int j = 0; j < m; j++) cout<<v[i][j]<<' ';
#define assign1(v,n,value) for(ll i=0;i<n;i++)v[i]=value;
#define assign2(v,n,m,value) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) v[i][j]=value;
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n;
    cin>>n;

    ll a[n];
    ll x1,x2,x3;
    cout<<"? "<<1<<" "<<2<<endl;
    cout.flush();
    cin>> x1;
    cout<<"? "<<1<<" "<<3<<endl;
    cout.flush();
    cin>> x2;
    cout<<"? "<<2<<" "<<3<<endl;
    cout.flush();
    cin>> x3;
    
    a[1]= x1-x2+x3;
    a[1]/=2;
    a[0]=x1-a[1];
    a[2]=x3-a[1];
    // cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
    n-=3;
    ll index=4;
    while(n--){
    cout<<"? "<<1<<" "<<index<<endl;
    cout.flush();
    cin>> x1;
    a[index-1]=x1-a[0];
    index++;
    }
    cout<<"! ";
    for(auto x: a) cout<<x<<' ',cout.flush();
    cout.flush();
  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    //cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}