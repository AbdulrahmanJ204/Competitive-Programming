#include <iostream>
using namespace std;
int main() {
int a[100],n;
cout<<"please enter array size : "<<endl;
cin>>n;
cout<<"please enter the elments :"<<endl;
    for (int i = 0; i <n ; ++i) {
      cout<<"a["<<i<<"] =";
      cin>>a[i];
    }
    cout<<"your array : "<<endl;
    for (int i = 0; i <n ; ++i) {
        cout<<"a["<<i<<"] = "<<a[i]<<endl;
    }
    cout<<"reverse:"<<endl;                       /*
 * for (i=n-1; i<=0;i--;)
 * cout<<a[i]<<" ";
 *
 *
 * */
    for (int i = 0; i < n; ++i) {
        cout<<"a["<<i<<"] = "<<a[n-i-1]<<endl;
    }
    int b[100];
    for (int i = 0; i <n ; ++i) {
        b[i]=a[n-i-1];

    }
    cout<<endl;
    cout<<"array b : "<<endl;
    for (int j = 0; j <n ; ++j) {
        cout<<"b["<<j<<"] = "<<b[j]<<endl;
    }
    cout<<"to add a number please choose the position : "<<endl;
    int x;
    cin>>x;
    n++;
    for (int k = n-1; k >= x; --k) {
        a[k+1]=a[k];
    }
    cout<<"please add the number "<<endl;
    cin>>a[x];
    for (int i = 0; i <n ; ++i) {
        cout<<"a["<<i<<"] = "<<a[i]<<endl;}
    cout<<"please choose the position to delete a number :"<<endl;
    cin>>x;

    for (int k = x; k <n-1 ; ++k) {
        a[k]=a[k+1];
    }
    n--;
    for (int i = 0; i <n ; ++i) {
        cout<<"a["<<i<<"] = "<<a[i]<<endl;}
    return 0;
}
