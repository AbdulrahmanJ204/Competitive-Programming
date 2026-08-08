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
    int s,m;
    cin>>m>>s;
    int x=ceil(float(s)/9);
    string ans="";
    ll mod=s%9;
    for (int i = 0; i < m; ++i) {
        ans+='0';
    }
    if(x>m) {
        cout << -1 << ' ' << -1 << endl;
        return 0;
    }
    if(s==0) {
        if (m == 1) cout << 0 << ' ' << 0 << endl;
        else cout << -1 << ' ' << -1 << endl;
        return 0;
    }
    if(s==1||m==1)
    {
        ans[0]=s+'0';
        cout<<ans<<' '<<ans<<endl;
        return 0;
    }
      //  cout<<ans;
        for (int i = 0; i <x; ++i) {
            ans[i]='9';
        }

        if(mod>0)
            ans[x-1]=mod+'0';
        string bans=ans;

        if(ans[ans.size()-1]=='0') {
            ans[ans.size() - 1]++;
            ans[x-1]--;
        }
            reverse(ans.begin(),ans.end());
        cout<<ans<<' '<<bans;

    return 0;
}