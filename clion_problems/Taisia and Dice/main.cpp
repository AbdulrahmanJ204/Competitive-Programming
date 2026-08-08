#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,r,s;
        cin>>n>>s>>r;
        int a[n], max=s-r,sum=max*n-max;
        for (int i = 0; i < n; ++i) {
            a[i]=max;
        }
        int counter=0;
      while(sum>r&&counter<n)
      {
        if(a[counter]==1)
        {
            counter++;
            continue;
        }
        else
        {
            a[counter]--;
            sum--;
        }
      }


        for (int i = 0; i < n; ++i) {
            cout<<a[i]<<' ';
        }
        cout<<endl;

    }


    return 0;
}