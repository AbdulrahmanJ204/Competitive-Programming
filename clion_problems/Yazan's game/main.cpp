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
    int n,m;
    cin>>n>>m;
    int a[n][m];


    bool exist=true;
    bool first=true;
    int fi=1e9,fj=1e9;
    int li=-1,lj=-1;
    int c=0;
    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < m ; ++j) {
            cin>>a[i][j];
            if(a[i][j]==0)
            {   c++;
                fi=min(i,fi);
                fj=min(j,fj);
                li=max(i,li);
                lj=max(j,lj);

            }

        }
    }

    if(lj-fj>3)
        exist=false;
    if(li-fi>3) exist=false;

    if(exist) {
        if(n>=3&&m>=3) {
            if (a[fi + 1][fj + 1] == 0)
                exist = false;
        } else {
            int c0=0,c1=0;
            if (n == m) {
                for (int i = 0; i <n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        if(a[i][j]==0)
                            c0++;
                        else c1++;
                    }
                }
                if(c1==0)
                    exist=false;
            }
            else if(n<m)
            {   exist=false;
                for (int i = 0; i < n; ++i) {
                    if(a[i][fj+1]==1) exist=true;
                }
            }
            else if(m<n)
            {
                exist=false;
                for (int i = 0; i < m; ++i) {
                    if(a[fi+1][i]==1) exist=true;
                }
            }
        }
    }
        if(exist)
            cout<<"WIN"<<endl;
        else cout<<"LOSE"<<endl;






    return 0;
}