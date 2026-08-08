#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int minx=100000,maxx=0;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        minx=min(a[i],minx);
        maxx=max(a[i],maxx);
    }
    cout<<maxx-minx<<endl;
    /*
     * second solution
     *

    int mx=abs(a[0]-a[1]);
    for (int j = 0; j < n; ++j) {
        for (int i = j; i < n; ++i) {
        mx = max(mx,abs(a[j]-a[i]));

        }
        }                                       o(n^2)
    cout<<mx<<endl;
    */
//second solution


    return 0;
}
