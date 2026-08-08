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
    int n,q;
    cin>>n>>q;
    int a[n+1];
    for (int i = 1; i < n+1; ++i) {
        cin>>a[i];
    }
    while(q--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        if(l==r) {
            if (a[l] == k)
                cyes;
            else
                cno;
            continue;
        }
        bool exist=false;
        int mid;
        while(l<r)
        {
            mid=(l+r)/2;
            if(a[mid]==k) {
                exist = true;
                break;
            }
            else if(a[mid]>k)
                r=mid-1;
            else if(a[mid]<k)
                l=mid+1;
            if(l==r) {
                if (a[l] == k)
                    exist=true;
            }
        }
        if(exist)
            cyes;
        else
            cno;
    }
    return 0;
}