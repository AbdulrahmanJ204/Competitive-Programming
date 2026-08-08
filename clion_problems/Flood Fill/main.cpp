    /*
                .------.____
             .-'       \ ___)
          .-'         \\\
       .-'        ___  \\)
    .-'          /  (\  |)
             __  \  ( | |
            /  \  \__'| |
           /    \____).-'
         .'       /   |
        /     .  /    |
      .'     / \/     |
     /      /   \     |
           /    /    _|_
           \   /    /\ /\
            \ /    /__v__\
             '    |       |
                  |     .#|
                  |#.  .##|
                  |#######|
                  |#######|
                          (
                            )     (
                     ___...(-------)-....___
                 .-""       )    (          ""-.
           .-'``'|-._             )         _.-|
          /  .--.|   `""---...........---""`   |
         /  /    |                             |
         |  |    |                             |
          \  \   |                             |
           `\ `\ |                             |
             `\ `|                             |
             _/ /\                             /
            (__/  \                           /
         _..---""` \                         /`""---.._
      .-'           \                       /          '-.
     :               `-.__             __.-'              :
     :                  ) ""---...---"" (                 :
      '._               `"--...___...--"`              _.'
        \""--..__                              __..--""/
         '._     """----.....______.....----"""     _.'
            `""--..,,_____            _____,,..--""`
                          `"""----"""`
     * */
    #include <bits/stdc++.h>
    using namespace std;
    #define test  int t;cin>>t;while(t--)
    #define ll long long
    #define endl '\n'
    #define cendl cout<<endl
    #define cyes cout<<"YES"<<endl
    #define cno cout<<"NO"<<endl
    #define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);


    int main() {
        InTheNameOfAllah
        int n;
        cin>>n;
        int c[n];
        for (int i = 0; i < n; ++i) {
            cin>>c[i];
        }
        vector<int> a;
        for (int i = 0; i < n-1; ++i) {
            if(c[i]!=c[i+1])
                a.push_back(c[i]);
        }
        if(n==1) {
            cout << 0 << endl;
            return 0;
        }
        if(a.size()>=1) {
            if (c[n - 1] != a[a.size() - 1])
                a.push_back(c[n - 1]);
        }
        else {
            cout << 0 << endl;
            return 0;
        }
       // for(auto x: a) cout<<x<<' '; cendl;

        n=a.size();
        if(n==2) {
            cout << 1 << endl;
            return 0;
        }
        int ans=n;
        for (int i = 0; i < n; ++i) {
            map<ll,ll> m;
            for (int j = i+1; j < n; ++j) {
                m[a[j]]++;
            }

            for (int k = i-1; k >=0 ; --k) {
                m[a[k]]--;
            }
            int sum=0;
            for(auto x: m)
                if(x.second==0)sum+=1;
                else sum+=abs(x.second);
            ans=min(ans,sum);
            //cendl;for(auto x: a) cout<<x<<' ';
            //cendl;
            //cout<<"I= "<<i<<' '<<sum<<endl;
            //for(pair<ll,ll> x: m) cout<<x.first<<' '<<x.second<<endl;cendl;
        }
        int a[n];
        for (int i = 0; i < n; ++i) {
            
        }
        cout<<ans<<endl;
        return 0;
    }