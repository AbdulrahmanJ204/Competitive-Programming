#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"Yes"<<endl
#define cno cout<<"No"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
int main() {
    InTheNameOfAllah
    test {
        int a, b;
        cin >> a >> b;
        int s1 = a ^b;
        bool exist = false;
        for (int j = 1; j <= b; ++j) {
            int c = (a - 1) ^j;
            if (c > s1) {
                exist = true;
                break;
            }
        }
        if (exist) cyes;
        else
            cno;
    }
    return 0;
}