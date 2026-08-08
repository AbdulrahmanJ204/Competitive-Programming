#include <iostream>
using namespace std;
#include <string>
#include <cstring>

int main() {
    char a1[100],a2[100];
    cin>>a1>>a2;
   if(strcasecmp(a1,a2)<0)
       cout<<"-1"<<endl;
   else if (strcasecmp(a1,a2)>0)
   cout<<"1"<<endl;
   else
       cout<<"0"<<endl;

   return 0;
}
