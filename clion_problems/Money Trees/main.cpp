/*
            .------.____
         .-'       \ ___)
      .-'         \\\
   .-'        ___  \\)
.-'          /  (\  |)
         __  \  ( | |
        /  \  \__'| |
       /    \____).-'
     .'       /   |
    /     .  /    |
  .'     / \/     |
 /      /   \     |
       /    /    _|_
       \   /    /\ /\
        \ /    /__v__\
         '    |       |
              |     .#|
              |#.  .##|
              |#######|
              |#######|
                      (
                        )     (
                 ___...(-------)-....___
             .-""       )    (          ""-.
       .-'``'|-._             )         _.-|
      /  .--.|   `""---...........---""`   |
     /  /    |                             |
     |  |    |                             |
      \  \   |                             |
       `\ `\ |                             |
         `\ `|                             |
         _/ /\                             /
        (__/  \                           /
     _..---""` \                         /`""---.._
  .-'           \                       /          '-.
 :               `-.__             __.-'              :
 :                  ) ""---...---"" (                 :
  '._               `"--...___...--"`              _.'
    \""--..__                              __..--""/
     '._     """----.....______.....----"""     _.'
        `""--..,,_____            _____,,..--""`
                      `"""----"""`
 * */
#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
int n,k;
const int N=2e5+10;
int a[N];
int h[N];
int pre[N];
int p[N];
bool check(ll mid)
{   ll temp=0;
    bool ex=true;
    ll l=1,r=mid;
   // cout<<mid<<endl;

    while(r<=n)
    {  // if(mid==3)
        // cout<<pre[r]<<'g'<<pre[l-1]<<' '<<p[r-1]<<' '<<p[l]<<endl;
        if(pre[r]-pre[l-1]<=k&&p[r-1]-p[l-1]==0) {

            return true;
        }        l++;
        r++;
    }
return false;
}
int main() {
    InTheNameOfAllah
    test {
    cin>>n>>k;
        for (int i = 0; i <=n; ++i) {
            pre[i]=0;
            p[i]=0;
        }
        a[0]=0;
        h[0]=0;
        for (int i = 1; i <= n; ++i) {
            cin>>a[i];
            pre[i]=a[i];
        }
        pre[n+1]=2e9;
        for (int j = 1; j <= n; ++j) {
            cin>>h[j];
        }
        for (int i = 1; i <=n; ++i) {
            pre[i]+=pre[i-1];
        }
        p[0]=0;

        for (int i = 1; i <n; ++i) {
            if(h[i]%h[i+1]!=0)
                p[i]=p[i-1]+1;
            else p[i]=p[i-1];
        }

        p[n]=0;
        ll l=1,r=n,ans=0;
//        for (int i = 0; i < n + 1; ++i) {
//            cout<<pre[i]<<' ';
//        }cendl;
//        for (int i = 0; i < n + 1; ++i) {
//            cout<<p[i]<<' ';
//        }cendl;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        bool x=check(mid);
        if(x)
        {
            ans=max(ans,mid);
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans<<endl;
    }

    return 0;
}