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
    string s;
    cin>>s;
        string a, b;

        bool first=true;
        for (int i = 0; i < n; ++i) {
            if(s[i]=='0')
            {
                a+=s[i];
                b+=s[i];
            }
            else if(s[i]=='1')
            {
                if(first)
                {
                    first=false;
                    a+=s[i];
                    b+='0';
                }
                else {
                    a+='0';
                    b+=s[i];
                }
            }
            else if(s[i]=='2')
            {   if(first) {
                    a += '1';
                    b += '1';
                }
                else {
                    a += '0';
                    b += '2';
                }
            }


        }

        cout<<a<<endl<<b<<endl;

    }
    return 0;
}