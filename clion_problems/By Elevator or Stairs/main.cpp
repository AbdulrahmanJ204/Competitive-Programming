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
const int N=2e5+20;
ll dp[N][2];
int a[N],b[N];
int n,c;
ll solve(int i,int e)
{
    if(i<0) return 0;
    if(dp[i][e]!=-1) return dp[i][e];
    ll c1=1e9,c2=1e9;
    c1=a[i]+solve(i-1,0);
    if(e)
    c2=b[i]+solve(i-1,e);
    else c2=c+b[i]+solve(i-1,1);
    return dp[i][e]=min(c1,c2);
}
int main() {
    InTheNameOfAllah
    cin>>n>>c;
    for (int i = 0; i < N; ++i) {
        dp[i][0]=-1;
        dp[i][1]=-1;
    }
    a[n-1]=0;
    b[n-1]=0;
    for (int i = 0; i < n-1; ++i) {
        cin>>a[i];
    }
    for (int i = 0; i < n-1; ++i) {
        cin>>b[i];
    }
   dp[n-1][0]= a[n-1]+ solve(n-1,0);
    dp[n-1][1]=c+b[n-1]+solve(n-1,1);
        cout<<0<<' ';
    for (int i = 0; i < n-1; ++i) {
            cout << dp[i][0] << ' ';
        }

    return 0;
}