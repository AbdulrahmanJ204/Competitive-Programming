#include <bits/stdc++.h>
using namespace std;

#define ll long long
// #define int ll
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
map<char,int> cnt; 
string s;

bool check (int l){
  set<char> c;
  int qm = 0;
  
  for(auto x : cnt){
  if(x.first == '?') qm = x.second;
  else if(x.second) c.insert(x.first);
  
  }
  if(qm+c.size()== 26){
    c.clear();  
    char x = 'A';
    while(x<='Z') {if (!cnt[x]) c.insert(x);x++;}
    while(c.size()){
      if(s[l]=='?') s[l] = *c.begin() ,  c.erase(*c.begin());
      l++ ;
    }
    
    return true;
  }
  return false;
}
void solve()
{
    cin>>s;
    int n= s.size();
    if(n<26){
      cout<<-1;
      return;
    }
    int l = 0 , r = 0 ;
    
    while(r<26) cnt[s[r]] ++ , r++;
    bool f= check(l);
    while(r<n){
      if(f) break;  
      cnt[s[l]]--;
      l++;
      cnt[s[r]]++;
      f|=check(l);
    r++;  
    }
    
  if(f){
    for(auto& x : s) if(x=='?') x = 'A';
    cout<<s;
  }
    else cout<<-1;
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