#include<iostream>
using namespace std;
void print1(int n)
{   if (n==0)
    return;

   print1(n/10);
    cout<<n%10<<endl;
}
int main()
{print1(12345);
   return 0;
}
