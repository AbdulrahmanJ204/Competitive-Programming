#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl

int a[15];

bool open (int i,int n,int sum )
{
    if(n==i)
    {
        if(sum%360==0)
            return 1;
        return 0;
    }
    return open(i+1,n,sum+a[i])||open(i+1,n,sum-a[i]);

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;

    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    bool exist=open(0,n,0);
    if(exist) cyes;
    else cno;

    return 0;
}