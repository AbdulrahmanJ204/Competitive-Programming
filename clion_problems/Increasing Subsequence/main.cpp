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

// easy version
int main() {
    InTheNameOfAllah
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    string ans="";
    int l=0,r=n-1;
    bool dl=false, dr=false;
    int top= 0;
    while(l<=r) {
        if(l==r) {
            if (a[r] >= top)
                ans += 'R';

            break;
        }
        if(a[l]>top&&a[r]>top) {
            if(a[l]<a[r]) {
                top=a[l];
                ans+="L";
                l++;
            }
            else if(a[r]<a[l]) {
                top=a[r];
                ans+="R";
                r--;
            }

        } else if (a[l] > top) {
            top=a[l];
            ans+="L";
            l++;
        }
        else if(a[r]> top) {
            top=a[r];
            ans+="R";
            r--;
        }

        else { break; }
    }
    cout<<ans.size()<<endl;
    cout<<ans<<endl;

    return 0;
}