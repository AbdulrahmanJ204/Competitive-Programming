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
        string s1, s2;
        cin >> s1 >> s2;
        bool exist = false;
        int dot = 0, dot1 = 0, dot2 = 0, hash = 0;
        bool alldots1 = true, alldots2 = true;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == '#' && s2[i] == '#') {
                exist = true;
                hash++;
                alldots1 = false;
                alldots2 = false;
            } else if (s1[i] == '.' && s2[i] == '.')
                dot++;
            else if (s1[i] == '.' && s2[i] == '#') {
                dot1++;
                alldots2 = false;
            } else if (s1[i] == '#' && s2[i] == '.') {
                dot2++;
                alldots1 = false;
            }
        }

        sort(s1.begin(), s1.end());
        if (exist || alldots2 || alldots1) {
            cyes;
            cout << s1 << endl;
            for (int i = 0; i < dot2; ++i) {
                cout << '.';
            }
            for (int j = 0; j < hash; ++j) {
                cout << '#';
            }
            for (int l = 0; l < dot1; ++l) {
                cout << '#';
            }
            for (int k = 0; k < dot; ++k) {
                cout << '.';
            }
        } else
            cno;
        return 0;
    }