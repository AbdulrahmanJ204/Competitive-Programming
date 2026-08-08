
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define test ll t; cin>>t;while(t--)

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n,m,k=0,l=0,num=0;
    bool b=1;
    cin>>n>>m;
    ll a[n][m],q[9],wx,ey,wy,ex;

    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==0)
                num++;
        }

    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
            if(a[i][j]==0&&b==1)
            {
                k=i;
                l=j;
                b=0;
            }
    if(k==0)wx=k;else wx=k-1;
    if(l==0)ex=l;else ex=l-1;
    if(k==n-1)wy=k+1;else wy=k+2;
    if(l==m-1)ey=l+1;else ey=l+2;
    ll z=0;for(ll i=0;i<9;i++)q[i]=0;
    for(ll i=wx;i<wy;i++)
        for(ll j=ex;j<ey;j++)
        {
            ll ax,ay,qx,qy;
            if(i==0)ax=i;else ax=i-1;
            if(j==0)ay=j;else ay=j-1;
            if(i==n-1)qx=i+1;else qx=i+2;
            if(j==m-1)qy=j+1;else qy=j+2;
            if(a[i][j]==1)
                for(ll x=ax;x<qx;x++)
                    for(ll y=ay;y<qy;y++)
                        if(a[x][y]==0)
                            q[z]++;
            z++;}
    sort(q,q+9);
    if(q[8]==num)
        cout<<"WIN";
    else
        cout<<"LOSE";
}