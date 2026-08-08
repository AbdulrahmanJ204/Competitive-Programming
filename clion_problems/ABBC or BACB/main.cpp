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
int n;
const int N=2e5+10;
int dp[N];
ll solve(int i,int last)
{
    if(i>=n) return 0;
    ll c1=0,c2,c3=0;
    if(s[i]=='B'&&last==1) {
        c1 = 1 + solve(i + 1, 3);
    }else if(s[i]=='A'&&last==2) {
        c1 = 1 + solve(i + 1, 2);

    }  c2=solve(i+1,s[i]-'A'+1);
    return max(c1,c2);
}
ll solve2(int i,int last)
{
    if(i<0) return 0;
    ll c1=0,c2,c3=0;
    if(s[i]=='B'&&last==1) {
        c1 = 1 + solve(i - 1, 3);
    }else if(s[i]=='A'&&last==2) {
        c1 = 1 + solve(i - 1, 2);

    }  c2=solve(i-1,s[i]-'A'+1);
    return max(c1,c2);
}
int main() {
    InTheNameOfAllah
    test {
    cin>>s;
        n=s.size();
        ll ans=max(solve(0,0),solve(n-1,0));
    cout<<ans<<endl;

    }
    return 0;
}