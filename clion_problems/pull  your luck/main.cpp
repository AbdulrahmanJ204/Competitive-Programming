    #include <bits/stdc++.h>
    using namespace std;
    int main() {
        int t,temp;
        cin>>t;
        temp=t;
        while (temp--)
        {
                bool found=false;
                long long x,p,n;
                cin>>n>>x>>p;
                long long temp = min(2*n,p);
                for (long long i = 1; i <=temp ; ++i) {


                 long long forward=x+(i*(i+1)/2);
                    forward%=n;

                if(forward==0) {
                    found = true;
                break;}

                }

            if(found)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;}
        return 0;
    }
