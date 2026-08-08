#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;
        int size=r-l+1;
        ll a[size];
        ll a1[size];
        size=min(size,1000);
        for (int i = 0; i < size; ++i) {
            a[i]=l++;
            a1[i]=0;  }
        int maxa,mina;
        int index=0;
        for (int i = 0; i < size; ++i) {
            ll temp=a[i];
            maxa=0,mina=11;
            while(temp!=0)
            {
                int x=temp%10;
                maxa=max(x,maxa);
                mina=min(x,mina);
                temp/=10;
            }int dif=maxa-mina;
            a1[i]=dif;

        }
        maxa=0;
        for (int i = 0; i < size; ++i) {
            if(a1[i]>maxa)
            {
                index=i;
                maxa=a1[i];
            }
        }
        cout<<a[index]<<endl;
    }
    return 0;
}