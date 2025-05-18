#include <bits/stdc++.h>
using namespace std;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

void solve() {
    string s, t;
    cin >> s >> t;
    int lowerS[26],upperS[26],lowerT[26],upperT[26];
    for (int i = 0; i < 26; i++)
    {
      lowerS[i]=0;
      lowerT[i]=0;
      upperS[i]=0;
      upperT[i]=0;
    }
    for (int i = 0; i < s.size(); i++)
    {
      if(islower(s[i])) lowerS[s[i]-'a']++;
      else upperS[s[i]-'A']++;
    }


    for (int i = 0; i < t.size(); i++)
    {
      if(islower(t[i])) lowerT[t[i]-'a']++;
      else upperT[t[i]-'A']++;
    }
    int yay=0,whoops=0;
    for (int i = 0; i < 26; i++)
    {
int mn=min(lowerS[i],lowerT[i]);
      lowerS[i]-=mn;
      lowerT[i]-=mn;
      yay+=mn;
      mn=min(upperS[i],upperT[i]);
      upperS[i]-=mn;
      upperT[i]-=mn;
      yay+=mn;
    }

    for (int i = 0; i < 26; i++)
    {
      whoops+=min(upperS[i],lowerT[i]);
      whoops+=min(lowerS[i],upperT[i]);
    }
    
  cout<<yay<<' '<<whoops;

    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    // cin>>t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}