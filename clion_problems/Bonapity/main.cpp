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
            if(s1.size()!=s2.size()) {
                cout<<"No"<<endl;
                continue;
            }
            bool exist=true;
                for (int i = 0; i < s1.size(); ++i) {
                    s1[i]=tolower(s1[i]);
                    s2[i]=tolower(s2[i]);
                    if(s1[i]=='p')
                        s1[i]='b';
                    else if(s1[i]=='i')
                        s1[i]='e';
                    if(s2[i]=='p')
                        s2[i]='b';
                    else if(s2[i]=='i')
                        s2[i]='e';
                    if(s1[i]!=s2[i])
                        exist=false;
                }

                if(exist)
                    cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
            }
            return 0;
        }