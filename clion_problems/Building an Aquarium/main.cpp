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
const int N=2e5+10;
int a[N];
int n,x;
bool check(ll h)
{
    ll temp=0;
    for (int i = 0; i < n; ++i) {
        if(h-a[i]>0)
            temp+=(h-a[i]);

    }
    return temp<=x;
}
int main() {
    InTheNameOfAllah
    test {
    cin>>n>>x;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        ll l=1,r=2e9+1,ans=0;
        while(l<=r)
        {
            ll h=(l+r)/2;
            bool k=check(h);
            if(k)
            {
                ans=max(h,ans);
                l=h+1;
            }
            else r=h-1;
        }
    cout<<ans<<endl;
    }
    return 0;
}