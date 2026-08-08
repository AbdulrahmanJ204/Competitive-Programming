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
    char a[8][8];
    string ans="";
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                cin>>a[i][j];
                if(a[i][j]!='.')
                    ans+=a[i][j];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}