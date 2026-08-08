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
    string s;
    cin>>s;
    int cnt[26];
        for (int i = 0; i < 26; ++i) {
            cnt[i]=0;
        }
        for (int i = 0; i < s.size(); ++i) {
            cnt[s[i]-'a']++;
        }
        int count=0;
        for (int j = 0; j < 26; ++j) {
            if(cnt[j]>1)
                count++;

        }
        if(count>=2)
            cyes;
        else
            cno;

    }
    return 0;
}