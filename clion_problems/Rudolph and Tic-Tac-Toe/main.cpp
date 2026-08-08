#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
char a[3][3];
bool done;
void solvex()
{
    for (int i = 0; i < 3; ++i) {
        bool x=true;
        for (int j = 0; j < 3; ++j) {
            if(a[i][j]!='X')
                x=false;
        }
        if(x) {
            cout << 'X' << endl;
            done=true;
            return;
        }
    }
    for (int i = 0; i < 3; ++i) {
        bool x=true;
        for (int j = 0; j < 3; ++j) {
            if(a[j][i]!='X')
                x=false;
        }
        if(x) {
            cout << 'X' << endl;done=true;
            return;
        }
    }bool x=true;
    for (int i = 0; i < 3; ++i) {
        if(a[i][i]!='X')
            x=false;
    }if(x){
        cout << 'X' << endl;done=true;
        return;
    }
    x=true;
    for (int i = 0; i < 3; ++i) {
        if(a[i][2-i]!='X')
            x=false;
    }
    if(x){
        cout << 'X' << endl;done=true;
        return;
    }

}
void solveo()
{
    for (int i = 0; i < 3; ++i) {
        bool x=true;
        for (int j = 0; j < 3; ++j) {
            if(a[i][j]!='O')
                x=false;
        }
        if(x) {
            cout << 'O' << endl;done=true;
            return;
        }
    }
    for (int i = 0; i < 3; ++i) {
        bool x=true;
        for (int j = 0; j < 3; ++j) {
            if(a[j][i]!='O')
                x=false;
        }
        if(x) {
            cout << 'O' << endl;done=true;
            return;
        }
    }bool x=true;
    for (int i = 0; i < 3; ++i) {
        if(a[i][i]!='O')
            x=false;
    }if(x){
        cout << 'O' << endl;done=true;
        return;
    }
    x=true;
    for (int i = 0; i < 3; ++i) {
        if(a[i][2-i]!='O')
            x=false;
    }
    if(x){
        cout << 'O' << endl;done=true;
        return;
    }

}
void solvep()
{
    for (int i = 0; i < 3; ++i) {
        bool x=true;
        for (int j = 0; j < 3; ++j) {
            if(a[i][j]!='+')
                x=false;
        }
        if(x) {
            cout << '+' << endl;done=true;
            return;
        }
    }
    for (int i = 0; i < 3; ++i) {
        bool x=true;
        for (int j = 0; j < 3; ++j) {
            if(a[j][i]!='+')
                x=false;
        }
        if(x) {
            cout << '+' << endl;done=true;
            return;
        }
    }bool x=true;
    for (int i = 0; i < 3; ++i) {
        if(a[i][i]!='+')
            x=false;
    }if(x){
        cout << '+' << endl;done=true;
        return;
    }
    x=true;
    for (int i = 0; i < 3; ++i) {
        if(a[i][2-i]!='+')
            x=false;
    }
    if(x){
        cout << '+' << endl;done=true;
        return;
    }

}
int main() {
    InTheNameOfAllah
    test {
        done=false;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin>>a[i][j];
            }
        }
        solvex();
        solveo();
        solvep();
        if(!done)
            cout<<"DRAW"<<endl;

    }
    return 0;
}