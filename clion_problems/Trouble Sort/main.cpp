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
        int n;
        cin>>n;
        pair<ll,int> a[n];
        for (int i = 0; i < n; ++i) {
            cin>>a[i].first;
        }
        bool one=true,zero=true;
        for (int i = 0; i < n; ++i) {
            cin>>a[i].second;
            if(a[i].second)
                zero=false;
            else one=false;
        }
        if(one||zero)
        {   bool exist=true;
            for (int i = 0; i < n-1; ++i) {
                if(a[i]>a[i+1]) {
                    exist = false;
                    break;
                }
            }
            if(exist)
                cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
            continue;
        }

        cout<<"Yes"<<endl;







    }


    return 0;
}
