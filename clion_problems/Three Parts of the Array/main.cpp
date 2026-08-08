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
    int n;
    cin>>n;
    ll a[n];
    ll sum1=0,sum3=0,sum;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    int l=0,r=n-1   ;

    bool exist=false;
    while(l<=r)
    {
        if(sum1==sum3) {
            exist = true;
            sum=sum1;
        }
        if(sum1>sum3)
        {
            sum3+=a[r];
            r--;
        }
        else
        {
            sum1+=a[l];
            l++;
        }
        if(sum1==sum3) {
            sum=sum1;
        }
    }
//    if(sum1==sum3)
//        sum=sum1;
    if(exist)
        cout<<sum<<endl;
    else
        cout<<0<<endl;

    return 0;
}