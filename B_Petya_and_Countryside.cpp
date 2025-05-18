#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
         int n;
         cin>>n;
         int a[n];
         for(int i=0; i<n; i++)
         {
             cin>>a[i];
         }
         int ans=0;
         for(int i=0; i<n; i++)
        {
            int len=1;
            int last=a[i];
                for(int j=i-1; j>=0; j--)
                {
                    if(last>=a[j]){
                        len++;
                        last=a[j]   ;
                    }
                    else break;
                }
                last=a[i]   ;
            for(int j=i+1; j<n;j++)
            {

                    if(last>=a[j]){
                        len++;
                        last=a[j]   ;
                    }
                else break;
            }
            ans=max(len,ans);
        }
        cout<<ans;
    }
    return 0;
}
