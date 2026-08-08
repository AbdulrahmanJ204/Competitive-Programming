#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string f,s;
    cin>>f>>s;
    int c1,r1,c2,r2;
    c1=f[0]-'a';
    c2=s[0]-'a';
    r1=f[1]-'0';
    r2=s[1]-'0';
    vector<int>v;
    int row_dif=abs(r1-r2);
    int col_dif=abs(c1-c2);
    int ans=max(col_dif,row_dif);
    cout<<ans<<endl;
    if(c1<c2)
    {
        if(r1<r2)
        {
            while(r1!=r2&&c2!=c1) {
                cout << "RU" << endl;
                r1++;
                c1++;
            } while(r1!=r2)
            {
                cout<<"U"<<endl;
                r1++;
            }
        } else
        {
            while(r1!=r2&&c2!=c1) {
                cout << "RD" << endl;
                r1--;
                c1++;
            }
            while(r1!=r2)
            {
                cout<<"D"<<endl;
                r1--;
            }

        }
        while(c1!=c2)
        {
            cout<<"R"<<endl;
            c1++;
        }

    }
    else
    {
        if(r1<r2)
        {
            while(r1!=r2&&c2!=c1) {
                cout << "LU" << endl;
                r1++;
                c1--;
            }
            while(r1!=r2)
            {
                cout<<"U"<<endl;
                r1++;
            }
        } else
        {
            while(r1!=r2&&c2!=c1) {
                cout << "LD" << endl;
                r1--;
                c1--;
            }
            while(r1!=r2)
            {
                cout<<"D"<<endl;
                r1--;
            }

        }
        while(c1!=c2)
        {
            cout<<"L"<<endl;
            c1--;
        }
    }
    return 0;
}
