#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string a,b;
    cin>>a>>b;
    int ans=0;
    int ca4=0,cb4=0;
    for (int i = 0; i < a.size(); ++i) {
        if(a[i]=='4')
            ca4++;
        if(b[i]=='4')
            cb4++;
    }

    int noc;
    if(ca4!=cb4) {
        ans += abs(ca4 - cb4);
        noc=abs(ca4 - cb4);
        for (int i = 0; i < a.size(); ++i)
            if(noc>0&&a[i]!=b[i])
            {   a[i]=b[i];
                noc--;
            }
            else if(noc==0)
                break;
    }


    int tempdif=0;
    for (int i = 0; i < a.size(); ++i) {
        if(ans==a.size())
            break;
        if(a[i]!=b[i])
            tempdif++;
    }
    ans+=(tempdif/2);
    cout<<ans;

    return 0;
}