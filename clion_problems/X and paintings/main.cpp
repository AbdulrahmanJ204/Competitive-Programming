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
        int I,c,r;
        cin>>r>>c>>I;
        char a[101][101];
        for (int j = 0; j < 101; ++j) {
            for (int k = 0; k < 101; ++k) {
                a[j][k]='.';
            }
        }
        while(I--)
        {
            int c1,r1,c2,r2;
            char x;
            cin>>r1>>c1>>r2>>c2;
            cin>>x;
            for (int i = r1; i <=r2; ++i)
                for (int j = c1; j <= c2; ++j)
                    a[i][j]=x;


        }
        for (int i = 1; i <= r ; ++i) {
            for (int j = 1; j <= c; ++j) {
                cout<<a[i][j];
            }cendl;
        }


    }
    return 0;
}