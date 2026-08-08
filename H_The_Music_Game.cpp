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
    
    multiset<int> st;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin>>x;
      st.insert(x);
    }
    for (int i = 0; i < n-1; i++)
    {
    // tryAndCry(st);
      string s;
      cin>>s;
      int value= islower(s.back()) ? s.back()-'a'+1 : s.back()-'A'+1;
      auto end= st.end() , start = st.begin();
      end--;
      int dif1= abs(*start - value) , dif2  = abs(*end - value);
      // cout<<"V = "<<value<<"  s = "<< *start <<" e = "<<*end<<endl;
      // cout<<"d1 = "<<dif1 <<"  d2 = "<<dif2<<endl;
      if(dif1<dif2) st.erase(end);
      else if(dif1==dif2) st.erase(start);
      else st.erase(start);
    }
    
    cout<<*st.begin();

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