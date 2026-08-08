#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int r[n+1],c[m+1];
        for (int k = 0; k <=n ; ++k) {
            r[k]=1;
        }
        for (int i = 0; i <= m; ++i) {
            c[i]=1;
        }
        int a[n+1][m+1];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin>>a[i][j];
                if(a[i][j]==1)
                {
                    r[i]=0;
                    c[j]=0;
                }
            }
        }
        int sumr=0,sumc=0;
        for (int i = 1; i <= n; ++i) {
            sumr+=r[i];
        }
        for (int i = 1; i <= m; ++i) {
            sumc+=c[i];
        }
      //  cout<<sumc<<'\t'<<sumr<<endl;
        int ans=min(sumc,sumr);
        if(ans%2==0)
            cout<<"Vivek"<<endl;
            else
                cout<<"Ashish"<<endl;


    }


    return 0;
}
