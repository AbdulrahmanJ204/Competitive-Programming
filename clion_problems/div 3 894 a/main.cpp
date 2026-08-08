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
     int n,m;
     cin>>n>>m;
     char a[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin>>a[i][j];
            }
        }

        bool v=false,i=false,k=false,x=false;
        bool s=false;
        int v1=-1,i1=-1,k1=-1,x1=-1;
        for (int l = 0; l <m; ++l) {
            for (int j = 0; j < n; ++j) {
                if(a[j][l]=='v')
                {
                    v=true;
                    v1=l;
                    s=true;
                    break;
                }
            }
            if(s) break;
        }
        s=false;
        for (int l = 0; l <m; ++l) {
            for (int j = 0; j < n; ++j) {

                if(a[j][l]=='a')
                {
                    x=true;
                    x1=l;
                }
            }if(s) break;
        }
        for (int l = 0; l <m; ++l) {
            for (int j = 0; j < n; ++j) {
                if(a[j][l]=='i'&&l>v1&&l<x1)
                {
                    i=true;
                    i1=l;
                    s=true;
                    break;
                }

            }if(s) break;
        }
        s=false;
        for (int l = m-1; l >=0; --l) {
            for (int j = n-1; j >=0; --j) {
                if(a[j][l]=='k'&&l>i1&&l<x1)
                {
                    k=true;
                    k1=l;
                    s=true;
                    break;
                }
            }
            if(s) break;
        }

        ll mn=min({k1,x1,i1,v1}); if(mn==-1 || k1<=i1)
        {
            cno;
            continue;
        }

        if(v&&i&&k&&x)
            cyes;
        else cno;
    }

    return 0;
}