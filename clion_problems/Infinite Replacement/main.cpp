#include <bits/stdc++.h>
using namespace std;            not solved;;;;;;;;;;;
#define ll long long
ll fact(int a)
{
        ll r=1;
    for (int i = 1; i <= a; ++i) {
        r*=i;
        return r;
    }
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {

        string s,t;
        cin>>s>>t;
        if(t=="a")
        {
            cout<<1<<endl;
            continue;
        }
        int tsize=t.size();
                bool notdone=true;
        for (int i = 0; i <tsize ; ++i) {
            if(t[i]=='a') {
                cout << -1 << endl;
             notdone=false;
                break;
            }
        }
        int ssize=s.size();
        int ans=1;

       ll facts=fact(ssize), factt=fact(ssize-tsize);
       facts /=factt;
       ans+=facts;

        if(notdone)
            cout<<ans<<endl;
    }

    return 0;
}
