#include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin>>t;
        while(t--)
        {
            int n, k;
            cin >> n>>k;
            string s;
            cin >>s;
            string s2="",s3="",s4="";
            bool hmm = false;
            if(k%2==0)
            {
                sort(s.begin(),s.end());
                hmm = true;
            }
            else
            {
                string s2="",s3="",s4="";
                for (int i=0;i<n;i++)
                {
                    if(i%2==0)
                        s2 +=s[i];
                    else
                        s3 +=s[i];

                }
                sort(s2.begin(),s2.end());
                sort(s3.begin(),s3.end());
                bool hm=false;
                if (s2[0]<s3[0])
                {
                    hm=true;
                }
                if(hm)
               {
                   for(int i=0;i<n;i++){
                        if(i < s2.size())
                            s4 +=s2[i];
                        if(i < s3.size())
                            s4 +=s3[i];


                }
                }
                else
                {
                   for(int i=0;i<n;i++){
                        if(i< s3.size())
                            s4 +=s3[i];
                        if(i<s2.size())
                            s4 +=s2[i];

                }
               }


            }
            
            
            if(hmm)
                cout <<s<<endl;
            else
                cout <<s4<<endl;


        }

        return 0;
    }