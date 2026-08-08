#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
   int n;
   cin>>n;
   int a[n];
   int back=0,chest=0,bic=0;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        if(i%3==0)
            chest+=a[i];
        else if(i%3==1)
            bic+=a[i];
        else
            back+=a[i];
    }
    int mx=max(back,max(bic,chest));
    if(mx==back)
        cout<<"back"<<'\n';
    else if(mx==chest)
        cout<<"chest"<<'\n';
    else
    cout<<"biceps"<<'\n';
    return 0;
}
