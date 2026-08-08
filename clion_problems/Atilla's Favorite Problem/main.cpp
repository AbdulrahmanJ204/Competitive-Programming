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
        string s;
        cin>>s;
        char x='a';
        for (int i = 0; i < n; ++i) {
            x=max(x,s[i]);
        }
        cout<<x-'a'+1<<endl;
    }
    return 0;
}