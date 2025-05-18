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
const int z=33000;
vector<int> divs[z];
void divisors(ll x) {
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            divs[x].push_back(i);
            if (i != x / i)
                divs[x].push_back(x / i);
        }
    }
}

bool check(int a, int b){
  set<int> s;
  int cnt=0;
  for(auto x: divs[a]) s.insert(x),cnt++;
  for(auto x: divs[b]) s.insert(x),cnt++;
  return s.size()==cnt-1;
}

int main() {
    InTheNameOfAllah
    divs[1]={1};
    for (int i = 2; i < z; i++)
      divisors(i);
      
    while(true){
      int n;
      cin>>n;
      if(!n) break;
      int a[n];
      cin1(a,n);
      int pairs=0;
      for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
          if(check(a[i],a[j]))pairs++;
        
        if(!pairs){
          cout<<"No estimate for this data set."<<endl;
          continue;
        }
        
        double num=n*(n-1)/2;
        double pi= 6*num / pairs;
        pi=sqrt(pi);
        cout<<fixed<<setprecision(6)<<pi<<endl;
    }
    return 0;
}