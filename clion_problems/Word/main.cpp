//#include <iostream>
//#include <cstring>
//using namespace std;
//int main() {
//    string word;
//    cin>>word;
//    int size=word.size(),upper=0,lower=0;
//    for (int i = 0; i < size; ++i) {
//        if(isupper(word[i]))
//            upper++;
//        else
//            lower++;
//    }
//
//    if (upper>lower)
//        for (int j = 0; j < size; ++j) {
//           char x= toupper(word[j]);
//           cout<<x;
//        }
//    else for (int j = 0; j < size; ++j) {
//            putchar(tolower(word[j]));
//        }
//
//
//
//    return 0;
//}

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
    string s;
    cin>>s;
    int u=0,l=0;
    for (int i = 0; i < s.size(); ++i) {
        if(isupper(s[i]))
            u++;
        else l++;
    }
    if(u>l)
        for (int i = 0; i < s.size(); ++i) {
            s[i]=toupper(s[i]);
        }
    else
        for (int i = 0; i < s.size(); ++i) {
            s[i]=tolower(s[i]);
        }
    cout<<s<<endl;

    return 0;
}