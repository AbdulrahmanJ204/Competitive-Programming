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
int const N=509;
int a[N],n,x;
int dp[N][N][N];
ll solve(int i,int x,int last)
{
    if(i>=n) {
//        for (int j = 0; j < n - 1; ++j)
//            if (a[j] > a[j + 1]) return +1e9;
        return 0;
    }
   if(dp[i][x][last]!=-1) return dp[i][x][last];
    ll c1=1e9,c2=1e9;
    int ai=a[i];
    if(a[i]>x&&x>=last)
    {
        c1=1+solve(i+1,ai,x);
    }
    if(a[i]>=last)
    c2=solve(i+1,x,a[i]);
    return dp[i][x][last]= min(c1,c2);
}

int main() {
    InTheNameOfAllah
    test {
    cin>>n>>x;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <=500; ++j) {
                for (int k = 0; k <=500; ++k) {
                    dp[i][j][k]=-1;
                }

            }
        }
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        ll ans;
        ans=solve(0,x,0);
        if(ans>=1e9) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
