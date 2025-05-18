#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"
#define cno cout<<"NO"
#define cin(v) for(ll i=0;i<v.size();i++)cin>>v[i];
#define cin1(v,n) for(ll i=0;i<n;i++)cin>>v[i];
#define cin2(v,n,m) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) cin>>v[i][j];
#define tryAndCry(v) for(auto x : v){cout<<x<<" ";}cout<<"\n";
#define cout1(v,n) for(ll i=0;i<n;i++)cout<<v[i]<<' '; cendl;
#define cout2(v,n,m) for(ll i=0;i<n;i++,cendl) for (int j = 0; j < m; j++) cout<<v[i][j]<<' ';
#define assign1(v,n,value) for(ll i=0;i<n;i++)v[i]=value;
#define assign2(v,n,m,value) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) v[i][j]=value;
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define oo  LLONG_MAX;
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
 // مسألة للكب 
    ll coins,n;
    cin>>coins>>n;
    int a[n];
    cin1(a,n);
   
    int edited[n][2];
    assign2(edited , n , 2 , 0);
    map<int , int > mp;
    int c[]={1, 5 , 10 , 20 , 50};
    for (int i = 0; i < 5; i++)
      mp[c[i]];
    
    
    if(coins%5) mp[1]=coins%5;

    // cout<<"\nMp0 :\n";
    // for(auto x : mp) cout<<x.second<<" ";cendl;

    for (int i = 0; i < n; i++)
      if(a[i]%5) mp[1]+= (a[i]%5 > mp[1] ? 5 : 0), edited[i][0]=a[i]%5, a[i]-=a[i]%5 ;

    // cout<<"Mp1 :\n";
    // for(auto x : mp) cout<<x.second<<" ";cendl;
    coins-=mp[1];
    
    if(coins%10) mp[5]++;
    for (int i = 0; i < n; i++)
      if(a[i]%10 && mp[1]>=5&& !edited[i][0]) a[i]-=5 , edited[i][0]=5;
      else if(a[i]%10 && mp[5]==1) a[i]-=5 , edited[i][1]=5;
      else if(a[i]%10) mp[5]= 2 , a[i]-=5 , edited[i][1]=5;

    coins-=mp[5]*5;

    // cout2(edited , n , 2);
    // cout1(a,n);
    // cout<<"Mp5 :\n";
    // for(auto x : mp) cout<<x.second<<" ";cendl;
    // cout<<coins<<endl;


    
    ll rem= coins%50;
    mp[50]=coins/50;
    coins-=rem;
    // cout<<"Case : "<<rem<<endl;
    if(rem){
      if(rem==10 ){
        bool needTo50 = false;
        bool needTo10 = false;
        
        for (int i = 0; i < n; i++)
        {
          
          int item= a[i];
          int z= min(mp[50] , item/50);
          item-=z*50;
          int tenFrom1and5 = mp[5]*5 - edited[i][1] + mp[1]-edited[i][0];
          int can10 = tenFrom1and5>=10 ? 10 : 0;
          
          if(item){
            // cout<<"a[i] = "<<a[i]<<"  it = "<<item<<endl;
            if(item==20){
              // cout<<can10<<" t = "<<tenFrom1and5<<endl;
              if(!can10)needTo50=true;
            }
            else if(item==30){
              if(!can10) needTo10=true;
              needTo50=true;
            }
            else if(item==40)
            {
              needTo50=true;
            }
          }

        }
        if(needTo50){
          mp[50]--;
          if(needTo10){
            // cout<<"1\n";
            mp[10]++;
            mp[20]+=2;
          }
          else{
            // cout<<"2\n";
            mp[20]+=3;
          }
        }
        else{
            // cout<<"3\n";
          mp[10]++;
        }
      }
      else if(rem==20){
        bool need10 = false;
        bool need50 = false;
        
        for (int i = 0; i < n; i++)
        {
          int item= a[i];
          int z= min(mp[50] , item/50);
          item-=z*50;
          int tenFrom1and5 = mp[5]*5 - edited[i][1] + mp[1]-edited[i][0];
          int can10 = tenFrom1and5>=10 ? 10 : 0;

          if(item){
            if(item==10){
              if(!can10) need10 =true;
            }
            else if(item==30){
              if(!can10) need50 =true;
            }
            else if(item==40){
              need50=true;
            }
          }
        
        }
        
        if(need50){
          mp[50]--;

          mp[20]+=3 , mp[10]++; 
        }
        else{
          if(need10) mp[10]+=2;
          else mp[20]++;
        }
        

      }
      else if(rem== 30){
        bool need50= false;
        bool need10 = false;
        for (int i = 0; i < n; i++)
        {
          int item= a[i];
          int z= min(mp[50] , item/50);
          item-=z*50;
          int tenFrom1and5 = mp[5]*5 - edited[i][1] + mp[1]-edited[i][0];
          int can10 = tenFrom1and5>=10 ? 10 : 0;

          if(item){
            
            if(item==10){
              if(!can10) need10 =true;
            }
            else if(item==30){
              if(!can10) need10 =true;
            }
            else if(item==40){
              need50=true;
            }
          }

        }   
        if(need50){
          
          if(need10) mp[20]+=3 , mp[10]+=2;
          else mp[20]+=4;
        }
        else{
           mp[20]++ , mp[10]++;
        }

      }
      else if(rem==40){
        
         bool need10 = false , need50 =false;
         for (int i = 0; i < n; i++)
        {
          int item= a[i];
          int z= min(mp[50] , item/50);
          item-=z*50;
          int tenFrom1and5 = mp[5]*5 - edited[i][1] + mp[1]-edited[i][0];
          int can10 = tenFrom1and5>=10 ? 10 : 0;

          if(item){
            if(item==10 || item==30){
              if(!can10) need10=true;
            }  
          
          }
          
        }
        
          if(need10)
          mp[20]++ , mp[10]+=2;
          else mp[20]+=2;
        

      }
    }
    else{
      bool need50 =false;
      for (int i = 0; i < n; i++)
        {
          int item= a[i];
          int z= min(mp[50] , item/50);
          item-=z*50;
          int tenFrom1and5 = mp[5]*5 - edited[i][1] + mp[1]-edited[i][0];
          int can10 = tenFrom1and5>=10 ? 10 : 0;

          if(item){
            if(item==10){
              if(!can10) need50=true;
            }
            else need50 = true;
           
          }

        }
      if(need50) mp[50]-- , mp[20]+=2 , mp[10]++;
    }
    


 
    for(auto x : mp) cout<<x.second<<" ";
    
    
  return;
}

int32_t main() {
    InTheNameOfAllah
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}