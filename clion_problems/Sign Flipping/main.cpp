#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   test{
       int n;
       cin>>n;
       ll a[n];
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }

        for (int i = 0; i < n ; ++i) {
            if(i%2==0)
                a[i]=-abs(a[i]);
            else a[i]=abs(a[i]);
        }


        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
        cendl;
   }


    return 0;
}
