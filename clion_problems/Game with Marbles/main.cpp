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
        cin >> n;
        ll A = 0, B = 0;
        vector<int> a(n), b(n);
//        int a2[n], b2[n];
        pair<int, int> a1[n], b1[n];
        pair<int, int> a2[n], b2[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a1[i].first = a[i];
            a1[i].second = i;
//            A += a1[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            b1[i].first = b[i];
            b1[i].second = i;
//            B += b1[i].first;
        }
        vector<int >p(n);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
                  [&](int i, int j) {
                      return a[i] + b[i] > a[j] + b[j];
                  });
        for (int i = 0; i < n; ++i) {
            int ind=p[i];
            if(i%2==0) A+=a[ind]-1;
            else B+=b[ind]-1;
        }

        /*sort(a1, a1 + n);
        sort(b1, b1 + n);


        int x = n;
        bool alice = true;
        int mai = n - 1, bai = n - 1;

        while (x--) {
            if (alice) {
                while (a[a1[mai].second] <= 0) mai--;
                while (b[b1[bai].second] <= 0) bai--;
                int bindex;
                if (a1[mai] >= b1[bai]) {
                    bindex = a1[mai].second;
                    B -= b[bindex];
                    mai--;
                    a[bindex] = -1;
                    b[bindex] = -1;
                    A--;
                } else {
                    B -= b1[bai].first;
                    bindex = b1[bai].second;
                    bai--;
                    a[bindex] = -1;
                    b[bindex] = -1;
                    A--;
                }
                alice = false;
            } else {
                while (a[a1[mai].second] <= 0) mai--;
                while (b[b1[bai].second] <= 0) bai--;
                int bindex;
                if (b1[bai] >= a1[mai]) {
                    bindex = b1[bai].second;
                    A -= a[bindex];
                    bai--;
                    a[bindex] = -1;
                    b[bindex] = -1;
                    B--;
                } else {
                    A -= a1[mai].first;
                    bindex = a1[mai].second;
                    mai--;
                    a[bindex] = -1;
                    b[bindex] = -1;
                    B--;
                }
                alice = true;
            }
        }*/
        cout << A - B << endl;
    }
    return 0;
}