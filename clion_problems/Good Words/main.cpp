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
    string s1,s2;
    cin>>s1>>s2;
    int cnt=0;
    int cnt2=0;
    stack<char> s;
        for (int i = 0; i < s1.size(); ++i) {
            if(s1[i]==s2[cnt])
                cnt++;
        }
        if(cnt==s2.size()) {
            cout << "good" << endl;
            continue;
        }
        bool exist=false;
        int m=0;
        bool b[4];
        for (int i = 0; i < 4; ++i) {
            b[i]=0;
        }

        bool exist2=false;
        for (int i = 0; i < 4; ++i) {
            exist=false;
            for (int j = m+1; j < s1.size(); ++j) {
                if(s1[j]==s2[i]) {
                    m = j;
                    //b[i]=true;
                    exist = true;
                    break;
                }

            }
            if(!exist)
                if(b)
                    b =false;
                else {
                    exist2 = true;
                    break;
                }
        }

        if(!exist2)
            cout<<"almost good"<<endl;
        else cout<<"none"<<endl;
    }
    return 0;
}