#include <bits/stdc++.h>
using namespace std;
int main() {

    string s;
    cin>>s;
    int size=s.size();
    int cq=0;
    int pre[110];
    for (int i = 0; i < size; ++i) {
        if  (s[i] == 'Q' )
            cq++;
        pre[i]=cq;

    }
    cq=0;
    int suf[110];
    for (int i = size-1; i >=0; --i) {
        if  (s[i] == 'Q' )
            cq++;
        suf[i]=cq;

    }
    int ans=0;
    for (int i = 0; i < size; ++i) {
        if(s.at(i)=='A')
            ans+=(pre[i]*suf[i]);
    }
    cout<<ans<<endl;
    /* string s;
    getline(cin,s);
    int size=s.size();
    int cq=0;
    int c=0;
    int pre[110]={0};
    for (int i = 1; i < size; ++i) {
        if ((s.at(i) !='A')&&(s.at(i)!='Q'))
            s[i]='\0';
    }


    for (int i = 0; i < size; ++i) {
        if  (s[i] == 'Q' )
            cq++;
        pre[i]=cq;

    }
    cq=0;
    int suf[110];
    for (int i = size-1; i >=0; --i) {
        if  (s[i] == 'Q' )
            cq++;
        suf[i]=cq;

    }
    int ans=0;
    for (int i = 0; i < size; ++i) {
        if(s.at(i)=='A')
            ans+=(pre[i]*suf[i]);
    }
    cout<<ans<<endl;

     O(n)


     *//*

    */
/*
    string s;
    cin>>s;
    int size=s.size();
    int cq=0,scq=0;
    int ans=0;
    for (int i = 0; i < size; ++i)
    {   cq=0;
        scq=0;

        if (s[i]=='A')
        {
            for (int j = 0; j < i; ++j) {
                if (s[j] == 'Q')
                    cq++;
            }
            for (int k = i+1; k < size; ++k) {
                if (s[k] == 'Q')
                    scq++;
            }
            ans+=(scq*cq);
        }

    }
    cout<<ans<<endl;


            O(n^2)
*//*

    string s;
    getline(cin,s);
    int size=s.size();
    int ans=0;
    for (int i = 0; i < size; ++i)
    {   if(s[i]=='Q')
        for (int j = i+1; j < size; ++j) {
            if(s[j]=='A')
                for (int k = j+1; k <size ; ++k) {
                    if(s[k]=='Q')
                        ans++;
                }
        }
    }

cout<<ans<<endl;
//O(n^3)
*/


    return 0;
}
