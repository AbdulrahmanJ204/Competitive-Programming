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
string s;
int nneed[3],p[3],nhave[3];
ll m;
bool check(ll mid,ll money)
{
    for (int i = 0; i < 3; ++i) {
        if(nneed[i]==0) continue;
        ll c=nhave[i]/(nneed[i]);
        ll mod=nhave[i]%(nneed[i]);
        ll x=mid-c;

       if(c<mid)
        {
            if(p[i]*(x*nneed[i]-mod)>money)
                return false;
            else money-=(p[i]*(x*nneed[i]-mod));
        }

    }
//    cout<<mid<<endl;
//    if(n[0]<nb*mid)
//        if(n[0]+money/pb<nb*mid)
//            return false;
//        else money=money/(pb*(nb*mid-n[0]));
//    if(n[1]<ns*mid)
//        if(n[1]+money/ps<ns*mid)
//            return false;
//        else money=money/(ps*(ns*mid-n[1]));
//    if(n[2]<nc*mid)
//        if(n[2]+money/pc<nc*mid)
//            return false;

        return true;

}
int main() {
    InTheNameOfAllah
    cin>>s;
    for (int i = 0; i < 3; ++i) {
        cin>>nhave[i];
    }
    for (int i = 0; i < 3; ++i) {
        cin>>p[i];
    }
    cin>>m;
    for (int j = 0; j < 3; ++j) {
        nneed[j]=0;
    }
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]=='B')
            nneed[0]++;
        else if(s[i]=='S') nneed[1]++;
        else nneed[2]++;
    }
    ll l=1,r=2e12,ans=0;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        bool x=check(mid,m);
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