#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        s[i] = tolower(s[i]);
    }
    int n = s.size();
    for (int i = 0; i < s.size();) {
        if (s[i] == 'a' || s[i] == 'o' || s[i] == 'y' || s[i] == 'e' || s[i] == 'u' || s[i] == 'i')
            s.erase(i, 1);
        else i++;
    }
    for (int i = 0; i < s.size(); ++ ++i) {
        if (s[i] == 'a' || s[i] == 'o' || s[i] == 'y' || s[i] == 'e' || s[i] == 'u' || s[i] == 'i');
        else
            s.insert(i, ".");
    }
    cout << s << endl;
    return 0;
}