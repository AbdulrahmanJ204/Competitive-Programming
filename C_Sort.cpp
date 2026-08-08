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
    ll n,q;
    cin>>n>>q;
    string a,b;
    cin>>a>>b;
    a=' '+a;
    b=' '+b;
    int pre[n+1][26],preB[n+1][26];
    for (int i = 0; i < 26; i++)
    {
      pre[0][i]=0;
      preB[0][i]=0;
    }
    
    for (int i = 1; i < n+1; i++)
    {
      int fi= a[i]-'a', se=b[i]-'a';
      pre[i][fi]=pre[i-1][fi]+1;
      preB[i][se]=preB[i-1][se]+1;
      for (int j = 0; j < 26; j++)
      {
       if(j!=fi) pre[i][j]=pre[i-1][j];
       if(j!=se) preB[i][j]=preB[i-1][j];
      }
      
    }
    // cout2(pre,n+1,26);
    // cendl;
    // cout2(preB,n+1,26);

    while(q--){
      int l,r;
      cin>>l>>r;
      int ans=0;
      for (int i = 0; i < 26; i++)
      {
        int fi=pre[r][i]-pre[l-1][i];
        int se=preB[r][i]-preB[l-1][i];
        ans+=abs(fi-se);
      }
      cout<<ans/2<<endl;
    }

  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      
    }
    return 0;
}