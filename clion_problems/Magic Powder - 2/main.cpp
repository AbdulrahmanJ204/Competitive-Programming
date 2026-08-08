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
const int N=1e5+1;
ll a[N],b[N],c[N], n,k;
bool check(ll mid,ll k)
{  // cout<<mid<<' '<<k<<endl;
    for (int i = 0; i < n; ++i) {

        ll c=b[i]/a[i];
        ll mod=b[i]%a[i];
        ll x=mid-c;

        if(x>0)
            if(x*a[i]-mod>k)
                return false;
            else k-=(x*a[i]-mod);
    }
    return true;
}
int main() {
    InTheNameOfAllah

    cin>>n>>k;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin>>b[i];
    }
    ll l=0,r=2e9,ans=0;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        bool x=check(mid,k);
        if(x)
        {
            ans=max(ans,mid);
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}