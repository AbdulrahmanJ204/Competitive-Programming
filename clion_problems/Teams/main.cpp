#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
int main() {
    InTheNameOfAllah
    test {
    int n;cin>>n;
    ll a[n];
    ll gc=0;
    ll sum=0;
        for (int i = 0; i <n ; ++i) {
            cin>>a[i];
            gc=__gcd(gc,a[i]);
            sum+=a[i];
        }
        ll k,m;
        k=gc;
        m=sum/gc;
        cout<<k<<' '<<m<<endl;
    }
    return 0;
}