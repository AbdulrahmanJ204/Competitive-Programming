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
        int n;
        cin>>n;
        int a[n];
        int zero=0,nonzero=0;
        bool special = true,allzero=true;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            if(a[i]==0)
                zero++;
            else {
                allzero=false;
                nonzero++;
                if(a[i]>1) {
                    special=false;
                }

            }
        }
        if (allzero)
            cout<<1<<endl;
        else if(nonzero>=zero-1)
            cout<<0<<endl;
        else
        {   if(special)
            cout<<2<<endl;
            else
                cout<<1<<endl;
        }


    }
    return 0;
}