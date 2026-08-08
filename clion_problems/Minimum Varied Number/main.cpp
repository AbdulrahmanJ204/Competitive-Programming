#include <bits/stdc++.h>
#include <string>
using namespace std;
string solve(int a)
{   int c=9;
    string ans=" ";
    for (int i = 9; i >0 ; --i) {
        if(a-c>=0)
        {
            ans+= to_string(c);
            a-=c;
        }c--;
    }
    int size = ans.size()-1;
  reverse(ans.begin(),ans.end());
    return ans;
}


int main() {
    int t;
    cin>>t;
    int n;
    while (t--)
    { cin>>n;
    cout<<solve(n)<<endl;
    }
    return 0;
}
