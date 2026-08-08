#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    string s;
    cin>>s;
    bool done=false;
    int left=0,right =0;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]=='(' || s[i]=='[' || s[i]=='<' || s[i]== '{')
            left++;
        else
            right++;
        if(left==0 && right>0)
        {   done =true;
            break;
        }

    }
    if(left!=right)
    {
        cout<<"Impossible"<<endl;
    }
    else if(!done)
    {   int ans=0;
    bool done1=false;
        stack<char> a;
        for (int i = 0; i < s.size(); ++i) {

            if(s[i]=='(' || s[i]=='[' || s[i]=='<' || s[i]== '{')
            a.push(s[i]);
            else if(a.empty())
            {
                if(s[i]==')' || s[i]=='}' || s[i]=='>' || s[i]== ']')
                {   done1=true;
                    cout << "Impossible" << endl;
                    break;

                }
            }
           else if(!a.empty()) {
                if (a.top() == '(' && s[i] == ')')
                    a.pop();
                else if (a.top() == '{' && s[i] == '}')
                    a.pop();
                else if (a.top() == '[' && s[i] == ']')
                    a.pop();
                else if (a.top() == '<' && s[i] == '>')
                    a.pop();
                else { ans++;
                a.pop();}
            }
        }
        if(!done1)
        cout<<ans<<endl;

    }
    return 0;
}
