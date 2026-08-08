#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dif(int mn,int mx)
{
    return abs(mx-mn);
}
pair<int,int> mxmn1(string s)
{   int mx=0,mn=11;
    for (int i = 0; i < s.size(); ++i) {
        mx=max(s[i]-'0',mx);
        mn=min(s[i]-'0',mn);
    }
    pair<int, int> a(mx,mn);
    return a;
}
string fc(string a,string b,string ans)
{
    pair<int,int> mxmn(0,11);
    pair<int,int> tmxmn(0,11);
    mxmn=mxmn1(ans);
    bool done=false;
    int ans_dif=dif(mxmn.first,mxmn.second );
    for (int i = 0; i < a.size(); ++i) {string tempans=ans;
        if(b[i]-a[i]>=2 ||done==true)
        { int a1=a[i],b1=b[i];tempans=ans;
            done=true;
            for (int j = a1+1; j <b1 ; ++j) {
                tempans+=to_string(j);
                tmxmn=mxmn1(tempans);
                int tempans_dif=dif(tmxmn.first,tmxmn.second);
                if(ans_dif<=tempans_dif)
                {
                    ans=tempans;
                    mxmn=tmxmn;
                }
                tempans=tempans.substr(0,tempans.size()-1);
            }
        }
       else if(!done) {
            ans += a[i];
            mxmn = mxmn1(ans);
        }
    }


return ans;

}

string sc(string a,string b,string ans)
{
    pair<int,int> mxmn(0,11);
    pair<int,int> tmxmn(0,11);
    mxmn=mxmn1(ans);
    bool done=false;
    int ans_dif=dif(mxmn.first,mxmn.second );
    for (int i = 0; i < a.size(); ++i) {string tempans=ans;
        if(b[i]-a[i]>=2 ||done==true)
        { int a1=a[i],b1=b[i];tempans=ans;
            done=true;
            for (int j = a1+1; j <b1 ; ++j) {
                tempans+=to_string(j);
                tmxmn=mxmn1(tempans);
                int tempans_dif=dif(tmxmn.first,tmxmn.second);
                if(ans_dif<=tempans_dif)
                {
                    ans=tempans;
                    mxmn=tmxmn;
                }
                tempans=tempans.substr(0,tempans.size()-1);
            }
        }
        else if(!done) {
            ans += b[i];
            mxmn = mxmn1(ans);
        }
    }


    return ans;

}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        ll l = stoll(a),r=stoll(b);
        string ans1="";
        if(a.size()<b.size()) {
            for (int i = 0; i < a.size(); ++i) {
                cout << 9;
            }cout<<endl;
            continue;
        }

        if(a==b)
        {
            cout<<b<<endl;
            continue;
        }
        //for a=b done;
        for (int j = 0; j < a.size(); ++j) {
            if(a[j]==b[j])
            {
                ans1+=a[j];
            }
            else
            {

                break;
            }
        }
        string a2,a3;
        a2=fc(a,b,ans1);
        a3=sc(a,b,ans1);


        pair<int,int> mxmn(0,11);
        pair<int,int> tmxmn(0,11);
        mxmn=mxmn1(ans1);
        string ans=ans1;
        int ans_dif=dif(mxmn.first,mxmn.second);
        for (int i = 0; i < a.size(); ++i) {string tempans=ans;
            if(b[i]-a[i]>=2)
            {
                int a1=a[i],b1=b[i];

                for (int j = a1+1; j <b1 ; ++j) {
                    tempans+=to_string(j);
                    tmxmn=mxmn1(tempans);
                    int tempans_dif=dif(tmxmn.first,tmxmn.second);
                    if(ans_dif<=tempans_dif)
                    {
                        ans=tempans;
                        mxmn=tmxmn;
                    }
                    tempans=tempans.substr(0,tempans.size()-1);
                }
            }
            else
            {
                for (int j = i; j <a.size() ; ++j) {
                    ans+=char(mxmn.second);
                }
                break;
            }
        }
            ll a1=stoll(ans);
        ll a22=stoll(a2);
        ll a33=stoll(a3);
        if(a1>=l && a1<=r)
            cout<<ans<<endl;
        else if(a22>=l && a22<=r)
        cout<<a2<<endl;
        else if(a33>=l && a33<=r)
        cout<<a3<<endl;

    }
    return 0;
}
