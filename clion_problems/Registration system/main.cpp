#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
   int n;
   cin>>n;
   map<string,int> name;
   while (n--)
   {
       string x;
       cin>>x;

       if(name.count(x))
       {
           cout<<x<<name[x]++<<endl;
       } else
       {    name[x]++;
           cout<<"OK"<<endl;
       }

   }
    return 0;
}
