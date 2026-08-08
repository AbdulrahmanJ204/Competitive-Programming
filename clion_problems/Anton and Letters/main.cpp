    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define endl '\n'

    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        string s;
        getline(cin,s);
        set<char> s1;

        for (int i = 0; i < s.size(); ++i) {
            if(s[i]<='z'&&s[i]>='A')
                s1.insert(s[i]);
        }
        cout<<s1.size()<<endl;


        return 0;
    }
