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
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    string s="";
   // cout<<s<<endl;
    for (int i = 0; i < n; ++i) {
    //    cout<<s<<endl;
        if(s1[i]!=s2[i])
            s+=to_string(1);
        else
            s+=to_string(0);
    }
    ll ans=0;
    for (int j = 0; j < n; ++j) {
        if(s[j]=='1')
        {
            ans++;
            while(s[j]=='1')
                j++;
        j--;
        }

    }
    cout<<ans<<endl;
    return 0;
}