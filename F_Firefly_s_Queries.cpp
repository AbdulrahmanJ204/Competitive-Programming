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
const int z=2e5+10;
ll pre[z];
ll n,q;
ll sumToRight(ll shiftNumber , ll index){
  ll lastToRight=shiftNumber;
  if(lastToRight==0) lastToRight= n;

  if(shiftNumber){
  index+=shiftNumber;
  index= index%n ? index%n:n;
  }

  if(index<=lastToRight) return pre[lastToRight]-pre[index-1];
  
  return pre[lastToRight] + pre[n]-pre[index-1];
  
}
ll sumToLeft(ll shiftNumber, ll index){
  ll lastToRight=shiftNumber;
  if(lastToRight==0) lastToRight= n;
  
  if(shiftNumber){
  index+=shiftNumber;
  index= index%n ? index%n:n;
  }

  if(index<=lastToRight) return pre[n]-pre[lastToRight]+pre[index];
  
  return pre[index]-pre[lastToRight];

}

void solve()
{
    cin>>n>>q;
   
    pre[0]=0;
    for (ll i = 1,x; i < n+1; i++)
    {
      cin>>x;
      pre[i]=x+pre[i-1];
    }  
      
   
    while(q--){
      ll l ,r ;
      cin>>l>>r;
      ll shiftL = (l+n-1)/n -1 , shiftR=(r+n-1)/n -1 ;
      ll indexL = l%n ? l%n : n , indexR=  r%n ? r%n : n;
      ll ans=0;
      if(shiftR-shiftL>=1){
        ans=(shiftR-shiftL-1)*pre[n];
        ans+=sumToRight(shiftL, indexL);
        ans+=sumToLeft(shiftR , indexR);
      } 
      else  ans=sumToLeft(shiftR , indexR) + sumToRight(shiftL,indexL) - pre[n];
      cout<<ans<<endl;
    }
    

  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      // cendl;
    }
    return 0;
}