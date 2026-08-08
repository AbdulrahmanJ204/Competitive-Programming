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
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;

        if (x == s) {
            cout << 0 << endl;
            continue;
        }
        int ans=0;
        if(n<m)
        {
            while (x.size()<s.size())
            {
                x+=x;
                ans++;
            }
        }
        bool exist=false;
        int an=ans;
        for (int i = 0; i < 10-an; ++i) {
            int size=x.length(); //cout<<x<<' '<<size<<endl;
            string temp="";

            for (int j = 0; j < m ; ++j) {
                temp+=x[j];
            }
            ll l=0,r=m;
            if(temp==s) {
                exist = true;
            }
            while(r<size)
            {
                if(temp==s) {
                    exist = true;
                    break;
                }
                temp=temp.substr(1,temp.size()-1);

                temp+=x[r];
                //cout<<temp<<endl;
                r++;
                l++;
            }
            if(temp==s) {
                exist = true;
            }
            if(exist)
                break;
            x=x+x;
            ans++;
        }
        if(exist)
        cout << ans << endl;
        else cout<<-1<<endl;
    }

    return 0;
}