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
ll cnt[4];
ll n;
bool check(ll len)
{
    for (int j = 0; j < 4; ++j)
        cnt[j]=0;
    for (int i = 0; i < len; ++i)
        cnt[s[i]-'0']++;

    ll l=0,r=len;
    while(r<n)
    {
        if(cnt[1]&&cnt[2]&&cnt[3])
            return true;
        cnt[s[l]-'0']--;
        cnt[s[r]-'0']++;
        l++;r++;
    }
    if(cnt[1]&&cnt[2]&&cnt[3])
        return true;
    return false;
}
int main() {
    InTheNameOfAllah
    test {
    cin>>s;
    n=s.size();
    ll l=1,r=n;
    ll ans=1e9;
    while(l<=r)
    {
        ll len=(l+r)/2;
        bool x=check(len);
        if(x)
        {
            ans=min(ans,len);
            r=len-1;
        }
        else l=len+1;
    }
    if(ans==1e9) cout<<0<<endl;
    else cout<<ans<<endl;
    }
    return 0;
}