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
    int n;
    cin>>n;
    int a[n];
    bool b[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        b[i]=false;
    }
    int c=0,ans=0;
    bool x=true;
    while (x) {
        if(ans%2==0)
        {
            for (int i = 0; i < n; ++i) {
                if(a[i]<=c&&!b[i]) {
                    b[i] = true;
                    c++;
                }
            }
        }
        else
        {
            for (int i = n-1; i >=0; --i) {
                if(a[i]<=c&&!b[i]) {
                    b[i] = true;
                    c++;
                }
            }
        }

        x=false;
        for (int i = 0; i < n; ++i) {
            if(!b[i]) x=true;
        }
        if(x) ans++;
    }
    cout<<ans<<endl;
    return 0;
}