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
        cin >> n;
        int a[n];
        int cnt[26];
        map<int, int> m;
        string s;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            m[a[i]]++;
        }
        cin >> s;
        vector<int> v;
        for (auto x: m) v.push_back(x.second);
        string s2="";
        for (int j = 0; j < n; ++j) {
            s2+='.';
        }
        for (int i = 0; i < n; ++i) {
            char x= s[i];
            int d= a[i];
            if(s2[i]=='.') {
                for (int j = i; j < n; ++j) {
                    if (a[j] == d && s2[j]=='.')
                        s2[j] = x;
                }
            }
        }
//        cout<<s2<<endl;
        if(s2==s) cyes;
        else cno;
    }
    return 0;
}