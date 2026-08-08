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
    int n,k;
    cin>>n>>k;
    ll a[n];
    ll sum=0;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            sum+=a[i];
        }
        ll pre[k+1],suf[k+1];
        for (int i = 0; i <= k; ++i) {
            pre[i]=0;suf[i]=0;
        }
        sort(a,a+n);
        int temp=k,count=1;
        for (int i = 0; i < n-1; ++++i) {
            if(temp==0)
                break;
            pre[count]=pre[count-1]+a[i]+a[i+1];
            temp--;
            count++;
        }
        temp=k;count=k;
        for (int i = n-1; i >=0 ; --i) {
            if(temp==0)
                break;
            suf[count-1]=suf[count]+a[i];
            count--;
            temp--;
        }
        ll mn=10e17;
       
        for (int i = 0; i <= k; ++i) {
            mn=min(pre[i]+suf[i],mn);
        }


        cout<<sum-mn<<endl;




    }
    return 0;
}