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
const int z=0;

void solve()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    
    if(n%2){
      
      ll preE[n+1][26], preO[n+1][26];
      assign2(preE,n+1,26,0);
      assign2(preO,n+1,26,0);
      for (int i = 0; i < n; i++)
      {
        if(i%2){
          preO[i+1][s[i]-'a']++;
        }
        else preE[i+1][s[i]-'a']++;
      }
      for (int i = 1; i < n+1; i++)
      {
        for (int j = 0; j < 26; j++)
        {
          preE[i][j]+=preE[i-1][j];
          preO[i][j]+=preO[i-1][j];
        }
        
      }
      ll ans=1e18;
      for (int i = 1; i < n+1; i++)
      {
        ll mx1=0,mx2=0;
        for (int j = 0; j < 26; j++)
        {
          mx1=max(mx1, preE[i-1][j] + preO[n][j]-preO[i][j]);
          mx2=max(mx2, preO[i-1][j] + preE[n][j]-preE[i][j]);

        }
          ans=min(ans,n-mx1-mx2);
        
      }
      cout<<ans;
    }
    else {
      ll cntE[26], cntO[26];
      assign1(cntE,26,0);
      assign1(cntO,26,0);
      ll mx1=0,mx2=0;
      for (int i = 0; i < n; i++)
      {
        if(i%2) 
        {

        cntO[s[i]-'a']++ ; mx1=max(mx1,cntO[s[i]-'a']);
        }
        else{

        cntE[s[i]-'a']++; mx2=max(mx2,cntE[s[i]-'a']);
        } 
      }
      cout<<n-mx1-mx2;
      
    }

  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}