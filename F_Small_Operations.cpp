#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define gcd(a ,b) __gcd(a,b)
#define lcm(a,b) a*b/gcd(a,b)
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
const int N = 1e6+20;
vector<int> factors[N];
void sieve() {
    for (int i = 2; i < N; ++i) {
        if (factors[i].empty()) {
            for (int j = i; j < N; j += i) {   
              factors[j].push_back(i);
            }
        }
    }
}

void getPrimes(map<int,int> &mp ,int n){
  
  int x =n;
  for(auto& z : factors[n]){
    while(x%z==0){
      mp[z]++;
      x/=z;
    }
  }
  if(x>1) mp[x]++;
  
}
void solve()
{
    int x ,y, k;
    cin>>x>>y>>k;
    map<int,int> a , c;
    getPrimes(a,x);  
    getPrimes(c,y);  
    
    set<int> st;
    for(auto &z : a) st.insert(z.first); 
    for(auto &z : c) st.insert(z.first);
    
   
    vector<int> v , v2;
    for(auto&fact : st){
      if(a[fact]==c[fact]) continue;
      if(a[fact] != c[fact] && fact>k){
        cout<<-1;
        return;
      }
      int dif = a[fact] - c[fact];
      if(dif>0)
        while(dif--) v.push_back(fact);
      else
        while(dif++) v2.push_back(fact);
      
    } 
    // tryAndCry(v);
    // tryAndCry(v2);
    priority_queue<int> pq;
    multiset<int> st2;
    for (int z : v)
        if (z * z > k)
            pq.push(z);
        else
            st2.insert(z);
    int ans = pq.size();
    while (pq.size()) {
        int cur = pq.top();
        pq.pop();
        vector<int> toDelete;
        for (auto it = st2.rbegin(); it != st2.rend(); it++) {
            if (*it * cur <= k) {
                cur *= *it;
                toDelete.push_back(*it);
            }
        }
        for (int num : toDelete)
            st2.erase(st2.find(num));
    }
    int cur = 1;
    for (auto it = st2.rbegin(); it != st2.rend(); it++) {
        int num = *it;
        if (cur * num <= k)
            cur *= num;
        else {
            cur = num;
            ans++;
        }
    }
    if (cur > 1)
        ans++;
    st2.clear();
    for (int &z : v2)
        if (z * z > k)
            pq.push(z);
        else
            st2.insert(z);
    ans += pq.size();
    while (pq.size()) {
        int cur = pq.top();
        pq.pop();
        vector<int> toDelete;
        for (auto it = st2.rbegin(); it != st2.rend(); it++) {
            if (*it * cur <= k) {
                cur *= *it;
                toDelete.push_back(*it);
            }
        }
        for (int num : toDelete)
            st2.erase(st2.find(num));
    }
    cur = 1;
    for (auto it = st2.rbegin(); it != st2.rend(); it++) {
        int num = *it;
        if (cur * num <= k)
            cur *= num;
        else {
            cur = num;
            ans++;
        }
    }
    if (cur > 1)
        ans++;
    cout << ans;
    return;
}

int32_t main() {
    InTheNameOfAllah
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    sieve();
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}