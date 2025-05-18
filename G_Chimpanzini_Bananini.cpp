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
#define oo  LLONG_MAX
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll q;
    cin>>q;
    deque<int> a;
    int ans = 0 ,ansr =0 , sum = 0;
    bool r = false;
    while(q--){
      int s;
      cin>>s;
      if(s==1){
        int sz = a.size();
        if(r) {
          
          int e = a.front();
          ansr -= e * a.size();
          ansr += sum;
          a.pop_front();
          a.push_back(e);
          ans -=sum;
          ans+= e*a.size();
          
        }
        else{
          int e= a.back();
          ans -= e * a.size();
          ans+= sum;
          a.pop_back();
          
          a.push_front(e);
          ansr-=sum;
          ansr+= e*a.size();
        }
      }
      else if(s==2){
        r=!r;
      }
      else{
        int x;
        cin>>x;
        if(r)
        {
          a.push_front(x);
        }else
        {
          a.push_back(x);
        }
        sum+=x;
        ans+= !r ? a.size() * x : sum;
        ansr+= r ? a.size() * x : sum;
      }
      
      cout<<(r ? ansr : ans)<<endl;
    }

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