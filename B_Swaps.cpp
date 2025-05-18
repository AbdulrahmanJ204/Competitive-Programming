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
    string s1 , s2;
    cin>>s1>>s2;
    int n = s1.size();
    // sort(all(s1));
    // sort(all(s2));
    // cout<<s1<<endl<<s2<<endl;
    int cnt1[26];
    int cnt2[26];
    assign1(cnt1, 26 , 0);
    assign1(cnt2, 26 , 0);
    for (int i = 0; i < n; i++)
    {
      cnt1[s1[i]-'a']++;
      cnt2[s2[i]-'a']++;
    }
    
    multiset<int> st;
    for (int i = 0; i < 26; i++)
    {
      if(cnt1[i])
      st.insert(cnt1[i]);
    }

    for (int i = 0; i < 26; i++)
    if(cnt2[i]){
      if(!st.count(cnt2[i])){
        cno;
        return;
      }
      st.erase(st.find(cnt2[i]));
    }
    set<int> st1[26];
    for (int i = 0; i < n; i++)
    {
      st1[s1[i]-'a'].insert(s2[i]-'a');
    }
    
    for (int i = 0; i < 26; i++)
    {
      if(st1[i].size()>1) {
        cno;
        return;
      }
    }
    cyes;
    
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