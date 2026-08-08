#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    string s;
    cin>>s;
stack<char> s1;
    int ans=0;
    int size=s.size();

    for (int i = 0; i < size; ++i) {
        if(s[i]=='(')
            s1.push(s[i]);
         else {
            if (s1.empty())
                continue;
                ans += 2;
                s1.pop();

        }
   }

    cout<<ans<<endl;












    //    int c1=0,ans=0;
//    for (int i = 0; i < s.size(); ++i) {
//        if(s[i]=='(')
//            c1++;
//        else
//        {
//            if(c1>0) {
//                ans += 2;
//                        c1--;
//            }
//        }
//    }
//    cout<<ans<<endl;

    return 0;
}
