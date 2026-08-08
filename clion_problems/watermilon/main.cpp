#include <iostream>
using namespace std;
int main() {
    int w;
  cin>>w;
  bool can=false;
  int i=2;
    for (int j=w-i;i<=(w/2);i=i+2)
    {if ((i%2==0)&(j%2==0))
    can =true;
    }
    if (can==true)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}
