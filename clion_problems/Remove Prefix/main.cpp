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
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        map<int,int> m;
        int ans=0;
        for (int i = n-1; i >=0; --i) {
            m[a[i]]++;
            if(m[a[i]]>1) {
                ans=i+1;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
     int t;
     cin>>t;
     while(t--)
     {
        int n;
        cin>>n;
        int a[n+10];
        int maxa=0;
         for (int i = 1; i <= n; ++i) {
             cin>>a[i];
             maxa=max(maxa,a[i]);
         }
         bool deleted=false;
         bool cnt[maxa+10];
         for (int i = 0; i <= maxa; ++i) {
             cnt[i]=false;
         }
         for (int j = n; j > 0; --j) {
             if(cnt[a[j]]==true) {
                 cout << j << endl;
              deleted=true;
                 break;
             }
             cnt[a[j]]++;

         }

            if(!deleted)
                cout<<0<<endl;




     }
        return 0;
}
*/
