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
        string s1,s2;
        cin>>s1>>s2;

        bool im=false;
        ll ans=1;
        ll mo=1e9+7;
        for (int i = 0; i < n; ++i) {
            if(s1[i]=='1'&&s2[i]=='0') {
               im=true;
            break;
            }
            else if(s1[i]=='1'&&s2[i]=='1')
            { ans *= 2;
            ans%=mo; }

        }

        if(im)
            cout<<"IMPOSSIBLE"<<endl;
        else
            cout<<ans%(mo)<<endl;
    }
    return 0;
}