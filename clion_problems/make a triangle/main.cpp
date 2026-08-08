#include <iostream>
using namespace std;
int main() {
int a,b,c;
cin>>a>>b>>c;
int m=a;
if (m<b)
    m=b;
if (m<c)
    m=c;
int sum=a+b+c-m;
if (sum <=m)
    cout<<m-sum+1<<endl;
else
    cout<<"0"<<endl;
   return 0;
}
