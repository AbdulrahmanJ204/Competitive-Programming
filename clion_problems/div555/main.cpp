#include <iostream>
#include <string>
using namespace std;
int main() {
    int t;
    cin>>t;
    string a[10000];
    int d[10000];//size of a[];
    for (int i = 0; i <t ; ++i) //input
    {   cin>>d[i];
        cin>>a[i];
        for (int k = 0; k <d[i] ; ++k) //converting to lower case
            a[i].at(k)=tolower(a[i].at(k));
    }

    for (int i = 0; i <t ; ++i)//deleting duplicated characters
        for (int j = d[i]-1; j >0 ; --j)
         if(a[i].at(j) == a[i].at(j - 1))
            a[i][j]='\0';


    for (int i = 0; i <t ; ++i)//assembling characters together;
        for (int j = 0; j <d[i]-1 ; ++j)
            for (int k = 0; k <d[i]-1 ; ++k)
                if(a[i].at(k)=='\0'&&a[i].at(k+1)!='\0')
                {   a[i].at(k)=a[i].at(k+1);
                    a[i].at(k+1)='\0';
                }

    for (int l = 0; l <t ; ++l)
        if(a[l][0]=='m'&&a[l][1]=='e'&&a[l][2]=='o'&&a[l][3]=='w'&&a[l][4]=='\0')
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;

        return 0;
}
