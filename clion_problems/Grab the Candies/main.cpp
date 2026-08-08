#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        int even[n]={0},ceven=0,codd=0;
        int odd[n]={0};

        int sumodd=0,sumeven=0;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            if(a[i]%2==0)
            {
                even[ceven]=a[i];
                ceven++;
                sumeven+=a[i];
            }
            else
            {   sumodd+=a[i];
                odd[codd]=a[i];
                codd++;
            }
        }



        for (int i = 0; i < n-1; ++i) {
            for (int j = 0; j < n-1; ++j) {
                if((odd[j]>=odd[j+1]))
                    swap(odd[j+1],odd[j]);
                if(even[j]<=even[j+1])
                    swap(even[j],even[j+1]);
            }
        }

       int mih=0,bia=0;
        bool cando=true;
        for (int i = 0; i < n; ++i) {
            mih+=even[i];
            bia+=odd[i];
            if(bia>=mih) {
                cando = false;
                break;
            }
        }
        if(cando)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        }

    return 0;
}
