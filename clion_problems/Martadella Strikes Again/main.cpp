#include <bits/stdc++.h>
using namespace std;
#define test  ll t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    test {
    ll r,R;
    cin>>R>>r;
    float pi=3.14;
    float s1=pi*R*R,s2=2*pi*r*r;
    if(s1>s2)
        cout<<1<<endl;
    else
        cout<<2<<endl;
    }
    return 0;
}