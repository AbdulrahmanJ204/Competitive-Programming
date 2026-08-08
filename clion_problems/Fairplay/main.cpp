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
    int s=sqrt(n+1);
    if(s*s==(n+1)) {
        cout << s << endl;
        for (int i = 0; i < s; ++i) {
            cout << i + 1 << ' ';
        }
        cendl;
    }
    else cout<<-1<<endl;
    }
    return 0;
}