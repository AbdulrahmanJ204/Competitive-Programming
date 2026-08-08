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
    ll a[3];
        for (int i = 0; i < 3 ; ++i) {
            cin>>a[i];
        }
        sort(a,a+3);
            if(a[0]==a[2])
                cyes;
            else if(a[0]==a[1])
            {
                if(a[2]%a[1]!=0)
                    cno;
                else {
                    if(a[2]/a[1]>4) cno;
                    else cyes;
                }
            }
            else if(a[1]==a[2])
            {   if(a[0]==1)
                {
                    if(a[1]==2) cyes;
                    else cno;
                }
                else if(a[1]%a[0]!=0) cno;
                else {
                    if(a[1]/a[0]>2) cno;
                    else cyes;
                }
            }
            else {
                if(a[1]==2*a[0]&&a[2]==3*a[0])
                    cyes;
                else cno;
            }

    }
    return 0;
}