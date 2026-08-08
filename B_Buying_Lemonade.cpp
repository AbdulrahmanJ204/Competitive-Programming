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
#define oo  LLONG_MAX;
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n;
    cin>>n;
    int k;cin>>k;
    map<int,int> mp;
    int a[n];
    cin1(a,n);
    int empty= 0 , press= 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
      mp[a[i]]++;
      sum+=a[i];
    }
    if(k<=n){
      cout<<k;
      return; 
    }
    
    
    int notSure =0;
    int last = 0;
    int score= 0;
    for(auto &x : mp) {
    press+=notSure;
    int canTake=(n-empty);
    // cout<<"\nscore: "<<score<<endl;
    // cout<<"press = "<<press<<" empty = "<<empty<<endl;
    // cout<<"can 1: "<<canTake<<endl;
    if(score+canTake >= k){
      press+=k-score;
      break;
    }
    else press+=canTake , score+=canTake;

    canTake= (n-empty)*(max(x.first-last-1,0ll));
    // cout<<"can 2: "<<canTake<<endl;
    if(score+canTake >= k){
      press+=k-score;
      break;
    }
    else press+=canTake , score+=canTake;

    empty+=x.second;
    notSure = x.second;
    last = x.first;
    }
    cout<<press;
  return;
}

int32_t main() {
    InTheNameOfAllah
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}