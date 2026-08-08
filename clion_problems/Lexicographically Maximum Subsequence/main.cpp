#include <bits/stdc++.h>
using namespace std;
#define ll long long
string ans="";
void solve(string s)
{
    char mx=s[s.size()-1];
    int last_position=0;
    for (int i = 0; i < s.size() ; ++i)
    if (s[i] >= mx)
    {
        mx = s[i];
        last_position = i;
    }
    for (int j = 0; j <= last_position; ++j) {
        if(s[j]==mx)
        ans+=mx;
    }
    if(last_position==s.size()-1)
        return;
    solve(s.substr(last_position+1));

}

int main() {
    string s;
    cin>>s;
    solve(s);
    cout<<ans<<endl;
    return 0;
}
