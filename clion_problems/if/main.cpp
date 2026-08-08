#include <iostream>
using namespace std;
int sum(int n,int m)
{if (m==n)
    return m;
if(m>n)
    return m +sum(n,m-1);
/*5+6+7+8+9
 * n      m
 *
 *
 *
 * */

}
int main() {

int x,y;
cin>>x>>y;
cout<<sum(x,y)<<endl;
    return 0;
}
