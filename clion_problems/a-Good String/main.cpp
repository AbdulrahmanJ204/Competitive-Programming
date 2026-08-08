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
string s;
ll solve(int index,ll len,char c)
{   ll x1=0,x2=0;

    if(index>=n||len==0) return 0;
    if(len==1)
        if(s[index]==c) return 0;
        else return 1;
    for (int i = index; i < index+len/ 2; ++i) {
        if(s[i]!=c)
            x1++;
    }
    for (int j =index+ len/2; j < index+len; ++j) {
        if(s[j]!=c)
            x2++;
    }
    ll c1= x2+solve(index,len/2,c+1);
    ll c2= x1+solve(index+len/2,len/2,c+1);
    return min(c1,c2);
}
int main() {
    InTheNameOfAllah
    test {
    cin>>n;
    cin>>s;
    ll ans=solve(0,n,'a');
    cout<<ans<<endl;
    }
    return 0;
}