#include <bits/stdc++.h>
using namespace std;
#define test  ll t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

        ll n;
        cin>>n;
        ll a[n];
        ll even=0,odd=0,sum=0,min_odd=10e10;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            sum+=a[i];
            if(n%2==1)
            {   odd++;
                min_odd=min(min_odd,a[i]);
            }
        }
        if(sum%2==0)
            cout<<sum<<endl;
        else
        {
            sum-=min_odd;
            if(sum%2==0&&sum>0)
                cout<<sum<<endl;
            else
                cout<<-1;
        }


    return 0;
}