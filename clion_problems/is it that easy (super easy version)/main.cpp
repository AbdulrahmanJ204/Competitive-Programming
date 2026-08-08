
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
    cin >> n;
    int a[n];

    map<int, int> m;
    int c = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > 0)
            m[a[i]]++;
        else c++;
    }

    sort(a,a+n);
    int ans=0,cnt=0;
    while(cnt<n)
    {
        ans++;
        int h=0;
        for(int i=0;i<n;i++)
            if(a[i]>=h)
            {
                h++;
                a[i]=-1;
                cnt++;
            }
    }
    cout<<ans;
 /*   int ans = 0;
    int addtion=0;
    for (int i = 1; i <= 100; i++) {
        if (m[i] > c+addtion) {
            m[i] -= c + addtion;
            int temp = m[i] / (i + 1) + m[i] % (i + 1);
            addtion = max(temp, addtion);
        }

    }


    cout << c+addtion << endl;
*/
    return 0;
}