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
string a , b;
int n ;
int ans =0 , origin= 0;
multiset<int> st;
void fun(int i , int pos , int neg){
 if(i==n) 
 { st.insert(pos-neg);
    return;
}
if(b[i]=='+')      fun(i+1 , pos+1 , neg);
else if(b[i]=='-') fun(i+1 , pos , neg+1);
else {
  fun(i+1 , pos+1 , neg);
  fun(i+1 , pos , neg+1);
}

}
void solve()
{
    cin>>a>>b;
    n = a.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      if(a[i]=='+') origin++;
      else origin --;
      if(b[i]=='?') cnt++;
    }
    
    fun(0 , 0 ,0);
    int match = 0;
    for(int x : st) if (x == origin) match++;
    cout<<fixed<<setprecision(10) <<(double)match / (1ll<<cnt) ;
    // tryAndCry(st);
    // cout<<st.size()<<" "<<(1ll<<cnt)<<" \no : "<<origin;
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