#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define endl '\n'
#define cendl cout<<endl
#define csecondes cout<<"secondES"
#define cno cout<<"NO"
#define cin(v) for(ll i=0;i<v.size();i++)cin>>v[i];
#define cin1(v,n) for(ll i=0;i<n;i++)cin>>v[i];
#define cin2(v,n,m) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) cin>>v[i][j];
#define trsecondAndCrsecond(v) for(auto x : v){cout<<x<<" ";}cout<<"\n";
#define cout1(v,n) for(ll i=0;i<n;i++)cout<<v[i]<<' '; cendl;
#define cout2(v,n,m) for(ll i=0;i<n;i++,cendl) for (int j = 0; j < m; j++) cout<<v[i][j]<<' ';
#define assign1(v,n,value) for(ll i=0;i<n;i++)v[i]=value;
#define assign2(v,n,m,value) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) v[i][j]=value;
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define oo  LLONG_MAX
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);


struct point2d {
  double x, y;
  point2d() {}
  point2d(double x, double y): x(x), y(y) {}
  point2d& operator+=(const point2d &t) {
      x += t.x;
      y += t.y;
      return *this;
  }
  point2d& operator-=(const point2d &t) {
      x -= t.x;
      y -= t.y;
      return *this;
  }
  point2d& operator*=(double t) {
      x *= t;
      y *= t;
      return *this;
  }
  point2d& operator/=(double t) {
      x /= t;
      y /= t;
      return *this;
  }
  point2d operator+(const point2d &t) const {
      return point2d(*this) += t;
  }
  point2d operator-(const point2d &t) const {
      return point2d(*this) -= t;
  }
  point2d operator*(double t) const {
      return point2d(*this) *= t;
  }
  point2d operator/(double t) const {
      return point2d(*this) /= t;
  }
};
point2d operator*(double a, point2d b) {
  return b * a;
}
double cross(point2d a, point2d b) {
  return a.x * b.y - a.y * b.x;
}
point2d intersect(point2d a1, point2d d1, point2d a2, point2d d2) {
  double num = cross(a2 - a1, d2) , denum= cross(d1, d2);
  if(!num && !denum) return point2d(1e18 , 1e18); // same
  else if(!denum) return point2d(-1e18 , -1e18); // parallel
  return a1 + num / denum * d1;
}

void solve()
{
  pair<double,double> p[4];
  for (int i = 0; i < 4; i++)
  cin>>p[i].first>>p[i].second;
  
  
  point2d p0(p[0].first , p[0].second),
  p1(p[1].first , p[1].second),
  p2(p[2].first , p[2].second),
  p3(p[3].first , p[3].second);
  auto res = intersect(p0 , p1 -p0 ,p2 , p3-p2);
  if(res.x == 1e18 && res.x == res.y) cout<<"LINE";
  else if(res.x == -1e18 && res.x == res.y) cout<<"NONE";
  else {

    cout<<"POINT ";
    cout<<fixed<<setprecision(2)<<res.x<<" "<<res.y;
  }
 


  cendl;
  return;
}

int32_t main() {
    // InTheNameOfAllah
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
    cin>>t;
    cout<<"INTERSECTING LINES OUTPUT"<<endl;
    while(t--){
      solve();
      // cendl;
    }
    cout<<"END OF OUTPUT";
    return 0;
}