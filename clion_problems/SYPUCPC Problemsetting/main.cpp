#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"Yes"<<endl
#define cno cout<<"No"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
int main() {
    InTheNameOfAllah
    test {
    int mn=1e9;
        int n;
        cin>>n;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            mn=min(a[i],mn);

        }
        cout<<mn<<endl;
    }
    return 0;
}