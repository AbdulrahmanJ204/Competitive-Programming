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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int cnt[26], c[26];
        for (int i = 0; i < 26; ++i) {
            cnt[i]=0;
            c[i]=0;
        }
        for (int i = 0; i < n; ++i) {
            if(isupper(s[i]))
                c[s[i]-'A']++;
            else cnt[s[i]-'a']++;
        }
        int ans=0;
        for (int i = 0; i < 26; ++i) {
            ans+=min(c[i],cnt[i]);
            int temp=abs(c[i]-cnt[i])/2;
            if(k>0) {
                ans += min(k, temp);
                k -= temp;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}