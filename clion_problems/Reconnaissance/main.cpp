#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
int main() {
    int n,d,dif,counter=0;
    cin>>n>>d;
    int a[1000];
    for (int k = 0; k < n; ++k) {
        cin>>a[k];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
        if(i==j)
            continue;
            dif=a[i]-a[j];
            dif=abs(dif);

            cout<<i<<"  "<<j<<"     "<<dif<<endl;
            if((dif>d) || (dif==0))
            {   cout<<"cant"<<endl;
                continue;}
            cout<<"can"<<endl;
            ++counter;
        }
    }

    cout<<counter<<endl;
    return 0;
}
    //there is problem in their output bro :)