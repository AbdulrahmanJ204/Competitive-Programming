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
    int n,m,H,k;
    cin>>n>>m>>k>>H;
    int h[n];
        for (int i = 0; i < n; ++i) {
            cin>>h[i];
        }
        ll ans=0;
        for (int i = 0; i < n ; ++i) {
            for (int j = 1; j < m; ++j) {
                if(h[i]>H)
                {
                    if(j*k==h[i]-H) { ans++;
                        break;
                    }

                } else if(h[i]<H)
                {
                    if(j*k==H-h[i]) { ans++;
                        break;
                    }

                } else break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}