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
int n,m,k;
const int N=5010;
ll dp[N][N],p[N];
ll pre[N];
ll solve(int i,int c)
{
    if(c>=k) return 0;
    if(i>n) return -1e9;
    if(dp[i][c]!=-1) return dp[i][c];
    ll c1=pre[i+m-1]-pre[i-1]+solve(i+m,c+1);
    ll c2=solve(i+1,c);
    return dp[i][c]=max(c1,c2);




}
int main() {
    InTheNameOfAllah
    cin>>n>>m>>k;
    for (int i = 1; i <= n; ++i) {
        cin>>p[i];
        pre[i]=p[i];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dp[i][j]=-1;
        }
    }
    p[0]=0;
    pre[0]=0;
    for (int i = 0; i <= n; ++i) {
        pre[i]+=pre[i-1];
    }
    cout<<solve(1,0);

    return 0;
}