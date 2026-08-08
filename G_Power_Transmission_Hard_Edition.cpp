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

void fun(ll &a, ll &b) {

    if (a * b < 0) {
        a = -abs(a);
        b = abs(b);
    } else if (a * b > 0) {
        a = abs(a);
        b = abs(b);
    } else {
      if(b) b=1e6;
      if(a) a=1e6;
    }
    ll gc = __gcd(abs(a), abs(b));
    if (gc)
        a /= gc, b /= gc;
}


void solve()
{
    ll n;
    cin >> n;
    pair<ll, ll> a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    if (n == 2) {
        cout << 0;
        return;
    }
    if (n == 3) {
        ll dx1 = a[0].first - a[1].first, dx2 = a[1].first - a[2].first,
           dy1 = a[0].second - a[1].second, dy2 = a[1].second - a[2].second;

        if(!dx1&&!dx2) cout<<0;
        else if(!dx2||!dx1)cout<<3;
        else if(dx1*dy2==dx2*dy1) cout<<0;
        else cout<<3;
        

        return;
    }
    map<pair<pair<ll, ll>, pair<ll, ll>>, ll> lines;
    for (ll i = 0; i < n; i++) {
        ll x1 = a[i].first, y1 = a[i].second;
        for (ll j = i + 1; j < n; j++) {
            ll x2 = a[j].first, y2 = a[j].second;
            ll dx = x2 - x1, dy = y2 - y1;
            ll y= y1;
            ll x= x1; 
            ll cNumerator = y * dx - x * dy, cdeNumerator = dx;
            
            
            fun(dx, dy);
            fun(cNumerator, cdeNumerator);

            if (dx && dy) // not horizontal and not vertical y= 
                lines[make_pair(make_pair(dx, dy), make_pair(cNumerator, cdeNumerator))]++;
            else if(!dx) // vertical , x=x1
                lines[make_pair(make_pair(dx, 1e6), make_pair(x1, x1))]++;
            else if(!dy) // horizontal y=y1 
                lines[make_pair(make_pair(1e6, dy), make_pair(y1, y1))]++;
        }
    }

    ll total = 0,ans = 0;
    map<pair<ll, ll>, ll> mp;
    for (pair<pair<pair<ll, ll>, pair<ll, ll>>, ll> x : lines) {
        mp[x.first.first]++;
        total++;
    }

    for (auto &x : mp) {
            ans += (total - x.second) * x.second;
            // printf("mp[%d / %d] = %d \n",x.first.second,x.first.first,x.second);
    }

    cout<<ans/2;
  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    //cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}