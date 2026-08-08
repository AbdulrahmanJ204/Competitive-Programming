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
    int N=2*n;
    int a[N];
    int o=0;
    int x=2;
    int index=-1;
    vector<int> odd,even;
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
            if(a[i]%2==0)
                even.push_back(i+1);
            else {
                odd.push_back(i + 1);
            o++;}
        }
        if(o%2==1)
        {
            odd.pop_back();
            even.pop_back();
        }
        else if(o%2==0)
        {
            if(odd.size()!=0)
            {
                odd.pop_back();
                odd.pop_back();
            }
            else
            {
                even.pop_back();
                even.pop_back();
            }
        }


        int i=0;
        for(auto x:even)
        {
            cout<<x<<' ';
            i++;
            if(i==2)
            {
                i=0;
                cendl;
            }
        }
        for(auto x:odd)
        {
            cout<<x<<' ';
            i++;
            if(i==2)
            {
                i=0;
                cendl;
            }
        }
    }
    return 0;
}