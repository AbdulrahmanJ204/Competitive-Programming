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
        bool exist=false;
        string s;
        cin>>s;
        int l=0,ans=1;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i]=='L') {
                l++;
                ans = max(l, ans);
                exist=true;
            }
            else if(s[i]=='R')
            {   ans=max(l,ans);
                l=0;
            }
        }
        if(exist)
        cout<<ans+1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}