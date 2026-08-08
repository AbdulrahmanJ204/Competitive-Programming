#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
ll cnt1[26],n;
string s;
bool check(ll len,ll index)
{
    for (int j = 0; j < 26; ++j) {
        cnt1[j]=0;
    }
    for (int i = 0; i < len; ++i) {
        cnt1[s[i]-'a']++;
    }
    if(!cnt1[index])
        return false;
    ll l=0,r=len;
    while(r<n)
    {
        cnt1[s[l]-'a']--;
        cnt1[s[r]-'a']++;
        l++;r++;
        if(!cnt1[index])
            return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
     n=s.size();
    ll cnt[26];
    for (int i = 0; i < 26; ++i) {
        cnt[i]=0;
    }
    for (int j = 0; j <n ; ++j) {
        cnt[s[j]-'a']++;
    }
    ll ans=1e9;
    for (int i = 0; i < 26; ++i) {
        if(cnt[i]>0)
        {

            ll l=1,r=n;
            while(l<=r)
            {
                ll mid=(l+r)/2;
                if(check(mid,i))
                {   ans=min(mid,ans);
                    r=mid-1;
                }
                else l=mid+1;

            }
        }
    }

    cout<<ans<<endl;


    return 0;
}