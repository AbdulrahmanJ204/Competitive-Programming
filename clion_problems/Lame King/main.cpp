#include <bits\stdc++.h>
using namespace std;
int main() {
   int t,a,b;
   cin>>t;

    for (int i = 0; i <t ; ++i)
   {  int ans;
       cin>>a>>b;
       a=abs(a);
       b=abs(b);
       if(a==b)
       {
           cout<<a+b<<endl;
           continue;
       }
        ans=a+b;
        int skip;
        skip=abs(a-b)-1;
       cout<<ans+skip<<endl;

   }
    return 0;
}
