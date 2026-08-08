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

void solve()
{
    ll n;
    string s;
    cin >> s >> n;
    ll sum = 0;
    for (int i = 0; i < s.size(); i++)
        sum += s[i] - '0';

    if (sum <= n) {
        cout << 0;
        return;
    }
    reverse(all(s));
    s += "0";
    string ans = "";
    for (int i = 0; i < s.size(); i++)
        ans += "0";

    for (int i = 0; i < s.size() - 1; i++) {
      if (sum > n) {
          if (s[i] == '0') continue;

          ans[i] = (10 + '0' - s[i]) + '0';
          sum -= s[i] - '0';
          
          while (true) {
              i++;
              s[i]++;
              if (s[i] > '9')
                  s[i] = '0', sum -= 9;
              else
              {
                  sum++;
                  break;
              }
          }
          i--;
      } 
      else break;
    }

    reverse(all(ans));
    ll result=stoll(ans);
    cout<<result;
    

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