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
        vector<int> v;
        int i=2;
        int temp=n;

        for (ll i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                v.push_back(i);
                if (i != n / i)
                    v.push_back(n / i);
            }
        }
//        if(i*i==temp) v.push_back(temp);
        sort(v.begin(),v.end());
//        for(auto x: v) cout<<x<<' ';cendl;
        vector<ll> ans;
        int c=0;
        for (int i = 1; i < v.size(); ++i) {
            if(temp%v[i]==0) {
                ans.push_back(v[i]);
                temp/=v[i];
                c++;
            }
            if(c==2) break;
        }
        if(ans.size()<2) cout<<"No"<<endl;
        else {
        if(temp==1||temp==ans[0]|| temp==ans[1])
            cno;
        else {
            cyes;
            cout<<ans[0]<<' '<<ans[1]<<' '<<temp<<endl;
        }
        }
        //for(auto x: ans) cout<<x<<' ';cendl;

        /*if(v.size()<3) cout<<"NO"<<endl;
        else {
            ll a=1;
            int size=v.size();
            if(v[0]==v[size-1]) {
                if (size < 6) {
                    cout << "NO" << endl;
                    continue;
                }
            }

            cout<<"YES"<<endl;
            for (int i = 3; i < v.size(); ++i) {
                a*=v[i];
            }
            v[1]*=v[2];
            cout<<v[0]<<' '<<v[1]<<' '<<a<<endl;
        }*/
    }
    return 0;
}