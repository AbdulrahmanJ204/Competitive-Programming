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


int main() {
    InTheNameOfAllah
    test {
    int n;
    cin>>n;
    char a[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin>>a[i][j];
            }
        }
        int x=n/2;
        int ans=0;
        for (int i = 0; i < n / 2; ++i) {
            cendl;
            for (int j = i; j < n-1; ++j) {
                int mx=max({a[i][j]-'a' , a[i+j][n-1-i]-'a',a[n-1-j][ij]-'a',a[n-1-i][n-j-1]-'a'});
                cout<<char(mx+'a')<<' ';
                ans+=mx-(a[i][j]-'a');
                ans+=mx-(a[i+j][n-1-i]-'a');
                ans+=mx-(a[n-1-j][i+j]-'a');
                ans+=mx-(a[n-1-j][n-i-1]-'a');
            }
        }
        cout<<ans<<endl;
    }
    double pi=3.14159265359;
    return 0;
}