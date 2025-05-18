#include <bits/stdc++.h>
using namespace std;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define cin(v)                        \
    for (ll i = 0; i < v.size(); i++) \
        cin >> v[i];
#define unq(v) v.resize(distance(v.begin(), unique(all(v))));
#define tryAndCry(v)      \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << "\n";
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main() {
    InTheNameOfAllah 
    int n, m;
    ll pascal[102][102];
    pascal[0][0]=pascal[1][0]=pascal[1][1]=1;
    for (int i = 2; i < 101; i++)
    {
        pascal[i][0]=1;
        pascal[i][i]=1;
        for (int j = 1; j < i; j++)
        {
            pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
        }
        
    }
    
    while (cin >> n >> m && n != 0)
    {
        cout<<n<<" things taken "<<m<<" at a time is "<<pascal[n][m]<<" exactly."<<endl;
    }
    // vector<ll> upper, lower;
    // while (cin >> n >> m && n != 0) {
    //     upper.clear();
    //     lower.clear();
    //     int mx= max(n-m , m), mn= min(n-m , m);
    //     for (ll i = mx + 1 ; i <= n; i++)
    //         upper.push_back(i);
    //     for (ll i = 2; i <= mn; i++) 
    //             lower.push_back(i);
    //     for(auto &x : upper)
    //     for(auto &y : lower)
    //     {
    //       ll g= __gcd(x,y);
    //       x/=g;
    //       y/=g;
    //     }    
        
    //     ll ans=1;
    //     for(auto x: upper) ans*=x;
    //     for(auto x: lower) ans/=x;
        
    //     cout<<n<<" things taken "<<m<<" at a time is "<<ans<<" exactly."<<endl;
    // }
    return 0;
}