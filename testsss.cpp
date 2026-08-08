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
vector<ll> divisor(ll x) {
    vector<ll> v;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            v.push_back(i);
            if (i != x / i)
                v.push_back(x / i);
        }
    }
    return v;
}

struct Point{
  double x, y;
};
void rotate(Point &p, double angle) {
    double x_new = p.x * cos(angle) - p.y * sin(angle);
    double y_new = p.x * sin(angle) + p.y * cos(angle);
    p.x = x_new;
    p.y = y_new;
}

double calculateAngleWith_X_Axis(Point p1, Point p2) {
    return  atan2(p2.y - p1.y, p2.x - p1.x);
}

void solve()
{
    ll n;
    cin>>n;
    Point p1 , p2 , p3 , p4;
    p1.x =  p3.x = 1;
    p2 .y = p4.y = 1;
    p2.x = 2 , p4.x = 0;
    p1.y = 0 , p3 .y = 2;
    
    Point p5 = {5 ,5 };
    std::cout << "p1: (" << p1.x << ", " << p1.y << ")\n";
    std::cout << "p2: (" << p2.x << ", " << p2.y << ")\n";
    std::cout << "p3: (" << p3.x << ", " << p3.y << ")\n";
    std::cout << "p4: (" << p4.x << ", " << p4.y << ")\n";
    std::cout << "p5: (" << p5.x << ", " << p5.y << ")\n";
      
    double angle = calculateAngleWith_X_Axis(p1, p2);
    cout<<"angle = "<<angle<<endl;
    rotate(p1 , -angle);
    rotate(p2 , -angle);
    rotate(p3 , -angle);
    rotate(p4 , -angle);
    rotate(p5 , -angle);
    
    std::cout << "p1: (" << p1.x << ", " << p1.y << ")\n";
    std::cout << "p2: (" << p2.x << ", " << p2.y << ")\n";
    std::cout << "p3: (" << p3.x << ", " << p3.y << ")\n";
    std::cout << "p4: (" << p4.x << ", " << p4.y << ")\n";
    std::cout << "p5: (" << p5.x << ", " << p5.y << ")\n";
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