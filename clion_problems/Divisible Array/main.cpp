#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    test {
    int n;
    cin>>n;
    if(n==1) {
        cout << 1 << endl;
        continue;
    }
        for (int i = 1; i <= n ; ++i) {
            cout<<i*2<<' ';
        }
    cendl;

    }
    return 0;
}