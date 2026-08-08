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
ll n,l,r,x;
ll a[15];
ll solve(int i,ll sum,ll c,ll mx,ll mn)
{
    if(i==n)
    {
        if(sum>=l&&sum<=r&&mx-mn>=x&&c>=2)
            return 1;
        else return 0;
    }
    ll c1,c2;
    c1=solve(i+1,sum+a[i],c+1,max(a[i],mx),min(a[i],mn));
    c2=solve(i+1,sum,c,mx,mn);
    return c1+c2;

}
int main() {
    InTheNameOfAllah

    cin>>n>>l>>r>>x;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    cout<<solve(0,0,0,-1,1e10);

    return 0;
}