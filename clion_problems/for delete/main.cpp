#include <bits/stdc++.h>
#include <string>

using namespace std;

int main() {
    int t;
    cin >>t;
    while (t--)
    {
        int n,m;
        cin >>n>>m;
        int arr[n];

        for (int i = 0; i < n; ++i) {
            cin >>arr[i];
        }
        int ar[3];
        while (m--)
        {
            for (int i = 0; i < 3; ++i) {
                cin >>ar[i];
            }
            int sum=0;
            int temp[n];
            for (int i = 0; i < n; ++i) {
                temp[i]=arr[i];
                sum+=temp[i];
            }
            for (int i = ar[0]-1; i < ar[1]; ++i)
            {
                sum-=temp[i];
                temp[i]=ar[2];
                sum+=temp[i];
            }


            if (sum%2==0)
                cout <<"NO"<<endl;
            else
                cout <<"YES"<<endl;

        }




    }

    return 0;
}#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
