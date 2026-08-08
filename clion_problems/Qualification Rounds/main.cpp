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

int n, k;
const int N=1e5+10,K=4;
int a[N][K];
bool solve(int i,ll s1,ll s2,ll s3,ll s4, ll x)
{
    if(i==n)
        return x > 1 && s1 <= x / 2 && s2 <= x / 2 && s3 <= x / 2 && s4 <= x / 2;
    if(s1>x||s2>x||s3>x||s4>x) return false;

    bool c1,c2;
   // cout<<s1<<' '<<s2<<' '<<s3<<' '<<s4<<endl;
    c1=solve(i+1,s1+max(0,a[i][0]), s2+max(a[i][1],0), s3+max(a[i][2],0),s4+max(a[i][3],0),x+1);
    c2=solve(i+1,s1,s2,s3,s4,x);

    return c1||c2;
}
int main() {
    InTheNameOfAllah

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin>>a[i][j];

        }
        for (int l = k; l < K; ++l) {
            a[i][l]=0;


        }
    }
    
    bool x= solve(0,0,0,0,0,0);
    if(x) cyes;
    else cno;
    return 0;
}