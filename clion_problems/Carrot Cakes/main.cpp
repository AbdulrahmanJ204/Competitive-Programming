#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    double n,t,k,d;
    cin>>n>>t>>k>>d;

    int timef=0;
    bool need=false;
    while(n>0)
    {
        n-=k;
        timef+=t;
        if(timef>d && n>0)
            need=true;
    }

    if(need)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
