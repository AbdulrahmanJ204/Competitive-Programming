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
        ll a[n];
        ll even=0,odd=0;
        bool alleven=true;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            if(a[i]%2==0) {
                even++;
            }
            else { odd++;alleven=false; }
        }
        if(alleven)
            cout<<-1<<endl;
        else cout<<even<<endl;
    }
    return 0;
}