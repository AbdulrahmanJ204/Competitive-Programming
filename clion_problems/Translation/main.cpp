#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin>>s;
    string s1;
    cin>>s1;
    string t="";
    for (int i = s.size()-1; i >=0; --i) {
        t+=s[i];
    }
    if(s1==t)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
