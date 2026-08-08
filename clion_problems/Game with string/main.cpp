#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    stack<char> st;
    ll ans=0;
    for (int i = 0; i < s.size(); ++i) {
       if(!st.empty()) {
           if (s[i] == st.top()) {
               ans++;
               st.pop();
           }
           else
               st.push(s[i]);
       }
       else
           st.push(s[i]);
    }
    if(ans%2==0)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;

    return 0;
}
