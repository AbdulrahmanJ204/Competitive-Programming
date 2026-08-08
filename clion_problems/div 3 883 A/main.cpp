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
    int n;
    cin>>n;
    int a[n],b[n];
    int ans=0;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];cin>>b[i];
            if(b[i]<a[i])
                ans++;
        }
    cout<<ans<<endl;
    }
    return 0;
}