#include <iostream>
using namespace std;
int main() {
   int a[100],x,i;
   cout<<"please enter 10 positive numbers :"<<endl;
    for (i = 0; i <10 ; ) {
        cin>>x;
        if (x>=0)
        {a[i]=x;
        i++;} else
    cout<<"no negative numbers please :)"<<endl;
    }
    for ( i = 0; i <10 ; ++i) {
        cout<<a[i]<<"\t";
    }
    return 0;
}
