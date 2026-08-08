#include <iostream>
using namespace std;
int main() {
        int a[100];
        int n;
        cout<<"please enter array size:"<<endl;
        cin>> n;
        cout<<"please enter the elements: "<<endl;
    for (int i = 0; i <n ; ++i)
    {cin>>a[i];}
    cout<<"your array :"<<endl;
    for (int i = 0; i < n; ++i) {
        cout<<a[i]<<endl;

    }
    int max=0;
    for (int i = 0; i < n; ++i) {
        if(a[i]>max)
            max=a[i];
    }

    cout<< "the biggest number is : "<<max<<endl;



    cout<<"search for number :"<<endl;
    int x;
    cin>>x;
    int found=0;
    for (int i = 0; i <n ; ++i) {
        if (x==a[i])
        {cout<<i<<" found"<<endl;
        found=1;}

    }
    if (found==0)
        cout<<"not found"<<endl;

    do{ int b;
    cout<<"please choose to delete or add number :\n1.add \n2.delete"<<endl;
    cin>>b;
        switch (b) {
            case 1:{
                cout<<"please choose the number you want to add befor it : "<<endl;
                int x;
                cin>>x;
                int  i = 0;
                for (; i < n; ++i) {
                    if (x==a[i])
                        break;
                }
                for (int j = n-1; j >=i ; --j) {
                    a[j+1]=a[j];

                }
                cout<<"please add a number :"<<endl;
                cin>>a[i];

                cout<<"your array :"<<endl;
                for ( i = 0; i <= n; ++i) {

                    cout<<a[i]<<endl;}
                n++;
                break;}

            case 2 :{
                cout<<"please choose the number you want to delete: "<<endl;
                cin>>x;
                int k = 0;
                for (; k < n; ++k) {
                    if (x==a[k])
                        break;
                }
                for (int j = k; j <n ; ++j) {
                    a[j]=a[j+1];
                }
                cout<<"your array :"<<endl;
                for ( k = 0; k < n-1; ++k) {

                    cout<<a[k]<<endl;}
                n--;
            
            }

        }


    }while (a!=0);

    return 0;
}
