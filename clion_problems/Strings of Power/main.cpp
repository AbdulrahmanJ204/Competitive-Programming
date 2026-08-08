#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    bool h1[s.size()+1];
    int h[s.size()+1],m[s.size()+1];
    for (int j = 0; j <= s.size(); ++j) {
        h[j]=0;
        m[j]=0;
        h1[j]=false;
    }
    for (int i = 1; i <= s.size() - 5; ++i) {
        if(s[i-1]=='h'&&s[i]=='e'&&s[i+1]=='a'&&s[i+2]=='v'&&s[i+3]=='y')
        {
            h[i]=h[i-1]+1;
            h1[i]=true;
        }
        else
            h[i]=h[i-1];

    }

    for (int i = s.size() - 1; i >=4 ; --i) {
        if(s[i-4]=='h'&&s[i-3]=='e'&&s[i-2]=='a'&&s[i-1]=='v'&&s[i]=='l')
        {
            m[i]=m[i+1]+1;
        } else
        {
            m[i]=m[i+1];
        }

    }
    for (int i = 0; i < s.size(); ++i) {
        cout<<h[i]<<' ';
    }
    cout<<endl;
    for (int i = 0; i < s.size(); ++i) {
        cout<<m[i]<<' ';
    }
    return 0;
}
