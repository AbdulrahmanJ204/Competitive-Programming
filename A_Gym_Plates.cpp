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
ll n;
const int MXN=101,Q=3;
ll a[MXN];
ll dp[MXN][Q][Q][Q][Q][Q][Q][Q][Q][Q][Q];



ll fun(int i =0, int zero=0 , int one=0 , int two=0 , int three =0, int four=0 , int five=0 ,int six=0 , int seven=0 , int eight=0 , int nine=0){
  if(i==n) return 0;
  if(~dp[i][zero][one][two][three][four][five][six][seven][eight][nine]) return dp[i][zero][one][two][three][four][five][six][seven][eight][nine];
  
  ll c1=0,c2=0;
  bool can=true;

  vector<int> v={zero, one ,two , three , four , five , six , seven, eight, nine };
 ll temp=a[i];
  while(temp>0)
  {
    ll num= temp%10;
    temp/=10;
    v[num]++;
    if(v[num]>=3) can=false;
  }
  
  if(can)
  c1= a[i]+fun(i+1,v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7],v[8],v[9]);
  c2= fun(i+1,zero, one ,two , three , four , five , six , seven, eight, nine );
  
  return dp[i][zero][one][two][three][four][five][six][seven][eight][nine]= max(c1,c2);
}
void solve()
{
    cin>>n;
    cin1(a,n);
    for (int i = 0; i < n; i++)
    {
      for (int zero = 0; zero < Q; zero++)
      for (int one = 0; one < Q; one++)
      for (int two = 0; two < Q; two++)
      for (int three = 0; three < Q; three++)
      for (int four = 0; four < Q; four++)
      for (int five = 0; five < Q; five++)
      for (int six = 0; six < Q; six++)
      for (int seven = 0; seven < Q; seven++)
      for (int eight = 0; eight < Q; eight++)
      for (int nine = 0; nine < Q; nine++)
      dp[i][zero][one][two][three][four][five][six][seven][eight][nine]=-1;
      
      
    }
    
    // assign2(dp,n,Q,-1);
    cout<<fun(); 

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