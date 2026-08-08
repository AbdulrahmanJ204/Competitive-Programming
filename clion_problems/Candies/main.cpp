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
ll n;
bool check(ll mid) {
    ll x=0;
    ll temp=n;
    while(temp>0)
    {
        x+=min(temp,mid);
        temp-=mid;
        temp-=temp/10;
    }
    return x>=n/2;
}

int main() {
    InTheNameOfAllah
        cin>>n;
      /*  if(n==1)
        {
            cout<<1<<endl;
            return 0;
        }*/
//    39259424579862572
//    39259424579862572 \
//    39259424579862572
        ll l=1,r=n,ans=INT64_MAX;
        while (l <= r) {
            ll mid=(l+r)/2;
            if(check(mid))
            {
                ans=min(mid,ans);   
                r=mid-1;
            }
            else l=mid+1;
        }
        cout<<ans<<endl;

    return 0;
}