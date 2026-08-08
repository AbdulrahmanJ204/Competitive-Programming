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
        ll n;
        cin>>n;
        if(n==2)
            cout<<9<<endl;
        else if(n%4==2)
            cout<<9<<endl;
        else if(n%4==3)
            cout<<7<<endl;
        else if(n%4==0)
            cout<<1<<endl;
        else if(n%4==1)
            cout<<3<<endl;
    }
    return 0;
}