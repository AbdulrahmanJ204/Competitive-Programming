#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s;
    cin>>s;
    int ans=0;
    int n=s.size();
    int pre[n];
    int suf[n];
    int big[n];
    bool allbig=true,allsmall=true;
    int b=0,c=0;

    for (int i = 0; i < n; ++i) {
        if(isupper(s[i]))
        {
            big[i] = 1;
            b++;
            allsmall = false;
        }
        else
            {
            big[i] = 0;
            allbig = false;
            c++;
            }
        pre[i]=0;
        suf[i]=0;
    }

        if(allbig||allsmall)
        {
            cout<<0;
            return 0;
        }

        pre[0]=0;
        suf[n-1]=big[n-1];

        for (int j = 1; j < n; ++j) {
            if(big[j-1]==0)
            pre[j]=pre[j-1]+1;
            else
                pre[j]=pre[j-1];
        }

        for (int i = n-2; i >=0 ; --i) {
            suf[i]=suf[i+1]+big[i];
        }

        ans=min(c,b);
        
    for (int i = 0; i <n; ++i) {
        ans=min(ans,(suf[i]+pre[i]));
        }

    cout<<ans;
    return 0;
}
